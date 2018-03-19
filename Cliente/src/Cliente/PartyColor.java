/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Cliente;

import java.awt.Color;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFrame;

/**
 *
 * @author mrrobot
 */
public class PartyColor extends Thread {
   JFrame frame;
   boolean fin; 
   public PartyColor(JFrame frame)
   {
       this.frame = frame;
       fin = false;
   }
   
   public void run()
   {
       while(!fin)
       {
           try {
               frame.getContentPane().setBackground(Color.BLUE);
               Thread.sleep(1000);
               frame.getContentPane().setBackground(Color.CYAN);
               Thread.sleep(1000);
               frame.getContentPane().setBackground(Color.MAGENTA);
               Thread.sleep(1000);
               frame.getContentPane().setBackground(Color.yellow);
               Thread.sleep(1000);
               frame.getContentPane().setBackground(Color.ORANGE);
               Thread.sleep(1000);
               frame.getContentPane().setBackground(Color.RED);
               Thread.sleep(1000);
               frame.getContentPane().setBackground(Color.GREEN);
               Thread.sleep(1000);
               frame.getContentPane().setBackground(Color.GRAY);
               Thread.sleep(1000);
               frame.getContentPane().setBackground(Color.BLACK);
           } catch (InterruptedException ex) {
               Logger.getLogger(PartyColor.class.getName()).log(Level.SEVERE, null, ex);
           }
       }
   }
   
   public void setFin()
   {
       fin = true;
   }
}
