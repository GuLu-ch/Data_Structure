#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//队列
typedef struct Queue{
	int *data;
	int head, tail;
	int length, cnt;
}Queue;

//初始化 
Queue *init(int n){
	Queue *q = (Queue *)malloc(sizeof(Queue));
	q->data = (int *)malloc(sizeof(int) * n);
	q->head =  q->tail = q->cnt = 0;
	q->length = n;
	return q; 
} 

//销毁
void clear(Queue *q){
	if(q == NULL) return ;
	free(q->data);
	free(q);
	return ; 
} 

//判空
int empty(Queue *q){
	return q->cnt == 0;
} 

//返回队首元素
int front(Queue *q){
	return q->data[q->head];
} 

//进队列 
int push(Queue *q, int val){
	if(q == NULL) return 0;
	if(q->cnt == q->length) return 0;
	q->data[q->tail++] = val;
	if(q->tail == q->length) q->tail -= q->length; 
	q->cnt += 1; 
	return 1; 
}

//出队列
int pop(Queue *q){
	if(q == NULL) return 0;
	if(empty(q)) return 0;
	q->head++;
	if(q->head == q->length) q->head -= q->length; 
	q->cnt -= 1;
	return 1;
} 

//输出
void output(Queue *q){
	printf("queue = [");
	for(int i = q->head, j = 0; j < q->cnt; j++){
		int ind = (i + j) % q->length;
		printf(" %d",q->data[ind]);
	}
	printf("]\n");
	
} 

int main(){
	#define MAX_OP 20
	srand(time(0));
	Queue *q =init(MAX_OP);
	
	for(int i = 0; i < MAX_OP; i++){
		int val = rand() % 100;
		int op = rand() % 2;
		switch(op){
			case 0:{
				printf("push %d to queue = %d\n", val, push(q, val));
				break;
			}
			case 1:{
				int x = front(q);
				int y = pop(q);
				
				printf("pop %d from queue = %d\n", x, y); 
				break;
			}
		}
		output(q);
	}
	printf("head:%d, tail:%d, cnt:%d\n", q->head, q->tail, q->cnt); 
	for(int i = 0; i < MAX_OP; i++){
		int val = rand() % 100;
		printf("push %d to queue = %d\n", val, push(q, val));
	}
	output(q);
	
    return 0;
}

