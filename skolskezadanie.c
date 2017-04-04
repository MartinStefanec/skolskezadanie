#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <fcntl.h>
int main(int argc, char** argv){
	FILE *fw;
	char name[50] = {0};
	char n;
	
	scanf("Nazov suboru: %s\n", name);
	scanf("pocet: %s", n);
	
	if((fw = open(name, O_WRONLY | O_CREATE))==NULL)
		printf("Error. file cannot be opened!\n");
	
	
	return 0;
}
