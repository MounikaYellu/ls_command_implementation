//This file contains headers and Structure used for student record creation 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct st{
 			int roll;
			char name[20];
			float mark;
			struct st *link;
		}NODE;
