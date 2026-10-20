#ifndef GAME_OV222_ZENKOKU_ZUKAN_AWARD_H
#define GAME_OV222_ZENKOKU_ZUKAN_AWARD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zenkoku_zukan_award.c, prototypes copied from their definitions. */

struct ZenkokuZukanAwardWork;

int ZENKOKU_ZUKAN_AWARD_Init(void *owner,void *unused,void *input);
int ZENKOKU_ZUKAN_AWARD_Exit(void*scene,int unused1,int unused2,char*p);
int ZENKOKU_ZUKAN_AWARD_Main(int unused, int *state, int unused2, unsigned char *p);
void ZENKOKU_ZUKAN_AWARD_Task(void);
void ZENKOKU_ZUKAN_AWARD_LoadBgAssets(struct ZenkokuZukanAwardWork *p);
void ZENKOKU_ZUKAN_AWARD_Noop(struct ZenkokuZukanAwardWork *p);
void ZENKOKU_ZUKAN_AWARD_SetupWindows(struct ZenkokuZukanAwardWork *p);
void ZENKOKU_ZUKAN_AWARD_DeleteWindows(struct ZenkokuZukanAwardWork *p);
void ZENKOKU_ZUKAN_AWARD_FlushWindows(struct ZenkokuZukanAwardWork *p);
int ZENKOKU_ZUKAN_AWARD_IsWindowsReady(char*p);
void ZENKOKU_ZUKAN_AWARD_SetupTiles(struct ZenkokuZukanAwardWork *p);
void ZENKOKU_ZUKAN_AWARD_CreateActor(struct ZenkokuZukanAwardWork *p);
void ZENKOKU_ZUKAN_AWARD_DeleteActor(struct ZenkokuZukanAwardWork *p);
void ZENKOKU_ZUKAN_AWARD_SetupActorPos(char*p);
void ZENKOKU_ZUKAN_AWARD_UpdateActor(struct ZenkokuZukanAwardWork *p);
int ZENKOKU_ZUKAN_AWARD_IsActorIdle(struct ZenkokuZukanAwardWork *p);
void ZENKOKU_ZUKAN_AWARD_Callback(void);
/* END mkheaders: generated region */

#endif
