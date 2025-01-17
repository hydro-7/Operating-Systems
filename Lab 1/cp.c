#include "fcntl.h"
#include "types.h"

int main(int argc, char *argv[])
{
	int fd1, fd2;
	char buf[100];
	int cnt;
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_WRONLY | O_CREATE);
	while((cnt = read(fd1, buf, 100)))
	{
		write(fd2, buf, cnt);
	}
	close(fd1);
	close(fd2);
}
