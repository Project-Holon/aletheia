#ifndef GAME_OV183_BR_BVRANK_PROC_H
#define GAME_OV183_BR_BVRANK_PROC_H


/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_bvrank_proc.c, prototypes copied from their definitions. */

struct BrProcArgBasic;
struct Proc;
struct CodeinSidebarWork;
struct BrUtilTask;
struct CodeinButtonArg;
struct CodeinButtonWork;
struct TcbTask;
struct BrProcArgBattle;
struct CodeinRecordWork;
struct BrProcArgProfile;
struct CodeinListWork;
struct BsubwayScoreData;
struct GameData;
struct CodeinPointActors;
struct BrCodeinTriple;
struct CodeinResultWork;
struct BrProcArgType;
struct CodeinStatWork;
struct CodeinSearchList;
struct BrRecCache;
struct BrRes;
struct Unit;
struct BrCachedRecord;
struct Entries;
struct BrProcArgSave;
struct CodeinCodeWork;
struct BrProcArgHead;
struct CodeinWorkData;
struct CodeinProfileWork;
struct BrCodeinObject;
struct BrProcArgNet;
struct CodeinUploadWork;
struct BrProcArgRecord;
struct CodeinSaveWork;
struct BrProcArgResult;
struct CodeinSoclWork;
struct CodeinStoredFns;
typedef struct BrCodeinTriple BrCodeinTriple;

#include "../types.h"

int BR_CODEIN_ListCreate(void *proc, int unused, struct BrProcArgProfile *arg);
int BR_CODEIN_ListDestroy(struct Proc *proc, int unused, struct BrProcArgProfile *arg, struct CodeinListWork *work);
int BR_CODEIN_ListMain(void *unused,u32 *state,struct BrProcArgProfile *arg,struct CodeinListWork *work);
void BR_CODEIN_ListSetupText(struct CodeinListWork *work, struct BrProcArgProfile *arg);
void BR_CODEIN_ListSetupRowA(struct CodeinListWork *work,struct BrProcArgProfile *arg);
void BR_CODEIN_ListSetupRowB(struct CodeinListWork *work,struct BrProcArgProfile *arg);
void BR_CODEIN_ListSetupRowC(struct CodeinListWork *work, struct BrProcArgProfile *arg);
void BR_CODEIN_ListSetupRowD(struct CodeinListWork *work,struct BrProcArgProfile *arg);
void BR_CODEIN_ListTeardown(struct CodeinListWork *work, struct BrProcArgProfile *arg);
void BR_CODEIN_ListSetupButtons(struct CodeinListWork *work,struct BrProcArgProfile *arg);
void BR_CODEIN_ListDeleteButtons(struct CodeinListWork *work, struct BrProcArgProfile *arg);
int BR_CODEIN_ListHitButton(struct CodeinListWork *work, int x, int y);
int BR_CODEIN_ListIsEventA(struct BsubwayScoreData *work,struct GameData *gameData);
int BR_CODEIN_ListIsEventB(struct BsubwayScoreData *work, struct GameData *gameData);
int BR_CODEIN_ListIsEventC(struct BsubwayScoreData *work, struct GameData *gameData);
void BR_CODEIN_ListCreateActor(struct CodeinPointActors *work, void *manager, const BrCodeinTriple *arg, unsigned int value, s16 x, s16 y, u16 heap);
void BR_CODEIN_ListDeleteActor(struct CodeinPointActors *work);
void BR_CODEIN_ListSetActorAnim(struct CodeinPointActors *work, u32 value);
int BR_CODEIN_ResultCreate(void *proc, int seq, struct BrProcArgProfile *arg);
int BR_CODEIN_ResultDestroy(void *proc, int seq, struct BrProcArgProfile *arg, struct CodeinResultWork *work);
int BR_CODEIN_ResultMain(void *unused,u32 *state,struct BrProcArgProfile *arg,struct CodeinResultWork *work);
void BR_CODEIN_ResultSetupTextWin(struct CodeinResultWork *work, struct BrProcArgProfile *arg);
void BR_CODEIN_ResultSetupRowA(struct CodeinResultWork *work,struct BrProcArgProfile *arg);
void BR_CODEIN_ResultSetupRowB(struct CodeinResultWork *work,struct BrProcArgProfile *arg);
void BR_CODEIN_ResultSetupRowC(struct CodeinResultWork *work,struct BrProcArgProfile *arg);
void BR_CODEIN_ResultTeardown(struct CodeinResultWork *work, struct BrProcArgProfile *arg);
void BR_CODEIN_ResultSetupButtons(struct CodeinResultWork *work,struct BrProcArgProfile *arg);
void BR_CODEIN_ResultDeleteButtons(struct CodeinResultWork *work, struct BrProcArgProfile *arg);
int BR_CODEIN_ResultHitButton(struct CodeinResultWork *work, int x, int y);
int BR_CODEIN_StatCreate(void *proc, int seq, struct BrProcArgType *arg);
int BR_CODEIN_StatDestroy(void *proc, int seq, struct BrProcArgType *arg, struct CodeinStatWork *work);
int BR_CODEIN_StatMain(int proc, int seq, int arg, struct CodeinStatWork *work);
void BR_CODEIN_StatSetup(struct BrUtilTask *task,int *state,struct CodeinStatWork *work);
void BR_CODEIN_StatTeardown(struct BrUtilTask *proc, int seq, struct CodeinStatWork *work);
void BR_CODEIN_StatStepFadeIn(struct BrUtilTask *task, int *state, struct CodeinStatWork *work);
void BR_CODEIN_StatStepFadeOut(struct BrUtilTask *work, int *state, struct CodeinStatWork *arg);
void BR_CODEIN_StatStepMenu(struct BrUtilTask *task, int *state, struct CodeinStatWork *work);
void BR_CODEIN_SearchStep(struct BrUtilTask *task,u32 *state,struct CodeinStatWork *work);
void BR_CODEIN_SearchStepText(struct BrUtilTask *work, int *state, struct CodeinStatWork *arg);
void BR_CODEIN_SearchStepFade(struct BrUtilTask *work, int *state, struct CodeinStatWork *arg);
void BR_CODEIN_SearchCreateList(struct CodeinSearchList *menu,struct BrRecCache *base,struct BrRes *res,struct Unit *mgr,void *listParam,void *tapFx,u16 *sel,u16 heap);
void BR_CODEIN_SearchDeleteList(struct CodeinSearchList *work);
void BR_CODEIN_SearchMainList(struct CodeinSearchList *work, u16 heapId);
int BR_CODEIN_SearchGetHitId(struct CodeinSearchList *work);
void BR_CODEIN_SearchCreateActor(struct CodeinSearchList *search,struct Unit *mgr,u16 heap);
void BR_CODEIN_SearchDeleteActor(struct CodeinSearchList *work);
void BR_CODEIN_SearchUpdateActor(struct CodeinSearchList *search,int first,short step,u16 heap);
void BR_CODEIN_SearchBuildHeader(struct BrCachedRecord *work, struct Entries *out);
int BR_CODEIN_SearchHitBox(int x, int y);
/* END mkheaders: generated region */

#endif
