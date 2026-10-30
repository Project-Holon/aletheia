#ifndef GAME_OV183_BR_CODEIN_H
#define GAME_OV183_BR_CODEIN_H

typedef enum { STATE_ZERO=0, STATE_TWELVE=12 } CodeinSoclState;
typedef enum {INDEX_0,INDEX_1} Index;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_codein.c, prototypes copied from their definitions. */

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

int BR_CODEIN_CodeCreate(void *obj, int unused, struct BrProcArgSave *arg);
int BR_CODEIN_CodeDestroy(void *work, int unused, struct BrProcArgSave *arg, struct CodeinCodeWork *data);
int BR_CODEIN_CodeMain(void *unused,u32 *state,struct BrProcArgSave *arg,struct CodeinCodeWork *work);
int BR_CODEIN_CodeSetupButtons(struct CodeinCodeWork *work,struct BrProcArgSave *arg);
int BR_CODEIN_CodeDeleteButtons(struct CodeinCodeWork *work, struct BrProcArgSave *arg);
int BR_CODEIN_CodeStepInput(struct CodeinCodeWork *work,struct BrProcArgSave *arg);
int BR_CODEIN_CodeSetupMenu(struct CodeinCodeWork *work,struct BrProcArgSave *arg);
int BR_CODEIN_CodeDeleteMenu(struct CodeinCodeWork *work, struct BrProcArgSave *arg);
int BR_CODEIN_CodeStepMenu(struct CodeinCodeWork *work, struct BrProcArgSave *arg);
unsigned BR_CODEIN_CodeOpenPokeSearch(struct CodeinCodeWork *work, struct BrProcArgSave *arg);
int BR_CODEIN_CodeClosePokeSearch(struct CodeinCodeWork *work);
int BR_CODEIN_CodeStepPokeSearch(struct CodeinCodeWork *work, struct BrProcArgSave *arg);
int BR_CODEIN_CodeSetupPokeList(struct CodeinCodeWork *work,struct BrProcArgSave *arg);
int BR_CODEIN_CodeDeletePokeList(struct CodeinCodeWork *work, struct BrProcArgSave *arg);
int BR_CODEIN_CodeStepPokeList(struct CodeinCodeWork *work, struct BrProcArgSave *arg);
void BR_CODEIN_CodeSetupText(struct CodeinCodeWork *work, struct BrProcArgSave *arg);
void BR_CODEIN_CodeDeleteText(struct CodeinCodeWork *work,struct BrProcArgSave *arg);
void BR_CODEIN_CodeSetMenuText(struct CodeinCodeWork *work,struct BrProcArgSave *arg,int mode);
int BR_CODEIN_CodeHitTestOptions(void);
int BR_CODEIN_ProfileScreenCreate(void *task, int unused, struct BrProcArgHead *arg);
int BR_CODEIN_ProfileScreenDestroy(void *proc, int unused, struct BrProcArgHead *arg, struct CodeinWorkData *work);
int BR_CODEIN_ProfileScreenMain(int unused, int *state, struct BrProcArgHead *arg, struct CodeinWorkData *work);
void BR_CODEIN_ProfileUpdate(struct CodeinProfileWork *work);
int BR_CODEIN_ProfileGetState(struct CodeinProfileWork *work);
u64 BR_CODEIN_ProfileGetValue(struct CodeinProfileWork *work);
void BR_CODEIN_ProfileDestroy(struct CodeinProfileWork *work);
struct BrCodeinObject *BR_CODEIN_ProfileCreateObject(int heap, int n, void *actorSys, void *res, void *handles, int *entries);
void BR_CODEIN_ProfileDestroyObject(struct BrCodeinObject *work);
void BR_CODEIN_ProfileNoop(struct TcbTask *unused, void *work);
/* END mkheaders: generated region */

#endif
