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
	int subor,velkost,n,presiel=0,i,k,j,pocetfloatov,medzipocet=0,kolko;
	unsigned char cislo;
	float number,sucet,priemer;	
	if(argc!=2){
		printf("Expected 1 argument");
		return 0;
	}
	subor=open(argv[1], O_RDONLY|O_BINARY,S_IWUSR);
	if(subor<0) {
		printf("Wrong filename, Try again");
		return 0;
	}	
	velkost = lseek(subor, 0, SEEK_END);
	lseek(subor, 0, SEEK_SET);
	int dlzky[velkost/40];
	while(presiel<velkost){
		if(read(subor,&cislo,sizeof(unsigned char))==-1) {
			printf("Unable to read");
			return 0;
		}
		lseek(subor,sizeof(float)*cislo,SEEK_CUR);
		dlzky[n]=cislo;
		n++;
		presiel=presiel+sizeof(float)*cislo+1;
}
	printf("Pocet postupnosti: %d\n",n);
	for(i=0;i<n;i++) {
	pocetfloatov=pocetfloatov+dlzky[i];
	}
	
printf("Celkovy pocet floatov: %d\n",pocetfloatov);
	lseek(subor, 0, SEEK_SET);
	float *pole[pocetfloatov];
	for(i=0;i<pocetfloatov;i++){
		pole[i]=malloc(sizeof(float));
		if(pole[i]==0) {
			printf("Unable to allocate");
			return 0;
		}
	}
	for(i=0;i<n;i++){
		lseek(subor, 1, SEEK_CUR);
		 medzipocet=medzipocet+dlzky[i-1];
		for(j=0;j<dlzky[i];j++){
			if(read(subor,&number,sizeof(float))==-1) {
			printf("Unable to read");
			return 0;
		}
				kolko=medzipocet+j;
				*pole[kolko]=number;
			}
	}
	
	medzipocet=0;
	float priemery[n];
	printf("Priemery jednotlivych postupnosti:\n");
	for(i=0;i<n;i++){
		sucet=0;
		medzipocet=medzipocet+dlzky[i-1];
		for(j=medzipocet;j<medzipocet+dlzky[i];j++){
			sucet=sucet+*pole[j];
		}
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
		medzipocet=medzipocet+dlzky[i-1];
		for(j=medzipocet;j<medzipocet+dlzky[i];j++){
			printf("%f, ",*pole[j]);
		}
	}
	for(i=0;i<pocetfloatov;i++)	free(pole[i]);
	
	if(close(subor)==-1) {
			printf("Unable to close file");
			return 0;
		}
	
}
