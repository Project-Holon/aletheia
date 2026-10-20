#ifndef GAME_OV199_WIFIBATTLEMATCH_SYS_H
#define GAME_OV199_WIFIBATTLEMATCH_SYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wifibattlematch_sys.c, prototypes copied from their definitions. */

struct Out;
struct WifiBattleMatchSysWork;
struct WifiBattleMatchSysSetupRecord;
struct WifiBattleMatchSysProc;
struct Proc;
struct PWk;
struct MyWk;

#include "../types.h"

int WIFIBATTLEMATCH_SYS_CreateWork(void *a, int unused, u8 *arg);
int WIFIBATTLEMATCH_SYS_DestroyWork(void *sys, int unused, void *data, char *p);
int WIFIBATTLEMATCH_SYS_WaitTask(int unused,int *state,int unused2,char *p);
int *WIFIBATTLEMATCH_SYS_BuildRuleCommand(void *obj, u16 heap, char *ctx);
int WIFIBATTLEMATCH_SYS_HandleRuleCommand(void *obj, int *command, int *ctx);
int *WIFIBATTLEMATCH_SYS_BuildMatchCommand(int unused, u16 heap, char *ctx);
int WIFIBATTLEMATCH_SYS_HandleMatchCommand(void *obj, int *command, int *ctx);
u8 *WIFIBATTLEMATCH_SYS_BuildRegulationRecord(int unused, u16 heap, u8 *p);
int WIFIBATTLEMATCH_SYS_HandlePartyCommand(void *obj, int *command, int *ctx);
struct Out *WIFIBATTLEMATCH_SYS_BuildSetupRecord(int unused, u16 heap, struct WifiBattleMatchSysWork *p);
int WIFIBATTLEMATCH_SYS_ApplySetup(void *manager, u8 *arg, u8 *p);
int *WIFIBATTLEMATCH_SYS_BuildStartCommand(int unused, u16 heap, char *ctx);
int WIFIBATTLEMATCH_SYS_HandleStartCommand(char *p, char *q, char *work);
void *WIFIBATTLEMATCH_SYS_BuildSyncCommand(void *unused, u16 heap, char *p);
int WIFIBATTLEMATCH_SYS_HandleSyncCommand(char *a, char *work, char *p);
unsigned *WIFIBATTLEMATCH_SYS_BuildVersionCommand(int unused, u16 heap, u8 *p);
int WIFIBATTLEMATCH_SYS_HandleVersionCommand(char *p, char *q, char *work);
void *WIFIBATTLEMATCH_SYS_BuildRule2Command(void *unused, u16 heap, char *p);
int WIFIBATTLEMATCH_SYS_HandleRule2Command(char *a, void *work, char *p);
void *WIFIBATTLEMATCH_SYS_BuildSlotCommand(void *unused, u16 heap, char *p);
int WIFIBATTLEMATCH_SYS_DestroySlotCommand(char *p, char *q);
void WIFIBATTLEMATCH_SYS_AllocPartyBuffers(char *p, u16 heap);
void WIFIBATTLEMATCH_SYS_FreePartyBuffers(u8 *p);
void WIFIBATTLEMATCH_SYS_FillSetupRecord(u8 *p,void *party1,void *party2,u8 *save,void *reg,int setting,u8 *record,void *other,int mode);
void WIFIBATTLEMATCH_SYS_CountBoxSpecies(struct WifiBattleMatchSysSetupRecord *box, unsigned char *a, unsigned char *b);
void WIFIBATTLEMATCH_SYS_GetPartyCounts(const struct WifiBattleMatchSysSetupRecord *box, unsigned char *a, unsigned char *b);
void *WIFIBATTLEMATCH_SYS_CreateProcWork(void *a, void *b, void *c, int heap);
void WIFIBATTLEMATCH_SYS_DeleteProcWork(char *p);
int WIFIBATTLEMATCH_SYS_RunScreen(struct WifiBattleMatchSysProc *s);
int WIFIBATTLEMATCH_SYS_GetResult(char *p);
unsigned char WIFIBATTLEMATCH_SYS_GetKind(char *p);
void WIFIBATTLEMATCH_SYS_SetStep(char *p, int value);
void WIFIBATTLEMATCH_SYS_SetStepDone(unsigned char *p);
int WIFIBATTLEMATCH_SYS_CreateSubWork(struct Proc *p,int unused,char *q);
int WIFIBATTLEMATCH_SYS_DestroySubWork(void *a, void *b, void *c, char *work);
int WIFIBATTLEMATCH_SYS_HandleNetState(void *proc, int *seq, struct PWk *pw, struct MyWk *wk);
/* END mkheaders: generated region */

#endif
