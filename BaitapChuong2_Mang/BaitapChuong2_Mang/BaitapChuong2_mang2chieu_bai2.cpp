#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define FILENAME "students.txt"

// Cấu trúc thông tin sinh viên
typedef struct {
	int id;
	char studentCode[15];
	char name[50];
	float essayScore;
	float finalExamScore;
	float totalScore;
} Student;

// Hàm nhập thông tin sinh viên
void inputStudent(Student* stu) {
	printf("Nhap so thu tu: ");
	scanf_s("%d", &stu->id);

	printf("Nhap ma so sinh vien: ");
	scanf_s("%s", stu->studentCode, (unsigned)_countof(stu->studentCode));

	printf("Nhap ho ten sinh vien: ");
	scanf_s(" %[^\n]", stu->name, (unsigned)_countof(stu->name));

	printf("Nhap diem tieu luan: ");
	scanf_s("%f", &stu->essayScore);

	printf("Nhap diem thi ket thuc mon: ");
	scanf_s("%f", &stu->finalExamScore);

	// Tính điểm tổng kết
	stu->totalScore = 0.3 * stu->essayScore + 0.7 * stu->finalExamScore;
}

// Hàm xuất thông tin sinh viên
void printStudent(Student stu) {
	printf("So thu tu: %d\n", stu.id);
	printf("Ma so sinh vien: %s\n", stu.studentCode);
	printf("Ho ten sinh vien: %s\n", stu.name);
	printf("Diem tieu luan: %.2f\n", stu.essayScore);
	printf("Diem thi ket thuc mon: %.2f\n", stu.finalExamScore);
	printf("Diem tong ket: %.2f\n", stu.totalScore);
}

// Hàm nhập danh sách sinh viên từ bàn phím
void inputStudentList(Student students[], int* n) {
	printf("Nhap so sinh vien (n <= %d): ", MAX_STUDENTS);
	scanf_s("%d", n);

	if (*n > MAX_STUDENTS) {
		printf("So sinh vien vuot qua gioi han cho phep.\n");
		*n = MAX_STUDENTS;
	}

	for (int i = 0; i < *n; i++) {
		printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
		inputStudent(&students[i]);
	}
}

// Hàm xuất danh sách sinh viên
void printStudentList(Student students[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Thong tin sinh vien thu %d:\n", i + 1);
		printStudent(students[i]);
		printf("\n");
	}
}

// Hàm tìm sinh viên có điểm tổng kết cao nhất
Student findMaxScoreStudent(Student students[], int n) {
	Student max = students[0];
	for (int i = 1; i < n; i++) {
		if (students[i].totalScore > max.totalScore) {
			max = students[i];
		}
	}
	return max;
}

// Hàm tìm sinh viên có điểm tổng kết thấp nhất
Student findMinScoreStudent(Student students[], int n) {
	Student min = students[0];
	for (int i = 1; i < n; i++) {
		if (students[i].totalScore < min.totalScore) {
			min = students[i];
		}
	}
	return min;
}

// Hàm đếm số sinh viên đạt và không đạt
void countPassFail(Student students[], int n, int* pass, int* fail) {
	*pass = *fail = 0;
	for (int i = 0; i < n; i++) {
		if (students[i].totalScore >= 5.0) { // Giả sử điểm đạt là >= 5.0
			(*pass)++;
		}
		else {
			(*fail)++;
		}
	}
}

// Hàm qui đổi điểm từ hệ 10 sang hệ 4
float convertTo4Scale(float score) {
	if (score >= 8.5) return 4.0;
	if (score >= 7.0) return 3.5;
	if (score >= 5.5) return 3.0;
	if (score >= 4.0) return 2.0;
	return 1.0;
}

// Hàm xuất điểm qui đổi
void printConvertedScores(Student students[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Sinh vien %d: diem tong ket: %.2f, diem he 4: %.2f\n",
			students[i].id,
			students[i].totalScore,
			convertTo4Scale(students[i].totalScore));
	}
}

// Hàm sắp xếp sinh viên theo điểm tổng kết tăng dần
void sortStudentsAscending(Student students[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (students[i].totalScore > students[j].totalScore) {
				Student temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
}

// Hàm sắp xếp sinh viên theo điểm tổng kết giảm dần
void sortStudentsDescending(Student students[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (students[i].totalScore < students[j].totalScore) {
				Student temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
}

// Hàm tính điểm trung bình
float calculateAverageScore(Student students[], int n) {
	float total = 0;
	for (int i = 0; i < n; i++) {
		total += students[i].totalScore;
	}
	return total / n;
}

// Hàm lưu danh sách sinh viên vào file
void saveToFile(Student students[], int n) {
	FILE* file = fopen(FILENAME, "w");
	if (file == NULL) {
		printf("Khong the mo file.\n");
		return;
	}

	for (int i = 0; i < n; i++) {
		fprintf(file, "%d %s %s %.2f %.2f %.2f\n",
			students[i].id,
			students[i].studentCode,
			students[i].name,
			students[i].essayScore,
			students[i].finalExamScore,
			students[i].totalScore);
	}

	fclose(file);
}

// Hàm đọc danh sách sinh viên từ file
void readFromFile(Student students[], int* n) {
	FILE* file = fopen("/Text.txt", "r");
	if (file == NULL) {
		printf("Khong the mo file.\n");
		return;
	}

	*n = 0;
	while (fscanf(file, "%d %s %s %f %f %f",
		&students[*n].id,
		students[*n].studentCode,
		students[*n].name,
		&students[*n].essayScore,
		&students[*n].finalExamScore,
		&students[*n].totalScore) == 6) {
		(*n)++;
	}

	fclose(file);
}

// Hàm chính
int main() {
	Student students[MAX_STUDENTS];
	int n, pass, fail;

	// Nhập danh sách sinh viên từ bàn phím
	inputStudentList(students, &n);

	// Lưu danh sách sinh viên vào file
	saveToFile(students, n);

	// Đọc danh sách sinh viên từ file
	readFromFile(students, &n);

	// Xuất danh sách sinh viên
	printStudentList(students, n);

	// Tìm và in ra sinh viên có điểm cao nhất và thấp nhất
	Student maxStudent = findMaxScoreStudent(students, n);
	printf("Sinh vien co diem tong ket cao nhat:\n");
	printStudent(maxStudent);

	Student minStudent = findMinScoreStudent(students, n);
	printf("Sinh vien co diem tong ket thap nhat:\n");
	printStudent(minStudent);

	// Đếm số sinh viên đạt và không đạt
	countPassFail(students, n, &pass, &fail);
	printf("So sinh vien dat: %d\n", pass);
	printf("So sinh vien khong dat: %d\n", fail);

	// In điểm qui đổi
	printConvertedScores(students, n);

	// Sắp xếp và in danh sách sinh viên theo điểm tổng kết
	sortStudentsAscending(students, n);
	printf("Danh sach sinh vien theo diem tang dan:\n");
	printStudentList(students, n);

	sortStudentsDescending(students, n);
	printf("Danh sach sinh vien theo diem giam dan:\n");
	printStudentList(students, n);

	// Tính và in điểm trung bình
	float averageScore = calculateAverageScore(students, n);
	printf("Diem trung binh: %.2f\n", averageScore);

	return 0;
}
