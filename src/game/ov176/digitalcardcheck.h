#ifndef GAME_OV176_DIGITALCARDCHECK_H
#define GAME_OV176_DIGITALCARDCHECK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of digitalcardcheck.c, prototypes copied from their definitions. */

struct LiveBattleMatchWork;
struct BattleRecord;
struct WifibattlematchCallback;
typedef struct WifibattlematchCallback WifibattlematchCallback;

#include "../ov177/wifibattlematch_view_types.h"
#include "../ov176/livebattlematch_shared_types.h"
#include "../ov176/livebattlematch_shared_types.h"

void DIGITALCARDCHECK_UpdateMenu(struct LiveBattleMatchWork *obj, int a, int b);
int DIGITALCARDCHECK_GetMenuResult(struct LiveBattleMatchWork *p);
void DIGITALCARDCHECK_End(struct LiveBattleMatchWork *p,int v);
void DIGITALCARDCHECK_CreateRecord(struct LiveBattleMatchWork *p);
void DIGITALCARDCHECK_WaitRecord(struct LiveBattleMatchWork *p);
void DIGITALCARDCHECK_DeleteRecord(struct LiveBattleMatchWork *p);
int DIGITALCARDCHECK_IsRecordDone(struct LiveBattleMatchWork *p);
int DIGITALCARDCHECK_IsWorkDone(struct LiveBattleMatchWork *p);
void DIGITALCARDCHECK_SetRecordMode(struct LiveBattleMatchWork *p,int mode);
void DIGITALCARDCHECK_CreateRecord2(struct LiveBattleMatchWork *p, const WifiBattleMatchViewRecord *value);
void DIGITALCARDCHECK_DeleteRecord2(struct LiveBattleMatchWork *p);
int DIGITALCARDCHECK_IsRecord2Done(struct LiveBattleMatchWork *p);
void DIGITALCARDCHECK_CreateRecord3(struct LiveBattleMatchWork *p);
void DIGITALCARDCHECK_DeleteRecord3(struct LiveBattleMatchWork *p);
int DIGITALCARDCHECK_IsRecord3DoneA(struct LiveBattleMatchWork *p);
int DIGITALCARDCHECK_IsRecord3DoneB(struct LiveBattleMatchWork *p);
void DIGITALCARDCHECK_CopyRegulation(struct LiveBattleMatchWork *p,const void *q);
void DIGITALCARDCHECK_BuildBattleRecord(struct BattleRecord *p, struct LiveBattleMatchWork *q);
void DIGITALCARDCHECK_SetBattleRecordValue(struct BattleRecord *p, struct LiveBattleMatchWork *q);
LivebattlematchRequest *DIGITALCARDCHECK_Create(RequestConfig *p, int heap);
void DIGITALCARDCHECK_Delete(LivebattlematchRequest *p);
void DIGITALCARDCHECK_DeleteAlt(LivebattlematchRequest *p);
int DIGITALCARDCHECK_GetProcResult(LivebattlematchRequest *p);
void DIGITALCARDCHECK_SelectPhase(WifibattlematchCallback *a, int *unused, void *pArg);
void DIGITALCARDCHECK_Phase1(WifibattlematchCallback *a, int *state, void *pArg);
void DIGITALCARDCHECK_Phase2(WifibattlematchCallback *a, int *state, void *pArg);
void DIGITALCARDCHECK_Phase3(WifibattlematchCallback *a, int *state, void *pArg);
void DIGITALCARDCHECK_Phase4(WifibattlematchCallback *sys, int *state, void *pArg);
void DIGITALCARDCHECK_Phase5(WifibattlematchCallback *sys, int *state, void *pArg);
void DIGITALCARDCHECK_Phase6(WifibattlematchCallback *a, int *state, void *pArg);
void DIGITALCARDCHECK_EndPhase(WifibattlematchCallback *a, int *unusedState, void *unusedWork);
void DIGITALCARDCHECK_InitRecord(LivebattlematchRequest *p);
void DIGITALCARDCHECK_DeleteInitRecord(LivebattlematchRequest *p);
int DIGITALCARDCHECK_IsInitRecordDone(LivebattlematchRequest *p);
int DIGITALCARDCHECK_IsInitWorkDone(LivebattlematchRequest *p);
/* END mkheaders: generated region */

#endif
