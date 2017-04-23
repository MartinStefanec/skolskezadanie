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
	int dlzka;
	float cislo;
	if(strspn(argv[2], "0123456789") != strlen(argv[2])) {
	printf("Expected only number");
	return 0;
    }
	if(argc!=3){
		printf("Expected 2 arguments");
		return 0;
	}
	subor=open(argv[1],O_RDWR|O_CREAT|O_BINARY,S_IWUSR);	
	for (i=0;i<n;i++){
		dlzka==10+rand()%11;
		write(subor,&dlzka,sizeof(int));
		for (i=0;j<dlzka;j++){
			cislo=rand()/(float)(RAND_MAX);	
			write(subor,&cislo,sizeof(float));
		}
	}	
	close(subor);

	
}
