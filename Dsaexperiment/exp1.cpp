
#include <iostream>
using namespace std;

// Function to print array details (Index, Value, Address)
void printArrayDetails(int arr[], int n)
{
    cout << "\nIndex\tValue\tAddress\n";
    cout << "---------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "]" << "\t" << arr[i] << "\t" << &arr[i] << "\n";
    }
}

// 1. BUBBLE SORT
void bubblesort(int arr[], int n)
{
    cout << "\n--- Bubble Sort Passes ---\n";
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        cout << "Pass " << i + 1 << ":\t";
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
    cout << "\nSorted array is:";
    printArrayDetails(arr, n);
}

// 2. INSERTION SORT
void insertsort(int arr[], int n)
{
    cout << "\n--- Insertion Sort Passes ---\n";
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        cout << "Pass " << i << ":\t";
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
    cout << "\nSorted array is:";
    printArrayDetails(arr, n);
}

// 3. MERGE SORT
void merge(int arr[], int s, int mid, int e, int n)
{
    int brr[10];
    int i = s;
    int j = mid + 1;
    int k = s;

    while (i <= mid && j <= e)
    {
        if (arr[i] < arr[j])
        {
            brr[k] = arr[i];
            i++;
        }
        else
        {
            brr[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        brr[k] = arr[i];
        i++;
        k++;
    }
    while (j <= e)
    {
        brr[k] = arr[j];
        j++;
        k++;
    }

    for (int x = s; x <= e; x++)
    {
        arr[x] = brr[x];
    }

    static int pass = 1;
    cout << "Pass " << pass++ << ":\t";
    for (int x = 0; x < n; x++)
    {
        cout << arr[x] << " ";
    }
    cout << endl;
}

void mergesort(int arr[], int s, int e, int n)
{
    if (s < e) {
        int mid = (s + e) / 2;
        mergesort(arr, s, mid, n);
        mergesort(arr, mid + 1, e, n);
        merge(arr, s, mid, e, n);
    }
}

// 4. QUICK SORT
int partition(int arr[], int s, int e, int n)
{
    int key = arr[s];
    int i = s;
    int j = e;
    while (i < j)
    {
        while (arr[i] <= key && i < e)
        {
            i++;
        }
        while (arr[j] > key && j > s)
        {
            j--;
        }
        if (i < j)
        { 
            int temp = arr[i];
            arr [i] = arr [j];
            arr[j] = temp;
            //swap(arr[i], arr[j]);
        }
    }
       int temp = arr[s];
    arr[s] = arr[j];
    arr[j] = temp;

    static int pass = 1;
    cout << "Pass " << pass++ << ":\t";
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
    cout << endl;

    return j;
}

void quicksort(int arr[], int s, int e, int n)
{
    if (s < e)
    {
        int pos = partition(arr, s, e, n);
        quicksort(arr, s, pos - 1, n);
        quicksort(arr, pos + 1, e, n);
    }
}

// 5. SELECTION SORT
void selectsort(int arr[], int n)
{
    cout << "\n--- Selection Sort Passes ---\n";
    for (int i = 0; i < n; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;

        cout << "Pass " << i << ":\t";
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << "\n";
    }
    cout << "\nSorted array is:";
    printArrayDetails(arr, n);
}

// 6. LINEAR SEARCH
void linearSearch(int arr[], int n, int target)
{
    bool found = false;
    int index = -1;

    cout << "\n--- Linear Search Iterations ---\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Iteration " << i << ": Comparing target (" << target << ") with arr[" << i << "] (Value: " << arr[i] << ") -> ";
        if (arr[i] == target)
        {
            cout << "Match Found!\n";
            found = true;
            index = i;
            break;
        }
        else
        {
            cout << "No Match.\n";
        }
    }

    if (found)
        cout << "\nElement " << target << " is found at index " << index << "!" << endl;
    else
        cout << "\nElement " << target << " was not found in the array." << endl;
}

// 7. BINARY SEARCH
void binarySearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    bool found = false;
    int index = -1;
    int pass = 1;

    cout << "\n--- Binary Search Iterations ---\n";
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        cout << "Iteration " << pass++ << ": low = " << low << ", high = " << high
             << ", mid = " << mid << " (arr[" << mid << "] = " << arr[mid] << ") -> ";

        if (arr[mid] == target)
        {
            cout << "Match Found!\n";
            found = true;
            index = mid;
            break;
        }
        else if (arr[mid] < target)
        {
            cout << "Target is greater, moving right.\n";
            low = mid + 1;
        }
        else
        {
            cout << "Target is smaller, moving left.\n";
            high = mid - 1;
        }
    }

    if (found)
        cout << "\nElement " << target << " is found at index " << index << "!" << endl;
    else
        cout << "\nElement " << target << " was not found in the array." << endl;
}

// MAIN FUNCTION
int main()
{
    int arr[10];
    int n;

    cout << "Enter the no. of elements in array: ";
    cin >> n;

    // Check array size
    if (n < 1 || n > 10)
    {
        cout << "Please enter a number between 1 and 10.\n";
        return 0;
    }

    cout << "Enter the " << n << " elements in array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\nUnsorted array details:";
    printArrayDetails(arr, n);

    // STEP 1: SORTING MENU
    int choiceSort;
    cout << "\n==============================\n";
    cout << "       SORTING MENU           \n";
    cout << "==============================\n";
    cout << "Choose 1 for Bubble Sort\n";
    cout << "Choose 2 for Insertion Sort\n";
    cout << "Choose 3 for Merge Sort\n";
    cout << "Choose 4 for Quick Sort\n";
    cout << "Choose 5 for Selection Sort\n";
    cout << "Enter your choice (1 to 5): ";
    cin >> choiceSort;

    switch (choiceSort)
    {
    case 1:
        cout << "\nYou selected Bubble Sort.\n";
        bubblesort(arr, n);
        break;
    case 2:
        cout << "\nYou selected Insertion Sort.\n";
        insertsort(arr, n);
        break;
    case 3:
        cout << "\nYou selected Merge Sort.\n";
        cout << "\n--- Merge Sort Passes ---\n";
        mergesort(arr, 0, n - 1, n);
        cout << "\nSorted array is:";
        printArrayDetails(arr, n);
        break;
    case 4:
        cout << "\nYou selected Quick Sort.\n";
        cout << "\n--- Quick Sort Passes ---\n";
        quicksort(arr, 0, n - 1, n);
        cout << "\nSorted array is:";
        printArrayDetails(arr, n);
        break;
    case 5:
        cout << "\nYou selected Selection Sort.\n";
        selectsort(arr, n);
        break;
    default:
        cout << "Invalid sorting choice!\n";
        return 0;
    }

    // STEP 2: ASK FOR TARGET
    int target;
    cout << "\n---------------------------------\n";
    cout << "Enter the target element to search: ";
    cin >> target;

    // STEP 3: SEARCHING MENU
    int choiceSearch;
    cout << "\n==============================\n";
    cout << "       SEARCHING MENU         \n";
    cout << "==============================\n";
    cout << "Choose 1 for Linear Search\n";
    cout << "Choose 2 for Binary Search\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choiceSearch;

    switch (choiceSearch)
    {
    case 1:
        cout << "\nYou selected Linear Search.\n";
        linearSearch(arr, n, target);
        break;
    case 2:
        cout << "\nYou selected Binary Search.\n";
        binarySearch(arr, n, target);
        break;
    default:
        cout << "Invalid searching choice!\n";
    }

    return 0;
}
