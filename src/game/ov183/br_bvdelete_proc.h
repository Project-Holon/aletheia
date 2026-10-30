#ifndef GAME_OV183_BR_BVDELETE_PROC_H
#define GAME_OV183_BR_BVDELETE_PROC_H


/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_bvdelete_proc.c, prototypes copied from their definitions. */

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

int BR_CODEIN_UploadCreate(struct Proc *obj,int unused,struct BrProcArgNet *arg);
int BR_CODEIN_UploadDestroy(struct Proc *proc,int seq,struct BrProcArgNet *arg,struct CodeinUploadWork *work);
int BR_CODEIN_UploadMain(int proc,int seq,int arg,struct CodeinUploadWork *work);
void BR_CODEIN_UploadStepFadeIn(struct BrUtilTask *task,int *state,struct CodeinUploadWork *work);
void BR_CODEIN_UploadStepFadeOut(struct BrUtilTask *task,int *state,struct CodeinUploadWork *work);
void BR_CODEIN_UploadStep(struct BrUtilTask *task,int *state,struct CodeinUploadWork *work);
int BR_CODEIN_SaveCreate(struct Proc *obj,int unused,struct BrProcArgRecord *arg);
int BR_CODEIN_SaveDestroy(struct Proc *obj,int seq,struct BrProcArgRecord *arg,struct CodeinSaveWork *work);
int BR_CODEIN_SaveMain(int proc,int seq,int arg,struct CodeinSaveWork *work);
void BR_CODEIN_SaveStepFadeIn(struct BrUtilTask *task,int *state,struct CodeinSaveWork *work);
void BR_CODEIN_SaveStepFadeOut(struct BrUtilTask *task,int *state,struct CodeinSaveWork *work);
void BR_CODEIN_SaveStepVideo(struct BrUtilTask *task,int *state,struct CodeinSaveWork *work);
void BR_CODEIN_SaveSetupText(struct CodeinSaveWork *work,const struct BrProcArgRecord *input);
void BR_CODEIN_SaveDeleteTextWin(struct CodeinSaveWork *work, struct BrProcArgRecord *res);
void BR_CODEIN_SaveTeardown(struct CodeinSaveWork *work,struct BrProcArgRecord *arg);
int BR_CODEIN_SaveHitOptionLeft(struct CodeinSaveWork *work, int x, int y);
int BR_CODEIN_SaveHitOptionRight(struct CodeinSaveWork *work, int x, int y);
int BR_CODEIN_SoclCreate(void *obj,int seq,struct BrProcArgResult *arg);
int BR_CODEIN_SoclDestroy(struct Proc *obj,int seq,int arg,struct CodeinSoclWork *work);
int BR_CODEIN_SoclMain(int proc,int seq,int arg,struct CodeinSoclWork *work);
void BR_CODEIN_SoclStep(struct BrUtilTask *task,CodeinSoclState *state,struct CodeinSoclWork *work);
void BR_CODEIN_MenuStep(struct BrUtilTask *task,int *state,struct CodeinSoclWork *work);
void BR_CODEIN_MenuStepInput(struct BrUtilTask *task,unsigned *state,struct CodeinSoclWork *work);
void BR_CODEIN_MenuStepSave(struct BrUtilTask *task,unsigned *state,struct CodeinSoclWork *work);
void BR_CODEIN_CallAndClearStepFn(struct CodeinStoredFns *holder, struct CodeinSoclWork *work, struct BrProcArgResult *ctx);
void BR_CODEIN_CallAndClearDestroyFn(struct CodeinStoredFns *holder, struct CodeinSoclWork *work, struct BrProcArgResult *ctx);
void BR_CODEIN_CopySoclResource(struct CodeinStoredFns *resource);
void BR_CODEIN_SoclSetupText(struct CodeinSoclWork *work, struct BrProcArgResult *arg);
void BR_CODEIN_SoclTeardown(struct CodeinSoclWork *work,struct BrProcArgResult *arg);
/* END mkheaders: generated region */

#endif
