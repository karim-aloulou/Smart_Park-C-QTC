/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.PiJAva.services;

import edu.PiJAva.entities.Role;
import edu.PiJAva.entities.User;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import edu.PiJAva.tools.BCryptPass;
import edu.PiJAva.tools.MyConnection;
import java.sql.PreparedStatement;

/**
 *
 * @author Skymil
 */
public class ServiceUser implements IServiceUser<User>{
    Connection cnx;
    public ServiceUser(){
        cnx=MyConnection.getInstance().getCnx();
    }

    /**
     *
     * @param u
     * @param t
     */
@Override
    public void ajouter(User u) {
        
        try {
            String requete = "INSERT into user(name,email,roles,password,lastname)values(?,?,?,?,?)";
            PreparedStatement pst = MyConnection.getInstance().getCnx().prepareStatement(requete);
            pst.setString(1,u.getName());
            pst.setString(2,u.getEmail());
           pst.setString(3,u.getRole().toString()); 
           pst.setString(4,BCryptPass.cryptMDP(u.getPassword()));
          
           pst.setString(5,u.getLastname());
           
           pst.executeUpdate();
           System.out.println("User ajouteé avec succées !");
          
                    
        } catch (SQLException ex) {
          System.out.println(ex.getMessage());
        }
    }
    @Override
    public void modifier(int id, User t) {
        try {
            String query="UPDATE `user` SET "
                    + "`name`='"+t.getName()+"',"
                    + "`lastname`='"+t.getLastname()+"',"
                    + "`email`='"+t.getEmail()+"',"
                    + "`password`='"+BCryptPass.cryptMDP(t.getPassword())+"' WHERE id="+id;
            Statement st=cnx.createStatement();
            st.executeUpdate(query);
        } catch (SQLException ex) {
            Logger.getLogger(ServiceUser.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    @Override
    public void supprimer(int id) {
        try {
            String query="DELETE FROM `user` WHERE id="+id;
            Statement st=cnx.createStatement();
            st.executeUpdate(query);
        } catch (SQLException ex) {
            Logger.getLogger(ServiceUser.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

   @Override
    public List<User> afficher() {
        
        List<User>myList= new ArrayList();
        
        try {
            String requete = "SELECT * FROM user";
            Statement st = MyConnection.getInstance().getCnx().createStatement();
            ResultSet rs = st.executeQuery(requete);
            while (rs.next()){
                User c = new User();
                c.setId(rs.getInt("id"));
                 c.setName(rs.getString("name"));
                   
                c.setEmail(rs.getString("email"));                
               String roles = rs.getString("roles");
               c.setPassword(rs.getString("password"));
               
               c.setLastname(rs.getString("lastname"));
            if (roles != null) {
                if (roles.equals("ROLE_USER")) {
                    c.setRole(Role.ROLE_USER);
                } else if (roles.equals("ROLE_EXPERT")) {
                    c.setRole(Role.ROLE_EXPERT);
                } else if (roles.equals("ROLE_MECANICIEN")) {
                    c.setRole(Role.ROLE_MECANICIEN);
                } else if (roles.equals("ROLE_ADMIN")) {
                    c.setRole(Role.ROLE_ADMIN);
                }
            }
            
                
                            
              
                myList.add(c); 
            }
            
        }catch (SQLException ex) {
            System.out.println(ex.getMessage());
        }
        return myList ;
        
        
    }

    public User login(String email,String mdp){
        return afficher().stream().filter(
                u->u.getEmail().equals(email)
        ).filter(u->BCryptPass.checkPass(mdp, u.getPassword())).findFirst().orElse(null);
        
    }

    public User getUserByEmail(String email){
        return afficher().stream().filter(
                u->u.getEmail().equals(email)).findFirst().orElse(null);
    }
  
    public boolean checkuser(String email){
        return afficher().stream().filter(
                u->u.getEmail().equals(email)).findFirst().isPresent();
    }
}
