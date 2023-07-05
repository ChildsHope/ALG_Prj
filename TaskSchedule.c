//=============================================================================================================


#include "TaskSchedule.h"

#define TASK_1MS_JITTER					(1U)
#define TASK_5MS_JITTER					(2U)
#define TASK_10MS_JITTER				(3U)
#define TASK_20MS_JITTER				(5U)
#define TASK_50MS_JITTER				(7U)
#define TASK_100MS_JITTER				(11U)

#define TASK_NUM								(6U)

void Task_1MS(void);
void Task_5MS(void);
void Task_10MS(void);
void Task_20MS(void);
void Task_50MS(void);
void Task_100MS(void);

typedef void (*pFun)(void);

typedef struct 
{
	uint8_t name;/* data */
	uint8_t taskCnt;
	pFun taskFun;    
}TaskStruct_t;

TaskStruct_t TaskStruct[TASK_NUM] = {
		{1,1,Task_1MS},
};


void TaskSchedule_Loader(void)
{

}

//=============================================================================================================
