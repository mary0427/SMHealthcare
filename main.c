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
		/*시스템 종료 조건 
		(1) 사용자가 ‘4. Exit’ 옵션 선택 시 
		(2) 남은 칼로리 (섭취 칼로리 - 기초 대사량 - 소모 칼로리) = 0 이 될 시 */
	
	do {
    	if (calories_remaining = 0){
            printf("You have consumed all your calories for today! \n");
            return 0; //시스템 종료 조건(2) 
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
            	inputExercise(&health_data); //사용자의 운동/시간 입력 +  healthdata 구조체에 해당정보 저장
            	saveData(HEALTHFILEPATH, &health_data); //healthdata 구조체에 저장된 정보를 'health_data' 파일로 백업 
                break;
                
            case 2:
            	//Diet
            	inputDiet(&health_data); //사용자의 음식 입력 +  healthdata 구조체에 해당정보 저장
            	saveData(HEALTHFILEPATH, &health_data); //healthdata 구조체에 저장된 정보를 'health_data' 파일로 백업 
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
    } while (choice != 4); //시스템 종료조건 (1) 
	

    return 0;
}

