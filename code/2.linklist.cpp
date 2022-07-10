#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

//链表
typedef struct ListNode{
	int data;
	struct ListNode *next;
}ListNode; 
typedef struct LinkList{
	ListNode head;//虚拟头节点 
	int length;
}LinkList;

//初始化 
ListNode *init_listnode(int val){
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = val;
	p->next = NULL;
	return p;
}
LinkList *init_linklist(){
	LinkList *l = (LinkList *)malloc(sizeof(LinkList));
	l->head.next = NULL;//虚拟头节点的下一位为空 
	l->length = 0;
	return l;
}

//销毁 
void clear_listnode(ListNode *node){
	if(node == NULL) return ;
	free(node);
	return ;
}
void clear_linklist(LinkList *l){
	if(l == NULL) return ;
	ListNode *p = l->head.next;
	ListNode *q;
	while(p){
		q = p->next;
		clear_listnode(p);
		p =  q->next;
	}
	free(l);
	return ;
}

//插入
int insert(LinkList *l, int ind, int val){
	if(l == NULL) return 0;
	if(ind < 0 || ind > l->length) return 0; 
	ListNode *p = &(l->head);//head为虚拟头节点  
	ListNode *node = init_listnode(val);//待插入的节点 
	while(ind--){
		p = p->next; 
	}//p指向待插入节点前一个位置
	node->next = p->next;
	p->next = node;
	l->length += 1;
	return 1;
} 

int erase(LinkList *l, int ind){
	if(l == NULL) return 0;
	if(ind < 0 || ind >= l->length) return 0;
	ListNode *p = &(l->head);//head为虚拟头节点  
	ListNode *q;
	while(ind--){
		p = p->next; 
	} //待删除的节点的前一个
	q = p->next->next;//保存被删除节点的后一个节点地址
	clear_listnode(p->next);
	p->next = q;
	l->length -= 1;
	return 1;
}

//输出
void output(LinkList *l){
	printf("LinkList(%d) ：",l->length);
	for(ListNode *p = l->head.next; p; p = p->next){
		printf("%d -> ", p->data);
	}
	printf("NULL\n");
	return ;
} 

#define MAX_OP 20

int main(){
	srand(time(0));
	LinkList *l = init_linklist();
	for(int i = 0; i < MAX_OP; i++){
		int op =rand() % 4;
		int ind = rand() % (l->length + 1);
		int val = rand() % 100;
		switch(op){
			case 0:
			case 1:
			case 2:{
				printf("insert %d at %d to LinkList = %d\n", 
				val, ind, insert(l, ind, val));
				
			}break;
			case 3:{
				printf("erase item at %d fron LinkList = %d\n", 
				ind, erase(l, ind));
				
			}break;
		}
		output(l);
		printf("\n");
		
	}
	
	clear_linklist(l);

    return 0;
}

