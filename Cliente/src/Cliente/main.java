/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Cliente;

import org.apache.thrift.protocol.TBinaryProtocol;
import org.apache.thrift.protocol.TProtocol;
import org.apache.thrift.transport.TSocket;
import org.apache.thrift.transport.TTransportException;

/**
 *
 * @author mrrobot
 */
public class main {

    static TSocket transport;
    static TProtocol protocol;
    static Juego.Client juego;

    public static void main(String[] args) {
        try {
            transport = new TSocket("localhost",9090);
            transport.open();
            protocol = new TBinaryProtocol(transport);
            juego = new Juego.Client(protocol);
            System.out.print("Iniciando interfaz grafica");
            Inicio ini = new Inicio(transport,protocol,juego);
            ini.setVisible(true);
//            GUI gui = new GUI(transport,protocol,juego);
//            gui.setVisible(true);
        } catch (TTransportException ex) {
            System.out.print("Servidor no encontrado");
        }

    }
}
