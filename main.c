#include <stdio.h>            // used for:
                              // - printf

#include <libssh/server.h>    // used for:
                              // - ssh_bind, the data type for ssh server bind
                              // - ssh_bind_options_set, options for ssh server binding


int main(int argc, char **argv) {
  int port = 22;
  ssh_bind sshbind = ssh_bind_new();
  
  ssh_bind_options_set(sshbind, SSH_BIND_OPTIONS_BINDADDR, "localhost"); 
  ssh_bind_options_set(sshbind, SSH_BIND_OPTIONS_BINDPORT, &port); 

  if (ssh_bind_listen(sshbind) < 0) {
    printf("Error listening to socket: %s\n", ssh_get_error(sshbind));
    return -1;
  }

  return 0;
}
