/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Cliente;

import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JLabel;
import org.apache.thrift.TException;

/**
 *
 * @author mrrobot
 */
public class CheatTiro extends Thread{
    Juego.Client juego;
    boolean fin;
    JLabel punteo;
    public CheatTiro(Juego.Client juego, JLabel punteo)
    {
        fin = false;
        this.juego = juego;
        this.punteo = punteo;
    }
    
    public void run()
    {
        while(!fin)
        {
            try {
                juego.atacar(0, 0);
                punteo.setText(juego.getPunteo()+"");
                Thread.sleep(5000);
            } catch (TException ex) {
                Logger.getLogger(CheatTiro.class.getName()).log(Level.SEVERE, null, ex);
            } catch (InterruptedException ex) {
                Logger.getLogger(CheatTiro.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    
    public void setFin()
    {
        fin = true;
    }
}
