#include<iostream>
using namespace std;

template<class T>
class Vector {
	private:
		T *arr;
		int length, maxSize;
		void resize_vector() {
			T *temp = new T[maxSize];
			maxSize *= 2;
			copy_from(arr, temp);
			arr = new T[maxSize];
			copy_from(temp, arr);
		}
		void copy_from(T *src, T* dest) {
			for(int i = 0 ; i < length ; i++)
				dest[i] = src[i];
			delete[] src; // delete the source array
		}
		void decimate() {
			maxSize /= 2;
			T* temp = new T[maxSize];
			copy_from(arr, temp);
			arr = new T[maxSize];
			copy_from(temp, arr);
		}
	public:
//		static T* iterator;
		Vector() {
			arr = new T[1];
			maxSize = 1;
			length = 0;
		}
		void push_back(T val) {
			if(maxSize == length)
				resize_vector();
			arr[length++] = val;
		}
		T* begin() {
			return arr;
		}
		T* end() {
			return &arr[length-1];
		}
		T* rbegin() {
			return &arr[length-1];
		}
		T* rend() {
			return arr;
		}
		const T* cbegin() {
			return arr;
		}
		const T* cend() {
			return &arr[length-1];
		}
		const T* crbegin() {
			return &arr[length-1];
		}
		const T* crend() {
			return arr;
		}
		T* at(int g) {
			return &arr[g];
		}
		T* data() {
			return &arr;
		}
		T* front() {
			return arr;
		}
		T* back() {
			return &arr[length-1];
		}
		bool empty(){
			return length == 0;
		}
		int size() {
			return length;
		}
		int max_size() {
			return maxSize;
		}
		void resize(int l) {
			length = l;
		}
		void pop_back() {
			if(!length)
				return;
			length--;
			if(length <= maxSize/2)
				decimate(); // if the length of the array is less than half of maxsize then reduce the memory allocation by 2
		}
		void shrink_to_fit() {
			maxSize = size();
			T* temp = new T[maxSize];
			copy_from(arr, temp);
			arr = new T[maxSize];
			copy_from(temp, arr);
		}
//		operator overloading
		T operator[](int i){
			return arr[i];
		}
};
