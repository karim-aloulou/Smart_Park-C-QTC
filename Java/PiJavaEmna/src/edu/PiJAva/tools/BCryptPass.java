/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.PiJAva.tools;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.mindrot.jbcrypt.BCrypt;

/**
 *
 * @author Skymil
 */
public class BCryptPass {
    public static String cryptMDP(String mdp){
        return BCrypt.hashpw(mdp,BCrypt.gensalt(10));
    }
    public static boolean checkPass(String pass,String password){
        return BCrypt.checkpw(pass, password);
    }
    
    
}
