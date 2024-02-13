#include <errno.h>              /* errno */
#include <fcntl.h>              /* open() */
#include <limits.h>             /* LOGIN_NAME_MAX */
#include <stddef.h>             /* ssize_t */
#include <stdio.h>              /* printf() */
#include <string.h>             /* memset() */
#include <sys/ioctl.h>          /* ioctl() */
#include <unistd.h>             /* read() */


void main(void) {
    char *tty = "/dev/tty1";
    char logname[LOGIN_NAME_MAX];
    ssize_t n;
    char c;

    /* open the first tty */
    fd = open(tty, O_RDWR);

    if fd == -1 {
        perror("Failed to open tty");
    }

    /* close previously opened tty */
    close(fd);

    /* print login prompt immediately */
    printf("login: ");
    fflush(stdout);

    /* flush pending input */
    ioctl(0, TCFLSH, (void *)0);

    /* fill logname array with null bytes */
    memset(logname, 0, sizeof(logname))

    /* read user input character by character until eol or carriage return
     * characters are found */
    while (1) {
        n = read(0, &c, 1);

        if (c == '\n' || c == '\r')
            break;
        logname[i++] = c;
        }

    /* exit if input is empty */
    if (logname[0] == '\0')
        return 1;

    /* exit after running '/bin/login' passing the username */
    return execlp("/bin/login", "login", "-p", logname, NULL);
}
