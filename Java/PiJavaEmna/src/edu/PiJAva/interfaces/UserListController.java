/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.PiJAva.interfaces;

import edu.PiJAva.entities.Role;
import edu.PiJAva.entities.User;
import edu.PiJAva.services.ServiceUser;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.net.URL;
import java.sql.SQLException;
import java.util.List;
import java.util.Optional;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonBar;
import javafx.scene.control.ButtonType;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.stage.Stage;
import javax.swing.JOptionPane;

/**
 * FXML Controller class
 *
 * @author 21694
 */
public class UserListController implements Initializable {

    @FXML
    private TableView<User> tvuser;
    @FXML
    private TableColumn<User, String> cnom;
    @FXML
    private TableColumn<User, String> cprenom;
    @FXML
    private TableColumn<User, String> cemail;
    @FXML
    private TableColumn<User, Role> crole;
    User u =new User();
     ServiceUser su=new ServiceUser();
     ObservableList<User> data=FXCollections.observableArrayList();
    @FXML
    private Label TxUserName;
    
    @FXML
    private TextField search;
    @FXML
    private Button Exporter;
    
    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
            u=su.getUserByEmail(LoginController.iduserglobal);
        TxUserName.setText("ADMIN "+u.getName().toUpperCase()+" "+u.getLastname().toUpperCase());
        
       /* search.textProperty().addListener((observable, oldValue, newValue) -> {
            if (oldValue != null && (newValue.length() < oldValue.length())) {
                tvuser.setItems(data);
            }
            String value = newValue.toLowerCase();
            ObservableList<User> subentries = FXCollections.observableArrayList();
            for (User entry : tvuser.getItems()) {
                boolean match = true;
                
                String name = entry.getName();
                String lastname = entry.getLastname();                

                if (!name.toLowerCase().contains(value)&&
                        !lastname.toLowerCase().contains(value))
                         {
                    match = false;
                }
                if (match) {
                    subentries.add(entry);
                }
            }
                 });
 */
    }    

    @FXML
    private void Dashbord(ActionEvent event) {
        FXMain.setScene("Admin");
    }

    @FXML
    private void DepotConstat(ActionEvent event) {
        FXMain.setScene("Dep");
    }

    @FXML
    private void Facture(ActionEvent event) {
        FXMain.setScene("Fac");
    }

    @FXML
    private void Profile(ActionEvent event) {
        FXMain.setScene("ProfileAdmin");
    }

    @FXML
    private void Reclamation(ActionEvent event) {
        FXMain.setScene("Rec");
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
         FXMain.setScene("InterfaceLogin");
        
    }
    }

    @FXML
    private void resfreshuser() {
        
        
           data.clear();
        data=FXCollections.observableArrayList(su.afficher());
       
        cnom.setCellValueFactory(new PropertyValueFactory<>("name"));
        cprenom.setCellValueFactory(new PropertyValueFactory<>("lastname"));
        cemail.setCellValueFactory(new PropertyValueFactory<>("email"));
        
        crole.setCellValueFactory(new PropertyValueFactory<>("roles"));
        
        tvuser.setItems(data);
        search.textProperty().addListener((observable, oldValue, newValue) -> {
            if (oldValue != null && (newValue.length() < oldValue.length())) {
                tvuser.setItems(data);
            }
            String value = newValue.toLowerCase();
            ObservableList<User> subentries = FXCollections.observableArrayList();
            for (User entry : tvuser.getItems()) {
                boolean match = true;
                
                String name = entry.getName();
                String lastname = entry.getLastname();                

                if (!name.toLowerCase().contains(value)&&
                        !lastname.toLowerCase().contains(value))
                         {
                    match = false;
                }
                if (match) {
                    subentries.add(entry);
                }
            }
                tvuser.setItems(subentries);
                 });
        
    }

    @FXML
    private void remove(ActionEvent event) {
        
          if (tvuser.getSelectionModel().getSelectedItem() != null) {
        int id = tvuser.getSelectionModel().getSelectedItem().getId();
        
        // Create a confirmation dialog box
        Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
        alert.setTitle("Confirmation");
        alert.setHeaderText(null);
        alert.setContentText("Êtes-vous sûr de vouloir supprimer cet User?");
        Optional<ButtonType> result = alert.showAndWait();
        
        // If the user confirms the deletion, call the supprimer() method and refresh the list
        if (result.isPresent() && result.get() == ButtonType.OK) {
            su.supprimer(id);
            resfreshuser();
        }
    } else {
        // Display an error message if no item is selected
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle("Error");
        alert.setHeaderText(null);
        alert.setContentText("Veuillez sélectionner un Utilisateur");
        alert.showAndWait();
    }
    }
    private String getPath() {
        String userHome = System.getProperty("user.home");
        String fileSeparator = System.getProperty("file.separator");
        String documentsPath = userHome + fileSeparator + "Documents";
        System.out.println("User's documents path: " + documentsPath);
        return documentsPath;
    }


    @FXML
    private void Exporter(ActionEvent event) {
        try {
            //the file path
//            File file = new File("C:\\Users\\user\\Desktop\\image\\file.csv");
                        File file = new File(getPath() + "\\file.csv");

            //if the file not exist create one
            if (!file.exists()) {
                file.createNewFile();
            } else {
                file.delete();
            }

            FileWriter fw = new FileWriter(file.getAbsoluteFile());
            BufferedWriter bw = new BufferedWriter(fw);

            bw.write("name;lastname;email;roles;");
            bw.newLine();
            //loop for jtable rows
            for (int i = 0; i < tvuser.getItems().size(); i++) {
                //loop for jtable column
                for (int j = 0; j < tvuser.getColumns().size(); j++) {
                    bw.write(tvuser.getColumns().get(j).getCellData(i) + ";");
                }
                bw.newLine();
            }
            //close BufferedWriter
            bw.close();
            //close FileWriter 
            fw.close();
            JOptionPane.showMessageDialog(null, "Data Exported");

        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
    
    
}
