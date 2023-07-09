#include<vector>
#include<iostream>
using namespace std;

// This is a divide and conqueour algo which has a worst case t.c. of O(n^2) and best case and avg case t.c of O(nlogn)
// Its best case and avg t.c can vary on logic of finding out pivot .
// .ie. logic of finding partition index...................
//  int partition (int arr[], int low, int high)
//     {
//         int left = low;
//         int right = high;
//         int pivot = left;
//       while(left != right){
//           if(pivot == left){
//               while(arr[right] >= arr[pivot] && right > left)right--;
//               swap(arr[pivot],arr[right]);
//               pivot = right;
//           }
//           else if(pivot == right){
//               while(arr[left] <= arr[pivot] && left < right)left++;
//               swap(arr[pivot],arr[left]);
//               pivot = left;
//           }
//       }
//       return pivot;
    
//     }


// Another logic for partition.
int partition(int arr[],int low,int high){
    int cnt = 0;
    int pivot = arr[low];
    for(int i = low+1;i<=high;i++){
        if(pivot >= arr[i])cnt++;
    }
    int pivotIndex = low + cnt;
    swap(arr[pivotIndex] , arr[low]);
    int i = low;
    int j = high;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] < pivot)i++; 
        while(arr[j] > pivot)j--;
        if(i <= pivotIndex && j >= pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}
 void quickSort(int arr[], int low, int high)
    {
        if(low >= high)return;
        int pivot = partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
        return;
    }
    

int main(int argc, char const *argv[])
{
    int arr[6] = {1,9,9,9,10,1};
    quickSort(arr,0,5);
    cout<<arr[0]<<" ";
    cout<<arr[1]<<" ";
    cout<<arr[2]<<" ";
    cout<<arr[3]<<" ";
    cout<<arr[4]<<" ";
    cout<<arr[5]<< "";
    cout<<endl;
    
    return 0;
}
