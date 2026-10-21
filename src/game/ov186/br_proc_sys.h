#ifndef GAME_OV186_BR_PROC_SYS_H
#define GAME_OV186_BR_PROC_SYS_H

#include "../ov186/br_proc_sys_types.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_proc_sys.c, prototypes copied from their definitions. */

struct BrProcSysContext;
struct BrProcQuery;

#include "../types.h"

int BR_PROC_SYS_Init(void *obj,int unused,char *q);
int BR_PROC_SYS_Exit(int sys,int unused,int unused2,int *p);
int BR_PROC_SYS_Main(int sys,int *state,int unused,int *p);
void BR_PROC_SYS_BuildBasicRecord(int *out,int *source,int unused,int type);
void BR_PROC_SYS_NoopA(void);
void BR_PROC_SYS_BuildChoiceRecord(int *out,int *source,int *ctx,int type);
void BR_PROC_SYS_BuildBattleRecord(int *out,int *source,const char *ctx,int type);
void BR_PROC_SYS_SetPendingFlag(u32 *a, u32 *b);
void BR_PROC_SYS_BuildProfileRecord(char *r5, int *r4);
void BR_PROC_SYS_NoopB(void);
void BR_PROC_SYS_BuildProfileRecord2(char *r5, int *r4);
void BR_PROC_SYS_NoopC(void);
void BR_PROC_SYS_BuildTypeRecord(int *out, int *source, const int *ctx, int type);
void BR_PROC_SYS_NoopD(void);
void BR_PROC_SYS_CopyRecord1(char *p,char *q);
void BR_PROC_SYS_NoopE(void);
void BR_PROC_SYS_CopyRecord2(int *out,int *source);
void BR_PROC_SYS_NoopF(void);
void BR_PROC_SYS_CopyRecord3(char *p,char *q);
void BR_PROC_SYS_NoopG(void);
void BR_PROC_SYS_BuildRecord(int *out,int *source,int *ctx,int type);
void BR_PROC_SYS_UpdateRecord(char *p,char *q);
void BR_PROC_SYS_BuildRecord2(int *out,int *source,const char *ctx,int type);
void BR_PROC_SYS_NoopH(void);
void BR_PROC_SYS_NoopI(void);
void BR_PROC_SYS_LoadRecords(char *p, int skip, void *sys, int heap);
struct BrProcSysContext *BR_PROC_SYS_Create(unsigned fallback, void *base, unsigned count, unsigned arg, unsigned *list, unsigned short heap);
void BR_PROC_SYS_Delete(int *p);
void BR_PROC_SYS_RunSlot(char *p);
int BR_PROC_SYS_IsDone(int *p);
unsigned BR_PROC_SYS_GetSlotId(struct BrProcQuery *p);
void BR_PROC_SYS_PopEntry(unsigned *ctx);
void BR_PROC_SYS_PushEntry(unsigned *ctx, unsigned index);
void BR_PROC_SYS_SetupWindow(struct BrProcSysContext *p);
void BR_PROC_SYS_FlushWindows(struct BrProcSysContext *p);
void BR_PROC_SYS_InitEntry(char *p,int a,int b);
void BR_PROC_SYS_ClearEntry(void *p);
/* END mkheaders: generated region */

#endif
