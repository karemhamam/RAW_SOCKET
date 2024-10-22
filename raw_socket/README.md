
# ICMP Ping Program in C

This program demonstrates how to use raw sockets in C to send an ICMP "ping" (echo request) packet to a specified IP address. The program constructs the ICMP packet, calculates its checksum, and sends it to Google's DNS server (8.8.8.8).

## How It Works

1. **Raw Socket**: The program creates a raw socket to send ICMP messages directly over the network.
2. **ICMP Packet**: An ICMP echo request is constructed and sent. ICMP (Internet Control Message Protocol) is commonly used for network diagnostics, such as the "ping" command.
3. **Checksum Calculation**: The checksum function ensures data integrity by calculating a checksum for the ICMP header.
4. **Send Packet**: The program sends the packet to Google's DNS server at `8.8.8.8`.

> **Note**: The program only sends an ICMP echo request and does not wait for or process the reply.

## Requirements

- A Linux environment
- `gcc` (GNU Compiler Collection) installed
- Root privileges to run the program (due to raw socket usage)

## How to Compile and Run

1. **Save the Code**: Save the provided code in a file named `raw_socket.c`.
2. **Compile the Code**:
    ```bash
    gcc raw_socket.c -o raw_socket
    ```
3. **Run the Program**:
    ```bash
    sudo ./raw_socket
    ```

## Expected Output

- If the program runs successfully, there will be no output, as it only sends an ICMP packet.
- If there is an error creating the socket or sending the packet, an error message will be displayed.

## Contribution
feel free to fork the repository and submit a pull request. For major changes, please open an issue first to discuss what you would like to change.

## License
(mahamedhamam15@gmail.com)