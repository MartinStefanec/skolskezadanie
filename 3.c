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
	int podmienkanacislo = 0;
	int k;
	for(k=0,k<strlen(argv[2]),k++){
		if(argv[2[k]]<0||argv[2[k]]>9) podmienkanacislo++;
	}
	
	if(argc!=3||podmienkanacislo)
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