/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Cliente;

import java.awt.Color;
import javax.swing.JFrame;

/**
 *
 * @author mrrobot
 */
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.logging.Level;
import java.util.logging.Logger;

import javazoom.jl.decoder.JavaLayerException;
import javazoom.jl.player.Player;

public class PartyMode extends Thread {

    JFrame frame;
    boolean fin;
    PartyColor col;
    public PartyMode(JFrame frame) {
        fin = false;
        this.frame = frame;
        col = new PartyColor(frame);
    }

    public void run() {
        col.start();
        while (!fin) {
            try {
                Player apl = new Player(new FileInputStream(
                        "/home/mrrobot/Documentos/2486034770301@ingenieria.usac.edu.gt/Estructuras/Laboratorio/Proyecto1EDD/Cliente/src/Cliente/fade.mp3"));
                apl.play();
            } catch (JavaLayerException ex) {
                Logger.getLogger(PartyMode.class.getName()).log(Level.SEVERE, null, ex);
            } catch (FileNotFoundException ex) {
                Logger.getLogger(PartyMode.class.getName()).log(Level.SEVERE, null, ex);
            }
        }

    }

    public void setFin() {
        col.setFin();
        fin = true;
    }
}
