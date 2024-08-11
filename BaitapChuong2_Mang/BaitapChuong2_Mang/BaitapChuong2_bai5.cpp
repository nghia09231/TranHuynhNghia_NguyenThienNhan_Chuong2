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
bool hasAllOddDigits(int n) {
	if (n == 0) return false;
	while (n > 0) {
		int digit = n % 10;
		if (digit % 2 == 0) return false;
		n /= 10;
	}
	return true;
}
bool isAllEven(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 != 0) return false;
	}
	return true;
}
bool isAlternatingEvenOdd(int arr[], int size) {
	if (size < 2) return true; // Dãy rỗng hoặc chỉ có 1 phần tử
	bool expectEven = (arr[0] % 2 == 0);
	for (int i = 1; i < size; i++) {
		if ((arr[i] % 2 == 0) != expectEven) return false;
		expectEven = !expectEven;
	}
	return true;
}

int main() {
	int size;

	printf("Nhap so phan tu cua mang: ");
	scanf_s("%d", &size);

	// Cấp phát bộ nhớ cho mảng
	int* arr = (int*)malloc(size * sizeof(int));
	if (arr == NULL) {
		printf("Khong the cap phat bo nho.\n");
		return 1;
	}

	// Nhập giá trị cho mảng
	printf("Nhap cac phan tu cua mang:\n");
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &arr[i]);
	}

	// Menu
	int choice;
	do {
		printf("\nMenu:\n");
		printf("1. Dem so phan tu la so nguyen to\n");
		printf("2. Xuat cac phan tu ma tung chu so la so le\n");
		printf("3. Tim vi tri so lon nhat (cuoi cung)\n");
		printf("4. Kiem tra mang toan so chan\n");
		printf("5. Kiem tra mang co phai la day so chan le xen ke\n");
		printf("6. Thoat\n");
		printf("Nhap lua chon: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1: {
					int primeCount = 0;
					for (int i = 0; i < size; i++) {
						if (isPrime(arr[i])) {
							primeCount++;
						}
					}
					printf("So phan tu la so nguyen to: %d\n", primeCount);
					break;
		}
		case 2: {
					printf("Cac phan tu ma tung chu so la so le:\n");
					for (int i = 0; i < size; i++) {
						if (hasAllOddDigits(arr[i])) {
							printf("%d ", arr[i]);
						}
					}
					printf("\n");
					break;
		}
		case 3: {
					int maxVal = arr[0];
					int lastIndex = 0;
					for (int i = 1; i < size; i++) {
						if (arr[i] >= maxVal) {
							maxVal = arr[i];
							lastIndex = i;
						}
					}
					printf("Vi tri so lon nhat (cuoi cung): %d\n", lastIndex);
					break;
		}
		case 4: {
					if (isAllEven(arr, size)) {
						printf("Mang toan so chan.\n");
					}
					else {
						printf("Mang khong toan so chan.\n");
					}
					break;
		}
		case 5: {
					if (isAlternatingEvenOdd(arr, size)) {
						printf("Mang la day so chan le xen ke.\n");
					}
					else {
						printf("Mang khong la day so chan le xen ke.\n");
					}
					break;
		}
		case 6:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le.\n");
		}

	} while (choice != 6);

	// Giải phóng bộ nhớ
	free(arr);

	return 0;
}
