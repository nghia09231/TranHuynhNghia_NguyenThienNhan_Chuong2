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
				
		}
		case 3: {
				
		}
		case 4: {
				
		}
		case 5: {
			
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
