#ifndef GAME_OV112_MUS_ITEM_DRAW_H
#define GAME_OV112_MUS_ITEM_DRAW_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mus_item_draw.c, prototypes copied from their definitions. */

struct McssActorPool;
struct Tagged;
struct McssActorElem;
struct G3dResource;
typedef struct McssActorPool McssActorPool;
typedef struct McssActorElem McssActorElem;

#include "../types.h"
#include "../ov112/mus_item_draw_shared_types.h"

McssActorPool *MUSICAL_MCSS_CreateActorPool(u32 owner,int count,u16 heap);
void MUSICAL_MCSS_DeleteActorPool(u8 *p);
void MUSICAL_MCSS_UpdateObject(McssActorPool *p);
void MUSICAL_MCSS_NoOp3(void *unused);
u16 MUSICAL_MCSS_GetArcFileCount(int i);
void MUSICAL_MCSS_SetupObject(u8 *elem,u8 *a,u8 *b);
int MUSICAL_MCSS_IsElemModeSupportedA(u8 *elem, int index);
int MUSICAL_MCSS_IsElemModeSupportedB(u8 *pool,int index,int mode);
int MUSICAL_MCSS_IsElemModeSupportedC(u8 *pool,int index,int mode);
int MUSICAL_MCSS_ElemHasAltDepth(u8 *elem);
int MUSICAL_MCSS_ElemKeepsFlippedHeight(u8 *elem);
void *MUSICAL_MCSS_CreateResourceArc(int type);
void MUSICAL_MCSS_FreeResourceArc(struct Tagged *resourceArc);
u16 MUSICAL_MCSS_FindFreeActorIndex(McssActorPool *pool);
McssActorElem *MUSICAL_MCSS_AddImage(McssActorPool *pool,int type,struct G3dResource *id,int *v);
McssActorElem *MUSICAL_MCSS_AddImageNoVram(McssActorPool *pool, int type, u32 id, int *v);
McssActorElem *MUSICAL_MCSS_AddElem(McssActorPool *p, u16 index, int *v, s16 a, s16 b);
void MUSICAL_MCSS_FreeElem(u8 *pool,u8 *e);
void MUSICAL_MCSS_FreeElemImage(u8 *pool, u8 *e, int type, u16 id);
void MUSICAL_MCSS_TransferVram(char *p, char *e, void *unused);
void MUSICAL_MCSS_CopyElem(void *unused, u8 *s, u8 *d);
void MUSICAL_MCSS_SetElemVisible(u8 *pool,u8 *e,u32 value);
void MUSICAL_MCSS_SetElemPos(void *unused, McssActorElem *p, const int *q);
void MUSICAL_MCSS_SetElemScale(u32 unused,McssActorElem *elem,void *q);
void MUSICAL_MCSS_SetElemRotZ(void *unused, u8 *elem, s16 a, s16 b);
void MUSICAL_MCSS_SetElemRot(void *unused, u8 *elem, s16 *a, s16 *b);
void MUSICAL_MCSS_SetElemField(void *unused, u8 *elem, u16 v);
void MUSICAL_MCSS_GetElemField(int unused, u16 *p, u16 *out);
void MUSICAL_MCSS_SetElemFlag(u8 *unused, McssActorElem *s, int flag);
int MUSICAL_MCSS_GetElemFlag(int unused, McssActorElem *p);
void MUSICAL_MCSS_GetElemOffset(u8 *elem, McssOffset *out);
void *MUSICAL_MCSS_GetActorPoolResource(McssActorPool *pool);
/* END mkheaders: generated region */

#endif
