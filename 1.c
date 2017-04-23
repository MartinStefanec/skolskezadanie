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

	
	printf("%d",n);
	printf(" %s",argv[1]);
	
	subor=open(argv[1],O_RDWR|O_CREAT,S_IWUSR);	
	for (i=0;i<n;i++){
		for (i=0;j<10+rand()%10;j++){	
			write(subor,);
		}
	}	
	

	
}
