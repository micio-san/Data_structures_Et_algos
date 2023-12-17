//Simple sort
//Selection sort
//Insertion sort
//Quick sort
//Merge sort
//Heap sort

#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX = 20;

void printArr(int x, int *val) {
    for (int i = 0; i < x; i++) {
        cout << val[i] << "  ";
     
    }   
    cout << endl;
}

int simpleSort() {
    int arr[MAX] = {};
    int n=0;
    cout << "Gimme number"<< "\n";
    cin >> n;
    if (n > MAX) {
        cout << "Gimme a number smaller than" << MAX << "\n";
        simpleSort();
    }
    else {
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100;
        }  

        printArr(n, arr);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        cout << "Sorted" << "\n";
        printArr(n, arr);
    }
  return 0;
}

int selectionSort(){
    int arr[MAX] = {};
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 100;
    }
    printArr(MAX,arr);
    for (int i = 0; i < MAX; i++) {
        int min = i;
        for (int j = i+1; j < MAX; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    printArr(MAX, arr); 
    return 0;
}

int insertionSort() {
    int arr[MAX] = {};
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 100;
    }
    printArr(MAX, arr);
    for (int i = 1; i < MAX; i++) {
        int temp = arr[i];
        int valLeft = i - 1;
        while (valLeft >= 0 && arr[valLeft] > temp) {
            arr[valLeft +1] = arr[valLeft];
            valLeft--;
        }
        arr[valLeft + 1] = temp;
    }
    printArr(MAX, arr);
    return 0;
}

int partition(int arr[8], int start,int end) {
    //pick the pivot to always be at the end
    int pivot = arr[end];
    int j = start -1;
    //loops trough the array
    for (int i = start; i < end; i++) {
        //will stopo if i is smaller than our pivot and do
        if (arr[i] < pivot) {
            // if element smaller than pivot is found
   // swap it with the greater element pointed by i
            j++;
            //
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    //now all our vars smaller than pivot are on the left and the bigger on the right
    // swap pivot with the greater element at i
    j++;
    //insert pivot into final place
    int temp = arr[j];
    arr[j] = arr[end];
    arr[end] = temp;
    printArr(8,arr);
    return j;
};

void quickSort(int arr[8], int start, int end) {
    /*IN MAIN int arr[8] = { 10,7,12,1,8,3,2,6 };
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[start]);
    quickSort(arr, start, end - 1);*/
    //condition to break the loop, se l'inizio e la fine sono uguali vale 1
    if (end <= start) {
        return;
    }
    //psarition is an helper function which returns the location of pivot
    int pivot = partition(arr, start, end);
    //pass each partition recursively back into the array, leaving the pivot out
    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot +1, end);
}

void merge(int arr[],int start,int mid,int end) {
   //
    int const arrOneSize = mid - start + 1;
    int const arrTwoSize = end - mid;
    cout << "hihi" << arrOneSize << "\n";
    int *leftArray = new int[arrOneSize];
    int *rightArray = new int[arrTwoSize];

    for (int i = 0; i < arrOneSize; i++) {
        leftArray[i] = arr[start + i];
    }
    for (int j = 0; j < arrTwoSize; j++) {
        rightArray[j] = arr[mid + 1 + j];
    }
    int indexArrOne = 0;
    int indexArrTwo = 0;
    int indexMergedArr = start;
    //control that indexes never go over the size
    while (indexArrOne < arrOneSize && indexArrTwo < arrTwoSize) {
        if (leftArray[indexArrOne] <= rightArray[indexArrTwo]) {
            arr[indexMergedArr] = leftArray[indexArrOne];
            indexArrOne++;
        }
        else {
            arr[indexMergedArr] = rightArray[indexArrTwo];
            indexArrTwo++;
        }
        indexMergedArr++;
    }
    while (indexArrOne < arrOneSize) {
        arr[indexMergedArr] = leftArray[indexArrOne];
        indexArrOne++;
        indexMergedArr++;
    }
    while (indexArrTwo < arrTwoSize) {
        arr[indexMergedArr] = rightArray[indexArrTwo];
        indexArrTwo++;
        indexMergedArr++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int arr[8], int start, int end) {
    if (start >=end)
        return;
    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid +1, end);
    merge(arr,start,mid,end);
    printArr(end, arr);
}

int main()
{
    int arr[8] = {3,7,8,5,4,2,6,1};
    int end = sizeof(arr) / sizeof(arr[0]);
    printArr(end, arr);
    mergeSort(arr, 0, end -1);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
