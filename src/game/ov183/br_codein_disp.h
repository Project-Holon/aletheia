#ifndef GAME_OV183_BR_CODEIN_DISP_H
#define GAME_OV183_BR_CODEIN_DISP_H


/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_codein_disp.c, prototypes copied from their definitions. */

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

void BR_CODEIN_ProfileSetupSprite(struct CodeinProfileWork *work);
void BR_CODEIN_ProfileDeleteActor(struct CodeinProfileWork *work);
void BR_CODEIN_ProfileCreateRecordActors(struct CodeinProfileWork *work);
void BR_CODEIN_ProfileCreateMarkerActors(struct CodeinProfileWork *work);
void BR_CODEIN_ProfileCreateArrowActors(struct CodeinProfileWork *work);
void BR_CODEIN_ProfileSetActorVisible(struct CodeinProfileWork *work, int index, int visible);
void BR_CODEIN_ProfileSetActorPos(struct CodeinProfileWork *work,int i);
void BR_CODEIN_ProfileAddActorSurfacePos(struct CodeinProfileWork *coords, int index);
void BR_CODEIN_ProfileUpdateActorAnims(struct CodeinProfileWork *work);
int BR_CODEIN_ProfileGetActorIndex(int tag, int mode);
void BR_CODEIN_ProfileUpdateActorVisible(struct CodeinProfileWork *work);
void BR_CODEIN_ProfileSetActorAnimFrame(struct CodeinProfileWork *work,int animated);
void BR_CODEIN_ProfileUpdateActorPos(struct CodeinProfileWork *work);
void BR_CODEIN_ProfileCreateOam(struct CodeinProfileWork *work);
void BR_CODEIN_ProfileDeleteOam(struct CodeinProfileWork *work);
void BR_CODEIN_ProfileDeleteBgHandle(struct CodeinProfileWork *work);
void BR_CODEIN_ProfileCreateOamObjects(struct CodeinProfileWork *work);
void BR_CODEIN_ProfilePrintOamObject(struct CodeinProfileWork *object,Index index,int x,int y,int unused);
void BR_CODEIN_ProfileSetActorAnim(struct CodeinProfileWork *work,int state);
void BR_CODEIN_ProfileInitRecordLayout(struct CodeinProfileWork *profile);
void BR_CODEIN_ProfileSetAnimSeq(struct CodeinProfileWork *work, int v);
int BR_CODEIN_ProfileCreateAllActors(struct CodeinProfileWork *work);
int BR_CODEIN_ProfileReturnTrue(void);
s32 BR_CODEIN_ProfileUpdatePendingAndButtons(struct CodeinProfileWork *work);
int BR_CODEIN_ProfileUpdateScrollAnim(struct CodeinProfileWork *work);
int BR_CODEIN_ProfileUpdateActorAnim(struct CodeinProfileWork *work);
void BR_CODEIN_ProfileBuildAnimName(struct CodeinProfileWork *work);
void BR_CODEIN_ProfileApplyRecords(struct CodeinProfileWork *p);
void BR_CODEIN_ProfileCreateButtons(struct CodeinProfileWork *work);
void BR_CODEIN_ProfileHandleInput(u32 idx, s32 arg, void *);
void BR_CODEIN_ProfileApplyPendingStep(struct CodeinProfileWork *work);
void BR_CODEIN_ProfileClear(struct CodeinProfileWork *work);
int BR_CODEIN_ProfileFindActorIndex(struct CodeinProfileWork *work,int value);
int BR_CODEIN_ProfileFindRecord(const struct CodeinProfileWork *work, int value);
/* END mkheaders: generated region */

#endif
