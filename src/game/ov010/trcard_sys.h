#ifndef GAME_OV010_TRCARD_SYS_H
#define GAME_OV010_TRCARD_SYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of trcard_sys.c, prototypes copied from their definitions. */

struct ProcSys;
struct TrainerCardParam;
struct TrainerCardWork;
struct MinimalWork;
struct ViewWork;
struct EditWork;
typedef struct TrainerCardParam TrainerCardParam;
typedef struct TrainerCardWork TrainerCardWork;
typedef struct MinimalWork MinimalWork;
typedef struct ViewWork ViewWork;
typedef struct EditWork EditWork;

#include "../types.h"
#include "../ov010/field_event_types.h"

int TRCARD_SYS_RunChildProc(struct ProcSys **childSlot);
int TRCARD_SYS_Init(void *proc, int state, TrainerCardParam *param);
int TRCARD_SYS_InitMinimal(void *proc, int state, void *param);
int TRCARD_SYS_Main(void *proc, int *state, TrainerCardParam *param, TrainerCardWork *work);
int TRCARD_SYS_Exit(void *proc, int state, TrainerCardParam *param, TrainerCardWork *work);
int TRCARD_SYS_ExitMinimal(void *proc, int state, void *param, MinimalWork *work);
int TRCARD_SYS_StateChooseScreen(TrainerCardWork *work, TrainerCardParam *param);
int TRCARD_SYS_StateStartCardProc(TrainerCardWork *work);
int TRCARD_SYS_StateWaitCardProc(TrainerCardWork *work);
int TRCARD_SYS_StateStartEditProc(TrainerCardWork *work);
int TRCARD_SYS_StateWaitEditProc(TrainerCardWork *work);
int TRCARD_SYS_StateStartBadgeProc(TrainerCardWork *work);
int TRCARD_SYS_StateWaitBadgeProc(TrainerCardWork *work);
u32 TRCARD_SYS_SumCappedRecords(void *records, int group, u32 cap);
void TRCARD_SYS_BuildProfile(TrainerCardProfile *out, void *save, int mode, int flag, volatile u16 heap);
ViewWork *TRCARD_SYS_CreateViewWork(void *cardData, u32 heapId, void *profile);
EditWork *TRCARD_SYS_CreateEditWork(void *cardData, u8 *profile, u32 heapId);
int TRCARD_SYS_CountStars(void *save);
int TRCARD_SYS_ScrCmdSetRecordFlag36(void *unused, void *scriptCtx);
int TRCARD_SYS_ScrCmdStartFieldProc(void *unused, void *scriptCtx);
int TRCARD_SYS_ScrCmdRunScriptTask(void *unused, void *scriptCtx);
void TRCARD_SYS_SetRecordFlag36(void *gameSystem);
/* END mkheaders: generated region */

#endif
