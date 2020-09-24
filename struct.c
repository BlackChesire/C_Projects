#include <stdio.h>
#include <string.h>

struct Student {
	char name[250];
	int math_grade;
	int english_grade;
	int hebrew_grade;
};

struct School {
	float math_weight;
	float english_weight;
	float hebrew_weight;
};

float calc_avg(struct Student* student, struct School* school) {
	printf("sizeof student = %zu\n", sizeof(student));
	float math_total = school->math_weight * student->math_grade;
	float english_total = school->english_weight * student->english_grade;
	float hebrew_total = school->hebrew_weight * student->hebrew_grade;
	return math_total + english_total + hebrew_total;
}

int main() {
	struct Student student = { 0 };
	strcpy(student.name, "Donald Trump");
	student.math_grade = 100;
	student.english_grade = 75;
	student.hebrew_grade = 89;

	struct School school = { 0 };
	school.math_weight = 0.1;
	school.english_weight = 0.7;
	school.hebrew_weight = 0.3;

	printf("Avg = %f\n", calc_avg(&student, &school));
	return 0;
}