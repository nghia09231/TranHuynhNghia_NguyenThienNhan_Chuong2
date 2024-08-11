#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 50

// Hàm kiểm tra số hoàn thiện
int isPerfect(int num) {
	if (num <= 0) return 0;
	int sum = 1;
	for (int i = 2; i <= sqrt((double)num); i++) {
		if (num % i == 0) {
			sum += i;
			if (i != num / i) {
				sum += num / i;
			}
		}
	}
	return sum == num && num != 1;
}

// Hàm kiểm tra số nguyên tố
int isPrime(int num) {
	if (num <= 1) return 0;
	if (num == 2) return 1;
	if (num % 2 == 0) return 0;
	for (int i = 3; i <= sqrt((double)num); i += 2) {
		if (num % i == 0) return 0;
	}
	return 1;
}

// Hàm nhập ma trận
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int* m, int* n) {
	printf("Nhap so dong (m): ");
	scanf("%d", m);
	printf("Nhap so cot (n): ");
	scanf("%d", n);

	printf("Nhap cac phan tu cua ma tran:\n");
	for (int i = 0; i < *m; i++) {
		for (int j = 0; j < *n; j++) {
			printf("Nhap phan tu a[%d][%d]: ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
}

// Hàm xuất ma trận
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int m, int n) {
	printf("Ma tran:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

// Bài 1: Liệt kê các cột có tổng nhỏ nhất trong ma trận
void listColumnsWithMinSum(int matrix[MAX_SIZE][MAX_SIZE], int m, int n) {
	int minSum = 1e9; // Khởi tạo với giá trị lớn
	int columnSum[MAX_SIZE] = { 0 };

	for (int j = 0; j < n; j++) {
		int sum = 0;
		for (int i = 0; i < m; i++) {
			sum += matrix[i][j];
		}
		columnSum[j] = sum;
		if (sum < minSum) {
			minSum = sum;
		}
	}

	printf("Cac cot co tong nho nhat (%d):\n", minSum);
	for (int j = 0; j < n; j++) {
		if (columnSum[j] == minSum) {
			printf("Cot %d\n", j);
		}
	}
}

// Bài 2: Liệt kê các dòng có nhiều số hoàn thiện nhất trong ma trận
void listRowsWithMostPerfectNumbers(int matrix[MAX_SIZE][MAX_SIZE], int m, int n) {
	int maxPerfectCount = 0;
	int perfectCount[MAX_SIZE] = { 0 };

	for (int i = 0; i < m; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (isPerfect(matrix[i][j])) {
				count++;
			}
		}
		perfectCount[i] = count;
		if (count > maxPerfectCount) {
			maxPerfectCount = count;
		}
	}

	printf("Cac dong co nhieu so hoan thien nhat (%d):\n", maxPerfectCount);
	for (int i = 0; i < m; i++) {
		if (perfectCount[i] == maxPerfectCount) {
			printf("Dong %d\n", i);
		}
	}
}

// Bài 3: Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
void listRowsWithAllEven(int matrix[MAX_SIZE][MAX_SIZE], int m, int n) {
	printf("Cac dong chua toan gia tri chan:\n");
	for (int i = 0; i < m; i++) {
		int allEven = 1;
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] % 2 != 0) {
				allEven = 0;
				break;
			}
		}
		if (allEven) {
			printf("Dong %d\n", i);
		}
	}
}

// Bài 4: Tìm giá trị xuất hiện nhiều nhất trong ma trận
void findMostFrequentValue(int matrix[MAX_SIZE][MAX_SIZE], int m, int n) {
	int freq[MAX_SIZE * MAX_SIZE * 2] = { 0 }; // Giả sử giá trị nằm trong phạm vi -MAX_SIZE*MAX_SIZE đến MAX_SIZE*MAX_SIZE
	int maxFreq = 0;
	int mostFrequentValue = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int value = matrix[i][j];
			freq[value + MAX_SIZE * MAX_SIZE]++;
			if (freq[value + MAX_SIZE * MAX_SIZE] > maxFreq) {
				maxFreq = freq[value + MAX_SIZE * MAX_SIZE];
				mostFrequentValue = value;
			}
		}
	}

	printf("Gia tri xuat hien nhieu nhat: %d (xuat hien %d lan)\n", mostFrequentValue, maxFreq);
}

// Bài 5: Tìm số nguyên tố nhỏ nhất trong ma trận
void findSmallestPrime(int matrix[MAX_SIZE][MAX_SIZE], int m, int n) {
	int smallestPrime = 1e9;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (isPrime(matrix[i][j]) && matrix[i][j] < smallestPrime) {
				smallestPrime = matrix[i][j];
			}
		}
	}
	if (smallestPrime == 1e9) {
		printf("Khong co so nguyen to trong ma tran.\n");
	}
	else {
		printf("So nguyen to nho nhat: %d\n", smallestPrime);
	}
}

// Bài 6: Tìm phần tử lớn (nhỏ) nhất trong dòng thứ k
void findExtremaInRow(int matrix[MAX_SIZE][MAX_SIZE], int n, int k, int* min, int* max) {
	*min = matrix[k][0];
	*max = matrix[k][0];
	for (int j = 1; j < n; j++) {
		if (matrix[k][j] < *min) {
			*min = matrix[k][j];
		}
		if (matrix[k][j] > *max) {
			*max = matrix[k][j];
		}
	}
}

// Bài 7: Tìm phần tử lớn (nhỏ) nhất trong cột thứ k
void findExtremaInColumn(int matrix[MAX_SIZE][MAX_SIZE], int m, int k, int* min, int* max) {
	*min = matrix[0][k];
	*max = matrix[0][k];
	for (int i = 1; i < m; i++) {
		if (matrix[i][k] < *min) {
			*min = matrix[i][k];
		}
		if (matrix[i][k] > *max) {
			*max = matrix[i][k];
		}
	}
}

// Hàm chính
int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	int m, n;

	// Nhập ma trận
	inputMatrix(matrix, &m, &n);

	// Xuất ma trận
	printMatrix(matrix, m, n);

	// Bài 1: Liệt kê các cột có tổng nhỏ nhất trong ma trận
	listColumnsWithMinSum(matrix, m, n);

	// Bài 2: Liệt kê các dòng có nhiều số hoàn thiện nhất trong ma trận
	listRowsWithMostPerfectNumbers(matrix, m, n);
	
	// Bài 3: Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
	listRowsWithAllEven(matrix, m, n);

	// Bài 4: Tìm giá trị xuất hiện nhiều nhất trong ma trận
	findMostFrequentValue(matrix, m, n);

	// Bài 5: Tìm số nguyên tố nhỏ nhất trong ma trận
	findSmallestPrime(matrix, m, n);

	// Bài 6: Tìm phần tử lớn (nhỏ) nhất trong dòng thứ k
	int k;
	printf("Nhap chi so dong k: ");
	scanf("%d", &k);
	if (k >= 0 && k < m) {
		int rowMin, rowMax;
		findExtremaInRow(matrix, n, k, &rowMin, &rowMax);
		printf("Trong dong %d:\n", k);
		printf("Gia tri nho nhat: %d\n", rowMin);
		printf("Gia tri lon nhat: %d\n", rowMax);
	}
	else {
		printf("Chi so dong k khong hop le.\n");
	}

	// Bài 7: Tìm phần tử lớn (nhỏ) nhất trong cột thứ k
	printf("Nhap chi so cot k: ");
	scanf("%d", &k);
	if (k >= 0 && k < n) {
		int colMin, colMax;
		findExtremaInColumn(matrix, m, k, &colMin, &colMax);
		printf("Trong cot %d:\n", k);
		printf("Gia tri nho nhat: %d\n", colMin);
		printf("Gia tri lon nhat: %d\n", colMax);
	}
	else {
		printf("Chi so cot k khong hop le.\n");
	}

	return 0;
}
