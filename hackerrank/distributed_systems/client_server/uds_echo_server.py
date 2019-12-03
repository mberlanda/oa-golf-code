def write_string_to_socket(connection, message):
    connection.send(message)
    return

def read_string_from_socket(connection):
    return connection.recv(1024)

def process_client_connection(connection):

    while True:
        # read message 
        message = read_string_from_socket(connection)

        print "Message received = ", message
        sys.stdout.flush()

        # Your logic goes here
        # write message back to client
        write_string_to_socket(connection, message)

        if message == "END":
            break