//
//  cal_diets.c
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

#define MAX_DIETS 100      			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food


// list of diets 
static Diet diet_list[MAX_DIETS];
static int diet_list_size = 0;


/*
    description : read the information in "diets.txt"
*/

void loadDiets(const char* DIETFILEPATH) {
    FILE *file = fopen(DIETFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for diets! \n");
        return;
    }

     // ToCode: to read a list of the diets from the given file
    int check_EOF; 
	while (1) 
    	{
    	//'diets.txt' 파일을 읽고 diet_list[n]에 저장
    	check_EOF = fscanf(file,"%s %d", &diet_list[diet_list_size].food_name, &diet_list[diet_list_size].calories_intake); //음식이름, 음식 칼로리 읽어옴 
			//디버깅: %s %d 사이 반드시 공백을 넣어줘야 %d가 공백을 읽어오지 않는다!!
		
		diet_list_size++; //식사 하나 저장할 때마다 size 1 증가 
        
        if (check_EOF == EOF){
    		//파일 끝이면 while문 종료. 
    		break;
		}
		
        if (diet_list_size >= MAX_DIETS){
        	//무한루프 방지조건
        	break; 
			//최대 MAX_DIETS개까지 동작하고 종료. 
		}
    }
    fclose(file);
}

/*
    description : to enter the selected diet and the total calories intake in the health data
    input parameters : health_data - data object to which the selected diet and its calories are added 
    return value : No
    
    operation : 1. provide the options for the diets to be selected
    			2. enter the selected diet and the total calories intake in the health data
*/

void inputDiet(HealthData* health_data) {
    int choice, i;
    
    // ToCode: to provide the options for the diets to be selected
    printf("The list of diets:\n");
    	
		//for문을 활용, diet_list[i]의 멤버를 참조해 print 
	for (i=0; i<diet_list_size; i++){
		printf("%d. %s - ", i+1, diet_list[i].food_name);
		printf("%d kcal\n", diet_list[i].calories_intake);
	}
    
	// ToCode: to enter the diet to be chosen with exit option
    printf("Enter the number of the food : ");
    scanf("%d", &choice); //choice변수에 사용자가 선택한 식사번호 입력 

    // ToCode: to enter the selected diet in the health data
    

    // ToCode: to enter the total calories intake in the health data


}

