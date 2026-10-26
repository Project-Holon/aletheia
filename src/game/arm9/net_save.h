#ifndef GAME_ARM9_NET_SAVE_H
#define GAME_ARM9_NET_SAVE_H

#include "../types.h"
#include "../arm9/procsys.h"

struct GameData;

/* Screen procs of the net save overlay (ov115). */
extern const ProcData gNetSaveMainProc;
extern const ProcData gNetSaveRetryProc;

struct NetSaveTask *GFL_NET_SAVE_Create(u32 heapId, struct GameData *gameData);
struct NetSaveTask *GFL_NET_SAVE_CreateWithCallback(u32 heapId, struct GameData *gameData, void (*callback)(void *arg), void *callbackArg);

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of net_save.c, prototypes copied from their definitions. */

struct NetSaveTask;
struct NetSaveProcWork;

#include "../types.h"

void GFL_NET_SAVE_SetStep(struct NetSaveTask *task, void (*step)(struct NetSaveTask *task));
struct NetSaveTask *GFL_NET_SAVE_Create(u32 heapId, struct GameData *gameData);
struct NetSaveTask *GFL_NET_SAVE_CreateWithCallback(u32 heapId, struct GameData *gameData, void (*callback)(void *arg), void *callbackArg);
u32 GFL_NET_SAVE_CheckFinished(struct NetSaveTask *task);
void GFL_NET_SAVE_Delete(struct NetSaveTask *task);
void GFL_NET_SAVE_StepBegin(struct NetSaveTask *task);
void GFL_NET_SAVE_StepWaitSaveStart(struct NetSaveTask *task);
void GFL_NET_SAVE_StepWaitSync72(struct NetSaveTask *task);
void GFL_NET_SAVE_StepDelay(struct NetSaveTask *task);
void GFL_NET_SAVE_StepWaitSync73(struct NetSaveTask *task);
void GFL_NET_SAVE_StepProgress(struct NetSaveTask *task);
void GFL_NET_SAVE_StepFinish(struct NetSaveTask *task);
int GFL_NET_SAVE_InitWork(void *proc);
int GFL_NET_SAVE_Main(u32 proc, u32 seq, u32 parentWork, struct NetSaveProcWork *work);
/* END mkheaders: generated region */

#endif
