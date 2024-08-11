#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

// Hàm nhập ma trận
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int* n, int* m) {
	printf("Nhap so dong (n): ");
	scanf("%d", n);
	printf("Nhap so cot (m): ");
	scanf("%d", m);

	printf("Nhap cac phan tu cua ma tran:\n");
	for (int i = 0; i < *n; i++) {
		for (int j = 0; j < *m; j++) {
			printf("Nhap phan tu a[%d][%d]: ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
}

// Hàm xuất ma trận
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n, int m) {
	printf("Ma tran:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

// Hàm so sánh để sắp xếp tăng dần
int compareAsc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

// Hàm so sánh để sắp xếp giảm dần
int compareDesc(const void* a, const void* b) {
	return (*(int*)b - *(int*)a);
}

// Hàm sắp xếp các phần tử trong dòng chẵn tăng và dòng lẻ giảm
void sortRows(int matrix[MAX_SIZE][MAX_SIZE], int n, int m) {
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) { // Dòng chẵn
			qsort(matrix[i], m, sizeof(int), compareAsc);
		}
		else { // Dòng lẻ
			qsort(matrix[i], m, sizeof(int), compareDesc);
		}
	}
}

// Hàm sắp xếp các phần tử trong cột chẵn tăng và cột lẻ giảm
void sortColumns(int matrix[MAX_SIZE][MAX_SIZE], int n, int m) {
	for (int j = 0; j < m; j++) {
		int column[MAX_SIZE];
		for (int i = 0; i < n; i++) {
			column[i] = matrix[i][j];
		}
		if (j % 2 == 0) { // Cột chẵn
			qsort(column, n, sizeof(int), compareAsc);
		}
		else { // Cột lẻ
			qsort(column, n, sizeof(int), compareDesc);
		}
		for (int i = 0; i < n; i++) {
			matrix[i][j] = column[i];
		}
	}
}

// Hàm sắp xếp ma trận zic-zac
void sortZigzag(int matrix[MAX_SIZE][MAX_SIZE], int n, int m) {
	int temp[MAX_SIZE * MAX_SIZE];
	int idx = 0;

	// Lưu các phần tử vào mảng tạm
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[idx++] = matrix[i][j];
		}
	}

	// Sắp xếp mảng tạm
	qsort(temp, n * m, sizeof(int), compareAsc);

	// Đưa các phần tử vào ma trận theo kiểu zic-zac
	idx = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < m; j++) {
				matrix[i][j] = temp[idx++];
			}
		}
		else {
			for (int j = m - 1; j >= 0; j--) {
				matrix[i][j] = temp[idx++];
			}
		}
	}
}

// Hàm chính
int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	int n, m;

	// Nhập ma trận
	inputMatrix(matrix, &n, &m);

	// Xuất ma trận
	printf("Ma tran ban dau:\n");
	printMatrix(matrix, n, m);

	// Bài 1: Sắp xếp các phần tử trong ma trận sao cho dòng chẵn tăng và dòng lẻ giảm
	sortRows(matrix, n, m);
	printf("Ma tran sau khi sap xep theo dong:\n");
	printMatrix(matrix, n, m);

	// Nhập lại ma trận
	inputMatrix(matrix, &n, &m);

	// Xuất ma trận
	printf("Ma tran ban dau:\n");
	printMatrix(matrix, n, m);

	// Bài 2: Sắp xếp các phần tử trong ma trận sao cho cột chẵn tăng và cột lẻ giảm
	sortColumns(matrix, n, m);
	printf("Ma tran sau khi sap xep theo cot:\n");
	printMatrix(matrix, n, m);

	// Nhập lại ma trận
	inputMatrix(matrix, &n, &m);

	// Xuất ma trận
	printf("Ma tran ban dau:\n");
	printMatrix(matrix, n, m);

	// Bài 3: Sắp xếp ma trận tăng dần/giảm dần theo zic-zac
	sortZigzag(matrix, n, m);
	printf("Ma tran sau khi sap xep zic-zac:\n");
	printMatrix(matrix, n, m);

	return 0;
}
