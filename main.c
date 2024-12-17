//
//  main.c
//  Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define EXERCISEFILEPATH "exercises.txt"
#define DIETFILEPATH "diets.txt"
#define HEALTHFILEPATH "health_data.txt"

static int choice; 

int main() {
	// To initialize the health data object
    HealthData health_data = {0}; 
    
    // Tocode: to read the list of the exercises and diets
    //loadExercises(EXERCISEFILEPATH);
    //loadDiets(DIETFILEPATH);

    // ToCode: to run the "Healthcare Management Systems" until all calories are used up or the user wants to exit the system
		/*�ý��� ���� ���� 
		(1) ����ڰ� ��4. Exit�� �ɼ� ���� �� 
		(2) ���� Į�θ� (���� Į�θ� - ���� ��緮 - �Ҹ� Į�θ�) = 0 �� �� �� */
	
	do {
    	if (calories_remaining = 0){
            printf("You have consumed all your calories for today! \n");
            return 0; //�ý��� ���� ����(2) 
		} 
		else{
			printf("\n=======================================================================\n");
        	printf("[Healthcare Management Systems] \n");
        	printf("1. Exercise \n");
        	printf("2. Diet \n");
        	printf("3. Show logged information \n");
        	printf("4. Exit \n");
        	printf("Select the desired number: ");
        	scanf("%d", &choice);
        	printf("=======================================================================\n");
        }
        
		// ToCode: to run the sysmtem based on the user's choice
        switch (choice) {
            case 1:
            	//Exercise
            	inputExercise(&health_data); //������� �/�ð� �Է� +  healthdata ����ü�� �ش����� ����
            	saveData(HEALTHFILEPATH, &health_data); //healthdata ����ü�� ����� ������ 'health_data' ���Ϸ� ��� 
                break;
                
            case 2:
            	//Diet
            	inputDiet(&health_data); //������� ���� �Է� +  healthdata ����ü�� �ش����� ����
            	saveData(HEALTHFILEPATH, &health_data); //healthdata ����ü�� ����� ������ 'health_data' ���Ϸ� ��� 
                break;
                
            case 3:
            	//Show logged information
            	printHealthData(&health_data); 
                break;
                
            case 4:
            	//Exit
    			printf("Exit the system.\n");
    			printf("=======================================================================\n");
                break;
                
            default:
                printf("[Error] Invalid option. \n");
                printf("Please try again! \n");
        }
    } while (choice != 4); //�ý��� �������� (1) 
	

    return 0;
}

