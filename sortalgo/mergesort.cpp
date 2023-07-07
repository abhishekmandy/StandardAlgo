#include<vector>
#include<iostream>
using namespace std;


// 1. EASY TO UNDERSTAND AND IMPLEMENT BUT HIGHER SPACE COMPLEXITY
// WITH REDUCED IMPLEMENTATION COMPLEXITY AND SAME TIME COMPLEXITY OF NLOGN IN ALL CASES.
// IS A STABLE ALGO
// IS IN PLACE
// BUT NOT A ONLINE ALGO.


// vector<int> merge(int arr[],int s,int e,int n){
//     // base case.

//     int m = s+(e-s)/2;
//     if(s > e){
//         vector<int>ans;
//         return ans;
//     }
//     if(s == e){
//         vector<int>ans  = {arr[s]};
//         return ans;
//     }

//     // left.
//     vector<int> left = merge(arr,s,m,n);
//     // right.
//     vector<int> right = merge(arr,m+1,e,n);
//     // code for merging sorted arrays..

//     vector<int> ans(left.size() + right.size());
//     int i = 0;
//     int j = 0;
//     int k = 0;
//     while(i<left.size() && j<right.size()){
//         if(left[i] > right[j]){
//             ans[k++] = right[j++];
//         }
//         else if(right[j] > left[i]){
//             ans[k++] = left[i++];
//         }
//         else{
//             ans[k++] = left[i++];
//             ans[k++] = right[j++];
//         }
//     }
//     while(i<left.size()){
//         ans[k++]  = left[i++];
//     }
//     while(j<right.size()){
//         ans[k++]  = right[j++];
//     }
    
//     return ans;
// }


// 2. SLIGHLY TRICKY IN IMPLEMENTATION BUT USES LESS SPACE COMPLEXITY...................
void merge(int s,int e ,int arr[]){
    int m = s + (e-s)/2;
    int n1 = m-s+1;
    int n2 = e-m;

    int *l1 = new int[n1];
    int *l2 = new int[n2];

    for(int i = s;i<n1+s;i++){
        l1[i-s]  = arr[i];
    }
    for(int i = m+1;i<n2+m+1;i++){
        l2[i-m-1] = arr[i];
    }

    // merge.
    int i = 0;
    int j = 0;
    int k = s;
    while(i<n1 && j<n2){
        if(l1[i]> l2[j]){
            arr[k++] = l2[j++];
        }
        else if(l1[i] < l2[j]){
            arr[k++] = l1[i++];
        }
        else{
            arr[k++] = l1[i++];
            arr[k++]  = l2[j++];
        }
    }
    while(i<n1){
        arr[k++] = l1[i++];
    }
    while(j < n2){
        arr[k++] = l2[j++];
    }
    return;
}

void mergesort(int arr[],int s,int e,int n){
    if(s >= e)return;
    int m = s + (e-s)/2;
    mergesort(arr,s,m,m-s+1);
    mergesort(arr,m+1,e,e-m);
    merge(s,e,arr);
    return;
}

int main(int argc, char const *argv[])
{
    int arr[10] = {1,33,-3,0,2,2,1,990,100,78};
    int s = 0;
    int e = 9;
    // vector<int>ans = merge(arr,s,e,10);
    // for(auto j : ans)cout<<j<<" ";

    mergesort(arr,s,e,10);
    for(int i = 0;i<10;i++)cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
