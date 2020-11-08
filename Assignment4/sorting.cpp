#include "sorting.h"

vector<int> genData(int size)
{
	vector<int> data;
	srand(time(NULL));
	for (int i = 0; i < size; ++i)
	{
		data.push_back(rand() % size + 1);
	}
	return data;
}

vector<int> bubbleSort(vector<int> data)
{
	milliseconds startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	for (int i = 0; i < data.size() - 1; ++i)
	{
		for (int j = data.size() - 1; j > i; --j)
		{
			if (data[j] < data[j - 1])
			{
				int temp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = temp;
			}
		}
	}
	milliseconds endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	cout << "It took " << abs(startTime.count() - endTime.count()) << " milliseconds\n";
	return data;
}
