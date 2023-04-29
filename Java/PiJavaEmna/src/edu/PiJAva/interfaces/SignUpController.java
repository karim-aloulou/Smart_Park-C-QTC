/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.PiJAva.interfaces;

import edu.PiJAva.entities.Role;
import edu.PiJAva.entities.User;
import edu.PiJAva.services.ServiceUser;
import edu.PiJAva.tools.SmsAPI;
import java.net.URL;
import java.util.ResourceBundle;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.ProgressBar;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;

/**
 * FXML Controller class
 *
 * @author 21694
 */
public class SignUpController implements Initializable {

    @FXML
    private TextField TxName;
    @FXML
    private TextField TxLastname;
    @FXML
    private TextField TxEmail;
    @FXML
    private PasswordField TxPassword;
    @FXML
    private RadioButton RbExpert;
    @FXML
    private RadioButton RbUser;
    @FXML
    private RadioButton RbMecanicien;
     
    ServiceUser su =new ServiceUser();
    public static String emailsignup;
    @FXML
    private ProgressBar ProgressBarMdp;
    @FXML
    private Label Labelmdp;
    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle Rb) {
        // TODO
        TxPassword.setOnKeyReleased(this::progress);
    }    

    @FXML
    private void SignUp(ActionEvent event) {
        String erreur=controleDeSaisie();
        if(erreur.length()>0){
            Alert alert=new Alert(Alert.AlertType.WARNING);
            alert.setTitle("invalide");
            alert.setContentText(erreur);
            alert.showAndWait();
         }
        else {
            User u=new User();
            u.setName(TxName.getText());
            u.setLastname(TxLastname.getText());
            u.setEmail(TxEmail.getText());
                  
            u.setPassword(TxPassword.getText());
         
            u.setRole(RbUser.isSelected() ? Role.ROLE_USER : RbExpert.isSelected() ? Role.ROLE_EXPERT : RbMecanicien.isSelected() ? Role.ROLE_MECANICIEN: Role.ROLE_ADMIN);


            su.ajouter(u);
            
           emailsignup=u.getEmail();
           
           FXMain.setScene("Login");

        }
        
    }

    @FXML
    private void LogIn(MouseEvent event) {
        FXMain.setScene("Login");

    }
    
    
    public String controleDeSaisie(){
        Pattern pattern = Pattern.compile("^[A-Z0-9_!#$%&'*+/=?`{|}~^-]+(?:\\.[A-Z0-9_!#$%&'*+/=?`{|}~^-]+↵\n" +
				")*@[A-Z0-9-]+(?:\\.[A-Z0-9-]+)*$", Pattern.CASE_INSENSITIVE);
        Matcher matcher = pattern.matcher(TxEmail.getText());
        String erreur="";
        
        if(su.checkuser(TxEmail.getText())){
            erreur+="-email existe deja\n";
        }
        
        if(TxName.getText().trim().isEmpty()){
            erreur+="-nom vide\n";
        }
        if(TxLastname.getText().trim().isEmpty()){
            erreur+="-prenom vide\n";
        }
        // Vérifier que l'adresse e-mail est valide
    String email = TxEmail.getText().trim();
    if (!email.contains("@") || (!email.endsWith(".com") && !email.endsWith(".fr") && !email.endsWith(".tn"))) {
        erreur += "- Adresse e-mail invalide\n";
    }

        
        if(TxPassword.getText().trim().isEmpty()){
            erreur+="-mdp vide\n";
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

    private int checkPasswordStrength(String password) {
    // Cette fonction retourne un score de 0 à 4 en fonction de la difficulté du mot de passe
    int score = 0;
    Pattern mdpPattern = Pattern.compile("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");
    Matcher mdpMatcher = mdpPattern.matcher(password);
    if (mdpMatcher.matches()) {
        score = 4;
    } else {
        if (password.length() >= 8) {
            score += 1;
        }
        if (password.matches(".*\\d.*")) {
            score += 1;
        }
        if (password.matches(".*[A-Z].*")) {
            score += 1;
        }
        if (password.matches("^(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$")) {
            score += 1;
        }
    }
    return score;
}
    @FXML
    private void progress(KeyEvent event) {
        String password = TxPassword.getText();
        int score = checkPasswordStrength(password);
        ProgressBarMdp.setProgress(score / 4.0);
        if (score < 2) {
            ProgressBarMdp.setStyle("-fx-accent: red;");
            Labelmdp.setText("Mot de passe faible");
        } else if (score < 4) {
            ProgressBarMdp.setStyle("-fx-accent: orange;");
            Labelmdp.setText("Mot de passe moyen");
        } else {
            ProgressBarMdp.setStyle("-fx-accent: green;");
            Labelmdp.setText("Mot de passe fort");
        }
    }
    
}
