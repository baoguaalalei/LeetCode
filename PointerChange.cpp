#include <iostream>
#include <stdlib.h>
using namespace std;
/*
С�׶��������⣬�����������ݵ�λ�ã�����1->2->3->4->5�����������Ժ���2->1->4->3->5
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
		Node *pNew = (Node*)malloc(sizeof(Node));    //    Ϊ�ڵ����ռ�
		pNew->data = val;                            //    ���û���������ݸ����ڵ�ĳ�Ա
		pTail->next = pNew;
		pNew->next = NULL;                           //    �����һ���ڵ��ָ��ָ����һ���µĽڵ�
		pTail = pNew;                                //    ���½ڵ��е�ָ����Ϊ��
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