import socket

HOST = '127.0.0.1'  # Standard loopback interface address (localhost)
PORT = 65432        # Port to listen on (non-privileged ports are > 1023)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    print('1')
    s.bind((HOST, PORT))
    print('2')
    s.listen()
    print('3')
    conn, addr = s.accept()
    print('4')
    with conn:
        print('Connected by', addr)
        while True:
            data = conn.recv(1024)
            if not data:
                break
            conn.sendall(data)

input("Press Enter to exit")