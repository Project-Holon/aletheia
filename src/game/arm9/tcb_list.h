#ifndef GAME_ARM9_TCB_LIST_H
#define GAME_ARM9_TCB_LIST_H

#include "../types.h"

struct TcbSystem;
struct TcbTask;

/* Task callback: the task being run and the work pointer given to TCB_AddTask. */
typedef void (*TcbFunc)(struct TcbTask *task, void *work);

struct TcbTask *TCB_AddTask(struct TcbSystem *sys, TcbFunc func, void *work, u32 priority);
struct TcbTask *TCB_InsertTask(struct TcbSystem *sys, TcbFunc func, void *work, u32 priority);

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of tcb_list.c, prototypes copied from their definitions. */

struct TcbSystem;
struct TcbTask;

#include "../types.h"

void TCB_BuildFreeStack(struct TcbSystem *sys);
struct TcbTask *TCB_AllocTask(struct TcbSystem *sys);
u32 TCB_FreeTask(struct TcbSystem *sys, struct TcbTask *task);
u32 TCB_GetTaskOffset(u32 idx);
struct TcbSystem *TCB_Init(u32 capacity, struct TcbSystem *sys);
void TCB_Reset(struct TcbSystem *sys);
void TCB_Main(struct TcbSystem *sys);
void TCB_Noop(struct TcbSystem *sys);
struct TcbTask *TCB_AddTask(struct TcbSystem *sys, TcbFunc func, void *work, u32 priority);
struct TcbTask *TCB_InsertTask(struct TcbSystem *sys, TcbFunc func, void *work, u32 priority);
u32 TCB_DeleteTask(struct TcbTask *task);
/* END mkheaders: generated region */

#endif
