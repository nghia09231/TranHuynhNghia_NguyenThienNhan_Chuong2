#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void swapInt(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


void swapFloat(float* a, float* b) {
	float temp = *a;
	*a = *b;
	*b = temp;
}

void swapChar(char* a, char* b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

void swapString(char* a, char* b) {
	char temp[100];
	strcpy_s(temp, sizeof(temp), a);
	strcpy_s(a, sizeof(temp), b);
	strcpy_s(b, sizeof(temp), temp);
}

void interchangeSortIntAsc(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				swapInt(&arr[i], &arr[j]);
			}
		}
	}
}
void interchangeSortIntDesc(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] < arr[j]) {
				swapInt(&arr[i], &arr[j]);
			}
		}
	}
}
void interchangeSortFloatAsc(float* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				swapFloat(&arr[i], &arr[j]);
			}
		}
	}
}
void interchangeSortFloatDesc(float* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] < arr[j]) {
				swapFloat(&arr[i], &arr[j]);
			}
		}
	}
}
void interchangeSortCharAsc(char* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				swapChar(&arr[i], &arr[j]);
			}
		}
	}
}
void interchangeSortCharDesc(char* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] < arr[j]) {
				swapChar(&arr[i], &arr[j]);
			}
		}
	}
}
void interchangeSortStringAsc(char arr[][100], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strcmp(arr[i], arr[j]) > 0) {
				swapString(arr[i], arr[j]);
			}
		}
	}
}
void interchangeSortStringDesc(char arr[][100], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strcmp(arr[i], arr[j]) < 0) {
				swapString(arr[i], arr[j]);
			}
		}
	}
}

void displayIntArray(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void displayFloatArray(float* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%f ", arr[i]);
	}
	printf("\n");
}
void displayCharArray(char* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%c ", arr[i]);
	}
	printf("\n");
}
void displayStringArray(char arr[][100], int n) {
	for (int i = 0; i < n; i++) {
		printf("%s\n", arr[i]);
	}
}
void menu() {
	int choice;
	do {
		printf("Menu:\n");
		printf("1. Sap xep tang dan mang so nguyen\n");
		printf("2. Sap xep giam dan mang so nguyen\n");
		printf("3. Sap xep tang dan mang so thuc\n");
		printf("4. Sap xep giam dan mang so thuc\n");
		printf("5. Sap xep tang dan mang ky tu\n");
		printf("6. Sap xep giam dan mang ky tu\n");
		printf("7. Sap xep tang dan mang chuoi\n");
		printf("8. Sap xep giam dan mang chuoi\n");
		printf("0. Thoat\n");
		printf("Nhap lua chon: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1: {
					int n;
					printf("Nhap so phan tu: ");
					scanf_s("%d", &n);
					int* arr = (int*)malloc(n * sizeof(int));
					if (arr == NULL) {
						printf("Khong the cap phat bo nho!\n");
						return;
					}
					printf("Nhap cac phan tu:\n");
					for (int i = 0; i < n; i++) {
						scanf_s("%d", &arr[i]);
					}
					interchangeSortIntAsc(arr, n);
					printf("Mang sau khi sap xep tang dan: ");
					displayIntArray(arr, n);
					free(arr);
					break;
		}
		case 2: {
					int n;
					printf("Nhap so phan tu: ");
					scanf_s("%d", &n);
					int* arr = (int*)malloc(n * sizeof(int));
					if (arr == NULL) {
						printf("Khong the cap phat bo nho!\n");
						return;
					}
					printf("Nhap cac phan tu:\n");
					for (int i = 0; i < n; i++) {
						scanf_s("%d", &arr[i]);
					}
					interchangeSortIntDesc(arr, n);
					printf("Mang sau khi sap xep giam dan: ");
					displayIntArray(arr, n);
					free(arr);
					break;
		}
		case 3: {
					int n;
					printf("Nhap so phan tu: ");
					scanf_s("%d", &n);
					float* arr = (float*)malloc(n * sizeof(float));
					if (arr == NULL) {
						printf("Khong the cap phat bo nho!\n");
						return;
					}
					printf("Nhap cac phan tu:\n");
					for (int i = 0; i < n; i++) {
						scanf_s("%f", &arr[i]);
					}
					interchangeSortFloatAsc(arr, n);
					printf("Mang sau khi sap xep tang dan: ");
					displayFloatArray(arr, n);
					free(arr);
					break;
		}
		case 4: {
					int n;
					printf("Nhap so phan tu: ");
					scanf_s("%d", &n);
					float* arr = (float*)malloc(n * sizeof(float));
					if (arr == NULL) {
						printf("Khong the cap phat bo nho!\n");
						return;
					}
					printf("Nhap cac phan tu:\n");
					for (int i = 0; i < n; i++) {
						scanf_s("%f", &arr[i]);
					}
					interchangeSortFloatDesc(arr, n);
					printf("Mang sau khi sap xep giam dan: ");
					displayFloatArray(arr, n);
					free(arr);
					break;
		}
		case 5: {
					int n;
					printf("Nhap so phan tu: ");
					scanf_s("%d", &n);
					char* arr = (char*)malloc(n * sizeof(char));
					if (arr == NULL) {
						printf("Khong the cap phat bo nho!\n");
						return;
					}
					printf("Nhap cac ky tu:\n");
					for (int i = 0; i < n; i++) {
						scanf_s(" %c", &arr[i]);
					}
					interchangeSortCharAsc(arr, n);
					printf("Mang sau khi sap xep tang dan: ");
					displayCharArray(arr, n);
					free(arr);
					break;
		}
		case 6: {
					int n;
					printf("Nhap so phan tu: ");
					scanf_s("%d", &n);
					char* arr = (char*)malloc(n * sizeof(char));
					if (arr == NULL) {
						printf("Khong the cap phat bo nho!\n");
						return;
					}
					printf("Nhap cac ky tu:\n");
					for (int i = 0; i < n; i++) {
						scanf_s(" %c", &arr[i]);
					}
					interchangeSortCharDesc(arr, n);
					printf("Mang sau khi sap xep giam dan: ");
					displayCharArray(arr, n);
					free(arr);
					break;
		}
		case 7: {
					int n;
					printf("Nhap so phan tu: ");
					scanf_s("%d", &n);
					char(*arr)[100] = (char(*)[100])malloc(n * sizeof(*arr));
					if (arr == NULL) {
						printf("Khong the cap phat bo nho!\n");
						return;
					}
					printf("Nhap cac chuoi:\n");
					for (int i = 0; i < n; i++) {
						printf("Nhap chuoi thu %d: ", i + 1);
						scanf_s(" %99[^\n]", arr[i], (unsigned)_countof(arr[i]));
					}
					interchangeSortStringAsc(arr, n);
					printf("Mang sau khi sap xep tang dan:\n");
					displayStringArray(arr, n);
					free(arr);
					break;
		}
		case 8: {
					int n;
					printf("Nhap so phan tu: ");
					scanf_s("%d", &n);
					char(*arr)[100] = (char(*)[100])malloc(n * sizeof(*arr));
					if (arr == NULL) {
						printf("Khong the cap phat bo nho!\n");
						return;
					}
					printf("Nhap cac chuoi:\n");
					for (int i = 0; i < n; i++) {
						printf("Nhap chuoi thu %d: ", i + 1);
						scanf_s(" %99[^\n]", arr[i], (unsigned)_countof(arr[i]));
					}
					interchangeSortStringDesc(arr, n);
					printf("Mang sau khi sap xep giam dan:\n");
					displayStringArray(arr, n);
					free(arr);
					break;
		}
		case 0:
			printf("Thoat!\n");
			break;
		default:
			printf("Lua chon khong hop le!\n");
			break;
		}
	} while (choice != 0);
}

int main() {
	menu();
	return 0;
}