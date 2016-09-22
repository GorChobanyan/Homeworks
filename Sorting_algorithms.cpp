#include <iostream>
using namespace std;

void print_array(int array[], int size)
{
	for(int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

void bubbleSort(int array[], int size, bool order)
{
	bool swap;
	int temp;
	
	if (order)
		do
		{
			swap = false;
			for (int count = 0; count < (size - 1); count++)
			{
				if (array[count] > array[count + 1])
				{
					temp = array[count];
					array[count] = array[count + 1];
					array[count + 1] = temp;
					swap = true;
				}
				
				print_array(array, size);
			}
		} while (swap);
	else
		do
		{
			swap = false;
			for (int count = 0; count < (size - 1); count++)
			{
				if (array[count] < array[count + 1])
				{
					temp = array[count];
					array[count] = array[count + 1];
					array[count + 1] = temp;
					swap = true;
				}
				
				print_array(array, size);
			}
		} while (swap);		
}

void selectionSort(int array[], int size, bool order)
{
	int startScan, index, value;
	
	if (order)
		for (startScan = 0; startScan < (size - 1); startScan++)
		{
			index = startScan;
			value = array[startScan];
			for(int i = startScan + 1; i < size; i++)
			{
				if (array[i] < value)
				{
					value = array[i];
					index = i;
				}
			}
		array[index] = array[startScan];
		array[startScan] = value;
		
		print_array(array, size);
		}
	else
		for (startScan = 0; startScan < (size - 1); startScan++)
		{
			index = startScan;
			value = array[startScan];
			for(int i = startScan + 1; i < size; i++)
			{
				if (array[i] > value)
				{
					value = array[i];
					index = i;
				}
			}
		array[index] = array[startScan];
		array[startScan] = value;
		
		print_array(array, size);
		}	
}

void quickSort(int array[], int left, int right, bool order) 
{
    int i = left, j = right;
    int tmp;
    int pivot = array[(left + right) / 2];
		
	if(order)
    	while (i <= j) 
		{
            while (array[i] < pivot)
                i++;
            while (array[j] > pivot)
                j--;
            if (i <= j) 
			{
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
                i++;
                j--;
            }
            print_array(array, left + right);
        }
 	else
    	while (i <= j) 
		{
            while (array[i] > pivot)
                i++;
            while (array[j] < pivot)
                j--;
            if (i <= j) 
			{
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
                i++;
                j--;
            }
            	print_array(array, left + right);
        } 			
      // recursion
    if (left < j)
        quickSort(array, left, j, order);
    if (i < right)
    	quickSort(array, i, right, order);
}
	
void insertionSort(int array[], int size, bool order) 
{
    int i, j, tmp;
      
    if(order)
      	for (i = 1; i < size; i++) 
		{
            j = i;
            while (j > 0 && array[j - 1] > array[j]) 
			{
                tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
                j--;
                  
                print_array(array, size);
            }
      	}
    else
      	for (i = 1; i < size; i++) 
		{
           	j = i;
            while (j > 0 && array[j - 1] < array[j]) 
			{
                tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
                j--;
                
                print_array(array, size);
            }
      	}
}
	
void merge(int arr[], int l, int m, int r, bool order)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
	if(order)
		while (i < n1 && j < n2)
		{
			if (L[i] <= R[j])
			{
				arr[k] = L[i];
				i++;
			}
			else
			{
				arr[k] = R[j];
				j++;
			}
			k++;
		}
	else
		while (i < n1 && j < n2)
		{
			if (L[i] >= R[j])
			{
				arr[k] = L[i];
				i++;
			}
			else
			{
				arr[k] = R[j];
				j++;
			}
			k++;
		}
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r, bool order)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m, order);
        mergeSort(arr, m+1, r, order);
 
        merge(arr, l, m, r, order);
    }
}

int main()
{	 
	int a[] = {3, -1, 5, 34, -5, 8, 13, 7, -7, -16},
	arr_size = sizeof(a)/sizeof(a[0]);
	bool flag;
	
	cin >> flag;
	bubbleSort(a, arr_size, flag);
	//selectionSort(a, arr_size, flag);
	//insertionSort(a, arr_size, flag);
	//quickSort(a, 0, arr_size - 1, flag);
 	//mergeSort(a, 0, arr_size - 1, flag);
	print_array(a, arr_size);
	return 0;
}
