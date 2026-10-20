#ifndef GAME_OV176_DIGITALCARDCHECK_H
#define GAME_OV176_DIGITALCARDCHECK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of digitalcardcheck.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov176/livebattlematch_shared_types.h"
#include "../ov176/livebattlematch_shared_types.h"

void DIGITALCARDCHECK_UpdateMenu(void *obj, int a, int b);
int DIGITALCARDCHECK_GetMenuResult(u8 *p);
void DIGITALCARDCHECK_End(u8 *p,int v);
void DIGITALCARDCHECK_CreateRecord(u8 *p);
void DIGITALCARDCHECK_WaitRecord(int *p);
void DIGITALCARDCHECK_DeleteRecord(int *p);
int DIGITALCARDCHECK_IsRecordDone(u8 *p);
int DIGITALCARDCHECK_IsWorkDone(int *p);
void DIGITALCARDCHECK_SetRecordMode(u8 *p,int mode);
void DIGITALCARDCHECK_CreateRecord2(char *p, const struct WifiBattleMatchViewRecord *value);
void DIGITALCARDCHECK_DeleteRecord2(int *p);
int DIGITALCARDCHECK_IsRecord2Done(u8 *p);
void DIGITALCARDCHECK_CreateRecord3(char *p);
void DIGITALCARDCHECK_DeleteRecord3(u8 *p);
int DIGITALCARDCHECK_IsRecord3DoneA(u8 *p);
int DIGITALCARDCHECK_IsRecord3DoneB(u8 *p);
void DIGITALCARDCHECK_CopyRegulation(u8 *p,const void *q);
void DIGITALCARDCHECK_BuildBattleRecord(u8 *p, u8 *q);
void DIGITALCARDCHECK_SetBattleRecordValue(int *p, int *q);
LivebattlematchRequest *DIGITALCARDCHECK_Create(RequestConfig *p, int heap);
void DIGITALCARDCHECK_Delete(int *p);
void DIGITALCARDCHECK_DeleteAlt(int *p);
int DIGITALCARDCHECK_GetProcResult(int *p);
void DIGITALCARDCHECK_SelectPhase(int a, int unused, char *p);
void DIGITALCARDCHECK_Phase1(int *a, int *state, int *p);
void DIGITALCARDCHECK_Phase2(int *a, int *state, int *p);
void DIGITALCARDCHECK_Phase3(int *a, int *state, int *p);
void DIGITALCARDCHECK_Phase4(int sys, int *state, int *p);
void DIGITALCARDCHECK_Phase5(int sys, int *state, int *p);
void DIGITALCARDCHECK_Phase6(int a, int *state, int *p);
void DIGITALCARDCHECK_EndPhase(int a);
void DIGITALCARDCHECK_InitRecord(int *p);
void DIGITALCARDCHECK_DeleteInitRecord(int *p);
int DIGITALCARDCHECK_IsInitRecordDone(int *p);
int DIGITALCARDCHECK_IsInitWorkDone(int *p);
/* END mkheaders: generated region */

#endif
