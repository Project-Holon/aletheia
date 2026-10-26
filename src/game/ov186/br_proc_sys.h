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

int BR_PROC_SYS_Init(void *obj,int unused,struct BrProcGameState *q);
int BR_PROC_SYS_Exit(struct Proc *sys,int unused,int unused2,struct BrProcSys *p);
int BR_PROC_SYS_Main(int sys,int *state,int unused,struct BrProcSys *p);
void BR_PROC_SYS_BuildBasicRecord(struct BrProcArgBasic *out,struct BrProcSys *source,int unused,int type);
void BR_PROC_SYS_NoopA(void);
void BR_PROC_SYS_BuildChoiceRecord(struct BrProcArgChoice *out,struct BrProcSys *source,int *ctx,int type);
void BR_PROC_SYS_BuildBattleRecord(struct BrProcArgBattle *out,struct BrProcSys *source,const char *ctx,int type);
void BR_PROC_SYS_SetPendingFlag(u32 *a, struct BrProcSys *b);
void BR_PROC_SYS_BuildProfileRecord(struct BrProcArgProfile *r5, struct BrProcSys *r4);
void BR_PROC_SYS_NoopB(void);
void BR_PROC_SYS_BuildProfileRecord2(struct BrProcArgStats *r5, struct BrProcSys *r4);
void BR_PROC_SYS_NoopC(void);
void BR_PROC_SYS_BuildTypeRecord(struct BrProcArgType *out, struct BrProcSys *source, const int *ctx, int type);
void BR_PROC_SYS_NoopD(void);
void BR_PROC_SYS_CopyRecord1(struct BrProcArgSave *p,struct BrProcSys *q);
void BR_PROC_SYS_NoopE(void);
void BR_PROC_SYS_CopyRecord2(struct BrProcArgHead *out,struct BrProcSys *source);
void BR_PROC_SYS_NoopF(void);
void BR_PROC_SYS_CopyRecord3(struct BrProcArgNet *p,struct BrProcSys *q);
void BR_PROC_SYS_NoopG(void);
void BR_PROC_SYS_BuildRecord(struct BrProcArgRecord *out,struct BrProcSys *source,int *ctx,int type);
void BR_PROC_SYS_UpdateRecord(char *p,struct BrProcSys *q);
void BR_PROC_SYS_BuildRecord2(struct BrProcArgResult *out,struct BrProcSys *source,const char *ctx,int type);
void BR_PROC_SYS_NoopH(void);
void BR_PROC_SYS_NoopI(void);
void BR_PROC_SYS_LoadRecords(struct BrProcRecords *p, int skip, struct GameData *sys, int heap);
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
