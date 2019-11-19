
#include<stdio.h>
#include <stdlib.h>	/* for atof() */
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include <math.h>

struct Point{
	float x;
	float y;
};

struct Triangle{
	struct Point p1, p2, p3;
};

int main()
{
	int number = 10;
	struct Triangle **ret = calloc(sizeof(struct Triangle*), number);
	struct Triangle T;
	
	// some arbitrary traingle
	T.p1.x=4.0;T.p1.y=4.0;
	T.p2.x=6.0;T.p2.y=4.0;
	T.p3.x=5.0;T.p3.y=6.0;
	
	for (int i = 0 ; i < number ; i++){
		ret[i] = malloc(sizeof(struct Triangle));
		if (ret[i]==NULL)
		{
			printf("Error, memory not allocated");
			exit(0);
		}
		float x, y;
		x = (T.p1.x + T.p2.x) / 2.0;
		y = (T.p1.y + T.p2.y) / 2.0;
		
		T.p1.x=x;T.p1.y=y;
		T.p2.x=6.0;T.p2.y=4.0;
		T.p3.x=5.0;T.p3.y=6.0;
		*(ret[i]) = T;
	}
	
	for (int i = 0 ; i < number ; i++){
		printf("traingle : (%f,%f),(%f,%f),(%f,%f) ... \n",
			(*ret[i]).p1.x,(*ret[i]).p1.y,(*ret[i]).p2.x,
			(*ret[i]).p2.y,(*ret[i]).p3.x,(*ret[i]).p3.y);
		printf("freeing traingle %d ...\n",i);
		free(ret[i]);
	}
	
	

}