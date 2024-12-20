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
    while (fscanf(file,"%s %d", &exercise_list[exercise_list_size].exercise_name, &exercise_list[exercise_list_size].calories_burned) != EOF)  
    	{
    	//'exercises.txt' 파일을 읽고 exercise_list[n]에 저장
    	//debug: while 조건문 실행 시 파일 읽어오기가 같이 실행됨 유의 
    		//운동이름, 분 당 소모칼로리 읽어옴. 파일 끝이면 EOF(-1) 반환하고 while문 종료. 
			//디버깅: %s %d 사이 반드시 공백을 넣어줘야 %d가 공백을 읽어오지 않는다!! 
		
		exercise_list_size++; //운동 하나 저장할 때마다 size 1 증가 
    	
        if (exercise_list_size >= MAX_EXERCISES){
        	break; 
			//최대 MAX_EXERCISES개까지 동작하고 종료. 
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
    	
		//for문을 활용, exercise_list[i]의 멤버를 참조해 print 
	for (i=0; i<exercise_list_size; i++){
		printf("%d. %s - ", i+1, exercise_list[i].exercise_name);
		printf("%d kcal\n", exercise_list[i].calories_burned);
	}
	

    // ToCode: to enter the exercise to be chosen with exit option
	printf("Enter the number of the exercise  : ");
    scanf("%d", &choice); //choice변수에 사용자가 선택한 운동번호 입력 
    
    
    // To enter the duration of the exercise
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);

    // ToCode: to enter the selected exercise and total calcories burned in the health data
	strcpy(health_data->exercises[health_data->exercise_count].exercise_name, exercise_list[choice-1].exercise_name); //운동 이름 exercises[n].exercise_name에 저장
		//debug: 문자열은 직접 대입 불가. 반드시 strcpy함수 이용해야함(복사) 
    health_data->exercises[health_data->exercise_count].calories_burned = exercise_list[choice-1].calories_burned * duration; //총시간 소모칼로리(= 분당 소모칼로리*운동시간)을 exercises[n].calories_burned에 저장
   	
    health_data->total_calories_burned += health_data->exercises[health_data->exercise_count].calories_burned; //total 소모칼로리(sum) 계산 
	health_data->exercise_count++; //운동 횟수 count
}
