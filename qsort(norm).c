#include <stdio.h>
#include <stdlib.h>
void quickSort(int *numbers, int left, int right)
{
  int pivot;
  int l_hold = left;
  int r_hold = right;
  pivot = numbers[left];
  while (left < right)
  {
    while ((numbers[right] >= pivot) && (left < right))
      right--;
    if (left != right)
    {
      numbers[left] = numbers[right];
      left++;
    }
    while ((numbers[left] <= pivot) && (left < right))
      left++;
    if (left != right)
    { 
      numbers[right] = numbers[left];
      right--;
    }
  }
  numbers[left] = pivot;
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot)
    quickSort(numbers, left, pivot - 1);
  if (right > pivot)
    quickSort(numbers, pivot + 1, right);
}
int main()
{
  int k=0,n;
  int *a;
  FILE *pfile;
  pfile=fopen("C:/MinGW/progi/mass.txt","r");
  if(pfile==NULL)
  {
    printf("File not found\n");
            return -1;
  }
  while(fscanf(pfile,"%d",&n)==1)
  {
     k++;
  }
  fclose(pfile);
  pfile=fopen("C:/MinGW/progi/mass.txt","r");
  if(pfile==NULL)
  {
    printf("File not found\n");
            return -1;
  }
  a=(int*)malloc(k*sizeof(int));
  k=0;
  while(fscanf(pfile,"%d",&n)==1)
  {
        a[k]=n;
        k++;
  }
  for (int i = 0; i<k; i++)
    printf("%d ", a[i]);
  printf("\n");
  quickSort(a, 0, k-1);
  for (int i = 0; i<k; i++)
    printf("%d ", a[i]);
  printf("\n");
  getchar();
  return 0;
}