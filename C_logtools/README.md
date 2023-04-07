## Datagram server and client

Here I've implemented a datagram server with quite simple functionality. It is able just to recieve a part of a string, and to update and print it to console output. But I've tried to aprobe different features here:
- Linux specific high efficient epoll api for sockets multiplexing, not to be blocked in recvfrom function;
- Logging data about receiving information (address, port, timestamp and others) into binary file and develope a viewing tool;
- Graceful shutdown - the server correctly handles SIGINT signal and does not restart interrupted system calls;
- Printing functionality has been moved to separate thread and access to common data was protected by mutex. It is not necessary here, but definetely must have in more complex cases. 

To know pid of the server
```console
netstat -anp | grep 4577
```
To send SIGINT signal

```console
kill -SIGINT 50500
```
To run client
```console
./logclient 127.0.0.1 10 
```