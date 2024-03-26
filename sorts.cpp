
#include <iostream>
#include <cmath>

using namespace std;
void PrintArray(int* arr, int n) 
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//===================================
bool CheckAndSwap(int* p_1, int* p_2)
{
    if (*p_1 > *p_2)
    {
        swap(*p_2,*p_1);
        return true;
    }
    return false;
    
}
int BubbleSortOneIt(int* start_p, int * end_p)//возрастание
{
    int count = 0;
    for (int* q = start_p; q < end_p; q++)
    {
        count+=CheckAndSwap(q, q+1);

    }
    return count;
    
    
}

void BubbleSort(int* arr, int n) 
{
    /*
    for(int* p = arr+1 ; p < arr+n ; p++)
    {
        BubbleSortOneIr(arr, p);
    }
    */
    for(int i = 0 ; i < n ; i++)
    {
        if (BubbleSortOneIt(arr, arr + n - i)==0)
        {
            break;
        }
    }
}
void BubbleSort(int* start_p, int* end_p)
{
    BubbleSort(start_p, end_p - start_p);
}
//============================================
int* GetMinElInd(int* arr, int size_of_array)
{
    int* arr_min = arr;
    for(int i = 1; i < size_of_array ; i++)
    {
        if (arr[i] <= *arr_min)
        {
            arr_min = arr + i;
        }
        
    }
    return arr_min;
}

void SelectionSort(int* arr, int n) 
{
    for(int i = 0; i < n ; i++)
    {
        //swap(*(arr + n - 1 - i), *(GetMinElInd (arr, n - i)));
        swap(*(arr+i), *(GetMinElInd (arr + i, n - i)));
    }
    
}
//============================================

void Merge(int* arr_1, int n, int* arr_2, int k,int* arr)
{
   
    int i_1 = 0;
    int i_2 = 0;
    

    for (int i = 0; i < n+k; i++)
    {
       // cout << i <<" " << i_1 << " "<< i_2 << endl;
       
        if (i_1 >= n)
        {
            arr[i] = arr_2[i_2];
            i_2++;
        }
        else if (i_2 >= k)
        {
            arr[i] = arr_1[i_1];
            i_1++;
        }
        else if(arr_1[i_1] > arr_2[i_2])
        {
            arr[i] = arr_2[i_2];
            i_2++;
        }
        else
        {
            arr[i] = arr_1[i_1];
            i_1++;
        }

        

    }
    
}

void MergeSort(int* start_p, int* end_p)
{
    int n = end_p - start_p + 1;
    if (n == 1)
    {
        return;
    }
    cout << n << ": ";
    MergeSort(start_p,start_p+n/2 - 1);
    MergeSort(start_p+n/2,end_p);
    
    //PrintArray(start_p,n);
    int result_arr[n];
    Merge(start_p,n/2,start_p+n/2,n/2,result_arr);
    for (int i = 0; i < n; i++)
    {
        start_p[i] = result_arr[i];
    }
    
   
}


//============================================
int* Partition(int* left_bound, int* right_bound, int x)//////////////////////////
{
  while (left_bound <= right_bound)
  {
        if (*left_bound < x)
        {
            left_bound++;
        }
        else if (*right_bound >= x)
        {
            right_bound--;
        }
        else 
        {
            swap(*left_bound,*right_bound);
            left_bound++;
            right_bound--;
        }

  }
  return left_bound;

}
void QuickSort(int* start_p, int* end_p)
{
    int n = end_p - start_p + 1;
    if (n < 2)
    {
        return;
    }
    int pivot = start_p[n/2];
    int* p_second_part = Partition(start_p,end_p,pivot);
    if (p_second_part==start_p)
    {
        swap(*start_p,start_p[n/2]);
        QuickSort( p_second_part+1, end_p);
    }
    else
    {
        QuickSort(start_p, p_second_part - 1);
        QuickSort( p_second_part, end_p);
    }

    


}
//=======================================================================
void InsertSort1(int* start_p, int* end_p)
{
    int n = end_p - start_p + 1;
    for (int i = 1; i < n ; i++)
    {
        for(int j = 0; j < i;j++)
        {
            if (start_p[j] >= start_p[i])
            {
                int temp = start_p[i];
                for(int k = i; k > j;k--)
                {
                    start_p[k] = start_p[k - 1];
                }
                start_p[j] = temp;
                break;
                
                
            }
        }

       

    }
    PrintArray(start_p,n);

}
void InsertSort(int* start_p, int* end_p)
{
    int n = end_p - start_p + 1; 
    // 5 6 8 9 7
    // 5 6 8 9 9 , temp = 7
    // 5 6 8 8 9
    // 5 6 7 8 9
    for (int i = 1; i < n ; i++)
    {
        int temp = start_p[i];
        //cout << temp << endl;
        int j = i - 1;
        for(; j >= 0;j--)
        {
            //cout << j << ": ";
           // PrintArray(start_p,n);
            if (start_p[j] >= temp)
            {
                
                start_p[j+1] = start_p[j];

            }
            else
            {
                break;
            }

        }
        start_p[j+1] = temp;
        

       // PrintArray(start_p,n);
        //cout << "-----------" <<  endl;

    }
    PrintArray(start_p,n);

}
//=====================================

int ShakerSortOneItForw(int* start_p, int * end_p)//возрастание
{
    int count = 0;
    for (int* q = start_p; q < end_p; q++)
    {
        count+=CheckAndSwap(q, q+1);

    }
    return count;
    
    
}

int ShakerSortOneItBackw(int* start_p, int * end_p)//возрастание
{
    int count = 0;
    for (int* q = end_p ; q > start_p; q--)
    {
        count+=CheckAndSwap(q-1, q);

    }
    return count;
    
    
}

void  ShakerSort(int* start_p, int * end_p)//возрастание
{
    int n = end_p-start_p + 1;
    // i = 0, l = 0, r = n - 1
    // i = 1, l = 0, r = n - 2
    // i = 2, l = 1, r = n - 2
    // i = 3, l = 1, r = n - 3
    // r = n - 1 - (i+1)/2 
    for(int i = 0 ; i < n ; i++)
    {
        if (i%2==0)
        {
            ShakerSortOneItForw(start_p + i/2, end_p - (i+1)/2);
        }
        else
        {
            ShakerSortOneItBackw(start_p+i/2, end_p - (i+1)/2);
        }
        PrintArray(start_p,n);
    }
}
int main()
{
    srand(time(0));
    const int n = 8;
    int arr[n];
    int x = 0;
    int* p = arr;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand()%100;

    }
    PrintArray(arr,n);
    //QuickSort(arr, arr+n-1);
    //InsertSort(arr ,arr+n -1);
    ShakerSort(arr,arr+n-1);
   
}