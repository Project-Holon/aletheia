#ifndef GAME_OV220_TH_AWARD_H
#define GAME_OV220_TH_AWARD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of th_award.c, prototypes copied from their definitions. */

struct TcbTask;
struct ThAwardWork;

#include "../types.h"

int TH_AWARD_Init(void *host,void *unused,void *args);
int TH_AWARD_Exit(void *state,int unused1,int unused2,char *p);
int TH_AWARD_Main(void *unused, u32 *state, void *unused2, char *p);
void TH_AWARD_TaskNoop(struct TcbTask *unused, void *unused2);
void TH_AWARD_LoadBgAssets(struct ThAwardWork *p);
void TH_AWARD_Noop(void *work);
void TH_AWARD_CreateSpeciesActors(char *p);
void TH_AWARD_DeleteSpeciesActors(struct ThAwardWork *p);
void TH_AWARD_CreateBgActors(struct ThAwardWork *p);
void TH_AWARD_DeleteBgActors(struct ThAwardWork *p);
void TH_AWARD_SetupWindows(struct ThAwardWork *p);
void TH_AWARD_DeleteWindows(struct ThAwardWork *p);
void TH_AWARD_UploadWindows(struct ThAwardWork *o);
unsigned char TH_AWARD_GetLevelIndex(unsigned value);
/* END mkheaders: generated region */

#endif
