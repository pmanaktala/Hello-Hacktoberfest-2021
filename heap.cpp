//  Heap sort in cpp 
#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if (left<n && arr[left]>arr[largest])
    largest=left;
    if (right<n && arr[right]>arr[largest])
    largest=right;

    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n){
    for(int i=n/2;i>=0;i--)
    heapify(arr, n, i);

    for(int i=n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        heapify(arr, i,0);
    }
}

int main(){
    //input
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;

    int arr[n];
    cout<<"Enter the value of the "<<n<<" array elements\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];

    //calling function
    heapsort(arr, n);

    //output
    cout<<"Elements after sorting are:\n";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}