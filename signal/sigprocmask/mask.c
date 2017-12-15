#include <stdio.h>
#include <signal.h>
#include <unistd.h>


int main (int argc, char* argv[]){
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGINT);//ctrl+c
	sigaddset(&set, SIGTSTP);//ctrl+z
	sigaddset(&set, SIGKILL);//kill无效
	sigaddset(&set, 30);//kill有效
	sigaddset(&set, 31);//kill有效
	sigprocmask(SIG_BLOCK, &set, NULL);

	while (1) {
		sigpending(&set);
		for (int i = 1; i < 32; ++i) {
			if (sigismember(&set, i)) {
				putchar('1');
			}else {
				putchar('0');
			}
		}
		putchar('\n');

		sleep(1);
	}

	return 0;
}
