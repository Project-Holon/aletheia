#ifndef GAME_ARM9_NET_ERR_PROC_H
#define GAME_ARM9_NET_ERR_PROC_H

/* Public functions of net_err_proc.c, prototypes copied from their definitions. */

struct ProcSysProc;
struct NetSaveScreenWork;
typedef struct NetSaveScreenWork NetSaveScreenWork;

#include "../types.h"

int GFL_NET_SAVE_DeleteScreenWork(int proc, int seq, int pwork, int work);
int GFL_NET_SAVE_CreateScreenWork(void *ctx, int seq, int pwork);
int GFL_NET_SAVE_ScreenMain(u32 proc, u32 *seq, u32 pwork, u8 *ctx);
int GFL_NET_SAVE_ScreenExit(struct ProcSysProc *proc, u32 *seq, void *param, NetSaveScreenWork *work);

#endif
