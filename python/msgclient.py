# CS 6421 - Simple Message Board Client in Python
# T. Wood
# Run with:     python msgclient.py

# @author Cong Sun
# @Gwid G48099998

import socket
import sys


# System Argument should be [fileName] [Host IP] [Port Number] [Message_Name] [Message_Content], check the count for the argument before try to run the program
if len(sys.argv) != 5: print("error")

# The Second Argument is the Host IP
host = sys.argv[1];
#The Third Argument is the Port Number
portnum = sys.argv[2];

#Create the socket object
clientsocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#Connect to the server using the host IP and Port number
clientsocket.connect((host,int(portnum)))

#Send [Message_Name]
clientsocket.send(sys.argv[3])
#Send a new line character
clientsocket.send("\n")
#Send [Message_Content]
clientsocket.send(sys.argv[4])
print("Sent message to server!")
