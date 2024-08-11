#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}
bool containsAllPrimes(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		if (!isPrime(arr[i])) return false;
	}
	return true;
}
bool isSymmetric(int arr[], int size) {
	for (int i = 0; i < size / 2; i++) {
		if (arr[i] != arr[size - i - 1]) return false;
	}
	return true;
}
void checkOrder(int arr[], int size) {
	bool increasing = true;
	bool decreasing = true;

	for (int i = 1; i < size; i++) {
		if (arr[i] > arr[i - 1]) decreasing = false;
		if (arr[i] < arr[i - 1]) increasing = false;
	}

	if (increasing) {
		printf("Mang tang dan.\n");
	}
	else if (decreasing) {
		printf("Mang giam dan.\n");
	}
	else {
		printf("Mang khong tang khong giam.\n");
	}
}
int main() {
	int size;

	printf("Nhap so phan tu cua mang: ");
	scanf("%d", &size);

	// Cap phat bo nho cho mang
	int* arr = (int*)malloc(size * sizeof(int));
	if (arr == NULL) {
		printf("Khong the cap phat bo nho.\n");
		return 1;
	}

	// Nhap gia tri cho mang
	printf("Nhap cac phan tu cua mang:\n");
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	// Menu
	int choice;
	do {
		printf("\nMenu:\n");
		printf("1. Kiem tra mang co chua toan so nguyen to khong\n");
		printf("2. Kiem tra mang co doi xung khong\n");
		printf("3. Kiem tra mang co tang dan/giam dan/khong tang khong giam\n");
		printf("4. Thoat\n");
		printf("Nhap lua chon: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			if (containsAllPrimes(arr, size)) {
				printf("Mang chua toan so nguyen to.\n");
			}
			else {
				printf("Mang khong chua toan so nguyen to.\n");
			}
			break;

		case 2:
			if (isSymmetric(arr, size)) {
				printf("Mang doi xung.\n");
			}
			else {
				printf("Mang khong doi xung.\n");
			}
			break;


		case 3:
			
			checkOrder(arr, size);
			break;
		case 4:
			printf("Thoat chuong trinh.\n");
			break;

		default:
			printf("Lua chon khong hop le.\n");
		}

	} while (choice != 4);

	// Giai phong bo nho
	free(arr);

	return 0;
}
