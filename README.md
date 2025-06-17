# 📡 minitalk
A UNIX signal-based message transfer system. The client sends strings to the server using SIGUSR1 and SIGUSR2 to encode binary data.

🛠️ Features
Bit-by-bit character transmission using signals only.

Server can receive messages from multiple clients.

Optional bonus: Acknowledgment signals and Unicode support.

▶️ Example
1. Run the server:

<pre>
./server
# Output: "Your PID is: 12345"
2. In another terminal, run the client:
  
./client 12345 "Hello from client!"

  
Server output:
Hello from client!
  
</pre>
