#include <stdio.h>
#include<time.h>
#include <sys/time.h>

void bubble_sort(int a[], int n) {
    int i = 0, j = 0, tmp;
    for (i = 0; i < n; i++) {   // loop n times - 1 per element
        for (j = 0; j < n - i - 1; j++) { // last i elements are sorted already
            if (a[j] > a[j + 1]) {  // swap if order is broken
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}
void merge_sort(int i, int j, int a[], int aux[]) {

    if (j <= i) {
        return;     // the subsection is empty or a single element
    }
    int mid = (i + j) / 2;

    // left sub-array is a[i .. mid]
    // right sub-array is a[mid + 1 .. j]

    merge_sort(i, mid, a, aux);     // sort the left sub-array recursively
    merge_sort(mid + 1, j, a, aux);     // sort the right sub-array recursively

    int pointer_left = i;       // pointer_left points to the beginning of the left sub-array
    int pointer_right = mid + 1;        // pointer_right points to the beginning of the right sub-array
    int k;      // k is the loop counter

    // we loop from i to j to fill each element of the final merged array
    for (k = i; k <= j; k++) {
        if (pointer_left == mid + 1) {      // left pointer has reached the limit
            aux[k] = a[pointer_right];
            pointer_right++;
        } else if (pointer_right == j + 1) {        // right pointer has reached the limit
            aux[k] = a[pointer_left];
            pointer_left++;
        } else if (a[pointer_left] < a[pointer_right]) {        // pointer left points to smaller element
            aux[k] = a[pointer_left];
            pointer_left++;
        } else {        // pointer right points to smaller element
            aux[k] = a[pointer_right];
            pointer_right++;
        }
    }

    for (k = i; k <= j; k++) {      // copy the elements from aux[] to a[]
        a[k] = aux[k];
    }
}
void quicksort(int number[10000],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}


void heap_sort(int a[], int n) {
    int i, j,c, root, temp;

     for (i = 1; i < n; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;
            if (a[root] < a[c])   /* to create MAX heap array */
            {
                temp = a[root];
                a[root] = a[c];
                a[c] = temp;
            }
            c = root;
        } while (c != 0);
    }

    for (j = n - 1; j >= 0; j--)
    {
        temp = a[0];
        a[0] = a[j];    /* swap max element with rightmost leaf element */
        a[j] = temp;
        root = 0;
        do
        {
            c = 2 * root + 1;    /* left node of root element */
            if ((a[c] < a[c + 1]) && c < j-1)
                c++;
            if (a[root]<a[c] && c<j)    /* again rearrange to max heap array */
            {
                temp = a[root];
                a[root] = a[c];
                a[c] = temp;
            }
            root = c;
        } while (c < j);
    }
}

int main() {
  int a[10000],aux[10000],i, n,d, swap;
  double diff;
  clock_t start_bubble, end_bubble, start_merge, end_merge, start_quick, end_quick, start_heap, end_heap;
  printf("Enter number of elements in the array:\n");
  scanf("%d", &n);
  //printf("Enter %d integers\n", n);
  for (i = 0; i < n; i++){
        a[i]=rand()%10000;
  }
  printf("\n");

  start_bubble = clock();
  bubble_sort(a, n);
  end_bubble = clock();
  diff=(double)(end_bubble-start_bubble)/CLOCKS_PER_SEC*1000;



  printf("Printing the sorted array using Bubble sort algorithm:\n");
  for (i = 0; i < n; i++){
        printf("\t%d", a[i]);
  }
  printf("\n");
  printf("Time taken with Bubble sort:%lf ms\n",(diff));
  printf("\n");

  start_merge = clock();
  merge_sort(0, n - 1, a, aux);
  end_merge = clock();


  printf("Printing the sorted array using Merge  sort algorithm:\n");
  for (i = 0; i < n; i++){
        printf("\t%d", a[i]);
  }
  printf("\n");
  printf("Time taken with Merge sort:%lf ms\n",(double)(end_merge-start_merge)* 1000.0/CLOCKS_PER_SEC);
  printf("\n");
  start_quick=clock();
  quicksort(a,0,n-1);
  end_quick=clock();
  printf("Printing the sorted array using Quick  sort algorithm:\n");
  for (i = 0; i < n; i++){
        printf("\t%d", a[i]);
  }
  printf("\n");
  printf("Time taken with quick sort:%lf ms\n",(double)(end_quick-start_quick)* 1000.0/CLOCKS_PER_SEC);
  printf("\n");

    start_heap = clock();
    heap_sort(a,n);
    end_heap = clock();
    printf("\n");
    printf("Printing the sorted array using Heap sort algorithm:\n");
    for (i = 0; i < n; i++)
    {
     printf("\t %d", a[i]);
    }
    printf("\n");
    printf("Time taken with heap sort:%lf ms\n",(double)(end_heap-start_heap)* 1000.0/CLOCKS_PER_SEC);
    printf("\n");
}




