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

// Hàm xuất phân số
void printFraction(Fraction frac) {
	if (frac.denominator < 0) { // Đưa dấu âm về tử số
		frac.numerator = -frac.numerator;
		frac.denominator = -frac.denominator;
	}
	if (frac.denominator == 1) {
		printf("%d\n", frac.numerator); // Xuất dưới dạng số nguyên nếu mẫu số là 1
	}
	else {
		printf("%d/%d\n", frac.numerator, frac.denominator);
	}
}

// Hàm tìm ước số chung lớn nhất
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// Hàm tối giản phân số
void simplifyFraction(Fraction* frac) {
	int gcdValue = gcd(abs(frac->numerator), abs(frac->denominator));
	frac->numerator /= gcdValue;
	frac->denominator /= gcdValue;
}

// Hàm cộng hai phân số
Fraction addFractions(Fraction frac1, Fraction frac2) {
	Fraction result;
	result.numerator = frac1.numerator * frac2.denominator + frac2.numerator * frac1.denominator;
	result.denominator = frac1.denominator * frac2.denominator;
	simplifyFraction(&result);
	return result;
}

// Hàm trừ hai phân số
Fraction subtractFractions(Fraction frac1, Fraction frac2) {
	Fraction result;
	result.numerator = frac1.numerator * frac2.denominator - frac2.numerator * frac1.denominator;
	result.denominator = frac1.denominator * frac2.denominator;
	simplifyFraction(&result);
	return result;
}

// Hàm nhân hai phân số
Fraction multiplyFractions(Fraction frac1, Fraction frac2) {
	Fraction result;
	result.numerator = frac1.numerator * frac2.numerator;
	result.denominator = frac1.denominator * frac2.denominator;
	simplifyFraction(&result);
	return result;
}

// Hàm chia hai phân số
Fraction divideFractions(Fraction frac1, Fraction frac2) {
	Fraction result;
	result.numerator = frac1.numerator * frac2.denominator;
	result.denominator = frac1.denominator * frac2.numerator;
	simplifyFraction(&result);
	return result;
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
			result = addFractions(frac1, frac2);
			printf("Tong hai phan so la: ");
			printFraction(result);
			break;
		case 3:			
			result = subtractFractions(frac1, frac2);
			printf("Hieu hai phan so la: ");
			printFraction(result);
			break;
		case 4:			
			result = multiplyFractions(frac1, frac2);
			printf("Tich hai phan so la: ");
			printFraction(result);
			break;
		case 5:			
			result = divideFractions(frac1, frac2);
			printf("Thuong hai phan so la: ");
			printFraction(result);
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
