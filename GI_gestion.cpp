#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_STUDENTS 300
#define N 10

typedef struct {
    char id[11];
    int R;
    char lastName[51];
    char firstName[51];
    float grades[N];
} Student;

int numStudents = 0;
Student students[MAX_STUDENTS];
FILE *file;

void Menu();
void addStudent();
void displayStudent(char id[11]);
void displayAllStudents();
void modifyStudent(char id[11]);
void deleteStudent(char id[11]);

int main() {
    file = fopen("etudiant.txt", "r+");
    if (file == NULL) {
        printf("\033[1;31mError: Could not open file\033[0m\n");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        int R;
        char id[11];
        char lastName[51];
        char firstName[51];
        float grades[N];

        if(sscanf(line, "Student_Id: %[^,],Last_Name: %[^,],First_Name: %[^,],Number_Of_Grades: %d,Grades: %f,%f,%f,%f,%f,%f,%f",
            id, lastName, firstName, &R, &grades[0], &grades[1], &grades[2], &grades[3], &grades[4], &grades[5], &grades[6]) != 11) {
             printf("\033[1;31mError: Invalid file format\033[0m\n");
             exit(1);
             }
                 strcpy(students[numStudents].id, id);
    students[numStudents].R = R;
    strcpy(students[numStudents].lastName, lastName);
    strcpy(students[numStudents].firstName, firstName);
    memcpy(students[numStudents].grades, grades, sizeof(float) * N);
    numStudents++;
}

fclose(file);

Menu();

file = fopen("etudiant.txt", "w");
if (file == NULL) {
    printf("\033[1;31mError: Could not open file\033[0m\n");
    exit(1);
}

for (int i = 0; i < numStudents; i++) {
    fprintf(file, "Student_Id: %s,Last_Name: %s,First_Name: %s,Number_Of_Grades: %d,Grades: %.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f\n",
        students[i].id, students[i].lastName, students[i].firstName, students[i].R,
        students[i].grades[0], students[i].grades[1], students[i].grades[2],
        students[i].grades[3], students[i].grades[4], students[i].grades[5], students[i].grades[6]);
}

fclose(file);

return 0;
}

void Menu() {
int choice;
char id[11];
while(1) {
    printf("\n\t\t\t\033[1;34m-------------------------------------------------\n");
    printf("\t\t\t-"); printf("       What would you like to do?\t\t");printf("-\n");
    printf("\t\t\t-"); printf("  1. Add a student         \t\t\t");printf("-\n");
    printf("\t\t\t-"); printf("  2. Search for a student     \t\t\t");printf("-\n");
    printf("\t\t\t-"); printf("  3. Display all students  \t\t\t");printf("-\n");
    printf("\t\t\t-"); printf("  4. Modify a student      \t\t\t");printf("-\n");
    printf("\t\t\t-"); printf("  5. Delete a student      \t\t\t");printf("-\n");
    printf("\t\t\t-"); printf("  6. Exit                  \t\t\t");printf("-");
    printf("\n\t\t\t-------------------------------------------------\033[0m\n");
    printf("\n\t\t==>Enter your choice : ");
    scanf("%d",&choice);

    switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            printf("Enter the ID of the student: ");
            scanf("%s", id);
            displayStudent(id);
            break;
        case 3:
            displayAllStudents();
            break;
        case 4:
            printf("Enter the ID of the student: ");
            scanf("%s", id);
            modifyStudent(id);
            break;
        case 5:
            printf("Enter the ID of the student: ");
            scanf("%s", id);
            deleteStudent(id);
            break;
        case 6:
        	printf("\nExiting program...");
        	for(int i=0;i<3;i++){
             printf(".");
             sleep(2);
			}
            
            return;
        default:
            printf("\033[1;31mError: Invalid choice\033[0m\n");
            break;
    }
    printf("\nredirected to menu");
    for(int i=0;i<4;i++){
    	printf(".");
    	sleep(1);
	}
 
}

}

void addStudent() {
if (numStudents == MAX_STUDENTS) {
printf("\033[1;31mError: Maximum number of students reached\033[0m\n");
return;
}
Student newStudent;
fflush(stdin);
printf("==>Enter the Massar Id : ");
gets(newStudent.id);
for(int i=0;i<numStudents;i++){
if(strcmp(students[i].id,newStudent.id)==0){
	printf("\n\033[1;31mERROR:This Id is used by other student !!\033[0m\n");
	while(strcmp(students[i].id,newStudent.id)==0){
		printf("==>Enter A New Massar Id : ");
        gets(newStudent.id);
		if(strcmp(students[i].id,newStudent.id)==0){
		printf("\n\033[1;31mERROR:This Id is used by other student !!\033[0m\n");
		printf("==>Enter A New Massar Id : ");
        gets(newStudent.id);}
	}
}
}
printf("==>Enter the last name : ");
gets(newStudent.lastName);

printf("==>Enter the first name : ");
gets(newStudent.firstName);
fflush(stdin);
printf("==>Enter number of test you want to enter (Max 10): ");
("%d", &newStudent.R);

printf("==>Enter the %d grades of the student separated by spaces: ", newStudent.R);
for (int i = 0; i < newStudent.R; i++) {
    scanf("%f", &newStudent.grades[i]);
}

students[numStudents] = newStudent;
numStudents++;

printf("Student added successfully!\n");
}

void displayStudent(char id[11]) {
    for (int i = 0; i < numStudents; i++) {
        if (strcasecmp(students[i].id, id) == 0) {
            printf("\n\033[1;36m-------------------------------------------Student Details------------------------------------------------\n");
            printf("\tId Massar : %s\n", students[i].id);
            printf("\tLast Name : %s\n", students[i].lastName);
            printf("\tFirst Name : %s\n", students[i].firstName);
            printf("\tNumber of Grades : %d\n", students[i].R);
            printf("\tGrades :");
            for (int j = 0; j < students[i].R; j++) {
                printf(" %.2f", students[i].grades[j]);
            }
            printf("\n-----------------------------------------------------------------------------------------------------------\033[1;36m\n");
            printf("\n");
      return;
}}
printf("\033[1;31mError: Student not found\033[0m\n");
return;

}
void displayAllStudents() {
if (numStudents == 0) {
        printf("\nNo students to display.\n");
        return;
    }
    printf("\n\033[1;36m-------------------------------------------Student Details------------------------------------------------\n");
    for (int i = 0; i < numStudents; i++) {
       printf("student %d",i+1); printf("\t");printf("\tId Massar : %s\n", students[i].id);
                                 printf("\t\t");printf("\tLast Name : %s\n", students[i].lastName);
                                 printf("\t\t");printf("\tFirst Name : %s\n", students[i].firstName);
                                 printf("\t\t");printf("\tNumber of Grades : %d\n", students[i].R);
                                 printf("\t\t");printf("\tGrades :");
        for (int j = 0; j < students[i].R; j++) {
            printf(" %.2f", students[i].grades[j]);
        }
        printf("\n-----------------------------------------------------------------------------------------------------------\033[1;36m\n");
    }
}

void modifyStudent(char id[11]) {
for (int i = 0; i < numStudents; i++) {
if (strcmp(students[i].id, id) == 0) {
            printf("\n---------------------Student Details-----------------------\n");
            printf("\tId Massar : %s\n", students[i].id);
            printf("\tLast Name : %s\n", students[i].lastName);
            printf("\tFirst Name : %s\n", students[i].firstName);
            printf("\tNumber of Grades : %d\n", students[i].R);
            printf("\tGrades :");
            for (int j = 0; j < students[i].R; j++) {
                printf(" %.2f ,", students[i].grades[j]);
                if(j=students[i].R-1)
                 printf(" %.2f", students[i].grades[j]);
            }
            printf("\n------------------------------------------------------------\n");
        	int choice;
    while(1){
	        printf("\n\t\t\t\033[1;31m------------------------------------------------------------\n");
            printf("\t\t\t-");printf("\t\tWhat would you like to modify?\t\t ");printf("  -\n");
            printf("\t\t\t-");printf("\t\t1. Last Name    \t\t\t");printf("   -\n");
            printf("\t\t\t-");printf("\t\t2. First Name     \t\t        ");printf("   -\n");
            printf("\t\t\t-");printf("\t\t3. Number of Grades and Grades\t\t");printf("   -\n");
            printf("\t\t\t-");printf("\t\t4. Save and return to menu\t\t ");printf("  -");
            printf("\n\t\t\t------------------------------------------------------------\033[0m\n");
            printf("\t\t==>Enter your choice: ");
            scanf("%d", &choice);
             switch (choice) {
                case 1:
                    printf("\nEnter new Last Name: ");
                    fflush(stdin);
                    gets(students[i].lastName);
                    printf("Student last name with ID %s has been modified in the records.\n", id);
                    break;
                case 2:
                    printf("\nEnter new First Name: ");
                    fflush(stdin);
                    gets(students[i].firstName);
                    printf("Student first name with ID %s has been modified in the records.\n", id);
                    break;
                case 3:
                    printf("\nEnter new Number of Grades: ");
                    fflush(stdin);
                    scanf("%d", &students[i].R);
                    printf("Number of grades for student with ID %s has been modified in the records.\n", id);
                    printf("Enter new Grades (separated by spaces): ");
                    for (int j = 0; j < students[i].R; j++) {
                        scanf("%f,", &students[i].grades[j]);
                    }
                     printf("Grades for student with ID %s have been modified in the records.\n", id);

                     break;

                case 4:
                    printf("Student modified successfully!\n");
                    return;
                default:
                    printf("\nInvalid input. Please enter a value between 1 and 4.\n");
                    break;
            }
			}
			}
			printf("\033[1;31mError: Student not found\033[0m\n");
	}
}

void deleteStudent(char id[11]) {
for (int i = 0; i < numStudents; i++) {
if (strcmp(students[i].id, id) == 0) {
for (int j = i; j < numStudents - 1; j++) {
students[j] = students[j + 1];
}
numStudents--;
        printf("press any key.....\n");
        fflush(stdin);
        getchar();
        printf("Student deleted successfully!\n");
        return;
    }
}

printf("\033[1;31mError: Student not found\033[0m\n");
}
