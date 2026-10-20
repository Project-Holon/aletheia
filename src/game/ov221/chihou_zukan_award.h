#ifndef GAME_OV221_CHIHOU_ZUKAN_AWARD_H
#define GAME_OV221_CHIHOU_ZUKAN_AWARD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of chihou_zukan_award.c, prototypes copied from their definitions. */

struct ChihouZukanAwardWork;

int CHIHOU_ZUKAN_AWARD_Init(void *owner,void *unused,void *input);
int CHIHOU_ZUKAN_AWARD_Exit(void *owner,void *unused1,void *unused2,char *p);
int CHIHOU_ZUKAN_AWARD_Main(int unused, int *state, int unused2, unsigned char *p);
void CHIHOU_ZUKAN_AWARD_Task(void);
void CHIHOU_ZUKAN_AWARD_LoadBgAssets(struct ChihouZukanAwardWork *p);
void CHIHOU_ZUKAN_AWARD_Noop(char *p);
void CHIHOU_ZUKAN_AWARD_SetupWindows(struct ChihouZukanAwardWork *p);
void CHIHOU_ZUKAN_AWARD_DeleteWindows(struct ChihouZukanAwardWork *p);
void CHIHOU_ZUKAN_AWARD_FlushWindows(struct ChihouZukanAwardWork *p);
int CHIHOU_ZUKAN_AWARD_IsWindowsReady(unsigned char *p);
void CHIHOU_ZUKAN_AWARD_SetupTiles(struct ChihouZukanAwardWork *p);
void CHIHOU_ZUKAN_AWARD_CreateActor(struct ChihouZukanAwardWork *p);
void CHIHOU_ZUKAN_AWARD_DeleteActor(struct ChihouZukanAwardWork *p);
void CHIHOU_ZUKAN_AWARD_SetupActorPos(char *p);
void CHIHOU_ZUKAN_AWARD_UpdateActor(struct ChihouZukanAwardWork *p);
Bool CHIHOU_ZUKAN_AWARD_IsActorIdle(struct ChihouZukanAwardWork *p);
void CHIHOU_ZUKAN_AWARD_Setup3d(void);
/* END mkheaders: generated region */

#endif
