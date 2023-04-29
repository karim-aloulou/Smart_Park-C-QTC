/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GUI;

import edu.PiJAva.entities.User;
import edu.PiJAva.interfaces.FXMain;
import java.net.URL;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javax.mail.MessagingException;
import edu.PiJAva.services.ServiceUser;
import edu.PiJAva.tools.MailAPI;

/**
 * FXML Controller class
 *
 * @author Skymil
 */
public class FXMLforgotpasswordController implements Initializable {

   
    @FXML
    private PasswordField tfcmdp;
    @FXML
    private TextField tfcode;
    @FXML
    private Button btnupdate;
    ServiceUser su=new ServiceUser();
    int code=(int)Math.floor(Math.random()*(999999-100000+1)+100000);
    @FXML
    private Button btnchercher;
    @FXML
    private TextField TxEmail;
    @FXML
    private PasswordField TxPassword;

    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        
        tfcode.setVisible(false);
        TxPassword.setVisible(false);
        tfcmdp.setVisible(false);
        btnupdate.setVisible(false);
        // TODO
    }    

    @FXML
    private void chercherutilisateur(ActionEvent event) {
        
        if(su.checkuser(TxEmail.getText())){
            try {
                MailAPI.sendMail(TxEmail.getText(), "Demande de changement mot de passe", "Veuillez saisire ce code pour que vous pouvez modifier votre mot de passe:"+code);
                TxEmail.setVisible(false);
                btnchercher.setVisible(false);
                tfcode.setVisible(true);
                TxPassword.setVisible(true);
                tfcmdp.setVisible(true);
                btnupdate.setVisible(true);
            } catch (MessagingException ex) {
                Logger.getLogger(FXMLforgotpasswordController.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        else{
            Alert alert=new Alert(Alert.AlertType.WARNING);
            alert.setTitle("invalide");
            alert.setContentText("email introuvable!");
            alert.showAndWait();
        }
    }

    @FXML
    private void modifiermotdepasse(ActionEvent event) {
        String erreur=controleDeSaisie();
        if(erreur.length()>0){
            Alert alert=new Alert(Alert.AlertType.WARNING);
            alert.setTitle("invalide");
            alert.setContentText(erreur);
            alert.showAndWait();
        }
        else{
            User u=su.getUserByEmail(TxEmail.getText());
            u.setPassword(TxPassword.getText());
            su.modifier(u.getId(), u);
             FXMain.setScene("Login");
        }
    }
    public String controleDeSaisie(){
      Pattern pattern = Pattern.compile("^[A-Z0-9_!#$%&'*+/=?`{|}~^-]+(?:\\.[A-Z0-9_!#$%&'*+/=?`{|}~^-]+↵\n" +
				")*@[A-Z0-9-]+(?:\\.[A-Z0-9-]+)*$", Pattern.CASE_INSENSITIVE);
        Matcher matcher = pattern.matcher(TxEmail.getText());
        String erreur="";
       
   
        // Vérifier que l'adresse e-mail est valide
    String email = TxEmail.getText().trim();
    if (!email.contains("@") || (!email.endsWith(".com") && !email.endsWith(".fr") && !email.endsWith(".tn"))) {
        erreur += "- Adresse e-mail invalide\n";
    }

        
        
       
        
        if(!matcher.find()){
            erreur+="-email incorrect\n";
        }
        if(TxPassword.getText().length()<4){
        erreur+="-mot de passe doit etre sup a 4 char\n";
    }
    Pattern mdpPattern = Pattern.compile("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");
    Matcher mdpMatcher = mdpPattern.matcher(TxPassword.getText());
    if (!mdpMatcher.matches()) {
        erreur+="-mot de passe doit contenir au moins une lettre majuscule, une lettre minuscule, un chiffre et un caractère spécial et avoir une longueur d'au moins 8 caractères\n";
    }
        return erreur;
    }

    @FXML
    private void retour(ActionEvent event) {
          FXMain.setScene("Login");
    }
    
}
