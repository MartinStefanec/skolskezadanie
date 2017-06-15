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
	int subor,velkost,n=0,presiel=0,i=0,k,j,pocetfloatov=0,medzipocet=0,kolko,*dlzky;
	unsigned char cislo;
	float number,sucet,priemer,*pole,*priemery;	
	
	if(argc!=2){
		printf("Expected 1 argument");
		return 0;
	}
	
	subor=open(argv[1], O_RDONLY|O_BINARY,S_IWUSR);
	if(subor<0) {
		printf("Unable to open, Try again");
		return 0;
	}
		
	velkost = lseek(subor, 0, SEEK_END);
	lseek(subor, 0, SEEK_SET);
	while(presiel<velkost){
		if(read(subor,&cislo,sizeof(unsigned char))==-1) {
			printf("Unable to read");
			return 0;
		}
		
		lseek(subor,sizeof(float)*cislo,SEEK_CUR);
		n++;
		presiel=presiel+sizeof(float)*cislo+1;
	}
	
	printf("Pocet postupnosti: %d\n",n);
	lseek(subor, 0, SEEK_SET);
	dlzky=malloc(n*sizeof(int));
	if(dlzky==NULL) {
		printf("Unable to allocate");
		return 0;
	}
			
	for(i=0;i<n;i++) {
		if(read(subor,&cislo,sizeof(unsigned char))==-1) {
			printf("Unable to read");
			return 0;
		}
		
		lseek(subor,sizeof(float)*cislo,SEEK_CUR);
		dlzky[i]=cislo;
		pocetfloatov=pocetfloatov+dlzky[i];
	}
	
	printf("Celkovy pocet floatov: %d\n",pocetfloatov);
	lseek(subor, 0, SEEK_SET);
	pole=malloc(pocetfloatov*sizeof(float));
	if(pole==NULL) {
		printf("Unable to allocate");
		return 0;
	}
	
	for(i=0;i<n;i++){
		lseek(subor, sizeof(unsigned char), SEEK_CUR);
		for(j=0;j<dlzky[i];j++){
			if(read(subor,&number,sizeof(float))==-1) {
				printf("Unable to read");
				return 0;
			}
			
			kolko=medzipocet+j;
			pole[kolko]=number;
		}
		
		medzipocet=medzipocet+dlzky[i];
	}
	
	medzipocet=0;
	priemery=malloc(n*sizeof(float));
	if(priemery==NULL) {
		printf("Unable to allocate");
		return 0;
	}
	printf("Priemery jednotlivych postupnosti:\n");
	for(i=0;i<n;i++){
		sucet=0;
		for(j=medzipocet;j<medzipocet+dlzky[i];j++){
			sucet=sucet+pole[j];
		}
		
		medzipocet=medzipocet+dlzky[i];	
		priemery[i]=sucet/dlzky[i];
		printf("%d:%f\t",i+1,priemery[i]);
	}
	
	sucet=0;
	medzipocet=0;	
	printf("\nPriemer priemerov postupnosti: ");
	for(i=0;i<n;i++){
		sucet=sucet+priemery[i];
	}
	
	priemer=sucet/n;
	printf("%f\n",priemer);
	printf("Jednotlive postupnosti:");
	for(i=0;i<n;i++){
		printf("\n%d. postupnost: ",i+1);	
		for(j=medzipocet;j<medzipocet+dlzky[i];j++){
			printf("%f, ",pole[j]);
		}
		
		medzipocet=medzipocet+dlzky[i];
	}
	
	free(pole);
	free(priemery);
	free(dlzky);
	if(close(subor)==-1) {
		printf("Unable to close file");
		return 0;
	}
}
