//
// Created by rishitg on 3/7/25.
//

#include <stdio.h>
#include <stdlib.h>

typedef union student_grade Student;
typedef union student_grade* Student_addr;
union student_grade {
    char letterGrade;
    int roundedGrade;
    float exactGrade;
};

int main(void) {
    Student_addr s1 = (Student_addr) malloc(sizeof(Student));
    s1->exactGrade = 7.66f;

    printf("Student Exact Grade:\t%.2f\n", s1->exactGrade);
    printf("Student Rounded Grade:\t%d\n", s1->roundedGrade);
    printf("Student Letter Grade:\t%cf\n", s1->letterGrade);

    s1->roundedGrade = 8;

    printf("\nStudent Exact Grade:\t%.2f\n", s1->exactGrade);
    printf("Student Rounded Grade:\t%d\n", s1->roundedGrade);
    printf("Student Letter Grade:\t%c\n", s1->letterGrade);

    s1->letterGrade = 'B';

    printf("\nStudent Exact Grade:\t%.2f\n", s1->exactGrade);
    printf("Student Rounded Grade:\t%d\n", s1->roundedGrade);
    printf("Student Letter Grade:\t%c\n", s1->letterGrade);

    free(s1);
}