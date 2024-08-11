#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS  

void nhapMang(int a[], int *n) {
	printf("Nhap so phan tu cua mang: ");
	scanf("%d", n);
	for (int i = 0; i < *n; i++) {
		printf("Nhap a[%d]: ", i);
		scanf("%d", &a[i]);
	}
}

void xuatMang(int a[], int n) {
	printf("Cac phan tu cua mang: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
int timMax(int a[], int n) {
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

int timMin(int a[], int n) {
	int min = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;
}

void demChanLe(int a[], int n, int *chan, int *le) {
	*chan = *le = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			(*chan)++;
		}
		else {
			(*le)++;
		}
	}
}
int timKiemTuyenTinh(int a[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			return i;
		}
	}
	return -1;
}
int timKiemNhiPhan(int a[], int n, int x) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] == x) {
			return mid;
		}
		else if (a[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}

int main() {
	int n, m, choice, x;
	int a[100], b[100], c[100], d[200];

	do {
		printf("\nMenu:\n");
		printf("1. Nhap mang\n");
		printf("2. Xuat mang\n");
		printf("3. Tim max, min\n");
		printf("4. Dem so phan tu chan/le\n");
		printf("5. Tim kiem phan tu\n");
		printf("6. Dem so luong phan tu x\n");
		printf("7. Dem so luong phan tu lon hon x\n");
		printf("8. Tinh tong cac phan tu\n");
		printf("9. Xuat so nguyen to\n");
		printf("10. Xuat so hoan thien\n");
		printf("11. Xuat phan tu o vi tri chan/le\n");
		printf("12. Xuat max/min kem theo vi tri\n");
		printf("13. Gop hai day so\n");
		printf("0. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			nhapMang(a, &n);
			break;
		case 2:
			xuatMang(a, n);
			break;
		case 3:
			printf("Max: %d, Min: %d\n", timMax(a, n), timMin(a, n));
			break;
		case 4: {
					int chan, le;
					demChanLe(a, n, &chan, &le);
					printf("So phan tu chan: %d, le: %d\n", chan, le);
					break;
		}
		case 5: {
					int viTriTuyenTinh, viTriNhiPhan;
					printf("Nhap gia tri x can tim: ");
					scanf("%d", &x);
					printf("Tim kiem tuyen tinh:\n");
					viTriTuyenTinh = timKiemTuyenTinh(a, n, x);
					if (viTriTuyenTinh != -1) {
						printf("Tim thay x o vi tri %d\n", viTriTuyenTinh);
					}
					else {
						printf("Khong tim thay x\n");
					}
					printf("Tim kiem nhi phan:\n");
					
					viTriNhiPhan = timKiemNhiPhan(a, n, x);
					if (viTriNhiPhan != -1) {
						printf("Tim thay x o vi tri %d\n", viTriNhiPhan);
					}
					else {
						printf("Khong tim thay x\n");
					}
					break;
		}
		case 6:
			
		case 7:
			
		case 8:
			
		case 9:
			
		case 10:
			
		case 11:

		case 12:
		
		case 13:
		
		case 0:
		
		default:
			printf("Lua chon khong hop le!\n");
			break;
		}
	} while (choice != 0);

	return 0;
}