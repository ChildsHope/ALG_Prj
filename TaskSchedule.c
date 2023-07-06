//=============================================================================================================

/*************
**************


************/

/*************** Include **********************/

#include "TaskSchedule.h"

/***************** Macro **********************/

#define TASK_1MS_JITTER					(1U)
#define TASK_5MS_JITTER					(2U)
#define TASK_10MS_JITTER				(3U)
#define TASK_20MS_JITTER				(5U)
#define TASK_50MS_JITTER				(7U)
#define TASK_100MS_JITTER				(11U)

#define TASK_1MS_COUNTER				(1U)
#define TASK_5MS_COUNTER				(5U)
#define TASK_10MS_COUNTER				(10U)
#define TASK_20MS_COUNTER				(20U)
#define TASK_50MS_COUNTER				(50U)
#define TASK_100MS_COUNTER				(100U)

#define TASK_NUM						(6U)

typedef void (*pFun_t)(void);

/************ Function Declaration ************/
void Task_1MS(void);
void Task_5MS(void);
void Task_10MS(void);
void Task_20MS(void);
void Task_50MS(void);
void Task_100MS(void);


/*********** Variable Declaration *************/
typedef struct 
{
	uint8_t initShift;/**/
	uint8_t taskPeriod;
	pFun_t taskFun;    
}TaskStruct_t;

uint8_t u8_TimerTask[TASK_NUM];
uint8_t u8_flag_1MS = 0;

TaskStruct_t TaskStruct[TASK_NUM] = {
	
	{TASK_1MS_JITTER, 	TASK_1MS_COUNTER,	&Task_1MS},
	{TASK_5MS_JITTER,  	TASK_5MS_COUNTER,	&Task_5MS},
	{TASK_10MS_JITTER, 	TASK_10MS_COUNTER,	&Task_10MS},
	{TASK_20MS_JITTER,	TASK_20MS_COUNTER,	&Task_20MS},
	{TASK_50MS_JITTER,	TASK_50MS_COUNTER,	&Task_50MS},
	{TASK_100MS_JITTER,	TASK_100MS_COUNTER,	&Task_100MS},
};

/************* Global Function ***************/
void TaskSchedule_Init(void)
{
	uint8_t i;
	
	for(i = 0; i<TASK_NUM; i++)
	{
		u8_TimerTask[i] = TaskStruct[i].initShift + TaskStruct[i].taskPeriod;
	}
}

void TaskSchedule_Loader(void)
{
	uint8_t i;
	
	if(u8_flag_1MS)
	{
		u8_flag_1MS = 0;
		
		for(i = 0; i<TASK_NUM; i++)
		{
			u8_TimerTask[i]--;
			
			if(0 == u8_TimerTask[i])
			{
				TaskStruct[i].taskFun();
				u8_TimerTask[i] = TaskStruct[i].taskPeriod;
			}
		}
	}
}

/************* Private Function **************/
void Task_1MS(void)
{
	
}

void Task_5MS(void)
{
	
}

void Task_10MS(void)
{
	
}

void Task_20MS(void)
{
	
}

void Task_50MS(void)
{
	
}

void Task_100MS(void)
{
	
}

//=============================================================================================================
