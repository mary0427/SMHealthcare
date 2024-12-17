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
	
	//운동, 식사 동작마다 HealthData 구조체에 저장된 정보를 'health_data.txt’ 파일로 백업하기위한 코드 
	//cf. <cal_healthdata.h> - [Exercise구조체의 멤버변수 수정했음!] calories_burned_per_minute -> calories_burned (전체시간 소모칼로리 의미) 
	 
    // ToCode: to save the chosen exercise and total calories burned 
    fprintf(file, "[Exercises] \n");
    	//HealthData 구조체 멤버 exercises배열에 저장된 정보를 for문으로 차례차례 'health_data.txt’ 파일로 백업(fprintf) 
    	//exercises[i] 구조체의 멤버 : i번째 운동의 이름, i번째 운동의 "전체시간"동안의 소모칼로리
    for (i=0; i<(health_data->exercise_count); i++)
	{
		fprintf(file, "%s - %d kcal\n", health_data->exercises[i].exercise_name, health_data->exercises[i].calories_burned); 
	}
   	fprintf(file, "Total calories burned: %d kcal\n", health_data->total_calories_burned); //끝으로, total_calories_burned까지 참조 및 파일로 백업(fprintf) 
    
    
    // ToCode: to save the chosen diet and total calories intake 
    fprintf(file, "\n[Diets] \n");
    	//HealthData 구조체 멤버 diet배열에 저장된 정보를 for문으로 차례차례 'health_data.txt'파일로 백업(fprintf)
		//diet[i] 구조체의 멤버 : i번째 음식의 이름, i번째 음식의 칼로리
	for (i=0; i<(health_data->diet_count); i++)
	{
		fprintf(file, "%s - %d kcal\n", health_data->diet[i].food_name, health_data->diet[i].calories_intake); 
	}
   	fprintf(file, "Total calories intake: %d kcal\n", health_data->total_calories_intake); //끝으로, total_calories_intake까지 참조 및 파일로 백업(fprintf)


    // ToCode: to save the total remaining calrories
    	//'health_data.txt’파일로 백업(fprint)
    fprintf(file, "\n[Total] \n");
    fprintf(file, "Basal metabolic rate - %d kcal\n",BASAL_METABOLIC_RATE); //기초 대사량 (고정, 1300 kcal)
    calories_remaining = health_data->total_calories_intake - BASAL_METABOLIC_RATE - health_data->total_calories_burned; //남은 칼로리 (섭취 칼로리 - 기초 대사량 - 소모된 칼로리) 
    fprintf(file, "The remaining calories - %d kcal\n",calories_remaining);
    
    //save 완료. 파일 닫음. 
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
		//위saveData()함수의 백업과정과 유사. 파일출력(fprintf) 대신 모니터에 출력(printf).
	 
	printf("=========================== History of Exercise =======================\n");
  		//HealthData 구조체 멤버 exercises배열에 저장된 정보를 for문으로 차례차례 print.
    	//exercises[i] 구조체의 멤버 : i번째 운동의 이름, i번째 운동의 "전체시간"동안의 소모칼로리 
	for (i=0; i<(health_data->exercise_count); i++)
	{ 
		printf("Exercise: %s, Calories burned : %d kcal\n", health_data->exercises[i].exercise_name, health_data->exercises[i].calories_burned); 
	}
    printf("=======================================================================\n");


    // ToCode: to print out the saved history of diets
    printf("============================= History of Diet =========================\n");
		//HealthData 구조체 멤버 diet배열에 저장된 정보를 for문으로 차례차례 'health_data.txt'파일로 백업(fprintf)
		//diet[i] 구조체의 멤버 : i번째 음식의 이름, i번째 음식의 칼로리
	for (i=0; i<(health_data->diet_count); i++)
	{
		printf( "Food: %s, Calories intake: %d kcal\n", health_data->diet[i].food_name, health_data->diet[i].calories_intake); 
	}
    printf("=======================================================================\n");


	// ToCode: to print out the saved history of calories including basal metabolic rate, 
	// total calories burned, total calories intake, and the remaining calories
	printf("============================== Total Calories =========================\n");
    printf("Basal metabolic rate - %d kcal\n",BASAL_METABOLIC_RATE); //기초 대사량 (고정, 1300 kcal)
 	printf("Total calories burned: %d kcal\n", health_data->total_calories_burned); //total_calories_burned 참조 및 print
 	printf("Total calories intake: %d kcal\n", health_data->total_calories_intake); //total_calories_intake 참조 및 print
    calories_remaining = health_data->total_calories_intake - BASAL_METABOLIC_RATE - health_data->total_calories_burned; //남은 칼로리 (섭취 칼로리 - 기초 대사량 - 소모된 칼로리) 
    printf("The remaining calories - %d kcal\n",calories_remaining);
	printf("=======================================================================\n \n");
    
	
	// ToCode: to print out the recommendtaion depending on the current total calories burned and intake    
    if  (calories_remaining < 0)
    	//남은 칼로리 < 0 인 경우
    {
    	printf("[Warning] Too few calories!");
    	
    	if (health_data->total_calories_intake == DAILY_CALORIE_GOAL){
			//섭취 칼로리가 일일 권장 칼로리에 도달한 경우
	    printf("Your total calorie intake for today has reached your goal!");   
		}
		else if (health_data->total_calories_intake < DAILY_CALORIE_GOAL){
			//섭취 칼로리가 일일 권장 칼로리보다 적은 경우
	    printf("Your total calorie intake for today has not reached your goal, remember to eat more!!");   
		}
		else {
			//섭취 칼로리가 일일 권장 칼로리보다 많은 경우
	    printf("You have eaten more calories than planned today, but you have exercised too much!");   
		}	
	}
	
	else if  (calories_remaining > 0)
		//남은 칼로리 > 0 인 경우
    {
    	printf("Please exercise for your health!");
    	
    	if (health_data->total_calories_intake == DAILY_CALORIE_GOAL){
			//섭취 칼로리가 일일 권장 칼로리에 도달한 경우
	    printf("Your total calorie intake for today has reached your goal!");   
		}
		else if (health_data->total_calories_intake < DAILY_CALORIE_GOAL){
			//섭취 칼로리가 일일 권장 칼로리보다 적은 경우
			printf("Your total calorie intake for today has not reached your goal, remember to eat more!!");   
		}
	}
	
	else  
		//남은 칼로리 =0인 경우(시스템 종료조건임)
	;
    		// 함수 내에서는 아무 처리안함. main.c에서 do문으로 바로 넘겨질 예정.
			//do문에서 “You have consumed all your calories for today!”출력 + 시스템 종료 처리될 예정. 
	 printf("=======================================================================\n");
}
