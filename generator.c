#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<errno.h>
#include<string.h>
#include<time.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>


	
main(int argc, char *argv[]){
	srand(time(NULL));
	int n;
	n=atoi(argv[2]);
	int subor;
	int i,j;
	unsigned char dlzka;
	float cislo;
	if(strspn(argv[2], "0123456789") != strlen(argv[2])) {
	printf("Expected only number");
	return 0;
    }
	if(argc!=3){
		printf("Expected 2 arguments");
		return 0;
	}
	subor=open(argv[1], O_RDWR|O_CREAT|O_BINARY,S_IWUSR);	
	for (i=0;i<n;i++){
		dlzka=10+rand()%11;
//		printf("%d ",dlzka);
		write(subor,&dlzka,sizeof(unsigned char));
		for (j=0;j<dlzka;j++){
//			cislo=rand()/(float)(RAND_MAX);
			cislo=rand()%20;
//			printf("%f ",cislo);	
			write(subor,&cislo,sizeof(float));
		}
//		printf("\n");
	}	
	close(subor);
	
	
}
