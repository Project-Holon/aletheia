#ifndef GAME_OV183_BR_RECORD_PROC_H
#define GAME_OV183_BR_RECORD_PROC_H


/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_record_proc.c, prototypes copied from their definitions. */

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

int BR_CODEIN_SidebarCreate(int *task, int unused, struct BrProcArgBasic *work);
int BR_CODEIN_SidebarDestroy(struct Proc *task,int seq,int arg,struct CodeinSidebarWork *work);
int BR_CODEIN_SidebarMain(int proc,int seq,int arg,struct CodeinSidebarWork *work);
void BR_CODEIN_SidebarStepIntro(struct BrUtilTask *task,int *state,struct CodeinSidebarWork *work);
void BR_CODEIN_SidebarStepSlideIn(struct BrUtilTask *task, int *state, struct CodeinSidebarWork *work);
void BR_CODEIN_SidebarStepSlideOut(struct BrUtilTask *task, int *state, struct CodeinSidebarWork *work);
void BR_CODEIN_SidebarClearStep(struct BrUtilTask *task);
int BR_CODEIN_ButtonCreate(int *task,int seq,struct CodeinButtonArg *work);
int BR_CODEIN_ButtonDestroy(struct Proc *task,int seq,struct CodeinButtonArg *arg,struct CodeinButtonWork *work);
int BR_CODEIN_ButtonMain(int *task,int *state,struct CodeinButtonArg *work,struct CodeinButtonWork *arg);
void BR_CODEIN_ButtonLoadFadePalettes(struct TcbTask *unused, void *workArg);
int BR_CODEIN_RecordCreate(int *task,int *state,struct BrProcArgBattle *arg);
int BR_CODEIN_RecordDestroy(struct Proc *task,int seq,struct BrProcArgBattle *arg,struct CodeinRecordWork *work);
int BR_CODEIN_RecordMain(int proc,int seq,int arg,struct CodeinRecordWork *work);
void BR_CODEIN_RecordStepCreateProfile(struct BrUtilTask *task, int b, struct CodeinRecordWork *work);
void BR_CODEIN_RecordStepFadeIn(struct BrUtilTask *task, int *state, struct CodeinRecordWork *work);
void BR_CODEIN_RecordStepFadeOut(struct BrUtilTask *task, int *state, struct CodeinRecordWork *work);
void BR_CODEIN_RecordStepDeleteProfile(struct BrUtilTask *task,int b,struct CodeinRecordWork *work);
void BR_CODEIN_RecordStepMenu(struct BrUtilTask *task,int *state,struct CodeinRecordWork *work);
void BR_CODEIN_RecordStepProfileText(struct BrUtilTask *task,int *state,struct CodeinRecordWork *work);
void BR_CODEIN_RecordStepRequest(struct BrUtilTask *task,int *state,struct CodeinRecordWork *work);
void BR_CODEIN_RecordStepReceive(struct BrUtilTask *task,int *state,struct CodeinRecordWork *work);
void BR_CODEIN_RecordStepSave(struct BrUtilTask *task,int *state,struct CodeinRecordWork *work);
void BR_CODEIN_RecordStepConfirm(struct BrUtilTask *task,int *state,struct CodeinRecordWork *work);
void BR_CODEIN_RecordSetupProfile(struct CodeinRecordWork *work,struct BrProcArgBattle *arg);
void BR_CODEIN_RecordSetupActors(struct CodeinRecordWork *work,void *manager,void *party,u16 heap);
void BR_CODEIN_RecordCreateProfileScreen(struct CodeinRecordWork *work, struct BrProcArgBattle *arg);
void BR_CODEIN_RecordDeleteProfileScreen(struct CodeinRecordWork *work,struct BrProcArgBattle *unused);
void BR_CODEIN_RecordDeleteActors(struct CodeinRecordWork *work,struct BrProcArgBattle *arg);
void BR_CODEIN_RecordSetupButtons(struct CodeinRecordWork *work,struct BrProcArgBattle *arg);
void BR_CODEIN_RecordDeleteButtons(struct CodeinRecordWork *work, struct BrProcArgBattle *arg);
void BR_CODEIN_RecordCreateTextWin(struct CodeinRecordWork *work, struct BrProcArgBattle *unused);
void BR_CODEIN_RecordDeleteTextWin(struct CodeinRecordWork *work, struct BrProcArgBattle *unused);
void BR_CODEIN_RecordSetupTextWin(struct CodeinRecordWork *work, struct BrProcArgBattle *arg);
void BR_CODEIN_RecordTeardownTextWin(struct CodeinRecordWork *work, struct BrProcArgBattle *arg);
int BR_CODEIN_RecordIsMultiBattle(void *work);
int BR_CODEIN_RecordIsType2(void *work);
int BR_CODEIN_RecordHitProfileToggle(struct CodeinRecordWork *work, int x, int y);
int BR_CODEIN_RecordHitRecordPanel(struct CodeinRecordWork *work, int x, int y);
int BR_CODEIN_RecordHitOptionLeft(struct CodeinRecordWork *work, int x, int y);
int BR_CODEIN_RecordHitOptionRight(struct CodeinRecordWork *work, int x, int y);
/* END mkheaders: generated region */

#endif
