/**
 * writer
 */
 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include "writer.h"
/*
int open (const char *name, int flags);
int open (const char *name, int flags, mode_t mode);
void write-file(char *writefile, char *writestr);
*/
#include <unistd.h>
#include <syslog.h>
/*
ssize_t write (int fd, const void *buf, size_t count);
*/


int main(int argc, char* argv[]) {
//	printf ("Start program - ");
	if (argc == 3) {
		writefile(argv[1], argv[2]);
	} else {
		/* ERROR */
	}
//	writefile("/home/mab/Coursera_Assignments/finder-app/test.txt", "aaa aaaa aaaaa aaaaaa aaaaaaa aaaaaaaa");
};

int writefile(char *writefile, char *writestr) {
	int fd, len=strlen(writestr);
//	printf ("Parameters: arg1=%s arg2=%s\n", writefile, writestr);
	openlog(NULL, 0, LOG_USER);
	syslog(LOG_DEBUG,"Writing %s to %s", writestr, writefile);
	fd = open (writefile, O_CREAT | O_WRONLY | O_TRUNC,0664);
	if (fd == -1)
//		fprintf (stderr, "open failed: %s\n", strerror (errno));
		syslog(LOG_ERR,"open: %s",strerror (errno));
//		return 1;
	
	char *buf = writestr;
	ssize_t ret, nr;
//	printf ("Variables:\nlen=%d ", len);
	while (len != 0 && (ret = write (fd, buf, len)) != 0) {
//	printf ("buf=%s\nfd=%d ret=%ld nr=%ld\n", buf, fd, ret, nr);
	if (ret == -1) {
		if (errno == EINTR)
		return 0;
		continue;
//		perror ("write");
		syslog(LOG_ERR, "write: %s", strerror (errno));
//		return 1;
		break;
		}
	len -= ret;
	buf += ret;
	}
	
	/* CLOSE FILE */
	if (close (fd) == -1)
//		perror ("close");
		syslog(LOG_ERR, "close: %s", strerror (errno));
//		return 1;
	
	closelog();
	return 0;
}

