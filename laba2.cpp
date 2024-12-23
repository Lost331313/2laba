#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;

void bubble_sort(int arr[], int N) {
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start, end;
	nanoseconds result;
	start = steady_clock::now();
	for (int j = 0; j < N - 1; j++) {
		for (int i = 0; i < N - 1 - j; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
			};
		};
	};
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << result.count() << " наносекунд - время сортировки с помощью bubble sort" << endl;
}

//2
void from_small_to_big_2(int arr[], int N) {

	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start_time, end_time;
	nanoseconds result;
	start_time = steady_clock::now();

	end_time = steady_clock::now();
	result = duration_cast<nanoseconds>(end_time - start_time);

	bubble_sort(arr, N);
	cout << "Отсортированный массив: ";
	for (int a = 0; a < N; a++) {
		cout << arr[a] << ' ';
	};
	cout << endl;
};
//3
void max_min_elems_of_arr_3(int arr[], int not_sort[], int N) {
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start, end;
	nanoseconds result;
	start = steady_clock::now();
	// несортированный массив
	int min = not_sort[0];
	int max = not_sort[0];
	for (int i = 1; i < N; i++) {
		if (not_sort[i] < min) {
			min = not_sort[i];
		}
		if (not_sort[i] > max) {
			max = not_sort[i];
		}

	};
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << result.count() << " наносекунд - время выполенения с несортированным массивом" << endl;
	cout << "Максимальный и минимальный элементы для неотсортированного массива: " << min << ' ' << max << endl;
	// для отсортированного массива
	start = steady_clock::now();
	min = arr[0];
	max = arr[N - 1];
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << result.count() << " наносекунд - время выполненияс сортированным массивом" << endl;
	cout << "Максимальный и минимальный элементы для отсортированного массива: " << min << ' ' << max << endl;

};
//4
void median_of_arr_4(int arr[], int N) {
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start, end;
	nanoseconds result;
	int srednee_znachenie = (arr[0] + arr[N - 1]) / 2;
	cout << "Среднее от min и max " << srednee_znachenie << endl;
	int counter = 0;
	cout << "Под каким номером есть такое же число как среднее: ";
	start = steady_clock::now();
	for (int i = 0; i < N && arr[i] <= srednee_znachenie; i++) {
		if (arr[i] == srednee_znachenie) {
			cout << i << endl;
			counter += 1;
		}

	};
	end = steady_clock::now();

	if (counter == 0) {
		cout << "нет таких элементов массива" << endl;
	}
	else {
		cout << "Всего найдено чисел: " << counter << endl;
	};
	result = duration_cast<nanoseconds>(end - start);
	cout << "Нахождение заданных элементов заняло: " << result.count() << " наносекунд" << endl;
}

//5
void smaller_num_counter_5(int arr[], int N) {
	int num;
	int count = 0;
	cout << "Введите число: ";
	cin >> num;
	for (int i = 0; i < N && arr[i] < num; i++, count++);
	cout << endl;
	cout << "Количсетсво чисел меньше чем " << num << " = " << count << endl;
};
//6
void bigger_num_counter_6(int arr[], int N) {
	int num;
	int count = 0;
	cout << "Введите число: ";
	cin >> num;
	for (int i = N - 1; i >= 0 && arr[i] > num; i--, count++) {};
	cout << endl;
	cout << "Количество чисел больше чем " << num << " = " << count << endl;
};
//7
int binarySearch(int arr[], int value, int start, int end) {
	if (end >= start) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == value) {
			return mid;
		}
		if (arr[mid] > value) {
			return binarySearch(arr, value, start, mid - 1);
		}
		return binarySearch(arr, value, mid + 1, end);
	}
	return -1;
};

void find_number_in_arr_7(int arr[], int N) {
	int num;
	int num_in_arr = 0;
	cout << "Введите число для здания 7: ";
	cin >> num;
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>>start, end;
	nanoseconds result;
	cout << "Полным перебором: ";
	// полный перебор
	start = steady_clock::now();
	for (int a = 0; a < N; a++) {
		if (num == arr[a]) {
			num_in_arr = 1;
			break;
		}
	};
	end = steady_clock::now();
	if (num_in_arr == 1) {
		cout << "Введенное число есть в массиве" << endl;
	}
	else {
		cout << "Введенного числа нет в массиве" << endl;
	}
	result = duration_cast<nanoseconds>(end - start);
	cout << result.count() << " наносекунд - время выполнения обычным перебором" << endl;
	cout << "Бинарным поиском: ";
	start = steady_clock::now();
	// бинарный поиск
	int answer = binarySearch(arr, num, 0, N - 1);
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	if (answer == -1) {
		cout << "Введенного числа нет в массиве" << endl;
	}
	else {
		cout << "Введенное число есть в массиве" << endl;
	}
	cout << result.count() << " наносекунд - время выполнения бинарным поиском" << endl;

};
//8
void change_elems_of_arr_8(int arr[], int N) {
	int elem_index_1;
	int elem_index_2;
	cout << "Введи индексы, которые хочешь поменять в массиве:";
	cin >> elem_index_1;
	cout << endl;
	cin >> elem_index_2;
	swap(arr[elem_index_1], arr[elem_index_2]);
	cout << "Массив с изменнеными значениями " << endl;
	for (int i = 0; i < N; i++) {
		cout << arr[i] << ' ';
	};
	cout << endl;
};
// 5 ИДЗ
void idz(int arr[], int N) {
	int value_to_decrease;
	int counter_even = 0;
	int counter_odd = 0;
	int start_val = 1;
	int end_val = 9;
	srand(time(0));
	cout << "Введите значение для уменьшения четных элементов ";
	cin >> value_to_decrease;
	cout << "Выводим четные элементы, уменьшенные в процессе ";
	int random_value = (rand() % (end_val - start_val + 1) + start_val);
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			// уменьшение на заданное значение
			arr[i] = arr[i] - value_to_decrease;
			cout << arr[i] << ' ';
			// умножение четного на рандомное значение
			arr[i] = arr[i] * random_value;
			if (arr[i] % 2 == 0) {
				counter_even += 1;
			}
		}
		else if (i % 2 != 0 and arr[i] % 2 != 0) {
			counter_odd += 1;
		};
	};
	cout << endl;
	cout << "Выводим массив с четными элементами, умноженными на значение " << random_value << " : ";
	for (int i = 0; i < (N / 2); i++) {
		cout << arr[i] << " ";
	};
	cout << endl;
	cout << "Количество четных элементов имеющих четные значения: " << counter_even << endl;
	cout << "Количество нечетных элементов имеющих нечетные значения: " << counter_odd << endl;
	for (int i = 1; i < 10; i++) {
		int counter_del = 0;
		for (int j = 0; j < N; j++) {
			if (arr[j] % i == 0) {
				counter_del += 1;
			}
		};
		cout << "Количество чисел делящихся на " << i << " = " << counter_del << endl;
	};
};

//1
int main(){
	setlocale(0, "");

	const int N = 100;
	unsigned identificator;
	int Array[N];
	int not_sorted_array[N];
	unsigned int start_val = -99;
	int end_val = 99;
	srand(time(0));
	cout << "Сгенерированный массив: " << endl;
	for (int i = 0; i < N; i++) {
		Array[i] = rand() % (end_val - start_val + 1) + start_val;
		not_sorted_array[i] = Array[i];
		cout << Array[i] << ' ';
	};
	cout << endl;
    cout << "1. Сгенерировать массив заново" << endl;
	cout << "2. Сортировка от меньшего к большему" << endl;
	cout << "3. Поиск минимального и максимального значений" << endl;
	cout << "4. Расчет и поиск среднего значения max и min" << endl;
	cout << "5. Элементы массива меньше заданного числа" << endl;
	cout << "6. Элементы массива больше заданного числа" << endl;
	cout << "7. Найти число в массиве" << endl;
	cout << "8. Поменять элементы с заданными индексами местами" << endl;
	cout << "9. 5 ИДЗ " << endl;
	while (true) {
		cout << "Введите номер задания: ";
		if (!(cin >> identificator)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		switch (identificator) {

		case 1:
			cout << "Новый массив" << endl;
			for (int i = 0; i < N; i++) {
				Array[i] = rand() % (end_val - start_val + 1) + start_val;
				not_sorted_array[i] = Array[i];
				cout << Array[i] << ' ';
			}
			cout << endl;
			break;

		case 2:
			cout << "Сортировка от меньшего к большему" << endl;
			from_small_to_big_2(Array, N);
			break;

		case 3:
			max_min_elems_of_arr_3(Array, not_sorted_array, N);
			break;

		case 4:
			median_of_arr_4(Array, N);
			break;

		case 5:
			smaller_num_counter_5(Array, N);

			break;

		case 6:
			bigger_num_counter_6(Array, N);
			break;

		case 7:
			find_number_in_arr_7(Array, N);
			break;

		case 8:
			change_elems_of_arr_8(Array, N);
			break;
		case 9:
			idz(Array, N);
			break;

		
		}
	}
}