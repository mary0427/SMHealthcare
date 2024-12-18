//
//  cal_healthdata.h
//  Excercise for Calorie Diary
//
//  Created by Eunju Cha
//

#ifndef cal_healthdata_h
#define cal_healthdata_h

#include "cal_exercise.h"
#include "cal_diets.h"

#define MAX_EXERCISES 100  			// Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50	// Maximum length of the name of exercise
#define MAX_DIETS 100      			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food
#define DAILY_CALORIE_GOAL 2000  	// Recommended daily calorie intake for adult women
#define BASAL_METABOLIC_RATE 1300 	// Basal metabolic rate of adult women

int calories_remaining; //[변수 추가] 남은 칼로리 (섭취 칼로리 - 기초 대사량 - 소모 칼로리)

// excercise definition for linked list
typedef struct {
    char exercise_name[MAX_EXERCISE_NAME_LEN];	// the name of the exercise
    
	//[Exercise 멤버변수 수정함] calories_burned_per_minute -> calories_burned
    int calories_burned; // 소모칼로리 의미. (healthdata에선 총 시간동안 소모칼로리 / exercise_list에선 분당 소모칼로리) 

} Exercise;                    
//멤버변수 수정 이유: 코드의 효율성을 위함. saveData()와 printHealthData()함수에서는 총 시간  소모칼로리를 출력하므로 이를 담을 수 있도록 함. 
//운동 자체의 정보를 담는 exercise_list에서만 calories_burned 변수가 분 당 소모칼로리를 의미. 


// diet definition for linked list
typedef struct {
    char food_name[MAX_FOOD_NAME_LEN]; 	// the name of food
    int calories_intake;   				// calorie intake
} Diet;

// health data  definition for linked list
typedef struct {
	Exercise exercises[MAX_EXERCISES];  // exercise history
    Diet diet[MAX_DIETS];                // diet history
    int exercise_count;                  // number of exercises
    int diet_count;                      // number of diets
    int total_calories_burned;           // total calories burned
    int total_calories_intake;           // total calories intake
} HealthData;



void saveData(const char* HEALTHFILEPATH,const HealthData* health_data);
void printHealthData(const HealthData* health_data);


#endif /* cal_diets_h */
