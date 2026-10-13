#ifndef OV024_WEATHER_CLEAR_TYPES_H
#define OV024_WEATHER_CLEAR_TYPES_H

/* Clear weather kind (overlay 24, weather id 0): only the zone fog, no particles (WeatherKindDef of the weather task, ov021 weather_task.c).
 * Needs WeatherTaskSys from the including file: the main file includes
 * ../ov021/weather_task_types.h, a file at another depth declares the typedef. */

/* Work buffer of the clear weather kind (the task's workBuffer). */
typedef struct WeatherZoneFogWork {
    int fadeStarted;  /* 0 until the fade-in has been issued */
} WeatherZoneFogWork;

/* Weather task services (ov021 weather_task.c) used by the clear weather kind. */
extern void *WEATHER_TASK_GetWorkBuffer(WeatherTaskSys *task);
extern int WEATHER_TASK_FadeLight(WeatherTaskSys *task, int arcId, int memberId);
extern int WEATHER_TASK_SetLight(WeatherTaskSys *task, int arcId, unsigned int memberId);
extern void WEATHER_TASK_ResetLight(WeatherTaskSys *task, int phase);
extern void WEATHER_TASK_InitFog(WeatherTaskSys *task, int slope, int offset, int phase);
extern void WEATHER_TASK_DisableFog(WeatherTaskSys *task, int phase);
extern void WEATHER_TASK_ChangeFog(WeatherTaskSys *task, int slope, int offset, int frames, int mode);
extern void WEATHER_TASK_ChangeFogOffset(WeatherTaskSys *task, int endOffset, int frames, int mode);
extern int WEATHER_TASK_IsFogIdle(WeatherTaskSys *task);
extern int WEATHER_TASK_IsZoneFogActive(WeatherTaskSys *task);
extern int WEATHER_TASK_CheckZoneFogA(WeatherTaskSys *task);
extern int WEATHER_TASK_CheckZoneFogB(WeatherTaskSys *task);
extern int WEATHER_TASK_GetZoneFogC(WeatherTaskSys *task);
extern int WEATHER_TASK_GetZoneFogD(WeatherTaskSys *task);
extern int WEATHER_TASK_GetZoneFogE(WeatherTaskSys *task);

/* Stages of the clear weather kind (WeatherKindDef callbacks: task, variant, heap id). */
int WEATHER_CLEAR_Begin(WeatherTaskSys *task, int variant, int heapId);
int func_021EE788(WeatherTaskSys *task, int variant, int heapId);
int func_021EE7F0(WeatherTaskSys *task, int variant, int heapId);
int func_021EE838(WeatherTaskSys *task, int variant, int heapId);
int func_021EE83C(WeatherTaskSys *task, int variant, int heapId);
int func_021EE874(WeatherTaskSys *task, int variant, int heapId);

#endif
