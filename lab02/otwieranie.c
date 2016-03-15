#include <fcntl.h> //zawiera open, read...
#include <stdio.h>
#include <stdlib.h>     /* malloc, free, rand */ 

/* Not technically required, but needed on some UNIX distributions */
#include <sys/types.h>
#include <sys/stat.h>

int skip(int filehandler, int n, int times){
	
	char *buffer = malloc(n*sizeof(char));	
	int i,w;
	for( i=0; i< times; i++){
		w = read(filehandler, buffer, n); //może się posypać jak nie odczyta (sprawdzac wielkosc pliku?)
	}
	free(buffer);	
	return w;
}

int writeAt( char *patch, char *tekst, int n, int p){
	int fh,w;
	fh = open(path, O_RDWR );
	w = skip(fh, n, p);
	w = write(fh1, tekst, n);
	return w;	
}

int main (void) {
	
        int n = 3;   //buffer size
        char *path = "cokolwiek.txt";
        int fh,fh1;
        char *buffer = malloc(n*sizeof(char));
        char *tmp = malloc(n*sizeof(char));
        if(buffer == NULL) {
			fprintf(stderr, "Malloc failed!\n");
			//exit(EXIT_FAILURE);
		}
		
        int gotten, w1, w2;
		
		
		//open
        fh = open(path, O_RDWR ); //read and write
        printf ("File handle %d\n",fh);
        
        fh1 = open(path, O_RDWR ); //read and write
        printf ("File handle %d\n",fh1);
        
		w1 = write(fh1, "AAA", n);
		w1 = skip(fh1,n,1);
		w1 = write(fh1, "DDD", n);
 

        while (gotten = read(fh,buffer,2)) { //petla w ktorej czytamy plik
                buffer[gotten] = '\0';
                printf("%s",buffer);
        }
        free(buffer);
        close(fh);
        close(fh1);
	
	return 0;
}

//O_APPEND dodaje na koniec
