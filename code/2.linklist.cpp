#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

//����
typedef struct ListNode{
	int data;
	struct ListNode *next;
}ListNode; 
typedef struct LinkList{
	ListNode head;//����ͷ�ڵ� 
	int length;
}LinkList;

//��ʼ�� 
ListNode *init_listnode(int val){
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = val;
	p->next = NULL;
	return p;
}
LinkList *init_linklist(){
	LinkList *l = (LinkList *)malloc(sizeof(LinkList));
	l->head.next = NULL;//����ͷ�ڵ����һλΪ�� 
	l->length = 0;
	return l;
}

//���� 
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

//����
int insert(LinkList *l, int ind, int val){
	if(l == NULL) return 0;
	if(ind < 0 || ind > l->length) return 0; 
	ListNode *p = &(l->head);//headΪ����ͷ�ڵ�  
	ListNode *node = init_listnode(val);//������Ľڵ� 
	while(ind--){
		p = p->next; 
	}//pָ�������ڵ�ǰһ��λ��
	node->next = p->next;
	p->next = node;
	l->length += 1;
	return 1;
} 

int erase(LinkList *l, int ind){
	if(l == NULL) return 0;
	if(ind < 0 || ind >= l->length) return 0;
	ListNode *p = &(l->head);//headΪ����ͷ�ڵ�  
	ListNode *q;
	while(ind--){
		p = p->next; 
	} //��ɾ���Ľڵ��ǰһ��
	q = p->next->next;//���汻ɾ���ڵ�ĺ�һ���ڵ��ַ
	clear_listnode(p->next);
	p->next = q;
	l->length -= 1;
	return 1;
}

//���
void output(LinkList *l){
	printf("LinkList(%d) ��",l->length);
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

