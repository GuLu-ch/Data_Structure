#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

//二叉树
typedef struct Node{
	int val;
	struct Node *lchild, *rchild;
}Node;
typedef struct Tree{
	Node *root;
	int n;
}Tree;

//初始化 
Node *getNewNode(int val){
	Node *p = (Node *)malloc(sizeof(Node));
	p->val = val; 
	p->lchild = p->rchild = NULL;
	return p;
} 
Tree *getNewTree(){
	Tree *tree = (Tree *)malloc(sizeof(Tree));
	tree->n = 0;
	tree->root = NULL;
	return tree; 
} 

//销毁
void clearNode(Node *node){
	if(node == NULL) return ;
	clearNode(node->lchild);
	clearNode(node->rchild);
	free(node);
	return ;	
} 
void clearTree(Tree *tree){
	clearNode(tree->root);
	free(tree);
	return ;
} 

 

//插入
Node *insertNode(Node *root, int val, int *ret){
	//二叉排序树 
	if(root == NULL) {
		*ret = 1;
		return getNewNode(val);
	}
	if(root->val == val) return root;
	if(root->val > val) root->lchild = insertNode(root->lchild, val, ret);
	else root->rchild = insertNode(root->rchild, val, ret);
	return root;
}
void insert(Tree *tree, int val){
	int flag = 0; 
	tree->root = insertNode(tree->root, val, &flag);
	tree->n += flag;
	
	return ;
} 


//输出
void outputNode(Node *root){
	if(root == NULL) return ;
	printf("%d",root->val);
	if(root->lchild == NULL && root->rchild == NULL) return ;
	printf("(");
	outputNode(root->lchild);
	printf(",");
	outputNode(root->rchild); 
	printf(")");
	return ;
}
void outputTree(Tree *tree){
	printf("tree(%d) = ",tree->n);
	outputNode(tree->root);
	printf("\n");
	return; 
} 

//前序输出
void preorderNode(Node *node){
	if(node == NULL) return ;
	printf(" %d",node->val);
	preorderNode(node->lchild);
	preorderNode(node->rchild);
	return ;	 
} 
void preorder(Tree *tree){
	printf("preorder : "); 
	preorderNode(tree->root);
	printf("\n");
	return ;	 
} 

//中序输出
void inorderNode(Node *node){
	if(node == NULL) return ;
	inorderNode(node->lchild);
	printf(" %d",node->val);
	inorderNode(node->rchild);
	return ;	 
} 
void inorder(Tree *tree){
	printf("inorder : "); 
	inorderNode(tree->root);
	printf("\n");
	return ;	 
} 


//后序输出
void postorderNode(Node *node){
	if(node == NULL) return ;
	postorderNode(node->lchild);
	postorderNode(node->rchild);
	printf(" %d",node->val);
	return ;	 
} 
void postorder(Tree *tree){
	printf("postorder : "); 
	postorderNode(tree->root);
	printf("\n");
	return ;	 
} 



int main(){
	srand(time(0));
	Tree *tree = getNewTree();
	for(int i = 0; i < 10; i++){
		int val =rand() % 100;
		insert(tree, val);
		outputTree(tree); 
	}
	
	preorder(tree);
	inorder(tree);
	postorder(tree);
	clearTree(tree);
    return 0;
}

