/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Cliente;

import javax.swing.JLabel;

/**
 *
 * @author mrrobot
 */
public class Tiempo extends Thread {

    int seg, min;
    JLabel texto;

    public Tiempo(JLabel texto) {
        seg = min = 0;
        this.texto = texto;
    }

    @Override
    public void run() {
        try {
            while (true) {
                if (seg < 60) {
                    Thread.sleep(1000);
                    seg++;
                    if(seg < 10)
                    {
                        texto.setText("0"+min+":0"+seg);
                    }
                    else{
                        texto.setText("0"+min+":"+seg);
                    }
                }
                else
                {
                    seg = 0;
                    min++;
                    texto.setText("0"+min+":0"+seg);
                }
            }
        } catch (Exception e) {
            System.out.println("Error al detener el hilo por un segundo");
        }

    }
}
