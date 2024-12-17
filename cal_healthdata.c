//
//  cal_healthdata.c
//  Diets for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"


/*
    description : enter the exercise and diet history in "health_data.txt" 
    input parameters : health_data - data object in which the selected exercise and diet is stored
    return value : No
    
    operation : 1. save the chosen exercise and total calories burned 
    			2. save the chosen diet and total calories intake 
    			3. save the total remaining calrories
*/

void saveData(const char* HEALTHFILEPATH, const HealthData* health_data) {
	int i;
    FILE* file = fopen(HEALTHFILEPATH, "w");
    if (file == NULL) {
        printf("There is no file for health data.\n");
        return;
    }
	
	//�, �Ļ� ���۸��� HealthData ����ü�� ����� ������ 'health_data.txt�� ���Ϸ� ����ϱ����� �ڵ� 
	//cf. <cal_healthdata.h> - [Exercise����ü�� ������� ��������!] calories_burned_per_minute -> calories_burned (��ü�ð� �Ҹ�Į�θ� �ǹ�) 
	 
    // ToCode: to save the chosen exercise and total calories burned 
    fprintf(file, "[Exercises] \n");
    	//HealthData ����ü ��� exercises�迭�� ����� ������ for������ �������� 'health_data.txt�� ���Ϸ� ���(fprintf) 
    	//exercises[i] ����ü�� ��� : i��° ��� �̸�, i��° ��� "��ü�ð�"������ �Ҹ�Į�θ�
    for (i=0; i<(health_data->exercise_count); i++)
	{
		fprintf(file, "%s - %d kcal\n", health_data->exercises[i].exercise_name, health_data->exercises[i].calories_burned); 
	}
   	fprintf(file, "Total calories burned: %d kcal\n", health_data->total_calories_burned); //������, total_calories_burned���� ���� �� ���Ϸ� ���(fprintf) 
    
    
    // ToCode: to save the chosen diet and total calories intake 
    fprintf(file, "\n[Diets] \n");
    	//HealthData ����ü ��� diet�迭�� ����� ������ for������ �������� 'health_data.txt'���Ϸ� ���(fprintf)
		//diet[i] ����ü�� ��� : i��° ������ �̸�, i��° ������ Į�θ�
	for (i=0; i<(health_data->diet_count); i++)
	{
		fprintf(file, "%s - %d kcal\n", health_data->diet[i].food_name, health_data->diet[i].calories_intake); 
	}
   	fprintf(file, "Total calories intake: %d kcal\n", health_data->total_calories_intake); //������, total_calories_intake���� ���� �� ���Ϸ� ���(fprintf)


    // ToCode: to save the total remaining calrories
    	//'health_data.txt�����Ϸ� ���(fprint)
    fprintf(file, "\n[Total] \n");
    fprintf(file, "Basal metabolic rate - %d kcal\n",BASAL_METABOLIC_RATE); //���� ��緮 (����, 1300 kcal)
    calories_remaining = health_data->total_calories_intake - BASAL_METABOLIC_RATE - health_data->total_calories_burned; //���� Į�θ� (���� Į�θ� - ���� ��緮 - �Ҹ�� Į�θ�) 
    fprintf(file, "The remaining calories - %d kcal\n",calories_remaining);
    
    //save �Ϸ�. ���� ����. 
    fclose(file);
}

/*
    description : print the history of exercised and diets
    input parameters : health_data - data object in which the history of the exercise and diet is to be printed
    return value : No
    
    operation : 1. print out the saved history of exercises
    			2. print out the saved history of diets
    			3. print out the saved history of calories
*/

void printHealthData(const HealthData* health_data) {
	int i;
	
	// ToCode: to print out the saved history of exercises
		//��saveData()�Լ��� ��������� ����. �������(fprintf) ��� ����Ϳ� ���(printf).
	 
	printf("=========================== History of Exercise =======================\n");
  		//HealthData ����ü ��� exercises�迭�� ����� ������ for������ �������� print.
    	//exercises[i] ����ü�� ��� : i��° ��� �̸�, i��° ��� "��ü�ð�"������ �Ҹ�Į�θ� 
	for (i=0; i<(health_data->exercise_count); i++)
	{ 
		printf("Exercise: %s, Calories burned : %d kcal\n", health_data->exercises[i].exercise_name, health_data->exercises[i].calories_burned); 
	}
    printf("=======================================================================\n");


    // ToCode: to print out the saved history of diets
    printf("============================= History of Diet =========================\n");
		//HealthData ����ü ��� diet�迭�� ����� ������ for������ �������� 'health_data.txt'���Ϸ� ���(fprintf)
		//diet[i] ����ü�� ��� : i��° ������ �̸�, i��° ������ Į�θ�
	for (i=0; i<(health_data->diet_count); i++)
	{
		printf( "Food: %s, Calories intake: %d kcal\n", health_data->diet[i].food_name, health_data->diet[i].calories_intake); 
	}
    printf("=======================================================================\n");


	// ToCode: to print out the saved history of calories including basal metabolic rate, 
	// total calories burned, total calories intake, and the remaining calories
	printf("============================== Total Calories =========================\n");
    printf("Basal metabolic rate - %d kcal\n",BASAL_METABOLIC_RATE); //���� ��緮 (����, 1300 kcal)
 	printf("Total calories burned: %d kcal\n", health_data->total_calories_burned); //total_calories_burned ���� �� print
 	printf("Total calories intake: %d kcal\n", health_data->total_calories_intake); //total_calories_intake ���� �� print
    calories_remaining = health_data->total_calories_intake - BASAL_METABOLIC_RATE - health_data->total_calories_burned; //���� Į�θ� (���� Į�θ� - ���� ��緮 - �Ҹ�� Į�θ�) 
    printf("The remaining calories - %d kcal\n",calories_remaining);
	printf("=======================================================================\n \n");
    
	
	// ToCode: to print out the recommendtaion depending on the current total calories burned and intake    
    if  (calories_remaining < 0)
    	//���� Į�θ� < 0 �� ���
    {
    	printf("[Warning] Too few calories!");
    	
    	if (health_data->total_calories_intake == DAILY_CALORIE_GOAL){
			//���� Į�θ��� ���� ���� Į�θ��� ������ ���
	    printf("Your total calorie intake for today has reached your goal!");   
		}
		else if (health_data->total_calories_intake < DAILY_CALORIE_GOAL){
			//���� Į�θ��� ���� ���� Į�θ����� ���� ���
	    printf("Your total calorie intake for today has not reached your goal, remember to eat more!!");   
		}
		else {
			//���� Į�θ��� ���� ���� Į�θ����� ���� ���
	    printf("You have eaten more calories than planned today, but you have exercised too much!");   
		}	
	}
	
	else if  (calories_remaining > 0)
		//���� Į�θ� > 0 �� ���
    {
    	printf("Please exercise for your health!");
    	
    	if (health_data->total_calories_intake == DAILY_CALORIE_GOAL){
			//���� Į�θ��� ���� ���� Į�θ��� ������ ���
	    printf("Your total calorie intake for today has reached your goal!");   
		}
		else if (health_data->total_calories_intake < DAILY_CALORIE_GOAL){
			//���� Į�θ��� ���� ���� Į�θ����� ���� ���
			printf("Your total calorie intake for today has not reached your goal, remember to eat more!!");   
		}
	}
	
	else  
		//���� Į�θ� =0�� ���(�ý��� ����������)
	;
    		// �Լ� �������� �ƹ� ó������. main.c���� do������ �ٷ� �Ѱ��� ����.
			//do������ ��You have consumed all your calories for today!����� + �ý��� ���� ó���� ����. 
	 printf("=======================================================================\n");
}
