# https://www.hackerrank.com/challenges/can-funds-be-transferred-a
## Use this function to write data to socket
## write_string_to_socket(connection, message) where connection is the socket object and message is string
def write_string_to_socket(connection, message):
    connection.send(message)
    return

## Use this function to read data from socket
## def read_string_from_socket(connection) where connection is the socket object
def read_string_from_socket(connection):
    return connection.recv(1024)
## All global declarations go here
parents = {}

def find_path(n):
    path = [n]
    while parents[n]:
        path.append(parents[n])
        n = parents[n]
    return path

def compute_distance(a, b):
    path_a = find_path(a)
    path_b = find_path(b)

    while path_a and path_b and path_a[-1] == path_b[-1]:
        del path_a[-1]
        del path_b[-1]

    return len(path_a) + len(path_b) + 1

## This function is called only once before any client connection is accepted by the server.
## Read any global datasets or configurations here
def init_server():
    print("Reading training set")
    sys.stdout.flush()
    with open("training.txt", "r") as f:
        count = int(f.readline())
        for _ in range(count): 
            l = f.readline().strip()
            if l != "":
                x, y = map(int, l.split(","))
                parents[y] = x


## This function is called everytime a new connection is accepted by the server.
## Service the client here
def process_client_connection(connection):

    while True:
        # read message 
        message = read_string_from_socket(connection)

        print ("Message received = ", message)

        if message == "END":
            break
        else:
            a, b, q = map(int, message.split(","))
            result = "YES" if compute_distance(a, b) <= q else "NO"
            write_string_to_socket(connection, message)

# # Main structure
import socket
import threading
import sys

# NOTE: Use this path to create the UDS Server socket
SERVER_SOCKET_PATH = "./socket"

BUF_SIZE = 4096
BACKLOG = 10

def read_string_from_socket(connection):
    return connection.recv(BUF_SIZE)

def write_string_to_socket(connection, message):
    connection.send(message)

def main():
    init_server()
    
    sock = socket.socket(socket.AF_UNIX)
    sock.bind(SERVER_SOCKET_PATH)
    sock.listen(BACKLOG)
    while True:
        connection = sock.accept()[0]
        t = threading.Thread(target=process_client_connection, args=(connection,))
        t.start()
    sock.close()

if __name__ == '__main__':
    main()