/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.PiJAva.interfaces;

import edu.PiJAva.entities.User;
import edu.PiJAva.services.ServiceUser;
import java.net.URL;
import java.util.Optional;
import java.util.Random;
import java.util.ResourceBundle;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonBar;
import javafx.scene.control.ButtonType;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

/**
 * FXML Controller class
 *
 * @author chaab
 */
public class ProfileAdminController implements Initializable {

    @FXML
    private TextField TFname;
    @FXML
    private TextField TFlastname;
    @FXML
    private TextField TFemail;
    @FXML
    private PasswordField TFpassword;
    @FXML
    private Button modifbtn;
User u =new User();
    ServiceUser su=new ServiceUser();
    @FXML
    private Label UserName1;
    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
                 u=su.getUserByEmail(LoginController.iduserglobal);
                  TFname.setText(u.getName());
        TFlastname.setText(u.getLastname());
      
        TFemail.setText(u.getEmail());       
       UserName1.setText(generatePseudo(u.getName(), u.getLastname()));

     
    }    

    @FXML
    private void Dashbord(ActionEvent event) {
        FXMain.setScene("Admin");
    }

    @FXML
    private void DepotConstat(ActionEvent event) {
        FXMain.setScene("DEP");
    }

    @FXML
    private void Facture(ActionEvent event) {
        FXMain.setScene("FAC");
    }

    @FXML
    private void Profile(ActionEvent event) {
        FXMain.setScene("ProfileAdmin");
    }

    @FXML
    private void Reclamation(ActionEvent event) {
        FXMain.setScene("REC");
    }

    @FXML
    private void ListUser(ActionEvent event) {
        FXMain.setScene("UserList");
    }

    @FXML
    private void modifClicked(ActionEvent event) {
        
        
        String erreur=controleDeSaisie();
               if(erreur.length()>0){
            Alert alert=new Alert(Alert.AlertType.WARNING);
            alert.setTitle("invalide");
            alert.setContentText(erreur);
            alert.showAndWait();
        }
        else {
         u=su.getUserByEmail(LoginController.iduserglobal);
            u.setName(TFname.getText());
            u.setLastname(TFlastname.getText());
            u.setEmail(TFemail.getText());                
             u.setPassword(TFpassword.getText());
           
           
            }
            
            su.modifier(u.getId(),u);
        }
    
    
    
     public String controleDeSaisie(){
        Pattern pattern = Pattern.compile("^[A-Z0-9_!#$%&'*+/=?`{|}~^-]+(?:\\.[A-Z0-9_!#$%&'*+/=?`{|}~^-]+↵\n" +
				")*@[A-Z0-9-]+(?:\\.[A-Z0-9-]+)*$", Pattern.CASE_INSENSITIVE);
        Matcher matcher = pattern.matcher(TFemail.getText());
        String erreur="";
         
        
        
        if(TFname.getText().trim().isEmpty()){
            erreur+="-nom vide\n";
        }
        if(TFlastname.getText().trim().isEmpty()){
            erreur+="-prenom vide\n";
        }
        // Vérifier que l'adresse e-mail est valide
    String email = TFemail.getText().trim();
    if (!email.contains("@") || (!email.endsWith(".com") && !email.endsWith(".fr") && !email.endsWith(".tn"))) {
        erreur += "- Adresse e-mail invalide\n";
    }

        
        
    
        if(TFpassword.getText().trim().isEmpty()){
            erreur+="-mdp vide\n";
        }
       
        
        if(!matcher.find()){
            erreur+="-email incorrect\n";
        }
        if(TFpassword.getText().length()<4){
        erreur+="-mot de passe doit etre sup a 4 char\n";
    }
    Pattern mdpPattern = Pattern.compile("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");
    Matcher mdpMatcher = mdpPattern.matcher(TFpassword.getText());
    if (!mdpMatcher.matches()) {
        erreur+="-mot de passe doit contenir au moins une lettre majuscule, une lettre minuscule, un chiffre et un caractère spécial et avoir une longueur d'au moins 8 caractères\n";
    }
        return erreur;
    }

    @FXML
    private void LogOut(ActionEvent event) {
                Stage stage;
    Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
    alert.setTitle("Déconnexion");
    alert.setHeaderText("Vous êtes sur le point de vous déconnecter");
    alert.setContentText("Voulez-vous vous déconnecter "+u.getEmail()+"?");
    ButtonType okButton = new ButtonType("OK", ButtonBar.ButtonData.OK_DONE);
    ButtonType cancelButton = new ButtonType("Annuler", ButtonBar.ButtonData.CANCEL_CLOSE);
    alert.getButtonTypes().setAll(okButton, cancelButton);
    Optional<ButtonType> result = alert.showAndWait();
    if (result.isPresent() && result.get() == okButton) {
         FXMain.setScene("InterfaceLogin");
        
    }
    }
    
    public static String generatePseudo(String tfnom, String tfprenom) {
        String firstInitial = tfprenom.substring(0, 1).toLowerCase();
        String lastInitial = tfnom.substring(0, 1).toLowerCase();
        int randomNum = new Random().nextInt(10000); // generate a random number between 0 and 9999
        String pseudo = firstInitial + lastInitial + randomNum;
        return pseudo;
    }
    
}
