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
extern void *func_021A21B8(WeatherTaskSys *task);
extern int func_021A2108(WeatherTaskSys *task, int arcId, int memberId);
extern int func_021A2114(WeatherTaskSys *task, int arcId, unsigned int memberId);
extern void func_021A2120(WeatherTaskSys *task, int phase);
extern void func_021A22E0(WeatherTaskSys *task, int slope, int offset, int phase);
extern void func_021A231C(WeatherTaskSys *task, int phase);
extern void func_021A232C(WeatherTaskSys *task, int slope, int offset, int frames, int mode);
extern void func_021A2390(WeatherTaskSys *task, int endOffset, int frames, int mode);
extern int func_021A23B0(WeatherTaskSys *task);
extern int func_021A23D4(WeatherTaskSys *task);
extern int func_021A23E8(WeatherTaskSys *task);
extern int func_021A23F4(WeatherTaskSys *task);
extern int func_021A2400(WeatherTaskSys *task);
extern int func_021A240C(WeatherTaskSys *task);
extern int func_021A2418(WeatherTaskSys *task);

/* Stages of the clear weather kind (WeatherKindDef callbacks: task, variant, heap id). */
int func_021EE740(WeatherTaskSys *task, int variant, int heapId);
int func_021EE788(WeatherTaskSys *task, int variant, int heapId);
int func_021EE7F0(WeatherTaskSys *task, int variant, int heapId);
int func_021EE838(WeatherTaskSys *task, int variant, int heapId);
int func_021EE83C(WeatherTaskSys *task, int variant, int heapId);
int func_021EE874(WeatherTaskSys *task, int variant, int heapId);

#endif
