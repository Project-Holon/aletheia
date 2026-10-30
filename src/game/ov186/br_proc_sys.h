#ifndef GAME_OV186_BR_PROC_SYS_H
#define GAME_OV186_BR_PROC_SYS_H

#include "../ov186/br_proc_sys_types.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_proc_sys.c, prototypes copied from their definitions. */

struct BrProcGameState;
struct Proc;
struct BrProcSys;
struct BrProcArgBasic;
struct BrProcArgChoice;
struct BrProcArgBattle;
struct BrProcArgProfile;
struct BrProcArgStats;
struct BrProcArgType;
struct BrProcArgSave;
struct BrProcArgHead;
struct BrProcArgNet;
struct BrProcArgRecord;
struct BrProcArgResult;
struct BrProcRecords;
struct GameData;
struct BrProcSysContext;
struct BrProcOps;
struct BrProcSlot;

#include "../types.h"

struct BrProcSysContext *BR_PROC_SYS_Create(unsigned fallback, const struct BrProcOps *base, unsigned count, struct BrProcSys *arg, unsigned *list, unsigned short heap);
void BR_PROC_SYS_Delete(struct BrProcSysContext *p);
void BR_PROC_SYS_RunSlot(struct BrProcSysContext *p);
int BR_PROC_SYS_IsDone(struct BrProcSysContext *p);
unsigned BR_PROC_SYS_GetSlotId(struct BrProcSysContext *p);
void BR_PROC_SYS_PopEntry(struct BrProcSysContext *ctx);
void BR_PROC_SYS_PushEntry(struct BrProcSysContext *ctx, unsigned index);
void BR_PROC_SYS_SetupWindow(struct BrProcSysContext *p);
void BR_PROC_SYS_FlushWindows(struct BrProcSysContext *p);
void BR_PROC_SYS_InitEntry(struct BrProcSlot *p,int a,const struct BrProcOps *b);
void BR_PROC_SYS_ClearEntry(struct BrProcSlot *p);
/* END mkheaders: generated region */

#endif
