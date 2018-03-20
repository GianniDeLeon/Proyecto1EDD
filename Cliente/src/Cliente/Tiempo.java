/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Cliente;

import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import org.apache.thrift.TException;

/**
 *
 * @author mrrobot
 */
public class Tiempo extends Thread {

    int seg, min, nivel;
    JLabel texto,gemas,punteo;
    Juego.Client juego;
    boolean pausa, finHilo;
    JButton selecNivel,disparo;
    public Tiempo(JLabel texto, int nivel, Juego.Client juego,JButton selecNivel,JLabel gemas,JButton disparo,JLabel punteo) {
        seg = min = 0;
        this.nivel = nivel;
        this.texto = texto;
        this.juego = juego;
        pausa = finHilo = false;
        this.selecNivel = selecNivel;
        this.gemas = gemas;
        this.disparo = disparo;
        setCheat = false;
        this.punteo = punteo;
    }

    @Override
    public void run() {
        try {
            while (!finHilo) {
                while (!pausa) {
                    ////
                    if ((nivel == 1 || nivel == 2) && min == 1) {
                        //fin juego nivel 1
                        finJuego();
                    } else if ((nivel == 3 || nivel == 4) && min == 1 && seg == 30) {
                        //fin juego nivel 3-4
                        finJuego();
                    } else if ((nivel == 5 || nivel == 6) && min == 2) {
                        //fin juego nivel 5-6
                        finJuego();
                    } else if (nivel >= 7 && min == 3) {
                        //fin juego nivel >7
                        finJuego();
                    }
                    ////
                    if (seg < 60) {
                        Thread.sleep(1000);
                        seg++;
                        if (seg < 10) {
                            texto.setText("0" + min + ":0" + seg);
                        } else {
                            texto.setText("0" + min + ":" + seg);
                        }
                    } else {
                        seg = 0;
                        min++;
                        texto.setText("0" + min + ":0" + seg);
                    }
                }
                Thread.sleep(1000);
            }
        } catch (Exception e) {
            System.out.println("Error al detener el hilo por un segundo");
        }

    }

    public void finJuego() {
        try {
            if(setCheat)
            {
                tiro.setFin();
            }
            disparo.setEnabled(false);
            texto.setText("00:00");
            selecNivel.setEnabled(true);
            SetFinHilo();
            juego.setSeg(seg);
            juego.setMin(min);
            juego.finalizar();
            if(JOptionPane.showConfirmDialog(null, "Desea ver los enemigos eliminados", "Realy Nigga?", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE) == 0)
            {
                juego.graficarEnemigosEliminados();
                Eliminados elim = new Eliminados();
                elim.setVisible(true);
            }
            if(juego.ganoNivel())
            {
                JOptionPane.showMessageDialog(null, "Felicidades has ganado el nivel");
            }
            else
            {
                JOptionPane.showMessageDialog(null, "Vuelve a intentar el nivel");
            }
            gemas.setText(juego.getCantGemas()+"");
            juego.graficarNiveles();
        } catch (TException ex) {
            Logger.getLogger(Tiempo.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public void SetPausa() {
        pausa = !pausa;
    }

    public void SetFinHilo() {
        if(setCheat)
        {
            tiro.setFin();
        }
        SetPausa();
        finHilo = true;
        JOptionPane.showMessageDialog(null, "Se a terminado el tiempo");
    }
    
    CheatTiro tiro;
    boolean setCheat;
    public void cheatTiro()
    {
        tiro = new CheatTiro(juego,punteo);
        setCheat = true;
        tiro.start();
    }
}
