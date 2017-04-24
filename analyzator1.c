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
	int subor,velkost,pocitadlo,presiel=0,i,j;
	unsigned char cislo;
	float **polesmernikov;	
	if(argc!=2){
		printf("Expected 1 argument");
		return 0;
	}
	subor=open(argv[1], O_RDONLY|O_BINARY,S_IWUSR);	
	velkost = lseek(subor, 0, SEEK_END);
	lseek(subor, 0, SEEK_SET);
	printf("%d \n",velkost);
	int pocetfloatov[velkost/40];
	while(presiel<velkost){
		read(subor,&cislo,sizeof(unsigned char));
		lseek(subor,sizeof(float)*cislo,SEEK_CUR);
		pocetfloatov[pocitadlo]=cislo;
		pocitadlo++;
		presiel=presiel+sizeof(float)*cislo+1;
			//printf("%d ",pocitadlo);
		//	printf("%d ",presiel);
}
	printf("%d ",pocitadlo);
//	for(i=0;i<pocitadlo;i++) printf("%d-ta postupnost: %d\n ",i,pocetfloatov[i]);
int pocetvpost[pocitadlo];
	
	while(j<pocitadlo){
		read(subor,&cislo,sizeof(unsigned char));
		lseek(subor,sizeof(float)*cislo,SEEK_CUR);
		pocetfloatov[j]=cislo;
		j++;
}

	
	
}
