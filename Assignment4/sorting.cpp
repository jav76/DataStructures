#include "sorting.h"

void genData(int* data, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; ++i)
	{
		data[i] = rand() % 2147483647;
	}
}

void printArray(int* data, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << data[i] << endl;
	}
}

void copyArray(int* source, int* dest, int size)
{
	for (int i = 0; i < size; ++i)
	{
		dest[i] = source[i];
	}
}

void bubbleSort(int* data, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = size - 1; j > i; --j)
		{
			if (data[j] < data[j - 1])
			{
				int temp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = temp;
			}
		}
	}
}

void insertionSort(int* data, int size)
{
	int i, j, current;
	for (i = 1; i < size; ++i)
	{
		current = data[i];
		j = i - 1;
		while (j >= 0 && data[j] > current)
		{
			data[j + 1] = data[j];
			--j;
		}
		data[j + 1] = current;
	}
}

void selectionSort(int* data, int size)
{
	int low;
	for (int i = 0; i < size; ++i)
	{
		low = i;
		for (int j = size - 1; j > i; --j)
		{
			if (data[j] < data[low])
			{
				low = j;
			}
		}
		int temp = data[i];
		data[i] = data[low];
		data[low] = temp;
	}
}



void mergeSort(int* data, int* temp, int left, int right)
{
	if (left == right)
	{
		return;
	}
	int mid = (left + right) / 2;
	mergeSort(data, temp, left, mid);
	mergeSort(data, temp, mid + 1, right);

	for (int i = left; i <= right; ++i)
	{
		temp[i] = data[i];
	}

	int i1 = left; 
	int i2 = mid + 1;

	for (int current = left; current <= right; ++current)
	{
		if (i1 == mid + 1)
		{
			data[current] = temp[i2++];
		}
		else if (i2 > right)
		{
			data[current] = temp[i1++];
		}
		else if (temp[i1] < temp[i2])
		{
			data[current] = temp[i1++];
		}
		else
		{
			data[current] = temp[i2++];
		}
	}
}

int partitionMid(int* data, int left, int right)
{
	int pivot = left + (right - left) / 2;
	int pivotVal = data[pivot];
	int i = left;
	int j = right;
	while (i <= j)
	{
		while (data[i] < pivotVal)
		{
			++i;
		}
		while (data[j] > pivotVal)
		{
			--j;
		}
		if (i <= j)
		{
			int temp = data[i];
			data[i] = data[j];
			data[j] = temp;
			++i;
			--j;
		}
	}
	return i;
}

void quickSortMid(int* data, int left, int right)
{
	if (left < right)
	{
		int pivot = partitionMid(data, left, right);
		quickSortMid(data, left, pivot - 1);
		quickSortMid(data, pivot, right);
	}
}

int partitionFirst(int* data, int left, int right)
{
	int pivot = left;
	int pivotVal = data[pivot];
	int i = left;
	int j = right;
	while (i <= j)
	{
		while (data[i] < pivotVal)
		{
			++i;
		}
		while (data[j] > pivotVal)
		{
			--j;
		}
		if (i <= j)
		{
			int temp = data[i];
			data[i] = data[j];
			data[j] = temp;
			++i;
			--j;
		}
	}
	return i;
}

void quickSortFirst(int* data, int left, int right)
{
	if (left < right)
	{
		int pivot = partitionFirst(data, left, right);
		quickSortFirst(data, left, pivot - 1);
		quickSortFirst(data, pivot, right);
	}
}


void race(int* original, int* toSort, int* temp, int size, bool sorted)
{
	genData(original, size);
	copyArray(original, toSort, size);
	if (sorted == true)
	{
		quickSortMid(toSort, 0, size - 1);
		cout << endl << "Testing sorts with pre-sorted data" << endl;
	}
	else
	{
		cout << endl << "Testing sorts with random data" << endl;
	}
	multimap<int, string> results;
	pair<int, string> resultEntry;
	milliseconds startTime;
	milliseconds endTime;
	int place = 1;

	cout << endl << "Timing O(n^2) sorts..." << endl;

	startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	bubbleSort(toSort, size);
	endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	resultEntry = { abs(startTime - endTime).count(), "Bubble sort" };
	results.insert(resultEntry);

	if (sorted == false)
	{
		copyArray(original, toSort, size);
	}
	startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	insertionSort(toSort, size);
	endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	resultEntry = { abs(startTime - endTime).count(), "Insertion sort" };
	results.insert(resultEntry);

	if (sorted == false)
	{
		copyArray(original, toSort, size);
	}
	startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	selectionSort(toSort, size);
	endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	resultEntry = { abs(startTime - endTime).count(), "Selection sort" };
	results.insert(resultEntry);

	cout << "Results for O(n^2) sorts:" << endl;

	
	for (multimap<int, string>::iterator i = results.begin(); i != results.end(); ++i)
	{
		if (place == 1)
		{
			cout << "1st place: ";
		}
		else if (place == 2)
		{
			cout << "2nd place: ";
		}
		else
		{
			cout << "3rd place: ";
		}
		cout << i->second << " " << i->first << "ms" << endl;
		++place;
	}
	results.clear();

	cout << endl << "Timing O(nlogn) sorts..." << endl;

	if (sorted == false)
	{
		copyArray(original, toSort, size);
	}
	startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	mergeSort(toSort, temp, 0, size - 1);
	endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	resultEntry = { abs(startTime - endTime).count(), "Merge sort" };
	results.insert(resultEntry);

	if (sorted == false)
	{
		copyArray(original, toSort, size);
	}
	startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	quickSortMid(toSort, 0, size - 1);
	endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	resultEntry = { abs(startTime - endTime).count(), "Quick sort (middle pivot)" };
	results.insert(resultEntry);

	if (sorted == false)
	{
		copyArray(original, toSort, size);
	}
	startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	quickSortFirst(toSort, 0, size - 1);
	endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	resultEntry = { abs(startTime - endTime).count(), "Quick sort (first pivot)" };
	results.insert(resultEntry);

	cout << endl << "Results for O(nlogn) sorts:" << endl;

	place = 1;
	for (multimap<int, string>::iterator i = results.begin(); i != results.end(); ++i)
	{
		if (place == 1)
		{
			cout << "1st place: ";
		}
		else if (place == 2)
		{
			cout << "2nd place: ";
		}
		else
		{
			cout << "3rd place: ";
		}
		cout << i->second << " " << i->first << "ms" << endl;
		++place;
	}
}

int getChoice()
{
	cout << endl;
	cout << "1) 1000" << endl;
	cout << "2) 5000" << endl;
	cout << "3) 10,000" << endl;
	cout << "4) 50,000" << endl;
	cout << "5) 75,000" << endl;
	cout << "6) 100,000" << endl;
	cout << "7) 500,000" << endl;
	cout << "Enter the size of the dataset to test: ";

	int choice;
	cin >> choice;
	while (cin.fail() || choice < 1 || choice > 7)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << endl << "Invalid option. Please try again." << endl;
		cin >> choice;
	}
	return choice;
}