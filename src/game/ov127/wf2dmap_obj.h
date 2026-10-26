#ifndef GAME_OV127_WF2DMAP_OBJ_H
#define GAME_OV127_WF2DMAP_OBJ_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wf2dmap_obj.c, prototypes copied from their definitions. */

struct Wf2dmapObjList;
typedef struct Wf2dmapObjList Wf2dmapObjList;

#include "../types.h"
#include "../ov127/wf2dmap_obj_types.h"

Wf2dmapObjList *WF2DMAP_OBJ_CreateList(u32 count, u32 heap);
void WF2DMAP_OBJ_DeleteList(u8 *p);
void WF2DMAP_OBJ_DispatchById(void *a, u8 *q);
void WF2DMAP_OBJ_UpdateList(u8 *p);
u32 WF2DMAP_OBJ_GetCount(u8 *p);
Wf2dmapObj *WF2DMAP_OBJ_Create(void *a,u16 *s);
void WF2DMAP_OBJ_Clear(void *p);
char *WF2DMAP_OBJ_FindById(Wf2dmapObjList *p, unsigned id);
char *WF2DMAP_OBJ_GetByIndex(Wf2dmapObjList *p, int i);
char *WF2DMAP_OBJ_FindById2(Wf2dmapObjList *p,unsigned id);
char *WF2DMAP_OBJ_GetByIndex2(Wf2dmapObjList *p,int i);
int WF2DMAP_OBJ_GetSlot(u8 *p, unsigned int i);
void WF2DMAP_OBJ_SetSlot(void *p, int i, int v);
Wf2dmapPos WF2DMAP_OBJ_OffsetPos(Wf2dmapPos p,int i);
unsigned char WF2DMAP_OBJ_GetDirectionTableEntry(int i);
char *WF2DMAP_OBJ_AllocSlot(Wf2dmapObjList *p);
Wf2dmapPos WF2DMAP_OBJ_GetPos(char *p);
Wf2dmapPos WF2DMAP_OBJ_GetDestPos(char *p);
Wf2dmapPos WF2DMAP_OBJ_GetCurrentPos(char *p);
void WF2DMAP_OBJ_SetPos(char *p, Wf2dmapPairU16 v);
void WF2DMAP_OBJ_SetDestPos(char *p, Wf2dmapPairU16 v);
u8 *WF2DMAP_OBJ_FindAtPos(u8 *p, void *list, int n);
void WF2DMAP_OBJ_ApplyCommand(char *p,char *q);
/* END mkheaders: generated region */

#endif
