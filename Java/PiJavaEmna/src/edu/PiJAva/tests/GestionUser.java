/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.PiJAva.tests;

import edu.PiJAva.entities.Role;
import edu.PiJAva.entities.User;
import edu.PiJAva.services.ServiceUser;

/**
 *
 * @author 21694
 */
public class GestionUser {
        public static void main(String[] args) {
        // TODO code application logic here
        ServiceUser su=new ServiceUser();
        User u;
           u = new User("aaa","aaabb","kawla@gmail.com","bbbb",Role.ROLE_ADMIN);
          
       // su.ajouter(u);
       // System.out.println(su.login("kawla@gmail.com", "bbbb"));
        //su.modifier(28, u);
      // su.supprimer(27);
     
      System.out.println(su.afficher());
      
        }
    
}
