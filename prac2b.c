#include<stdio.h>
#include <stdlib.h>	/* for atof() */
#include <string.h>

#define MAXLINE 200

int main() {
	FILE *ofp;
	char line[MAXLINE];
	
	char name[] = "Alex";
	int age = 20;
	float height = 1.75;
	
	printf("Name: %s\n",name);
	printf("Age: %d\n", age);
	printf("Height: %f", height);
	
	ofp = fopen("output.txt", "w");
	
	if (ofp == NULL){
		printf("error opening output file\n");
		return -1;
	}
	
	fprintf(ofp, "%s\n", name);
	fprintf(ofp, "%d\n", age);
	fprintf(ofp, "%f\n", height);
	
	fclose(ofp);
};