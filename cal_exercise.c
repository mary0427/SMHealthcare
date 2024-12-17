//
//  cal_exercise.c
//  Excercise for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_EXERCISES 100  			// Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50	// Maximum length of the name of exercise


// To declare the structure of the exercises
static Exercise exercise_list[MAX_EXERCISES];
int exercise_list_size = 0;


/*
    description : read the information in "excercises.txt"
*/

void loadExercises(const char* EXERCISEFILEPATH) {
    FILE *file = fopen(EXERCISEFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for exercises! \n");
        return;
    }

    // ToCode: to read a list of the exercises from the given file
    while (fscanf(file,"%s", &exercise_list[exercise_list_size].exercise_name) != EOF) //���ϳ����� ���� 
    	{
    	//'exercises.txt' ������ �а� exercise_list[n]�� ����
    	fscanf(file,"%s", &exercise_list[exercise_list_size].exercise_name); //� �̸� �о�� 
		fscanf(file,"%d", &exercise_list[exercise_list_size].calories_burned); //�� �� �Ҹ�Į�θ� �о��  
		
		exercise_list_size++; //� �ϳ� ������ ������ size 1 ���� 
    
        if (exercise_list_size >= MAX_EXERCISES){
        	//���ѷ��� ��������
        	break; 
			//�ִ� MAX_EXERCISES������ �����ϰ� ����.
		}
    }

    fclose(file);
    
}


/*
    description : to enter the selected exercise and the total calories burned in the health data
    input parameters : health_data - data object to which the selected exercise and its calories are added 
    return value : No
    
    operation : 1. provide the options for the exercises to be selected
    			2. enter the duration of the exercise
    			3. enter the selected exercise and the total calories burned in the health data
*/

void inputExercise(HealthData* health_data) {
    int choice, duration, i;
    
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
    	
		//for���� Ȱ��, exercise_list[i]�� ����� ������ print 
	for (i=0; i<exercise_list_size; i++){
		printf("%d. %s - ", i+1, exercise_list[i].exercise_name);
		printf("%d kcal\n", exercise_list[i].calories_burned);
	}
	

    // ToCode: to enter the exercise to be chosen with exit option
	printf("Enter the number of the exercise  : ");
    scanf("%d", &choice); //choice������ ����ڰ� ������ ���ȣ �Է� 
    
    
    // To enter the duration of the exercise
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);

    // ToCode: to enter the selected exercise and total calcories burned in the health data
	strcpy(health_data->exercises[health_data->exercise_count].exercise_name, exercise_list[choice].exercise_name); //� �̸� exercises[n].exercise_name�� ���� 
    health_data->exercises[health_data->exercise_count].calories_burned = exercise_list[choice].calories_burned * duration; //�ѽð� �Ҹ�Į�θ� = �д� �Ҹ�Į�θ�*��ð��� 
    health_data->exercise_count++; //� Ƚ�� count																		//exercises[n].calories_burned�� ����
    health_data->total_calories_burned += health_data->exercises[health_data->exercise_count].calories_burned; //total �Ҹ� Į�θ�(sum) ��� 

}
