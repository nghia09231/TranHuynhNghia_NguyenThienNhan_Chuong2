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
			
		case 4: {
				
		}
		case 5: {
				
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