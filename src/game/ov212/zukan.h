#ifndef GAME_OV212_ZUKAN_H
#define GAME_OV212_ZUKAN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zukan.c, prototypes copied from their definitions. */

struct Proc;
struct ZukanParam;
struct ZukanWork;
struct Blk37;
struct Obj;
struct ZknSearchActorTemplate;

#include "../types.h"

int ZUKAN_Create(struct Proc *obj,int unused,struct ZukanParam *ctx);
int ZUKAN_Update(int a,int b,int c,struct ZukanWork *p);
int ZUKAN_Delete(struct Proc *obj, void *b, void *c, struct ZukanWork *p);
void ZUKAN_FreeIdList(struct ZukanWork *p);
int ZUKAN_SetResumeState(struct ZukanWork *p, int v);
u32 ZUKAN_GetResumeState(struct ZukanWork *p);
void ZUKAN_StartProc211(struct ZukanWork *p);
int ZUKAN_ResumeProc211(struct ZukanWork *p);
void ZUKAN_StartProc209(struct ZukanWork *p);
int ZUKAN_ResumeProc209(struct ZukanWork *p);
void ZUKAN_StartProc210(struct ZukanWork *p);
int ZUKAN_ResumeProc210(struct ZukanWork *p);
void ZUKAN_StartProc208(struct ZukanWork *p);
int ZUKAN_ResumeProc208(struct ZukanWork *p);
u16 ZUKAN_LoadListAndSelection(struct Blk37 *save,u16 **out,u16 heap);
void ZUKAN_FixLastViewedSpecies(void *p,u16 *ids,unsigned count);
int ZUKAN_IsNationalMode(struct Blk37 *p);
void ZUKAN_InitQuery(struct Blk37 *p, u8 *out);
void ZUKAN_StartWipeIn(u32 heap);
void ZUKAN_StartWipeOut(u32 heap);
void ZUKAN_TickCounter(u32 a, u32 b, u32 *counter);
struct Obj *ZUKAN_CreateActor(void *bank, const struct ZknSearchActorTemplate *t, u16 heap);
/* END mkheaders: generated region */

#endif
