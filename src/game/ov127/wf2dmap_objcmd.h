#ifndef GAME_OV127_WF2DMAP_OBJCMD_H
#define GAME_OV127_WF2DMAP_OBJCMD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wf2dmap_objcmd.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov127/wf2dmap_obj_types.h"

void WF2DMAP_OBJCMD_Update(u8 *p);
void WF2DMAP_OBJCMD_StartCmd0(char *p, Wf2dmapPos v, int n);
void WF2DMAP_OBJCMD_StartCmd1(char *p, Wf2dmapPos v, int n);
void WF2DMAP_OBJCMD_StartCmd2(char *p, Wf2dmapPos v, int n);
void WF2DMAP_OBJCMD_StartCmd3(char *p, Wf2dmapPos v, int n);
void WF2DMAP_OBJCMD_StartCmd4(char *p, Wf2dmapPos v, int n);
void WF2DMAP_OBJCMD_StartCmd5(char *p, Wf2dmapPos v, int n);
void WF2DMAP_OBJCMD_StartCmd6(char *p, Wf2dmapPos v, int n);
void WF2DMAP_OBJCMD_StartCmd7(char *p, Wf2dmapPos v, int n);
void WF2DMAP_OBJCMD_StartCmd8(char *p, Wf2dmapPos v, int n);
void WF2DMAP_OBJCMD_StartCmd9(char *p, Wf2dmapPos v, int n);
void WF2DMAP_OBJCMD_StartCmd10(char *p, Wf2dmapPos v, int n);
void WF2DMAP_OBJCMD_StartCmd11(void *p, Wf2dmapPos v, int n);
int WF2DMAP_OBJCMD_StepNoop(void);
int WF2DMAP_OBJCMD_StepAdvance(void *p);
int WF2DMAP_OBJCMD_StepAdvanceSnap(void *p);
int WF2DMAP_OBJCMD_StepAdvanceSnap2(void *p);
int WF2DMAP_OBJCMD_StepNoop2(void);
int WF2DMAP_OBJCMD_StepAdvance2(void *p);
int WF2DMAP_OBJCMD_StepAdvance3(void *p);
Wf2dmapPos WF2DMAP_OBJCMD_OffsetPos(Wf2dmapPos p,int i);
int WF2DMAP_OBJCMD_AdvanceTimer(u8 *p);
void WF2DMAP_OBJCMD_Restart(char *p);
int WF2DMAP_OBJCMD_Dispatch(void *a, void *b, const u8 *desc, int *out);
int WF2DMAP_OBJCMD_SpawnIdle04(u8 *p,int a,int b,const u8 *desc,u8 *out);
int WF2DMAP_OBJCMD_SpawnIdleNew(u8 *p,int a,int b,const u8 *desc,u8 *out);
int WF2DMAP_OBJCMD_SpawnIfFree(void *p, void *q, void *r, const u8 *s, void *t);
int WF2DMAP_OBJCMD_SpawnIfFreeThunk(void *a, void *b, void *c, const u8 *d, void *e);
int WF2DMAP_OBJCMD_SpawnIdle(u8 *p,int a,int b,const u8 *desc,u8 *out);
int WF2DMAP_OBJCMD_StepNoop3(void);
int WF2DMAP_OBJCMD_SpawnIfFreeThunk2(void *a, void *b, void *c, const u8 *d, void *e);
int WF2DMAP_OBJCMD_SpawnIdle2(u8 *p,int a,int b,const u8 *desc,u8 *out);
int WF2DMAP_OBJCMD_IsTileOccupied(void *p, void *q, int n);
/* END mkheaders: generated region */

#endif
