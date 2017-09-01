#include <stdio.h>
 void HeapAdjust(int array[],int i,int Nlength)
 {
	 int nChild;
	 int Temp;
	 for (; 2*i+1 < Nlength; )
	 {
		 nChild = 2*i+1;
		 if (nChild<Nlength-1&&array[nChild]<array[nChild+1]) nChild++;
		 if (array[nChild]>array[i])
		 {
			 Temp=array[i];
			 array[i]=array[nChild];
			 array[nChild]=Temp;
		 }
		 else break;
		 i = nChild;
	 } 
	return;	
 }

 void HeapSort(int *array,int length)
{
	for (int i=length/2-1;i>=0;i--)
	{
		HeapAdjust(array,i,length);
	}
	for (int i=length-1;i>0;i--)
	{
		array[0]=array[0]^array[i];
		array[i]=array[0]^array[i];
		array[0]=array[0]^array[i];
		
		HeapAdjust(array,0,i);
	}
}
/*int main(){
	 int array[] = {0,1,2,3,4,5,6,7,8,9};
	 HeapSort(array,sizeof(array)/sizeof(int));
	 for (int i=0;i<sizeof(array)/sizeof(int);i++)
	 {
		 printf("%d ",array[i]);
	 }
	 return 0;
 }
 */