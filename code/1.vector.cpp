#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

//Ë³Ðò±í
typedef struct Vector{
	int *data;
	int size,length; 
}Vector;

//³õÊ¼»¯ 
Vector *init(int n){
	Vector *vec =  (Vector *)malloc(sizeof(Vector));
	vec->data = (int *)malloc(sizeof(int) * n);
	vec->size = n;
	vec->length = 0;
	return vec;
}

//Ïú»Ù 
void clear(Vector *vec){
	if(vec == NULL) return;
	free(vec->data);
	free(vec);
	return ; 
}

//À©ÈÝ
int expand(Vector *vec){
	int new_size = vec->size * 2;
	int *p = (int *)realloc(vec->data,sizeof(int) * new_size); 
	if(p == NULL) return 0; 
	vec->size = new_size;
	vec->data = p;
	return 1;
} 

//²åÈë 
int  insert(Vector *vec, int ind, int val){
	if(vec == NULL) return 0;
	if(vec->length == vec->size) {
		if(!expand(vec)) return 0;
		printf("expand vector size to %d success\n",vec->size);
	}
	if(ind <0 || ind > vec->length) return 0;
	for(int i = vec->length; i > ind; i--){
		vec->data[i] = vec->data[i - 1];
	}
	vec->data[ind] = val;
	vec->length += 1;
	return 1; 
}

//É¾³ý 
int erase(Vector *vec, int ind){
	if(vec == NULL) return 0;
	if(vec->length == 0) return 0;
	if(ind < 0 || ind >= vec->length) return 0;
	for (int i = ind + 1; i < vec->length; i++){
		vec->data[i - 1] = vec->data[i];
	} 
	vec->length -= 1;
	return 1;
} 

//Êä³öË³Ðò±í
void output(Vector *vec){
	printf("Vector(%d) = [",vec->length);
	for (int i = 0; i < vec->length; i++){
		if( i != 0) printf(", "); 
		printf("%d",vec->data[i]);
	} 
	printf("]\n");
	return ; 
} 

int main(){
	#define MAX_OP 20
	srand(time(0));
	Vector *vec = init(1);
	int op, ind, val;
	for(int i = 0; i < MAX_OP; i++){
		op = rand() % 2;
		ind = rand() % (vec->length + 1 );
		val = rand() % 100;
		switch(op){
			case 0:{
				printf("insert %d at %d to vector\n",val,ind);
				insert(vec, ind, val);
				break;
			}
			case 1:{
				printf("erase item at %d from vector\n",ind);
				erase(vec,ind);
				break;
			}
		}
		
		output(vec);
		 
	}
	
	
	return 0;
} 
