#ifndef GAME_OV133_DUP_FITTING_ITEM_H
#define GAME_OV133_DUP_FITTING_ITEM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dup_fitting_item.c, prototypes copied from their definitions. */

struct DupFittingWork;
struct Object;
struct DupFittingItemData;
struct McssActorElem;

#include "../types.h"

void DUP_FITTING_ITEM_NoOp(struct DupFittingWork *p, u8 n);
u8 *DUP_FITTING_ITEM_CreateList(u16 heap, int max);
void DUP_FITTING_ITEM_DeleteList(void *list);
void DUP_FITTING_ITEM_InsertElem(u8*list,u8*elem);
void DUP_FITTING_ITEM_InsertElemTail(u8*list,u8*elem);
void DUP_FITTING_ITEM_RemoveElem(u8*list,u8*elem);
void *DUP_FITTING_ITEM_ListGetHead(char *list);
unsigned short DUP_FITTING_ITEM_ListGetCount(char *list);
int DUP_FITTING_ITEM_ListIsFull(char *list);
u8 *DUP_FITTING_ITEM_CreateElem(u16 heap, struct Object*pool, u8*data, int*pos);
void DUP_FITTING_ITEM_DeleteElem(u8*elem,u8*pool);
void DUP_FITTING_ITEM_FreeElemImage(u8*elem,u8*pool,u8*data);
u8 *DUP_FITTING_ITEM_ElemGetNext(u8 *elem);
struct DupFittingItemData *DUP_FITTING_ITEM_ElemGetData(u8 *elem);
void DUP_FITTING_ITEM_ElemSetSprite(u8 *elem, u8 *value);
u8 *DUP_FITTING_ITEM_ElemGetSprite(u8 *elem);
struct McssActorElem *DUP_FITTING_ITEM_ElemGetRenderElem(u8 *elem);
void DUP_FITTING_ITEM_ElemSetPos(u8 *elem, const u8 *src);
u8 *DUP_FITTING_ITEM_ElemGetPos(u8 *elem);
void DUP_FITTING_ITEM_ElemSetBasePos(u8 *elem, const u8 *src);
u8 *DUP_FITTING_ITEM_ElemGetBasePos(u8 *elem);
void DUP_FITTING_ITEM_ElemSetStartScale(u8 *elem, u32 value);
u32 DUP_FITTING_ITEM_ElemGetStartScale(u8 *elem);
void DUP_FITTING_ITEM_ElemSetScale(u8 *elem, u32 value);
int DUP_FITTING_ITEM_ElemGetScale(char *elem);
void DUP_FITTING_ITEM_ElemSetAnimFrames(char *elem, u32 value);
u16 DUP_FITTING_ITEM_ElemGetAnimFrames(char *elem);
void DUP_FITTING_ITEM_ElemSetFrameIndex(char *elem, int value);
u32 DUP_FITTING_ITEM_ElemGetFrameIndex(char *elem);
int DUP_FITTING_ITEM_ElemHitTest(u8 *elem, int x, int y);
unsigned int DUP_FITTING_ITEM_ElemHitDistance(u8 *elem, int x, int y);
/* END mkheaders: generated region */

#endif
