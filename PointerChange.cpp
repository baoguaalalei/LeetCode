#include <iostream>
#include <stdlib.h>
using namespace std;
/*
小米二轮面试题，两两交换数据的位置，例如1->2->3->4->5，经过处理以后变成2->1->4->3->5
*/
struct Node{
	int  data;
	Node *next;
};

Node * change(Node* Data){
	Node * temp1;
	if (Data->next==NULL)
    {
		return Data;
    }

	if (Data->next->next!=NULL)
	{	
		temp1 = Data->next;		
		Data->next = temp1->next;
		temp1->next = Data;
		Data->next=change(Data->next);		
	}
	else
	{
		return Data;	
	}
	return temp1;
}
int main(){
    Node * pHead = (Node*)malloc(sizeof(Node));
	pHead->data = 0;
	Node * pTail = pHead;
    pTail->next = NULL;
	int i,len;
	len = 5;
	for(i = 1; i < len; i++)
	{
		int val =i;		
		Node *pNew = (Node*)malloc(sizeof(Node));    //    为节点分配空间
		pNew->data = val;                            //    将用户输入的数据赋给节点的成员
		pTail->next = pNew;
		pNew->next = NULL;                           //    将最后一个节点的指针指向下一个新的节点
		pTail = pNew;                                //    将新节点中的指针置为空
    }	
	pTail = pHead;
	for ( i = 0;i < len;i++ )
	{
		printf("%d\n",pTail->data);
		pTail = pTail->next;
	}
	pHead = change(pHead);
	pTail = pHead;

for ( i = 0;i < len;i++ )
{
	if (pTail!=NULL)
	{
		printf("%d\n",pTail->data);
		pTail = pTail->next;
	}	
}
}