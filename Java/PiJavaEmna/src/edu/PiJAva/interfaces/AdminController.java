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
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.ButtonBar;
import javafx.scene.control.ButtonType;
import javafx.scene.control.Label;
import javafx.stage.Stage;

/**
 * FXML Controller class
 *
 * @author 21694
 */
public class AdminController implements Initializable {

    /**
     * Initializes the controller class.
     */
    User u =new User();
     ServiceUser su=new ServiceUser();
    @FXML
    private Label TxUserName;
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
        u=su.getUserByEmail(LoginController.iduserglobal);
        TxUserName.setText("ADMIN "+u.getName().toUpperCase()+" "+u.getLastname().toUpperCase());
    }    

    @FXML
    private void Dashbord(ActionEvent event) {
        FXMain.setScene("DasbordAdmin");
    }

    @FXML
    private void DepotConstat(ActionEvent event) {
        FXMain.setScene("DepotConstatAdmin");
    }

    @FXML
    private void Facture(ActionEvent event) {
        FXMain.setScene("FactureAdmin");
    }

    @FXML
    private void Profile(ActionEvent event) {
        FXMain.setScene("ProfileAdmin");
    }

    @FXML
    private void Reclamation(ActionEvent event) {
        FXMain.setScene("ReclamationAdmin");
    }   

    @FXML
    private void ListUser(ActionEvent event) {  
        FXMain.setScene("UserList");
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
         FXMain.setScene("Login");
        
    }
    }
    
}
