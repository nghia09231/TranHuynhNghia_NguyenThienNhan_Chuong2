#include <stdio.h>

#define MAX_SIZE 50

// Hàm nhập ma trận vuông
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int* n) {
	printf("Nhap kich thuoc ma tran (n): ");
	scanf("%d", n);

	printf("Nhap cac phan tu cua ma tran:\n");
	for (int i = 0; i < *n; i++) {
		for (int j = 0; j < *n; j++) {
			printf("Nhap phan tu a[%d][%d]: ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
}

// Hàm xuất ma trận vuông
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n) {
	printf("Ma tran:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

// Hàm tính tổng các phần tử trên đường chéo chính
int sumMainDiagonal(int matrix[MAX_SIZE][MAX_SIZE], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += matrix[i][i];
	}
	return sum;
}


// Hàm chính
int main() {
	int matrix[MAX_SIZE][MAX_SIZE];
	int n;

	// Nhập ma trận
	inputMatrix(matrix, &n);

	// Xuất ma trận
	printf("Ma tran ban dau:\n");
	printMatrix(matrix, n);

	// Bài 1: Tính tổng các phần tử trên đường chéo chính
	int sumMain = sumMainDiagonal(matrix, n);
	printf("Tong cac phan tu tren duong cheo chinh: %d\n", sumMain);

	

	return 0;
}
