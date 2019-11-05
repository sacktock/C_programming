#include<stdio.h>
#include <stdlib.h>	/* for atof() */
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 200

int getwords(char *line, char *words[], int maxwords)
{
char *p = line;
int nwords = 0;

while(1)
	{
	while(isspace(*p))
		p++;

	if(*p == '\0')
		return nwords;

	words[nwords++] = p;

	while(!isspace(*p) && *p != '\0')
		p++;

	if(*p == '\0')
		return nwords;

	*p++ = '\0';

	if(nwords >= maxwords)
		return nwords;
	}
}

struct Point{
	float x;
	float y;
	float z;
};

struct Triangle{
	struct Point p1, p2, p3;
};

int main(int argc, char *argv[]) {
	char input_file[20];
	char output_file[20];
	FILE *ifp, *ofp;
	char line[MAXLINE];
	char *av[9];
	int na = 0;
	struct Triangle t[5];
	
	if (argc == 1){
		strcpy(input_file,"input.txt");
		strcpy(output_file, "output.txt");
	} else {
		if (argc == 2){
			strcpy(input_file, argv[1]);
			strcpy(output_file, "output.txt");
		} else if (argc > 2){
			strcpy(input_file, argv[1]);
			strcpy(output_file, argv[2]);
		}
	}
	
	ifp = fopen(input_file,"r");
	
	if (ifp == NULL){
		printf("error opening input file\n");
		return -1;
	}
	
	for (int i = 0 ; i < 5 ; i++) {
		if (fgets(line,MAXLINE,ifp) == NULL){
			printf("error in data file\n");
			return -1;
		} else if (getwords(line, av, 9) != 9){
			printf("error in data file\n");
		} else {
			t[i].p1.x = atof(av[0]);
			t[i].p1.y = atof(av[1]);
			t[i].p1.z = atof(av[2]);
			
			t[i].p2.x = atof(av[3]);
			t[i].p2.y = atof(av[4]);
			t[i].p2.z = atof(av[5]);
			
			t[i].p3.x = atof(av[6]);
			t[i].p3.y = atof(av[7]);
			t[i].p3.z = atof(av[8]);
		}
		
	}
	fclose(ifp);
	
	ofp = fopen(output_file,"w");
	float A[5];
	if (ofp == NULL){
		printf("error opening output file\n");
		return -1;
	}
	
	for (int i =0 ; i < 5 ; i++){
		float P1[] = {t[i].p2.x - t[i].p1.x, t[i].p2.y - t[i].p1.y, t[i].p2.z - t[i].p1.z};
		float P2[] = {t[i].p3.x - t[i].p1.x, t[i].p3.y - t[i].p1.y, t[i].p3.z - t[i].p1.z};
		
		float U[] = {P1[1]*P2[2] - P2[1]*P1[2], P1[0]*P2[2] - P2[0]*P2[2], P1[0]*P2[1]-P2[0]*P1[1]};
		A[i] = sqrt(pow(U[0], 3) + pow(U[1], 3) + pow(U[2], 3));
	}
	
	for (int i=0 ; i < 5 ; i++){
		fprintf(ofp, "Area: %f\n", A[i]);
		printf("wrote %f to output.txt\n", A[i]);
	}
	
	fclose(ofp);

};