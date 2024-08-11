#include <stdio.h>
#include <stdlib.h> // Thêm thư viện này để sử dụng hàm abs

// Cấu trúc phân số
typedef struct {
	int numerator;   // Tử số
	int denominator; // Mẫu số
} Fraction;

// Hàm nhập phân số
void inputFraction(Fraction* frac) {
	printf("Nhap tu so: ");
	scanf_s("%d", &frac->numerator);
	do {
		printf("Nhap mau so (khac 0): ");
		scanf_s("%d", &frac->denominator);
		if (frac->denominator == 0) {
			printf("Mau so phai khac 0. Vui long nhap lai.\n");
		}
	} while (frac->denominator == 0);
}


int main() {
	Fraction frac1, frac2, result;
	int choice;

	do {
		printf("\nMenu:\n");
		printf("1. Nhap hai phan so\n");
		printf("2. Tinh tong hai phan so\n");
		printf("3. Tinh hieu hai phan so\n");
		printf("4. Tinh tich hai phan so\n");
		printf("5. Tinh thuong hai phan so\n");
		printf("6. Thoat\n");
		printf("Nhap lua chon: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("Nhap phan so thu nhat:\n");
			inputFraction(&frac1);
			printf("Nhap phan so thu hai:\n");
			inputFraction(&frac2);
			break;
		case 2:			
			break;
		case 3:			
			break;
		case 4:			
			break;
		case 5:			
			break;
		case 6:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long nhap lai.\n");
			break;
		}
	} while (choice != 6);

	return 0;
}
