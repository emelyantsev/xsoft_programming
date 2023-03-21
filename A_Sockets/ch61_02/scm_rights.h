#include <sys/socket.h>
#include <sys/un.h>
#include <fcntl.h>
#include "unix_sockets.h"       /* Declares our unix*() socket functions */
#include "tlpi_hdr.h"

#define SOCK_PATH "scm_rights"