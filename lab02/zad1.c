
//#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h> //zawiera open, read..

//#include <stdlib.h>
//#include <stdio.h>

int main (void) {
	

        int fh;
        char buffer[65];
        int gotten;

        fh = open("cokolwiek.txt",O_RDONLY);
        printf ("File handle %d\n",fh);
        while (gotten = read(fh,buffer,64)) {
                buffer[gotten] = '\0';
                printf("aaaa %s",buffer);
                }
	
	return 0;
}
