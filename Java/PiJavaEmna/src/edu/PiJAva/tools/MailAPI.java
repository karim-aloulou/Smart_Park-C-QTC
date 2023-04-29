/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.PiJAva.tools;

import java.util.Properties;
import javax.mail.Message;
import javax.mail.MessagingException;
import javax.mail.PasswordAuthentication;
import javax.mail.Session;
import javax.mail.Transport;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeMessage;

/**
 *
 * @author Skymil
 */
public class MailAPI {
    public static void sendMail(String to,String sub,String msg) throws MessagingException{
        
            Properties prop=new Properties();
            prop.put("mail.smtp.host","smtp.gmail.com");
            prop.put("mail.smtp.port", "587");
            prop.put("mail.smtp.auth", "true");
            prop.put("mail.smtp.starttls.enable", "true");
            prop.put("mail.smpt.ssl.trust", "smtp.gmail.com");
            Session session=Session.getDefaultInstance(prop,new javax.mail.Authenticator(){
                protected PasswordAuthentication getPasswordAuthentication(){
                    return new PasswordAuthentication("emna.khlifaoui@esprit.tn","lpbt1234");
                }
            });
            MimeMessage message=new MimeMessage(session);
        
            message.addRecipient(Message.RecipientType.TO, new InternetAddress(to));
        
            message.setSubject(sub);
            message.setText(msg);
            Transport.send(message);
            System.out.println("message sent");
        
        
        
    }
    
}
