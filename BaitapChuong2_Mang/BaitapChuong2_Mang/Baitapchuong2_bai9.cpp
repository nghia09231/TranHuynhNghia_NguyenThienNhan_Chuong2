#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 50

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

// Hàm lấy chữ số đầu tiên
int getFirstDigit(int num) {
	if (num < 0) num = -num;
	while (num >= 10) {
		num /= 10;
	}
	return num;
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

// Bài 1: Tính tổng các phần tử có chữ số đầu là chữ số lẻ
int sumOddFirstDigit(int matrix[MAX_SIZE][MAX_SIZE], int m, int n) {
	int sum = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (getFirstDigit(matrix[i][j]) % 2 != 0) {
				sum += matrix[i][j];
			}
		}
	}
	return sum;
}

// Bài 2: Liệt kê các số hoàn thiện trong ma trận
void listPerfectNumbers(int matrix[MAX_SIZE][MAX_SIZE], int m, int n) {
	printf("Cac so hoan thien trong ma tran:\n");
	int found = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (isPerfect(matrix[i][j])) {
				printf("%d ", matrix[i][j]);
				found = 1;
			}
		}
	}
	if (!found) {
		printf("Khong co so hoan thien trong ma tran.\n");
	}
	printf("\n");
}

// Bài 3: Tính tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó
int sumLargerThanNextAbs(int matrix[MAX_SIZE][MAX_SIZE], int m, int n) {
	int sum = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (matrix[i][j] > abs(matrix[i][j + 1])) {
				sum += matrix[i][j];
			}
		}
	}
	return sum;
}


// Hàm chính
int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	int m, n;

	// Nhập ma trận
	inputMatrix(matrix, &m, &n);

	// Xuất ma trận
	printMatrix(matrix, m, n);

	// Bài 1: Tính tổng các phần tử có chữ số đầu là chữ số lẻ
	int sumOdd = sumOddFirstDigit(matrix, m, n);
	printf("Tong cac phan tu co chu so dau la chu so le: %d\n", sumOdd);
	
	// Bài 2: Liệt kê các số hoàn thiện trong ma trận
	listPerfectNumbers(matrix, m, n);

	// Bài 3: Tính tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó
	int sumLargerNextAbs = sumLargerThanNextAbs(matrix, m, n);
	printf("Tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau: %d\n", sumLargerNextAbs);

	return 0;
}
