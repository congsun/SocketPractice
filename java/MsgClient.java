// CS 6421 - Simple Message Board Client in Java
// T. Wood
// Compile with: javac MsgClient
// Run with:     java MsgClient

// @author Cong Sun
// @Gwid G48099998

import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;

public class MsgClient {
    public static void main(String[] args) {
        //System Argument should be [Host IP] [Port Number] [Message_Name] [Message_Content], check the count for the argument before try to run the program
        if(args.length != 4){
            System.out.println("argument number not corrent");
            System.exit(-1);
        }
        
        //The First Argument is the Host IP
        String host = args[0];
        //The Second Argument is the Port Number
        int portnum = Integer.parseInt(args[1]);
        try{
            //Create the socket object
            Socket socket = new Socket(host,portnum);
            //Create the PrintWriter object using the socket object
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            
            //Send [Message_Name] and a new line character
            out.println(args[2]);
            //Send [Message_Content]
            out.println(args[3]);
        }catch(Exception e){
            System.out.println(e);
        }

    }
}
