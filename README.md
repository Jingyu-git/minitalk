# minitalk

*This project has been created as part of the 42 curriculum by jingywu.*

## Description

minitalk is a small data exchange program using UNIX signals (SIGUSR1 & SIGUSR2).

The goal is to implement a client-server system using only UNIX signals to transmit data.

The server waits for incoming signals.

The client sends a string to the server bit by bit.


## Instructions

To compile the project: make
To compile bonus version: make bonus

Other rules:

make clean
make fclean
make re

### Execution

Start the server:

./server

The server will display its PID:

Server PID: 12345

Run the client:

./client <PID> "message"

Example:

./client 12345 "Hello 42"

## Resources

https://medium.com/@digitalpoolng/42-minitalk-building-a-simple-client-server-communication-program-in-c-a5e6d96c97ec

AI tools (ChatGPT) were used for: understanding signal handling concepts