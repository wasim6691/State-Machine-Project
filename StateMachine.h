//----------------------------------------------------------------
/*! 
 *   @file  StateMachine.h
 *   
 *   @author 
 *          Muhammad Wasim Akhtar Khan
 *   @date
            2019 created
 */
//---------------------------------------------------------------
#ifndef __STATE_MACHINE_H
#define __STATE_MACHINE_H

#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define SIZEOPTION 5
#define SIZESTRING 100 
#define NOOFTASKS   8

//Perfectly Scheduled Tasks
#define SLEEPING_TIME_START 0   
#define SLEEPING_TIME_END 180
#define MORNING_WALK_START 181
#define MORNING_WALK_END 360
#define BREAKFAST_TIME_START 361
#define BREAKFAST_TIME_END 540
#define CHATTING_TIME_START 541
#define CHATTING_TIME_END 720
#define LUNCH_TIME_START 721
#define LUNCH_TIME_END 900
#define TELEVISION_WATCHING_START 901
#define TELEVISION_WATCHING_END 1080
#define EXERCISE_TIME_START 1081
#define EXERCISE_TIME_END 1260
#define DINNER_TIME_START 1261
#define DINNER_TIME_END 1439
#define SPEED_UP_FACTOR 50      // <= 50 keeping in view the current timing schedule
#define TEN_MINUTES 10

   ///< Clock Timing
    double initial_time, current_time;
    time_t time_curr, time_new_curr, end_user_input;
    struct tm* local_current_time; 
    int hour, minutes, seconds, timeforschedule, counter, count, repeat_count;
    
    ///< declare a char buffer
    char optionstr[SIZEOPTION];
    char storagestr[SIZESTRING];

    ///< Tasks Status
    bool task_status[NOOFTASKS];
   
    ///< TASKS Sschedule According to GrandMaa Daily Routine
   typedef enum 
   { 
      SLEEPING_TIME=           0,  // Timing 00:00 to 03:00 
      MORNING_WALK              ,  //        03:01 to 06:00 
      BREAKFAST_TIME            ,  //        06:01 to 09:00 
      CHATTING_TIME             ,  //        09:01 to 12:00 
      LUNCH_TIME                ,  //        12:01 to 15:00 
      TELEVISION_WATCHING_TIME  ,  //        15:01 to 18:00
      EXERCISE_TIME             ,  //        18:01 to 21:00 
      DINNER_TIME                  //        21:01 to 23:59 
    
   } GRANDMASCHEDULETASKS_t;
  
   ///< StateMachines Internal States
   typedef enum 
   {
      UNDONE = 0,
      DONE
   } INTERNALSTATES_t;
 
    GRANDMASCHEDULETASKS_t   task_t;
   
   ///< Timing in minutes 
   int TimingInMinutes(int hours, int mins, int seconds);
   
   ///< Print the time to know about grandma schedule
   void EnterTheTime(void);
   
   ///< GrandmaSchedule Per Day
   void GrandmaScheduleSequence(int time);
   

 #endif // _STATE_MACHINE_H