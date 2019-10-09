//----------------------------------------------------------------
/*! 
 *   @file  StateMachine.c
 *   
 *   @author 
 *          Muhammad Wasim Akhtar Khan
 *   @date
            2019 created
 */
//---------------------------------------------------------------

#include "StateMachine.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void GrandmaScheduleSequence(int time)
{
       ///< Switch Case
        switch (time)
        {
            case SLEEPING_TIME_START ... SLEEPING_TIME_END:
                  if(count == 0)
                     printf(" \n Grandmaa is Sleeping");
                  else if(repeat_count >=1)
                     printf(" \n Chill! Grandmaa You already have slept"); 
                  else
                     { }
            break;
            
            case MORNING_WALK_START ... MORNING_WALK_END:
                   if(count == 1)
                       printf(" \nGrandmaa is having morning walk with friends");
                   else if(repeat_count >=2)
                       printf(" \n Chill! Grandmaa You already had a Morning Walk");
                   else
                      { }    
            break; 
            
            case BREAKFAST_TIME_START ... BREAKFAST_TIME_END:
                   if(count == 2)
                       printf(" \nGrandmaa is having breakfast");
                   else if(repeat_count >=3)
                       printf(" \nChill! Grandmaa You already have a breakfast");
                   else
                      { } 
            break;
            
            case CHATTING_TIME_START ... CHATTING_TIME_END:
                    if(count ==3)
                       printf("\n Grandmaa is chatting with firends");
                    else if(repeat_count >=4)
                        printf(" \nChill! Grandmaa You already chatted with friends");
                    else
                        { }  
            break;
            
            case LUNCH_TIME_START ... LUNCH_TIME_END:
                    if(count ==4)
                        printf("\n Grandmaa is having lunch");
                    else if(repeat_count >=5)
                        printf(" \nChill! Grandmaa You already have a lunch");
                     else
                        { }  
            break;
            
            case TELEVISION_WATCHING_START ... TELEVISION_WATCHING_END:
                    if(count == 5)
                        printf("\n Grandmaa is watching television");
                    else if(repeat_count >=6)
                        printf(" \nChill! Grandmaa You already have watched television");
                     else
                        { }  
            break;
            
            case EXERCISE_TIME_START ... EXERCISE_TIME_END:
                    if(count == 6)
                        printf("\n Grandmaa is doing exercise for fitness");
                    else if(repeat_count >=7)
                        printf(" \nChill! Grandmaa You have already done the exercise");
                    else
                       { }   
            break;
            
            case DINNER_TIME_START ... DINNER_TIME_END:
                    if(count ==7)
                         printf("\n Grandmaa is having dinner");
                    else if(repeat_count >=8)
                        printf(" \nChill! Grandmaa You already have done the dinner");
                    else
                        { }  
            break;
            
            default: 
                 printf("\n Grandmaa is Perfectly fine. Enjoying the Life!");
            break;
            
        }
}


int TimingInMinutes(int hours, int mins, int seconds)

{
    int timeinmins= 0;
    
    timeinmins = hours * 60 + mins + seconds/60;
    
    //printf("\n The current time in minutes is: %d", timeinmins);
    
    return timeinmins;
}


void EnterTheTime ()
{
    printf ("\nPlease Enter the time for Grandma Schedule in \"hh:mm:ss\" format: ");
    fgets (storagestr, SIZESTRING, stdin);
    ///< store the values in hours and minutes variables. 
    sscanf (storagestr, "%d:%d:%d", &hour, &minutes, &seconds);
    //printf ("\nThe value of Hour is %d and the value of Minutes is %d and seconds is %d", hour, minutes, seconds);

    ///< Based on 24 Hour Clock Schedule 
    timeforschedule = TimingInMinutes(hour, minutes, seconds);
    printf ("\nThe value of timeforschedule %d", timeforschedule);
}
