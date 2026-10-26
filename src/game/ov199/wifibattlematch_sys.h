#ifndef GAME_OV199_WIFIBATTLEMATCH_SYS_H
#define GAME_OV199_WIFIBATTLEMATCH_SYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wifibattlematch_sys.c, prototypes copied from their definitions. */

struct WifiBattleMatchSysArgs;
struct WifiBattleMatchSysWork;
struct WifiBattleMatchSysRuleCmd;
struct WifiBattleMatchSysProc;
struct WifiBattleMatchSysMatchCmd;
struct WifiBattleMatchSysRegRecord;
struct Out;
struct WifiBattleMatchSysSetupArg;
struct WifiBattleMatchSysStartCmd;
struct WifiBattleMatchSysSyncCmd;
struct WifiBattleMatchSysVersionCmd;
struct WifiBattleMatchSysRule2Cmd;
struct BattleSetupParam;
struct WifiBattleMatchSysSetupOut;
struct WifiBattleMatchSysSetup;
struct WifiBattleMatchSysStep;
struct Proc;
struct WifiBattleMatchSysSubWork;
struct PWk;

#include "../types.h"

int WIFIBATTLEMATCH_SYS_CreateWork(void *a, int unused, struct WifiBattleMatchSysArgs *arg);
int WIFIBATTLEMATCH_SYS_DestroyWork(void *sys, int unused, void *data, struct WifiBattleMatchSysWork *p);
int WIFIBATTLEMATCH_SYS_WaitTask(int unused,int *state,int unused2,struct WifiBattleMatchSysWork *p);
struct WifiBattleMatchSysRuleCmd *WIFIBATTLEMATCH_SYS_BuildRuleCommand(struct WifiBattleMatchSysProc *obj, u16 heap, struct WifiBattleMatchSysWork *ctx);
int WIFIBATTLEMATCH_SYS_HandleRuleCommand(struct WifiBattleMatchSysProc *obj, struct WifiBattleMatchSysRuleCmd *command, struct WifiBattleMatchSysWork *ctx);
struct WifiBattleMatchSysMatchCmd *WIFIBATTLEMATCH_SYS_BuildMatchCommand(int unused, u16 heap, struct WifiBattleMatchSysWork *ctx);
int WIFIBATTLEMATCH_SYS_HandleMatchCommand(struct WifiBattleMatchSysProc *obj, struct WifiBattleMatchSysMatchCmd *command, struct WifiBattleMatchSysWork *ctx);
struct WifiBattleMatchSysRegRecord *WIFIBATTLEMATCH_SYS_BuildRegulationRecord(int unused, u16 heap, struct WifiBattleMatchSysWork *p);
int WIFIBATTLEMATCH_SYS_HandlePartyCommand(struct WifiBattleMatchSysProc *obj, struct WifiBattleMatchSysRegRecord *command, struct WifiBattleMatchSysWork *ctx);
struct Out *WIFIBATTLEMATCH_SYS_BuildSetupRecord(int unused, u16 heap, struct WifiBattleMatchSysWork *p);
int WIFIBATTLEMATCH_SYS_ApplySetup(void *manager, struct WifiBattleMatchSysSetupArg *arg, struct WifiBattleMatchSysWork *p);
struct WifiBattleMatchSysStartCmd *WIFIBATTLEMATCH_SYS_BuildStartCommand(int unused, u16 heap, struct WifiBattleMatchSysWork *ctx);
int WIFIBATTLEMATCH_SYS_HandleStartCommand(struct WifiBattleMatchSysProc *p, struct WifiBattleMatchSysStartCmd *q, struct WifiBattleMatchSysWork *work);
struct WifiBattleMatchSysSyncCmd *WIFIBATTLEMATCH_SYS_BuildSyncCommand(struct WifiBattleMatchSysProc *unused, u16 heap, struct WifiBattleMatchSysWork *p);
int WIFIBATTLEMATCH_SYS_HandleSyncCommand(struct WifiBattleMatchSysProc *a, struct WifiBattleMatchSysSyncCmd *work, struct WifiBattleMatchSysWork *p);
struct WifiBattleMatchSysVersionCmd *WIFIBATTLEMATCH_SYS_BuildVersionCommand(int unused, u16 heap, struct WifiBattleMatchSysWork *p);
int WIFIBATTLEMATCH_SYS_HandleVersionCommand(struct WifiBattleMatchSysProc *p, struct WifiBattleMatchSysVersionCmd *q, struct WifiBattleMatchSysWork *work);
struct WifiBattleMatchSysRule2Cmd *WIFIBATTLEMATCH_SYS_BuildRule2Command(struct WifiBattleMatchSysProc *unused, u16 heap, struct WifiBattleMatchSysWork *p);
int WIFIBATTLEMATCH_SYS_HandleRule2Command(struct WifiBattleMatchSysProc *a, struct WifiBattleMatchSysRule2Cmd *work, struct WifiBattleMatchSysWork *p);
struct BattleSetupParam *WIFIBATTLEMATCH_SYS_BuildSlotCommand(struct WifiBattleMatchSysProc *unused, u16 heap, struct WifiBattleMatchSysWork *p);
int WIFIBATTLEMATCH_SYS_DestroySlotCommand(struct WifiBattleMatchSysProc *p, struct BattleSetupParam *q);
void WIFIBATTLEMATCH_SYS_AllocPartyBuffers(struct WifiBattleMatchSysWork *p, u16 heap);
void WIFIBATTLEMATCH_SYS_FreePartyBuffers(struct WifiBattleMatchSysWork *p);
void WIFIBATTLEMATCH_SYS_FillSetupRecord(struct WifiBattleMatchSysSetupOut *p,void *party1,void *party2,void *save,void *reg,int setting,struct BattleSetupParam *record,struct WifiBattleMatchSysSetup *other,int mode);
void WIFIBATTLEMATCH_SYS_CountBoxSpecies(struct BattleSetupParam *box, unsigned char *a, unsigned char *b);
void WIFIBATTLEMATCH_SYS_GetPartyCounts(const struct BattleSetupParam *box, unsigned char *a, unsigned char *b);
struct WifiBattleMatchSysProc *WIFIBATTLEMATCH_SYS_CreateProcWork(const struct WifiBattleMatchSysStep *a, int b, struct WifiBattleMatchSysWork *c, int heap);
void WIFIBATTLEMATCH_SYS_DeleteProcWork(struct WifiBattleMatchSysProc *p);
int WIFIBATTLEMATCH_SYS_RunScreen(struct WifiBattleMatchSysProc *s);
int WIFIBATTLEMATCH_SYS_GetResult(struct WifiBattleMatchSysProc *p);
unsigned char WIFIBATTLEMATCH_SYS_GetKind(struct WifiBattleMatchSysProc *p);
void WIFIBATTLEMATCH_SYS_SetStep(struct WifiBattleMatchSysProc *p, int value);
void WIFIBATTLEMATCH_SYS_SetStepDone(struct WifiBattleMatchSysProc *p);
int WIFIBATTLEMATCH_SYS_CreateSubWork(struct Proc *p,int unused,struct WifiBattleMatchSysSubWork *q);
int WIFIBATTLEMATCH_SYS_DestroySubWork(struct Proc *a, void *b, void *c, struct WifiBattleMatchSysSubWork *work);
int WIFIBATTLEMATCH_SYS_HandleNetState(void *proc, int *seq, struct PWk *pw, struct WifiBattleMatchSysSubWork *wk);
/* END mkheaders: generated region */

#endif
