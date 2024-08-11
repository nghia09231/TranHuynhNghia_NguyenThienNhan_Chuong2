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
int demSoLuongPhanTuX(int a[], int n, int x) {
	int dem = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			dem++;
		}
	}
	return dem;
}
int demSoLuongLonHonX(int a[], int n, int x) {
	int dem = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > x) {
			dem++;
		}
	}
	return dem;
}
int tongCacPhanTu(int a[], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		tong += a[i];
	}
	return tong;
}
bool laSoNguyenTo(int x) {
	if (x < 2) return false;
	for (int i = 2; i <= (int)sqrt((double)x); i++) {  
		if (x % i == 0) return false;
	}
	return true;
}

void xuatSoNguyenTo(int a[], int n) {
	printf("Cac so nguyen to trong mang: ");
	for (int i = 0; i < n; i++) {
		if (laSoNguyenTo(a[i])) {
			printf("%d ", a[i]);
		}
	}
	printf("\n");
}
bool laSoHoanThien(int x) {
	if (x < 1) return false;
	int tong = 0;
	for (int i = 1; i <= x / 2; i++) {
		if (x % i == 0) {
			tong += i;
		}
	}
	return tong == x;
}

void xuatSoHoanThien(int a[], int n) {
	printf("Cac so hoan thien trong mang: ");
	for (int i = 0; i < n; i++) {
		if (laSoHoanThien(a[i])) {
			printf("%d ", a[i]);
		}
	}
	printf("\n");
}
void xuatViTriChanLe(int a[], int n) {
	printf("Cac phan tu o vi tri chan: ");
	for (int i = 0; i < n; i += 2) {
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("Cac phan tu o vi tri le: ");
	for (int i = 1; i < n; i += 2) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
void xuatMaxMinKemViTri(int a[], int n) {
	int max = timMax(a, n);
	int min = timMin(a, n);
	printf("Gia tri max: %d o vi tri: ", max);
	for (int i = 0; i < n; i++) {
		if (a[i] == max) {
			printf("%d ", i);
		}
	}
	printf("\nGia tri min: %d o vi tri: ", min);
	for (int i = 0; i < n; i++) {
		if (a[i] == min) {
			printf("%d ", i);
		}
	}
	printf("\n");
}
void gopMang(int b[], int m, int c[], int n, int a[]) {
	int i = 0, j = 0, k = 0;
	while (i < m && j < n) {
		if (b[i] < c[j]) {
			a[k++] = b[i++];
		}
		else {
			a[k++] = c[j++];
		}
	}
	while (i < m) {
		a[k++] = b[i++];
	}
	while (j < n) {
		a[k++] = c[j++];
	}
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
			printf("Nhap gia tri x: ");
			scanf("%d", &x);
			printf("So luong phan tu bang %d la: %d\n", x, demSoLuongPhanTuX(a, n, x));
			break;
		case 7:
			printf("Nhap gia tri x: ");
			scanf("%d", &x);
			printf("So luong phan tu lon hon %d la: %d\n", x, demSoLuongLonHonX(a, n, x));
			break;
		case 8:
			printf("Tong cac phan tu cua mang la: %d\n", tongCacPhanTu(a, n));
			break;
		case 9:
			xuatSoNguyenTo(a, n);
			break;
		case 10:
			xuatSoHoanThien(a, n);
			break;
		case 11:
			xuatViTriChanLe(a, n);
			break;
		case 12:
			xuatMaxMinKemViTri(a, n);
			break;
		case 13:
			printf("Nhap so phan tu cua mang b: ");
			scanf("%d", &m);
			nhapMang(b, &m);
			printf("Nhap so phan tu cua mang c: ");
			scanf("%d", &n);
			nhapMang(c, &n);
			gopMang(b, m, c, n, d);
			printf("Mang sau khi gop va sap xep: ");
			xuatMang(d, m + n);
			break;
		case 0:
		
		default:
			printf("Lua chon khong hop le!\n");
			break;
		}
	} while (choice != 0);

	return 0;
}