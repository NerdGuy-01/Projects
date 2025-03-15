#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
const int BAR_LINES = 60;
const int MAX_TASK =5;
typedef struct
{
    int id;
    int progress;
    int step;
}Task;
void print(Task task)
{
 int number_of_sign = task.progress*BAR_LINES/100;
    printf(" Task %d :[",task.id);
    for(int i =1;i<=BAR_LINES ; i++)
    {
        if(i< number_of_sign)
        {
        printf("=");
        }
        else
        {
            printf(" ");
        }
    }
    printf("] %d%%\n",task.progress);
}
void clear_screen()
{
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}
int main()
{ 
    srand(time(0));
  Task task[MAX_TASK];
  for(int i=1;i<=MAX_TASK;i++)
  {
    task[i].id = i;
    task[i].progress = 0;
    task[i].step = (rand()%5)+1;
  }
  int task_complete = 1;
  while(task_complete)
  {
    task_complete = 0;
    clear_screen();
     for(int i=1;i<=MAX_TASK;i++)
     {
      task[i].progress += task[i].step;
      if(task[i].progress > 100)
      {
        task[i].progress = 100;
      }
      else if (task[i].progress < 100)
      {
       task_complete = 1;
      }
      print(task[i]);
     }
     sleep(1);
  }
  printf("All task completed!");
   return 0;
}
    