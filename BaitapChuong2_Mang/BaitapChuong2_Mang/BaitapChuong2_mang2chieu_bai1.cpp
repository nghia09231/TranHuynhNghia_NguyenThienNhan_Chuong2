#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50  // Đảm bảo rằng MAX_SIZE được khai báo

// Cấu trúc phân số
typedef struct {
	int numerator;   // Tử số
	int denominator; // Mẫu số
} Fraction;

// Hàm nhập một phân số
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

// Hàm xuất một phân số
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

// Hàm tính giá trị của phân số
double getFractionValue(Fraction frac) {
	return (double)frac.numerator / frac.denominator;
}

// Hàm nhập danh sách các phân số
void inputFractionArray(Fraction arr[], int* n) {
	printf("Nhap so phan tu cua mang (n <= %d): ", MAX_SIZE);
	scanf_s("%d", n);

	if (*n > MAX_SIZE) {
		printf("So phan tu vuot qua gioi han cho phep.\n");
		*n = MAX_SIZE; // Cắt giảm số lượng phần tử nếu vượt quá giới hạn
	}

	for (int i = 0; i < *n; i++) {
		printf("Nhap phan so thu %d:\n", i + 1);
		inputFraction(&arr[i]);
		simplifyFraction(&arr[i]);
	}
}

// Hàm xuất danh sách các phân số
void printFractionArray(Fraction arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Phan so thu %d: ", i + 1);
		printFraction(arr[i]);
	}
}

// Hàm tìm phân số có giá trị lớn nhất
Fraction findMaxFraction(Fraction arr[], int n) {
	Fraction max = arr[0];
	for (int i = 1; i < n; i++) {
		if (getFractionValue(arr[i]) > getFractionValue(max)) {
			max = arr[i];
		}
	}
	return max;
}

// Hàm tìm phân số có giá trị nhỏ nhất
Fraction findMinFraction(Fraction arr[], int n) {
	Fraction min = arr[0];
	for (int i = 1; i < n; i++) {
		if (getFractionValue(arr[i]) < getFractionValue(min)) {
			min = arr[i];
		}
	}
	return min;
}

// Hàm tính tổng các phân số
Fraction addFractions(Fraction a, Fraction b) {
	Fraction result;
	result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
	result.denominator = a.denominator * b.denominator;
	simplifyFraction(&result);
	return result;
}

// Hàm tính tích các phân số
Fraction multiplyFractions(Fraction a, Fraction b) {
	Fraction result;
	result.numerator = a.numerator * b.numerator;
	result.denominator = a.denominator * b.denominator;
	simplifyFraction(&result);
	return result;
}

// Hàm xuất nghịch đảo các phân số
void printInverseFractions(Fraction arr[], int n) {
	for (int i = 0; i < n; i++) {
		Fraction inv;
		inv.numerator = arr[i].denominator;
		inv.denominator = arr[i].numerator;
		simplifyFraction(&inv);
		printf("Nghich dao phan so thu %d: ", i + 1);
		printFraction(inv);
	}
}

// Hàm sắp xếp mảng phân số theo thứ tự tăng dần
void sortFractionsAscending(Fraction arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (getFractionValue(arr[i]) > getFractionValue(arr[j])) {
				Fraction temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

// Hàm sắp xếp mảng phân số theo thứ tự giảm dần
void sortFractionsDescending(Fraction arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (getFractionValue(arr[i]) < getFractionValue(arr[j])) {
				Fraction temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

// Hàm chính
int main() {
	Fraction arr[MAX_SIZE];
	int n;

	inputFractionArray(arr, &n);
	printFractionArray(arr, n);

	Fraction max = findMaxFraction(arr, n);
	printf("Phan so co gia tri lon nhat: ");
	printFraction(max);

	Fraction min = findMinFraction(arr, n);
	printf("Phan so co gia tri nho nhat: ");
	printFraction(min);

	Fraction sum = arr[0];
	Fraction product = arr[0];
	for (int i = 1; i < n; i++) {
		sum = addFractions(sum, arr[i]);
		product = multiplyFractions(product, arr[i]);
	}

	printf("Tong cac phan so: ");
	printFraction(sum);

	printf("Tich cac phan so: ");
	printFraction(product);

	printf("Nghich dao cac phan so:\n");
	printInverseFractions(arr, n);

	printf("Mang phan so sap xep tang dan:\n");
	sortFractionsAscending(arr, n);
	printFractionArray(arr, n);

	printf("Mang phan so sap xep giam dan:\n");
	sortFractionsDescending(arr, n);
	printFractionArray(arr, n);

	return 0;
}
