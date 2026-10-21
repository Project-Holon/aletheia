#ifndef GAME_ARM9_TCBL_H
#define GAME_ARM9_TCBL_H

struct TcblTask;
typedef void (*TcblFunc)(struct TcblTask *task, void *work);

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of tcbl.c, prototypes copied from their definitions. */

struct TcblSystem;
struct TcblTask;

#include "../types.h"

void *TCBL_GetOwnedWork(struct TcblTask *task);
struct TcblTask *TCBL_GetTaskSlot(struct TcblSystem *tcbl, u32 index);
struct TcblTask *TCBL_PopFreeTask(struct TcblSystem *tcbl);
void TCBL_PushFreeTask(struct TcblSystem *tcbl, struct TcblTask *task);
void TCBL_InitTaskLinks(struct TcblSystem *tcbl, struct TcblTask *task);
void TCBL_FreeTask(struct TcblTask *task);
void *TCBL_GetTaskWork(struct TcblTask *task);
void TCBL_BuildFreeList(struct TcblSystem *tcbl);
struct TcblSystem *TCBL_Create(u16 heapId, u16 workHeapId, u32 taskCount, u32 workSize);
void TCBL_Main(struct TcblSystem *tcbl);
void TCBL_Destroy(struct TcblSystem *tcbl);
void TCBL_DeleteAllTasks(struct TcblSystem *tcbl);
void TCBL_DeleteTask(struct TcblTask *task);
struct TcblTask *TCBL_AddTask(struct TcblSystem *tcbl, TcblFunc func, u32 workSize, u32 priority);
void TCBL_SetTaskFunc(struct TcblTask *task, TcblFunc func);
void *TCBL_GetWork(struct TcblTask *task);
/* END mkheaders: generated region */

#endif
