#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_SUBJECTS 5

// Cấu trúc thông tin môn học
typedef struct {
	char code[10];
	char name[50];
	int credits;
	float score;
} Subject;

// Cấu trúc thông tin sinh viên
typedef struct {
	char studentCode[15];
	char name[50];
	Subject subjects[MAX_SUBJECTS];
	float averageScore;
} Student;

// Hàm nhập thông tin môn học
void inputSubject(Subject* sub) {
	printf("Nhap ma mon: ");
	scanf_s("%s", sub->code, (unsigned)_countof(sub->code));

	printf("Nhap ten mon: ");
	scanf_s(" %[^\n]", sub->name, (unsigned)_countof(sub->name));

	printf("Nhap so tin chi: ");
	scanf_s("%d", &sub->credits);

	printf("Nhap diem: ");
	scanf_s("%f", &sub->score);
}

// Hàm nhập thông tin sinh viên
void inputStudent(Student* stu) {
	printf("Nhap ma so sinh vien: ");
	scanf_s("%s", stu->studentCode, (unsigned)_countof(stu->studentCode));

	printf("Nhap ho ten sinh vien: ");
	scanf_s(" %[^\n]", stu->name, (unsigned)_countof(stu->name));

	for (int i = 0; i < MAX_SUBJECTS; i++) {
		printf("Nhap thong tin mon hoc %d:\n", i + 1);
		inputSubject(&stu->subjects[i]);
	}

	// Tính điểm trung bình
	float totalScore = 0;
	int totalCredits = 0;
	for (int i = 0; i < MAX_SUBJECTS; i++) {
		totalScore += stu->subjects[i].score * stu->subjects[i].credits;
		totalCredits += stu->subjects[i].credits;
	}
	stu->averageScore = totalCredits > 0 ? totalScore / totalCredits : 0;
}

// Hàm xuất thông tin môn học
void printSubject(Subject sub) {
	printf("Ma mon: %s\n", sub.code);
	printf("Ten mon: %s\n", sub.name);
	printf("So tin chi: %d\n", sub.credits);
	printf("Diem: %.2f\n", sub.score);
}

// Hàm xuất thông tin sinh viên
void printStudent(Student stu) {
	printf("Ma so sinh vien: %s\n", stu.studentCode);
	printf("Ho ten sinh vien: %s\n", stu.name);

	for (int i = 0; i < MAX_SUBJECTS; i++) {
		printf("Thong tin mon hoc %d:\n", i + 1);
		printSubject(stu.subjects[i]);
		printf("\n");
	}

	printf("Diem trung binh: %.2f\n", stu.averageScore);
}

// Hàm nhập danh sách sinh viên
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

// Hàm tìm sinh viên qua mã số sinh viên
Student* findStudentByCode(Student students[], int n, const char* code) {
	for (int i = 0; i < n; i++) {
		if (strcmp(students[i].studentCode, code) == 0) {
			return &students[i];
		}
	}
	return NULL;
}

// Hàm tìm sinh viên có điểm trung bình cao nhất
Student findMaxAverageScoreStudent(Student students[], int n) {
	Student max = students[0];
	for (int i = 1; i < n; i++) {
		if (students[i].averageScore > max.averageScore) {
			max = students[i];
		}
	}
	return max;
}

// Hàm tìm sinh viên có điểm trung bình thấp nhất
Student findMinAverageScoreStudent(Student students[], int n) {
	Student min = students[0];
	for (int i = 1; i < n; i++) {
		if (students[i].averageScore < min.averageScore) {
			min = students[i];
		}
	}
	return min;
}

// Hàm thêm một sinh viên vào danh sách
void addStudent(Student students[], int* n, Student newStudent) {
	if (*n >= MAX_STUDENTS) {
		printf("Danh sach sinh vien da day.\n");
		return;
	}
	students[*n] = newStudent;
	(*n)++;
}

// Hàm xóa một sinh viên khỏi danh sách
void removeStudent(Student students[], int* n, const char* code) {
	int i;
	for (i = 0; i < *n; i++) {
		if (strcmp(students[i].studentCode, code) == 0) {
			break;
		}
	}

	if (i == *n) {
		printf("Khong tim thay sinh vien voi ma so: %s\n", code);
		return;
	}

	for (int j = i; j < *n - 1; j++) {
		students[j] = students[j + 1];
	}
	(*n)--;
}

// Hàm sắp xếp sinh viên theo điểm trung bình tăng dần
void sortStudentsAscending(Student students[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (students[i].averageScore > students[j].averageScore) {
				Student temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
}

// Hàm sắp xếp sinh viên theo điểm trung bình giảm dần
void sortStudentsDescending(Student students[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (students[i].averageScore < students[j].averageScore) {
				Student temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
}

// Hàm xếp loại học tập
void classifyStudents(Student students[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Sinh vien %s:\n", students[i].name);
		if (students[i].averageScore >= 8.0) {
			printf("Xep loai: Gioi\n");
		}
		else if (students[i].averageScore >= 6.5) {
			printf("Xep loai: Kha\n");
		}
		else if (students[i].averageScore >= 5.0) {
			printf("Xep loai: Trung binh\n");
		}
		else {
			printf("Xep loai: Yeu\n");
		}
	}
}

// Hàm thống kê số môn đậu/rớt
void statisticsPassFail(Student students[], int n) {
	int passCount = 0;
	int failCount = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < MAX_SUBJECTS; j++) {
			if (students[i].subjects[j].score >= 5.0) { // Giả sử điểm đậu là >= 5.0
				passCount++;
			}
			else {
				failCount++;
			}
		}
	}
	printf("Tong so mon dau: %d\n", passCount);
	printf("Tong so mon rot: %d\n", failCount);
}

// Hàm chính
int main() {
	Student students[MAX_STUDENTS];
	int n = 0;

	// Nhập danh sách sinh viên
	inputStudentList(students, &n);

	// Xuất danh sách sinh viên
	printStudentList(students, n);

	// Tìm sinh viên qua mã số sinh viên
	char code[15];
	printf("Nhap ma so sinh vien can tim: ");
	scanf_s("%s", code, (unsigned)_countof(code));

	Student* foundStudent = findStudentByCode(students, n, code);
	if (foundStudent) {
		printf("Thong tin sinh vien:\n");
		printStudent(*foundStudent);
	}
	else {
		printf("Khong tim thay sinh vien voi ma so: %s\n", code);
	}

	// Tìm sinh viên có điểm trung bình cao nhất và thấp nhất
	Student maxStudent = findMaxAverageScoreStudent(students, n);
	Student minStudent = findMinAverageScoreStudent(students, n);

	printf("Sinh vien co diem trung binh cao nhat:\n");
	printStudent(maxStudent);

	printf("Sinh vien co diem trung binh thap nhat:\n");
	printStudent(minStudent);

	// Thêm một sinh viên
	Student newStudent;
	printf("Nhap thong tin sinh vien can them:\n");
	inputStudent(&newStudent);
	addStudent(students, &n, newStudent);

	// Xóa một sinh viên
	char codeToRemove[15];
	printf("Nhap ma so sinh vien can xoa: ");
	scanf_s("%s", codeToRemove, (unsigned)_countof(codeToRemove));
	removeStudent(students, &n, codeToRemove);

	// Sắp xếp sinh viên theo điểm trung bình
	printf("Danh sach sinh vien theo diem trung binh tang dan:\n");
	sortStudentsAscending(students, n);
	printStudentList(students, n);

	printf("Danh sach sinh vien theo diem trung binh giam dan:\n");
	sortStudentsDescending(students, n);
	printStudentList(students, n);

	// Xếp loại học tập
	classifyStudents(students, n);

	// Thống kê số môn đậu/rớt
	statisticsPassFail(students, n);

	return 0;
}
