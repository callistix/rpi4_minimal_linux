#include <signal.h>             /* for signal related calls */
#include <unistd.h>             /* for pid, sid, and gid related calls */
#include <sys/wait.h>           /* for wait() call */

int main()
{
    sigset_t set;
    int status;

    /* exit with return code 1 if this executable is not called as process number one */
    if (getpid() != 1) return 1;

    /* initialise signal set to include all signals, which is one of the mandatory
     * initialisation methods for sigset_t */
    sigfillset(&set);

    /* set signal mask to block all signals, except SIGKILL and SIGSTOP */
    sigprocmask(SIG_BLOCK, &set, 0);

    /* if a fork is successful, wait for the child to exit */
    if (fork()) for (;;) wait (&status);

    /* set signal mask to allow all signals again */
    sigprocmask(SIG_UNBLOCK, &set, 0);

    /* set session id */
    setsid();

    /* set process group id */
    setpgid(0, 0);

    /* execute /etc/rc, passing its program name as only mandatory element of `argv`
     * to it, the third argument is just a mandatory NULL pointer */
    return execve("/etc/rc", (char *[]){ "rc", 0 }, (char *[]){ 0 });
}
