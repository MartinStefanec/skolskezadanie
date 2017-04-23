#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<errno.h>
#include<string.h>
#include<time.h>
#include<fcntl.h>
#include<time.h>
#include<sys/stat.h>
#include<unistd.h>


	
main(int argc, char *argv[]){
	srand(time(NULL));

	int n;
	n=atoi(argv[2]);
	int subor;
	int i,j;
	int dlzka=10+rand()%10;
	float cislo;
	printf("%d",n);
	printf(" %s",argv[1]);
	
	subor=open(argv[1],O_RDWR|O_CREAT|O_BINARY,S_IWUSR);	
	for (i=0;i<n;i++){
		write(subor,&dlzka,sizeof(int));
		for (i=0;j<dlzka;j++){
			cislo=rand()/(float)(RAND_MAX);	
			write(subor,&cislo,sizeof(float));
		}
	}	
	close(subor);

	
}
