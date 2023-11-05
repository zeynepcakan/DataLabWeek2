#include <stdio.h>
#include <stdlib.h>

struct patient{
	int age;
	char urgency[10];
	char name[20];
	int height;
	struct patient *next;
};

struct patient *start=NULL;
struct patient *temp=NULL;

//Add to head
void addAtBeginning(int age, char urgency[], char name[], int height) {
    struct patient *newPatient = (struct patient*)malloc(sizeof(struct patient));
    newPatient->age = age;
    strcpy(newPatient->urgency, urgency);
    strcpy(newPatient->name, name);
    newPatient->height = height;
    newPatient->next = start;
    start = newPatient;
}

//Add to tail
void addAtEnd(int age, char urgency[], char name[], int height) {
    struct patient *newPatient = (struct patient*)malloc(sizeof(struct patient));
    newPatient->age = age;
    strcpy(newPatient->urgency, urgency);
    strcpy(newPatient->name, name);
    newPatient->height = height;
    newPatient->next = NULL;
    
    if (start == NULL) { //list is empty
        start = newPatient;
        return;
    }
    
    struct patient *temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newPatient;
}

//Display
void displayPatients() {
	system("cls");
    if (start == NULL) {
        printf("Hospital is empty.\n");
        return;
    }
    
    struct patient *temp = start;
    printf("Patients:\n");
    while (temp != NULL) {
    	printf("\n");
        printf("Age: %d\nUrgency: %s\nName: %s\nHeight: %d\n", temp->age, temp->urgency, temp->name, temp->height);
        temp = temp->next;
    }
    
}

int main() {
    int choice, age, height;
    char name[20],urgency[10];
    
    while (1) {
        printf("\n**Hospital Automation**\n");
        printf("1. Add first\n");
        printf("2. Add last\n");
        printf("3. Display patient\n");
        printf("4. EXIT\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Age: ");
                scanf("%d", &age);
                printf("Urgency(green,yellow,red): ");
                scanf("%s", &urgency);
                printf("Name: ");
                scanf("%s", name);
                printf("Height: ");
                scanf("%d", &height);
                addAtBeginning(age, urgency, name, height);
                break;
            case 2:
                printf("Age: ");
                scanf("%d", &age);
                printf("Urgency(green,yellow,red): ");
                scanf("%s", &urgency);
                printf("Name: ");
                scanf("%s", name);
                printf("Height: ");
                scanf("%d", &height);
                addAtEnd(age, urgency, name, height);
                break;
            case 3:
                displayPatients();
                break;
            case 4:
                exit(0);
            default:
                printf("ERROR!\n");
        }
    }
    
    return 0;
}
