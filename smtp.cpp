#include "smtp.h"


Smtp::Smtp( const QString &user, const QString &pass, const QString &host, int port, int timeout )
    {
      socket = new QSslSocket(this);

      connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
      connect(socket, SIGNAL(connected()), this, SLOT(connected() ) );
      connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this,SLOT(errorReceived(QAbstractSocket::SocketError)));
      connect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(stateChanged(QAbstractSocket::SocketState)));
      connect(socket, SIGNAL(disconnected()), this,SLOT(disconnected()));


      this->user = user;
      this->pass = pass;

      this->host = host;
      this->port = port;
      this->timeout = timeout;


    }

    Smtp::~Smtp()
    {
      delete t;
      delete socket;
    }

    void Smtp::sendMail(const QString &from, const QString &to, const QString &subject, const QString &body)
    {
      message = "To: " + to + "\n";
      message.append("From: " + from + "\n");
      message.append("Subject: " + subject + "\n");
      message.append(body);

      message.replace( QString::fromLatin1( "\n" ), QString::fromLatin1( "\r\n" ) );
      qDebug()<<"Body :: "<<body;
      message.replace( QString::fromLatin1( "\r\n.\r\n" ),QString::fromLatin1( "\r\n..\r\n" ) );
      qDebug()<<"Message :: "<<message;

      this->from = from;
      rcpt = to;
      state = Init;
      socket->connectToHostEncrypted(host, port); //"smtp.gmail.com" and 465 for gmail TLS
      if (!socket->waitForConnected(timeout)) {
          qDebug() << socket->errorString();
        }

      t = new QTextStream( socket );
      qDebug()<<"MYSOCKET TEST : "<<socket;

    }

    void Smtp::stateChanged(QAbstractSocket::SocketState socketState)
    {

      qDebug() <<"stateChanged " << socketState;
    }

    void Smtp::errorReceived(QAbstractSocket::SocketError socketError)
    {
      qDebug() << "error " <<socketError;
    }

    void Smtp::disconnected()
    {

      qDebug() <<"disconneted";
      qDebug() << "error "  << socket->errorString();
    }

    void Smtp::connected()
    {
      qDebug() << "Connected ";
    }

    void Smtp::readyRead()
    {

      qDebug() <<"readyRead";


      QString responseLine;
      do
        {
          responseLine = socket->readLine();
          response += responseLine;
        }
      while ( socket->canReadLine() && responseLine[3] != ' ' );

      responseLine.truncate( 3 );

      qDebug() << "Server response code:" <<  responseLine;
      qDebug() << "Server response: " << response;

      if ( state == Init && responseLine == "220" )
        {

          *t << "EHLO localhost" <<"\r\n";

          t->flush();

          state = HandShake;
        }
      else if (state == HandShake && responseLine == "250")
        {
          socket->startClientEncryption();
          if(!socket->waitForEncrypted(timeout))
            {
              qDebug() << socket->errorString();
              state = Close;
            }

          *t << "EHLO localhost" << "\r\n";
          t->flush();
          state = Auth;
        }
      else if (state == Auth && responseLine == "250")
        {
          qDebug() << "Auth";
          *t << "AUTH LOGIN" << "\r\n";
          t->flush();
          state = User;
        }
      else if (state == User && responseLine == "334")
        {
          qDebug() << "Username";
          *t << QByteArray().append(user).toBase64()  << "\r\n";
          t->flush();

          state = Pass;
        }
      else if (state == Pass && responseLine == "334")
        {
          qDebug() << "Pass";
          *t << QByteArray().append(pass).toBase64() << "\r\n";
          t->flush();

          state = Mail;
        }
      else if ( state == Mail && responseLine == "235" )
        {
          qDebug() << "MAIL FROM:<" << from << ">";
          *t << "MAIL FROM:<" << from << ">\r\n";
          t->flush();
          state = Rcpt;
        }
      else if ( state == Rcpt && responseLine == "250" )
        {
          *t << "RCPT TO:<" << rcpt << ">\r\n"; //r
          t->flush();
          state = Data;
        }
      else if ( state == Data && responseLine == "250" )
        {

          *t << "DATA\r\n";
          t->flush();
          state = Body;
        }
      else if ( state == Body && responseLine == "354" )
        {
          *t << message << "\r\n.\r\n";
          t->flush();
          state = Quit;
        }
      else if ( state == Quit && responseLine == "250" )
        {

          *t << "QUIT\r\n";
          t->flush();
          state = Close;
          emit status( tr( "Message sent" ) );
        }
      else if ( state == Close )
        {
          deleteLater();
          return;
        }
      else
        {
          QMessageBox::warning(0,"System Message!","Something Went Wrong",QMessageBox::Ok);

          state = Close;
          emit status( tr( "Failed to send message" ) );
        }
      response = "";
    }
