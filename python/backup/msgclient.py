# CS 6421 - Simple Message Board Client in Python
# T. Wood
# Run with:     python msgclient.py

import socket
import sys

#host = "twood02.koding.io";
#portnum = 5555;
if len(sys.argv) != 5: print("error")


host = sys.argv[1];
portnum = sys.argv[2];

clientsocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
clientsocket.connect(host,int(portnum))
clientsocket.send(sys.argv[3])
clientsocket.send("\n")
clientsocket.send(sys.argv[4])
print("Sent message to server!")
