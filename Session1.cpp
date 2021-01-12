#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Course {
	char ID[10];
	int score;
};

struct Student {
	char name[255];
	double GPA;
	Course c; //object Course
};

Student *createStudent(const char *name, double gpa, const char *ID, int score){
	//alokasi memory
	Student *newStudent = (Student*)malloc(sizeof(Student));
	strcpy(newStudent->name, name); //strcpy((*newStudent).name, name);
	//(*newStudent).atributnya sama aja dengan newStudent->atributnya
	newStudent->GPA = gpa;
	strcpy(newStudent->c.ID, ID);
	newStudent->c.score = score;
	
	return newStudent;
}

void removeStudent (Student *s) {
	free(s); //buang memory yang sudah dialokasikan
	s = NULL; //kosongkan nilainya
}

void printStudent (Student *s) {
	printf("Name: %s\n", s->name);
	printf("GPA: %.2lf\n", s->GPA);
	printf("Course ID: %s\n", s->c.ID);
	printf("Score: %d\n", s->c.score);
}

int main(){
	//s1 mengarah ke sudent yang direturn oleh createStudent
	Student *s1 = createStudent("Budi", 3.90, "COMP6048", 100);
	Student *s2 = createStudent("Abdul", 4.00, "COMP6049", 85);
	printStudent(s1);
	printStudent(s2);
	
	return 0;
}
