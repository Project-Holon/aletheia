#ifndef GAME_ARM9_NET_ERR_PROC_H
#define GAME_ARM9_NET_ERR_PROC_H

typedef struct NetSaveScreenWork NetSaveScreenWork;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of net_err_proc.c, prototypes copied from their definitions. */

struct ProcSysProc;
struct Proc;
struct NetSaveProcWork;
struct NetSaveScreenInput;
struct NetSaveScreenWork;
typedef struct NetSaveScreenWork NetSaveScreenWork;

#include "../types.h"

int GFL_NET_SAVE_DeleteScreenWork(struct Proc *proc, int seq, int pwork, struct NetSaveProcWork *work);
int GFL_NET_SAVE_CreateScreenWork(void *ctx, int seq, struct NetSaveScreenInput *pwork);
int GFL_NET_SAVE_ScreenMain(u32 proc, u32 *seq, u32 pwork, u8 *ctx);
int GFL_NET_SAVE_ScreenExit(struct ProcSysProc *proc, u32 *seq, void *param, NetSaveScreenWork *work);
/* END mkheaders: generated region */

#endif
