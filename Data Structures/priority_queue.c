/* Program to build a priority queue using a heap */

#include <stdio.h>
int arr[1000];

int HEAP_SIZE = 0;

void heapify(int arr[], int i, int n){
    
    int left = 2*i + 1;
    int right = 2*i + 2;

    int max_ele;

    if (left <n && arr[left] > arr[i]) max_ele = left;
    else max_ele = i;

    if (right <n && arr[right] > arr[max_ele]) max_ele = right;

    if (max_ele != i){
        int temp = arr[max_ele];
        arr[max_ele] = arr[i];
        arr[i] = temp;

        heapify(arr, max_ele, n);
    }
}

void insert(int arr[], int ele){
    arr[HEAP_SIZE] = ele;
    HEAP_SIZE++;

    int i = HEAP_SIZE - 1;
    int parent = (i-1) / 2;

    while(arr[i] > arr[parent]){
        int temp = arr[parent];
        arr[parent] = arr[i];
        arr[i] = temp;
        i = parent;
        parent = (parent-1)/2;
    }
}

int delete(int arr[]){
    int ele = arr[0];

    if(HEAP_SIZE == 0){
        return -1;
    }
    
    int temp = arr[HEAP_SIZE-1];
    arr[HEAP_SIZE-1] = arr[0];
    arr[0] = temp;

    HEAP_SIZE--;

    heapify(arr, 0, HEAP_SIZE);

    return ele;
}

void display(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d | ", arr[i]);
    }
    printf("\n");
}

int main(){

    int opt;
    int ele;

    while(1){
        printf("---Menu---\n");
        printf("1. Insert Element\n");
        printf("2. Remove Element\n");
        printf("3. Quit\nEnter choice : ");
        scanf("%d", &opt);

        switch(opt){
            case 1:{
                printf("Enter ele: ");
                scanf("%d", &ele);
                insert(arr, ele); 
            }break;
            case 2:{
                ele = delete(arr);
                if(ele == -1) printf("Queue Empty");
                else printf("Element is : %d\n", ele);
            }break;
            case 3:{
                return 0;
            }break;
            default: printf("Wrong option!\n");
        }
        display(arr, HEAP_SIZE);
    }

    return 0;
}