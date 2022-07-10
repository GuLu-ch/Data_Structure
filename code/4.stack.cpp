#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//栈（先入后出） 
typedef struct Stack{
	int *data;
	int top, size;
}Stack; 

//初始化
Stack *init(int n){
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->data = (int *)malloc(sizeof(int) * n);
	s->size = n;
	s->top = -1;
	return s;
}

//销毁
void clear(Stack *s){
	if(s == NULL) return ;
	free(s->data);
	free(s);
	return ;
} 

//判空
int empty(Stack *s){
	return s->top == -1;
}

//取栈顶元素
int  top(Stack *s){
	if(empty(s)) return 0;
	return s->data[s->top];
} 

//入栈
int push(Stack *s, int val){
	if(s == NULL) return 0;
	if(s->top + 1 == s->size) return 0;
	s->top += 1;
	s->data[s->top] = val;
	return 1;
}

//出栈
int pop(Stack *s){
	if(s == NULL) return 0;
	if(empty(s)) return 0;
	s->top -= 1;
	return 1;
} 

//输出
void output(Stack *s){
	printf("stack(%d) = [", s->top + 1);
	for(int i = s->top; i  >= 0; i--){
		printf(" %d",s->data[i]);
	}
	printf("]\n");
	return ;
} 
 
int main(){
	#define MAX_OP 20
	Stack *s = init(MAX_OP);
	srand(time(0));
	for(int i = 0; i < MAX_OP; i++){
		int op = rand() % 2;
		int val = rand() % 100;
		switch(op){
			case 0:{
				printf("push %d to stack = %d\n", val, push(s, val));
				break;
			}
			case 1:{
				int x = top(s);
				int y = pop(s);
				printf("pop %d from stack = %d\n", x, y); 
				break;
			}
		}
		output(s);
	} 

    return 0;
}

