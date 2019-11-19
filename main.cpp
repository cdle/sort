#include<iostream>
using namespace std;

template<typename T>
void mergeSort(T* arr,int e, int b = 1)
{
    if(e!=b)
    {
        int d = (e-b)/2;//中心点偏移
        mergeSort(arr, b+d, b); 
        mergeSort(arr, e, b+d+1);
        if(arr[b+d-1]<arr[b+d])//优化
        {
            T* cp = new T[e-b+1];//开辟临时空间
            copy(arr+(b--)-1, arr+e, cp);
            T* xp = cp;//左边指针头
            T* mp = cp + d;//中间点指针
            T* yp = mp + 1;//右边指针头
            while(b<e){
                arr[b++] = (xp<=mp && *xp>*yp) ? *(xp++) : *(yp++);
            };
            delete[] cp;
        }
    }
}

template<typename T>
void mergeSortUB(T* arr,int n)
{
    for(int t =1; t<=n; t+=t)
    {
        for(int r=0; r+t < n; r+=t+t)
        {
            int b = r+1;
            int e = min(r+t+t,n);
            int d = t-1;
            if(arr[b+d-1]<arr[b+d])
            {
                T* cp = new T[e-b+1];
                copy(arr+(b--)-1, arr+e, cp);
                T* xp = cp;
                T* mp = cp + d;
                T* yp = mp + 1;
                while(b<e){
                    arr[b++] = (xp<=mp && *xp>*yp) ? *(xp++) : *(yp++);
                };
                delete[] cp;
            }
        }
    }
}

template<typename T>
void quickSort(T *arr,int n,int j=1)
{
    if(n<=1)return;
    int v = arr[j-1];
    int q = j;
    for(int i=0; i<n-1; i++)
    {
        if(v<arr[q+i])
        {
            swap(arr[j++],arr[q+i]);
        }
    }
    swap(arr[q-1],arr[j-1]);
    quickSort(arr,j-q,q);
    quickSort(arr,n-j+q-1,j+1);
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; 
    mergeSort(arr,20);
    for (int i = 0; i < 20; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}  
