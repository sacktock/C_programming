#include<stdio.h>
#include <stdlib.h>	/* for atof() */
#include <string.h>

#define MAXLINE 200

int main() {
	FILE *ifp;
	char line[MAXLINE];
	
	char name[20];
	int age;
	float height;
	
	ifp = fopen("read.txt","r");
	
	if (ifp == NULL){
		printf("error opening input file\n");
		return -1;
	}
	
	if (fgets(line, MAXLINE, ifp)== NULL){
		printf("error in data file\n");
		return -1;
	}
	strcpy(name, line); 
	if (fgets(line,MAXLINE, ifp)==NULL){
		printf("error in data file\n");
		return -1;
	}
	age = atoi(line);
	if (fgets(line,MAXLINE, ifp)==NULL){
		printf("error in data file\n");
		return -1;
	}
	height = atof(line);
	
	printf("Name: %s",name);
	printf("Age: %d\n", age);
	printf("Height: %f", height);
	
	fclose(ifp);

};