#ifndef GAME_OV205_SAVE_SCREEN_H
#define GAME_OV205_SAVE_SCREEN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of save_screen.c, prototypes copied from their definitions. */

struct SaveScreenContext;
struct SaveScreenWork;
struct ProcOwner;
struct SaveScreenNoticeWork;
typedef struct SaveScreenContext SaveScreenContext;
typedef struct SaveScreenWork SaveScreenWork;
typedef struct SaveScreenNoticeWork SaveScreenNoticeWork;

#include "../types.h"

int SAVE_SCREEN_Init(void *owner,int unused,void **args);
int SAVE_SCREEN_Main(void *unused,SaveScreenState *state,SaveScreenContext *context,SaveScreenWork *p);
int SAVE_SCREEN_Exit(void *p);
void SAVE_SCREEN_Setup(SaveScreenWork *p, SaveScreenContext *context);
void SAVE_SCREEN_Delete(SaveScreenWork *p);
void SAVE_SCREEN_SetupBackground(u16 heap);
void SAVE_SCREEN_DeleteBackground(void);
void SAVE_SCREEN_PrintEntry(SaveScreenWork *p,unsigned entry,s16 index,s16 kind);
void SAVE_SCREEN_SnapshotParty(SaveScreenWork *p);
void SAVE_SCREEN_SetTrainerDate(SaveScreenWork *p);
void SAVE_SCREEN_SetTrainerFlag(SaveScreenWork *p);
void SAVE_SCREEN_SaveFieldClock(SaveScreenWork *p);
void SAVE_SCREEN_AppendPartyRecord(SaveScreenWork *p);
void SAVE_SCREEN_PartSaveMain(SaveScreenWork *p);
int SAVE_SCREEN_NoticeInit(struct ProcOwner *obj,u32 unused,SaveScreenContext *ctx);
int SAVE_SCREEN_NoticeMain(void *input,u32 *state,u32 unused,SaveScreenNoticeWork *p);
int SAVE_SCREEN_NoticeExit(void *p);
void SAVE_SCREEN_SetupNoticeBackground(u16 heap);
void SAVE_SCREEN_DeleteNoticeBackground(void);
void SAVE_SCREEN_PrintText(SaveScreenNoticeWork *p,u32 index,s16 x,s16 y);
/* END mkheaders: generated region */

#endif
