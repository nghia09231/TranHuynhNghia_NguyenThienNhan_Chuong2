#include <stdio.h>
#include <conio.h>
// Hàm tìm kiếm phần tử trong mảng số nguyên
int timViTri(int x, int arr[], int n) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			return i;
		}
	}
	return -1; // Trả về -1 nếu không tìm thấy
}



int main() {
	int arrSoNguyen[] = { 7, 9, 13, 17, 27, 30, 31, 35, 38, 40 };
	char arrKyTu[] = { 'Z', 'R', 'L', 'K', 'H', 'F', 'E', 'C', 'A' };
	int nSoNguyen = sizeof(arrSoNguyen) / sizeof(arrSoNguyen[0]);
	int nKyTu = sizeof(arrKyTu) / sizeof(arrKyTu[0]);

	// Bài 1
	printf("Bai 1:\n");
	int so1[] = { 17, 35, 40 };
	for (int i = 0; i < sizeof(so1) / sizeof(so1[0]); i++) {
		int viTri = timViTri(so1[i], arrSoNguyen, nSoNguyen);
		if (viTri != -1) {
			printf("Tim thay %d tai vi tri %d\n", so1[i], viTri);
		}
		else {
			printf("Khong tim thay %d trong mang so nguyen\n", so1[i]);
		}
	}

	int so2[] = { 23, 10, 36 };
	printf("\n");
	for (int i = 0; i < sizeof(so2) / sizeof(so2[0]); i++) {
		int viTri = timViTri(so2[i], arrSoNguyen, nSoNguyen);
		if (viTri != -1) {
			printf("Tim thay %d tai vi tri %d\n", so2[i], viTri);
		}
		else {
			printf("Khong tim thay %d trong mang so nguyen\n", so2[i]);
		}
	}


	_getch();
	return 0;
}
