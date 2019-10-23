#include <iostream.h>
#include <conio.h>
#include <process.h>

class sort
{
public:
int front;
int rear;
int size;
int arr[5];
sort(){
  front=0;
  rear=-1;
  size=5;
  }
void insert();
void display();
void shell_sort();
void cr_merge(int, int);
void merge_sort(int, int, int);
void radix_sort();
void quick_sort(int, int);
int split(int, int);
};

void sort :: insert()
{
if(rear==size-1)
	{
	 cout<<"\nQueue is full.\n";
	 return;
	}

else
	{
	cout<<"Enter the value to be inserted: ";
	cin>>arr[++rear];
	}
}

void sort :: display()
{
for(int i=front; i<=rear; i++)
	{
	 cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void sort :: shell_sort ()
{
  int j;
  for (int gap = size / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < size; ++i)
    {
      int temp = arr[i];
      for (j = i; j >= gap && temp < arr[j - gap]; j -= gap)
      {
	arr[j] = arr[j - gap];
      }
      arr[j] = temp;
    }
  }
}

void sort :: cr_merge(int fir, int las)
{
int k;
if(fir<las)
{
k=(fir+las)/2;
cr_merge(fir, k);
cr_merge(k+1, las);
merge_sort(fir, k, las);
}
}

void sort :: merge_sort(int fir1, int k1, int las1)
{
int c[10];
int i, j, k;
i=fir1;
j=k1+1;
k=0;
while(i<=k1 && j<=las1)
{
if(arr[i]<arr[j])
{
c[k]=arr[i];
k++; i++;
}
else
{
c[k]=arr[j];
k++; j++;
}
}
while (i<=k1)
{
c[k]=arr[i];
i++; k++;
}
while (j<=las1)
{
c[k]=arr[i];
k++; j++;
}
for(i=fir1, j=0; i<=las1; i++, j++)
arr[i]=c[j];
}

void sort :: radix_sort()
{
int buckets[10][10], count[10];
int passes, large, div, bucketno;
int i,j,k;
large=arr[0];
for(i=1; i<size; i++)
{if(arr[i]>large)
large=arr[i];}
passes=0;
while(large>0)
{passes++;
large=large/10;
}
div=1;
for(i=1; i<=passes; i++)
{
 for(j=0; j<=9; j++)
 count[j] = 0;
 for(j=0; j<size; j++)
 { bucketno=(arr[j]/div)%10;
   buckets [bucketno] [count[bucketno]] = arr[j];
   count [bucketno]++;
 }}
 j=0;
 for(bucketno=0; bucketno<=9; bucketno++)
 {
   for(k=0; k<count[bucketno]; k++)
   arr[j++] = buckets [bucketno] [k];
   div=div*10;
 }
}

void sort :: quick_sort(int lower, int upper)
{
if (upper>lower)
{int i=split(lower, upper);
 quick_sort(lower, i-1);
 quick_sort(i+1, upper);
 }
}

int sort :: split (int lower, int upper)
{
int p, q, i, t;
p=lower+1;
q=upper;
i=arr[lower];
while(q>=p)
{
while(arr[p]<i)
p++;
while (arr[q]>i)
q--;
if(q>p)
{
t=arr[p];
arr[p]=arr[q];
arr[q]=t;
} }
t=arr[lower];
arr[lower]=arr[q];
arr[q]=t;
return q;
}

int main ()
{ clrscr();
  int ch;
  sort obj;
  while(1)
  {
  cout<<"1. Insert\n2. Shell Sort\n3. Merge Sort\n4. Radix Sort\n5. Quick Sort"
      <<"\n6. Display\n7. Exit\nEnter choice: ";
  cin>>ch;
  switch (ch)
  {
  case 1: obj.insert();
  break;
  case 2: obj.shell_sort();
  break;
  case 3: obj.cr_merge(0, 4);
  break;
  case 4: obj.radix_sort();
  break;
  case 5: obj.quick_sort(0, 4);
  break;
  case 6: obj.display();
  break;
  case 7: exit(1);
  break;
  default: cout<<"Invalid choice";
  break;
  }
  }
}