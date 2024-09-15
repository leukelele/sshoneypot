#include "config.h"           /* defined macros:
			                         * - addr bound to
			                         * - default port
			                         * - keyfile directory
			                         */

#include <stdio.h>            /* used for:
                               * - printf
			                         */

#include <libssh/server.h>    /* used for:
                               * - ssh_bind, the data type for ssh server bind
                               * - ssh_bind_options_set, options for ssh server binding
			                         */
#include <libssh/libssh.h>    /* used for:
			                         */

int main(int argc, char **argv) {

        connection = 
  ssh_bind sshbind = ssh_bind_new();

  ssh_bind_options_set(sshbind, SSH_BIND_OPTIONS_BINDADDR, LISTENADDR); 
  ssh_bind_options_set(sshbind, SSH_BIND_OPTIONS_BINDPORT, DEFLT_PORT); 
  ssh_bind_options_set(sshbind, SSH_BIND_OPTIONS_HOSTKEY, KEYFILE_DIR);

  if (ssh_bind_listen(sshbind) < 0) {
    printf("Error listening to socket: %s\n", ssh_get_error(sshbind));
    return -1;
  }

  while(1) {
    if (ssh_bind_accept(sshbind, session) == SSH_ERROR) {
      fprintf(stderr, "Error accepting a connection: `%s'.\n",ssh_get_error(sshbind));
      return -1;
    }
  }

  return 0;
}
