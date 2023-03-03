#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++) {
		std::cout << arr[i] << ", ";
	}
	std::cout << "\b\b]\n";
}
template <typename T>
void fill_arr(T arr[], const int length,int left,int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % (right - left) + left;
	}
}
void type_of(int num) {    std::cout << "INT\n";}
void type_of(float num) {  std::cout << "FLOAT\n"; }
void type_of(char num) {   std::cout << "CHAR\n"; }
void type_of(double num) { std::cout << "DOUBLE\n"; }
template <typename T>
void middle_sort(T arr[], const int length) {
	int left=0, right=0;
	for (int i = 0; i < length; i++) {
		if (arr[i] < 0) {
			left = i;
			break;
		}
	}
	for (int i=length-1;i>0;i--)
		if (arr[i] < 0) {
			right = i;
			break;
		}
	if (left!=right)
	//std::sort(arr+left+1, arr + right);
	for (int i = right-1; i > left+1 ; i--) {
		for (int j = left+1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
	}
	
}	
int sum_AB(int numA, int numB){
	if (numA > numB)
		std::swap(numA, numB);
	if (numA == numB)
		return numA;
	return sum_AB(numA,numB-1)+numB;
};
template <typename T>
void circle_move(T arr[], const int length, int num=1) {
	
	if (num > 0) {
		for (int i = 0; i < num; i++)
			for (int j = length - 1; j > 0; j--) {
				std::swap(arr[j], arr[j - 1]);
			}
	}
	else 
		if (num < 0) {
			
			for (int i = 0; i < -num; i++) {
				int tmp = arr[0];
				for (int j = 0; j < length - 1; j++) {
					std::swap(arr[j], arr[j + 1]);
				}
				arr[length-1] = tmp;
			}
		}
}
int main() {
	setlocale(LC_ALL, "Russian");
	int n,m;
	//Задача 1
	/*
	std::cout << "Задача №1.Типы данных\n";
	std::cout << "105 - ";type_of(105);
	std::cout << "90.34 - "; type_of(90.34);
	std::cout << "\'i\' - "; type_of('i');
	std::cout << "90.34f - "; type_of(90.34f);
	*/
	//Задача 2
	/*
	std::cout << "Задача 2.Рекурсивная сумма\nВведите 1-е число ->";
	std::cin >> n;
	std::cout << "Введите 2-е число ->";
	std::cin >> m;
	std::cout <<"Сумма чисел от "<< n <<" до "<< m <<" = "<<sum_AB(n, m);
	*/
	//Задача 3
	/*
	std::cout << "Задача 3.Сортировка середины\nИсходный массив:\n";
	const int size3 = 10;
	int arr3[size3];
	fill_arr(arr3, size3, -21, 21);
	print_arr(arr3, size3);
	middle_sort(arr3, size3);
	std::cout << "Итоговый массив:\n";
	print_arr(arr3, size3);
	*/
	//Задача 4
	std::cout << "Задача 4\n";
	const int size4 = 5;
	int arr4[size4];
	fill_arr(arr4, size4,-20,20);
	std::cout << "Исходный массив:\n";
	print_arr(arr4, size4);
	std::cout << "Измененный массив:\n";
	circle_move(arr4, size4, -3);
	print_arr(arr4, size4);

	return 0;
}