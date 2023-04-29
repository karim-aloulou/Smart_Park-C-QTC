/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.PiJAva.interfaces;

import co.yogesh.Captcha;
import edu.PiJAva.entities.User;
import edu.PiJAva.services.ServiceUser;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.embed.swing.SwingFXUtils;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javax.swing.JFrame;
import javax.swing.JLabel;

/**
 * FXML Controller class
 *
 * @author 21694
 */
public class LoginController implements Initializable {

    @FXML
    private TextField TxEmail;
    @FXML
    private PasswordField TxPassword;
     ServiceUser su =new ServiceUser();
    public static String iduserglobal;
    @FXML
    private ImageView captchagenerate;
    @FXML
    private TextField captchainput;
    private JLabel tempLabel;
     Captcha cap = new Captcha();
    /**
     * Initializes the controller class.
     * @param url
     * @param rb
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
        tempLabel = new JLabel();
       
        cap.setImageCaptcha(tempLabel);
        captchagenerate.setImage(SwingFXUtils.toFXImage(FXMain.iconToImage(tempLabel.getIcon()),null));
         JFrame frame = new JFrame("JOptionPane showMessageDialog example");
                    frame.setAlwaysOnTop(true);
    }    

    @FXML
    private void Login(ActionEvent event) {
  
        User u=su.login(TxEmail.getText(), TxPassword.getText());
        String access;

       if(cap.Validate(tempLabel, captchainput.getText()))
       {
           System.out.println("captcha valid");
       }else
       {
           System.out.println("captcha invalid");
            Alert alert = new Alert(Alert.AlertType.WARNING);
    alert.setTitle("Invalid Captcha");
    alert.setContentText("The captcha code entered is invalid.");
    alert.showAndWait();
        cap.setImageCaptcha(tempLabel);
        captchagenerate.setImage(SwingFXUtils.toFXImage(FXMain.iconToImage(tempLabel.getIcon()),null));

          
       }
        if(u!=null){
              iduserglobal= u.getEmail();
            switch (u.getRole()) {
                case ROLE_ADMIN:
                    //interface admin
                    FXMain.setScene("Admin");
                    break;
                case ROLE_MECANICIEN:
                    //interface mecanicien
                    FXMain.setScene("InterfaceMecanicien");
                    break;
                case ROLE_EXPERT:
                    //interface expert 
                    FXMain.setScene("InterfaceExpert");
                    break;
                default:
                    //interface USer
                    FXMain.setScene("InterfaceUser");
                    break;
            }

        }
        else{
            Alert alert=new Alert(Alert.AlertType.ERROR);
            alert.setTitle("invalide");
            alert.setContentText("Email ou mot de passe invalide!!");
            alert.showAndWait();
        }
    }
       @FXML
    private void gotoforgotpassword(MouseEvent event) {
          FXMain.setScene("FXMLforgotpassword");
       
    }

    @FXML
    private void SignUP(MouseEvent event) {
        FXMain.setScene("Sign up");
    }
    
}
