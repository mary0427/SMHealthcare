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
	HealthData* health_data_p = &health_data; //heath_data 구조체 포인터 선언 
    
    // Tocode: to read the list of the exercises and diets
    

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
            	
            	
            	saveData(HEALTHFILEPATH, health_data_p);
                break;
                
            case 2:
            	
            	
            	saveData(HEALTHFILEPATH, health_data_p);
                break;
                
            case 3:
            	printHealthData(health_data_p); 
                break;
                
            case 4:
            	
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

