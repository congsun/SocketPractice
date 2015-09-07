// CS 6421 - Simple Message Board Client in Java
// T. Wood
// Compile with: javac MsgClient
// Run with:     java MsgClient

import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;

public class MsgClient {
    public static void main(String[] args) {
//        String host = "52.4.52.48";
//        int portnum = 5555;
        String host = args[0];
        int portnum = Integer.parseInt(args[1]);
        

        try{
            Socket socket = new Socket(host,portnum);
            PrintWriter out = new PrintWriter(sock.getOutputStream(), true);
            out.println(args[2]);
            out.println(args[3]);
        }catch(Exception e){
            System.out.println("ERRRRRROR");
        }

    }
}
