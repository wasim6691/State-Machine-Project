//----------------------------------------------------------------
/*! 
 *   @file  main.c
 *   
 *   @author 
 *          Muhammad Wasim Akhtar Khan
 *   @date
            2019 created
 */
//---------------------------------------------------------------

#include "StateMachine.h"

int main ()
{
    ///< Char and Bool Array Initialization 
    strncpy(optionstr, "", sizeof(optionstr));
    strncpy(storagestr, "", sizeof(storagestr));
	memset(task_status, false, sizeof(task_status));
    
    ///< Variable Initialization
    hour =0, minutes =0, seconds =0, timeforschedule =0, count = 0, repeat_count = 0;
    time_curr = time(NULL); 
    
    ///< To get the initial starting time 
    local_current_time = localtime(&time_curr); 
    initial_time = TimingInMinutes(local_current_time->tm_hour, local_current_time->tm_min, local_current_time->tm_sec); 
    printf ("\n Initial Starting Time is : %f", initial_time);
    task_t = SLEEPING_TIME;
    bool already = false; 
	
    while (1)
    {
       counter = 0;
       for(int i = 0; i<NOOFTASKS; i++)
          if (task_status[NOOFTASKS])
                counter +=1;
          
       if(counter == (NOOFTASKS-1))
         {break;}                                  // While Loop Termination

      time_new_curr = time(NULL); 
      ///< To get the current time 
      local_current_time = localtime(&time_new_curr); 
      current_time = TimingInMinutes(local_current_time->tm_hour, local_current_time->tm_min, local_current_time->tm_sec); 
      //printf ("\n Current Time is : %f", current_time);
        
        switch (task_t)
        {
            case SLEEPING_TIME:
             if(!already)
               {
                if((current_time - initial_time) < (float)(SLEEPING_TIME_END- TEN_MINUTES)/SPEED_UP_FACTOR) 
                {
                  printf ("\n\n Sleeping time is Starting ");   
                  EnterTheTime();
                  repeat_count+=1;
                  GrandmaScheduleSequence(timeforschedule);
                  count +=1;
                }
                
                if(task_status[SLEEPING_TIME] == UNDONE)
                {
                   printf ("\n\nAre You Sleeping Grandma ? Yes, No: ");
                   fgets (optionstr, SIZEOPTION, stdin);
                   if (strcmp(optionstr, "YES"))
                   { 
                      task_status[SLEEPING_TIME] = DONE;
                   }
                   else
                   {
                      task_status[SLEEPING_TIME] = UNDONE;
                   }
                 }
                 already = true;
               }
                ///< Printing the the before 10 mins of finishing the task
                if ((current_time - initial_time) >= (float)(SLEEPING_TIME_END - TEN_MINUTES)/SPEED_UP_FACTOR)
                {
                  printf("\nGrandma's Sleeping time is about to finish. Get Ready to wake up.");
                  task_t = MORNING_WALK;
                  already = false;
                }
                break;
           
            case MORNING_WALK:
              if(!already)
               {
                if((current_time - initial_time) < (float)(MORNING_WALK_END - TEN_MINUTES)/SPEED_UP_FACTOR)
                {
                   printf ("\n\n Morning Walk time is Starting "); 
                   EnterTheTime();
                   repeat_count+=1;
                   GrandmaScheduleSequence(timeforschedule);
                   count +=1;
                }
                
                if(task_status[MORNING_WALK] == UNDONE)
                {
                    printf ("\n\nAre You Having a Morning Walk Grandma ? Yes, No: ");
                    fgets (optionstr, SIZEOPTION, stdin);
                    if (strcmp(optionstr, "YES"))
                    {
                      task_status[MORNING_WALK] = DONE;
                    }
                    else
                    {
                      task_status[MORNING_WALK] = UNDONE;
                    }
                }
                already = true;
               }
                ///< Printing the the before 10 mins of finishing the task
                if ((current_time - initial_time) >= (float)(MORNING_WALK_END - TEN_MINUTES)/SPEED_UP_FACTOR)
                {
                  printf("\nGrandma's Morning walk time is about to finish");
                  task_t = BREAKFAST_TIME;
                  already = false;
                }
            break;
            
            case BREAKFAST_TIME:
               if(!already)
               {
                if((current_time - initial_time) < (float)(BREAKFAST_TIME_END - TEN_MINUTES)/SPEED_UP_FACTOR)
                {
                  printf ("\n\n Breakfast time is Starting "); 
                  EnterTheTime();
                  repeat_count+=1;
                  GrandmaScheduleSequence(timeforschedule);
                  count +=1;
                }
                
                if(task_status[BREAKFAST_TIME] == UNDONE)
                {
                    printf ("\n\nAre You having breakfast ? Yes, No: ");
                    fgets (optionstr, SIZEOPTION, stdin);
                    if (strcmp(optionstr, "YES"))
                    {
                      task_status[BREAKFAST_TIME] = DONE;
                    }
                    else
                    {
                       task_status[BREAKFAST_TIME] = UNDONE;
                    }
                }
                already = true;
               }
                ///< Printing the the before 10 mins of finishing the task
                if ((current_time - initial_time) >= (float)(BREAKFAST_TIME_END - TEN_MINUTES)/SPEED_UP_FACTOR)
                {
                  printf("\nGrandma's Break fast time is about to finish ");
                  task_t = CHATTING_TIME;
                  already = false;
                }

            break;
            
            case CHATTING_TIME:
              if(!already)
               {
                if((current_time - initial_time) < (float)(CHATTING_TIME_END - TEN_MINUTES)/SPEED_UP_FACTOR)
                {
                  printf ("\n\n Chatting time is Starting "); 
                  EnterTheTime();
                  repeat_count+=1;
                  GrandmaScheduleSequence(timeforschedule);
                  count +=1;
                }
                
                if(task_status[CHATTING_TIME] == UNDONE)
                {
                    printf ("\n\nAre You chatting with friends ? Yes, No: ");
                    fgets (optionstr, SIZEOPTION, stdin);
                    if (strcmp(optionstr, "YES"))
                    {
                      task_status[CHATTING_TIME] = DONE;
                    }
                    else
                    {
                      task_status[CHATTING_TIME] = UNDONE;
                    }
                }
                already = true;
               }
                ///< Printing the the before 10 mins of finishing the task
                if ((current_time - initial_time) >= (float)(CHATTING_TIME_END - TEN_MINUTES)/SPEED_UP_FACTOR)
                {
                  printf("\nGrandma Chatting time is about to finish. get ready for the lunch time.");
                  task_t = LUNCH_TIME;
                  already = false;
                }
            break;
            
            case LUNCH_TIME:
             if(!already)
               {
                if((current_time - initial_time) < (float)(LUNCH_TIME_END - TEN_MINUTES)/SPEED_UP_FACTOR)
                {
                  printf ("\n\n Lunch time is Starting "); 
                  EnterTheTime();
                  repeat_count+=1;
                  GrandmaScheduleSequence(timeforschedule);
                  count +=1;
                }
                
                if(task_status[LUNCH_TIME] == UNDONE)
                {
                   printf ("\n\nAre You having lunch Grandma ? Yes, No: ");
                   fgets (optionstr, SIZEOPTION, stdin);
                   if (strcmp(optionstr, "YES"))
                   {
                      task_status[LUNCH_TIME] = DONE;
                   }
                   else
                   {
                      task_status[LUNCH_TIME] = UNDONE;
                   }
                }
                already = true;
               }
                ///< Printing the the before 10 mins of finishing the task
                if ((current_time - initial_time) >= (float)(LUNCH_TIME_END - TEN_MINUTES)/SPEED_UP_FACTOR)
                {
                  printf("\nGrandma Lunch time is about to finsh. Hurry up!");
                  task_t = TELEVISION_WATCHING_TIME;
                  already = false;
                }
            break;
            
            case TELEVISION_WATCHING_TIME:
            if(!already)
               {
                if((current_time - initial_time) < (float)(TELEVISION_WATCHING_END - TEN_MINUTES)/SPEED_UP_FACTOR)
                {
                  printf ("\n\nTelevision Watching time is Starting ");   
                  EnterTheTime();
                  repeat_count+=1;
                  GrandmaScheduleSequence(timeforschedule);
                  count +=1;
                }
                
                if(task_status[TELEVISION_WATCHING_TIME] == UNDONE)
                {
                   printf ("\n\nAre You watching Television Grandma ? Yes, No: ");
                   fgets (optionstr, SIZEOPTION, stdin);
                   if (strcmp(optionstr, "YES"))
                   {
                      task_status[TELEVISION_WATCHING_TIME] = DONE;
                   }
                   else
                   {
                      task_status[TELEVISION_WATCHING_TIME] = UNDONE;
                   }
                }
                already = true;
               }
                ///< Printing the the before 10 mins of finishing the task
                if ((current_time - initial_time) >= (float)(TELEVISION_WATCHING_END - TEN_MINUTES)/SPEED_UP_FACTOR)
                {
                  printf("\nGrandma television watching time is about to finish!. Get ready for the Exercise and Dance.");
                   task_t = EXERCISE_TIME;
                   already = false;
                }
            break;
            
            case EXERCISE_TIME:
            if(!already)
               {
                if((current_time - initial_time) < (float)(EXERCISE_TIME_END - TEN_MINUTES)/SPEED_UP_FACTOR)
                {
                  printf ("\n\n Exercise time is Starting "); 
                  EnterTheTime();
                  repeat_count+=1;
                  GrandmaScheduleSequence(timeforschedule);
                  count +=1;
                }
                
                if(task_status[EXERCISE_TIME] == UNDONE)
                {
                   printf ("\n\nAre You doing exercise Grandma ? Yes, No: ");
                   fgets (optionstr, SIZEOPTION, stdin);             
                   if (strcmp(optionstr, "YES"))
                   {
                      task_status[EXERCISE_TIME] = DONE;
                   }
                   else
                   {
                      task_status[EXERCISE_TIME] = UNDONE;
                   }
                }
                already = true;
               }
            
                ///< Printing the the before 10 mins of finishing the task
                if ((current_time - initial_time) >= (float)(EXERCISE_TIME_END-TEN_MINUTES)/SPEED_UP_FACTOR)
                {
                  printf("\nGrandma Exercise time is about to finish. Get Ready for dinner girl.");
                  task_t = DINNER_TIME;
                  already = false;
                }
            break;
            
            case DINNER_TIME:
             if(!already)
               {
                if((current_time - initial_time) < (float)(DINNER_TIME_END - TEN_MINUTES)/SPEED_UP_FACTOR)
                {
                  printf ("\n\n Dinner time is Starting "); 
                  EnterTheTime();
                  repeat_count+=1;
                  GrandmaScheduleSequence(timeforschedule);
                  count +=1;
                }
                
                if(task_status[DINNER_TIME] == UNDONE)
                {
                   printf ("\n\nAre You doing dinner Grandma ? Yes, No: ");
                   fgets (optionstr, SIZEOPTION, stdin);
                   if (strcmp(optionstr, "YES"))
                   {
                      task_status[DINNER_TIME] = DONE;
                   }
                   else
                   {
                      task_status[DINNER_TIME] = UNDONE;
                   }
                }
                already = true;
               }
                ///< Printing the the before 10 mins of finishing the task
                if ((current_time - initial_time) >= (float)(DINNER_TIME_END - TEN_MINUTES)/SPEED_UP_FACTOR)
                {
                  printf("\nGrandma Dinner time is about to finish. Please sleep now. ");
                  task_t = SLEEPING_TIME;
                  already = false;
                }
            break;
            
            default: 
                  printf("\nGrandma is doing nothing. Just Chilling :) ");
            break;
        } // End Switch
    } // End While

    getchar();
    return 0;
} // End Main
