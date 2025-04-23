
template <class T>
void bubbleSort(T arr[]) {
	int size = sizeof(arr);
    T temp{};

	for (int i{}; i < size -1;i++){
		for (int j{}; j < size-1;j++){
			if (arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
    }
}

template <class T>
void insertionSort(T arr[]){
	int n = arr.size();
	for (int i=1; i<n; ++i){
		T key = arr[i];
		int j=i-1;
		while(j>= 0 && arr[k] > key){
			arr[j+1]=arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
}
