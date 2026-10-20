/*
 * file:     wf2dmap_objcmd.c
 * unit:     yes
 * function: WF2DMAP_OBJCMD_Update, WF2DMAP_OBJCMD_StartCmd0, WF2DMAP_OBJCMD_StartCmd1, WF2DMAP_OBJCMD_StartCmd2, WF2DMAP_OBJCMD_StartCmd3, WF2DMAP_OBJCMD_StartCmd4, WF2DMAP_OBJCMD_StartCmd5, WF2DMAP_OBJCMD_StartCmd6, WF2DMAP_OBJCMD_StartCmd7, WF2DMAP_OBJCMD_StartCmd8, WF2DMAP_OBJCMD_StartCmd9, WF2DMAP_OBJCMD_StartCmd10, WF2DMAP_OBJCMD_StartCmd11, WF2DMAP_OBJCMD_StepNoop, WF2DMAP_OBJCMD_StepAdvance, WF2DMAP_OBJCMD_StepAdvanceSnap, WF2DMAP_OBJCMD_StepAdvanceSnap2, WF2DMAP_OBJCMD_StepNoop2, WF2DMAP_OBJCMD_StepAdvance2, WF2DMAP_OBJCMD_StepAdvance3, WF2DMAP_OBJCMD_OffsetPos, WF2DMAP_OBJCMD_AdvanceTimer, WF2DMAP_OBJCMD_Restart, WF2DMAP_OBJCMD_Dispatch, WF2DMAP_OBJCMD_SpawnIdle04, WF2DMAP_OBJCMD_SpawnIdleNew, WF2DMAP_OBJCMD_SpawnIfFree, WF2DMAP_OBJCMD_SpawnIfFreeThunk, WF2DMAP_OBJCMD_SpawnIdle, WF2DMAP_OBJCMD_StepNoop3, WF2DMAP_OBJCMD_SpawnIfFreeThunk2, WF2DMAP_OBJCMD_SpawnIdle2, WF2DMAP_OBJCMD_IsTileOccupied
 * address:  0x021C4CB4
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   WF2DMAP_OBJ_GetSlot 0x021C49A4 thumb ov127
 *   sWf2dmapObjCmdTable 0x021C604C data a4
 *   WF2DMAP_OBJ_SetPos 0x021C4B7C thumb ov127
 *   WF2DMAP_OBJ_SetDestPos 0x021C4B90 thumb ov127
 *   WF2DMAP_OBJ_SetSlot 0x021C4A00 thumb ov127
 *   WF2DMAP_OBJ_GetPos 0x021C4AC4 thumb ov127
 *   WF2DMAP_OBJ_OffsetPos 0x021C4A54 thumb ov127
 *   WF2DMAP_OBJ_FindById2 0x021C4994 thumb ov127
 *   sWf2dmapSpawnCmdTable 0x021C607C data a4
 *   WF2DMAP_OBJDRAW_FillSpawnDesc 0x021C5564 thumb ov127
 *   WF2DMAP_ACTOR_FIND_HasMatch 0x021C5550 thumb ov127
 *   WF2DMAP_MAP_IsCellBlocked 0x021C4844 thumb ov127
 */
#include "wf2dmap_obj_types.h"

#include "../types.h"

typedef int (*Wf2dmapSpawnCallback)(void *,void *,void *,const u8 *,void *);

/* 4-byte spawn command descriptor. */
typedef struct Wf2dmapSpawnCmd {
    u16 kind;               /* 0x00: object kind spawned */
    u8 value;               /* 0x02: compared with command slot 6 */
    u8 index;               /* 0x03: resource id */
} Wf2dmapSpawnCmd;

#include "wf2dmap_obj.h"
struct Wf2dmapPos;
#include "wf2dmap_objdraw.h"
#include "wf2dmap_actor_find.h"
#include "wf2dmap_map.h"
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
void WF2DMAP_OBJCMD_SpawnIfFreeThunk(int a, int b, int c, int d, int e);
int WF2DMAP_OBJCMD_SpawnIdle(u8 *p,int a,int b,const u8 *desc,u8 *out);
int WF2DMAP_OBJCMD_StepNoop3(void);
void WF2DMAP_OBJCMD_SpawnIfFreeThunk2(int a, int b, int c, int d, int e);
int WF2DMAP_OBJCMD_SpawnIdle2(u8 *p,int a,int b,const u8 *desc,u8 *out);
int WF2DMAP_OBJCMD_IsTileOccupied(void *p, void *q, int n);
extern const Wf2dmapSpawnCallback sWf2dmapSpawnCmdTable[];

extern int (*sWf2dmapObjCmdTable)(u8 *);

void WF2DMAP_OBJCMD_Update(u8 *p)
{
 int i=WF2DMAP_OBJ_GetSlot(p,5); int r=(*(int (**)(u8 *))((uptr)&sWf2dmapObjCmdTable+i*4))(p);
 (((Wf2dmapObj *)p)->updateCounter)++;
 if(r==1) {WF2DMAP_OBJCMD_Restart((char *)p); ((Wf2dmapObj *)p)->updateCounter=0;}
}

/*
 * extent: next larger wrapper starts at 0x021C4D34, its initial push
 *         is included by the stale label extent; filed separately.
 */
void WF2DMAP_OBJCMD_StartCmd0(char *p, Wf2dmapPos v, int n)
{
    WF2DMAP_OBJ_SetPos(p, *(Wf2dmapPairU16 *)&v);
    WF2DMAP_OBJ_SetDestPos(p, *(Wf2dmapPairU16 *)&v);
    WF2DMAP_OBJ_SetSlot(p, 6, n);
    WF2DMAP_OBJ_SetSlot(p, 5, 0);
}

/*
 * start: corrected from second label at initial push plus two bytes.
 */
void WF2DMAP_OBJCMD_StartCmd1(char *p, Wf2dmapPos v, int n)
{
    WF2DMAP_OBJ_SetPos(p, *(Wf2dmapPairU16 *)&v);
    WF2DMAP_OBJ_SetDestPos(p, *(Wf2dmapPairU16 *)&v);
    WF2DMAP_OBJ_SetSlot(p, 6, n);
    WF2DMAP_OBJ_SetSlot(p, 5, 1);
    WF2DMAP_OBJ_SetSlot(p, 8, 0);
    WF2DMAP_OBJ_SetSlot(p, 9, 2);
}

void WF2DMAP_OBJCMD_StartCmd2(char *p, Wf2dmapPos v, int n)
{
    Wf2dmapPos x = WF2DMAP_OBJCMD_OffsetPos(v, n);
    WF2DMAP_OBJ_SetDestPos(p, *(Wf2dmapPairU16 *)&v);
    WF2DMAP_OBJ_SetPos(p, *(Wf2dmapPairU16 *)&x);
    WF2DMAP_OBJ_SetSlot(p, 6, n);
    WF2DMAP_OBJ_SetSlot(p, 5, 2);
    WF2DMAP_OBJ_SetSlot(p, 8, 0);
    WF2DMAP_OBJ_SetSlot(p, 9, 8);
}

void WF2DMAP_OBJCMD_StartCmd3(char *p, Wf2dmapPos v, int n)
{
    Wf2dmapPos x = WF2DMAP_OBJCMD_OffsetPos(v, n);
    WF2DMAP_OBJ_SetDestPos(p, *(Wf2dmapPairU16 *)&v);
    WF2DMAP_OBJ_SetPos(p, *(Wf2dmapPairU16 *)&x);
    WF2DMAP_OBJ_SetSlot(p, 6, n);
    WF2DMAP_OBJ_SetSlot(p, 5, 3);
    WF2DMAP_OBJ_SetSlot(p, 8, 0);
    WF2DMAP_OBJ_SetSlot(p, 9, 4);
}

void WF2DMAP_OBJCMD_StartCmd4(char *p, Wf2dmapPos v, int n)
{
    WF2DMAP_OBJ_SetPos(p, *(Wf2dmapPairU16 *)&v);
    WF2DMAP_OBJ_SetDestPos(p, *(Wf2dmapPairU16 *)&v);
    WF2DMAP_OBJ_SetSlot(p, 6, n);
    WF2DMAP_OBJ_SetSlot(p, 5, 4);
}

void WF2DMAP_OBJCMD_StartCmd5(char *p, Wf2dmapPos v, int n)
{
    WF2DMAP_OBJ_SetPos(p, *(Wf2dmapPairU16 *)&v);
    WF2DMAP_OBJ_SetDestPos(p, *(Wf2dmapPairU16 *)&v);
    WF2DMAP_OBJ_SetSlot(p, 6, n);
    WF2DMAP_OBJ_SetSlot(p, 5, 5);
    WF2DMAP_OBJ_SetSlot(p, 8, 0);
    WF2DMAP_OBJ_SetSlot(p, 9, 16);
}

void WF2DMAP_OBJCMD_StartCmd6(char *p, Wf2dmapPos v, int n)
{
    Wf2dmapPos x = WF2DMAP_OBJCMD_OffsetPos(v, n);
    WF2DMAP_OBJ_SetDestPos(p, *(Wf2dmapPairU16 *)&v);
    WF2DMAP_OBJ_SetPos(p, *(Wf2dmapPairU16 *)&x);
    WF2DMAP_OBJ_SetSlot(p, 6, n);
    WF2DMAP_OBJ_SetSlot(p, 5, 6);
    WF2DMAP_OBJ_SetSlot(p, 8, 0);
    WF2DMAP_OBJ_SetSlot(p, 9, 16);
}

void WF2DMAP_OBJCMD_StartCmd7(char *p, Wf2dmapPos v, int n)
{
    Wf2dmapPos x = WF2DMAP_OBJCMD_OffsetPos(v, n);
    WF2DMAP_OBJ_SetDestPos(p, *(Wf2dmapPairU16 *)&v);
    WF2DMAP_OBJ_SetPos(p, *(Wf2dmapPairU16 *)&x);
    WF2DMAP_OBJ_SetSlot(p, 6, n);
    WF2DMAP_OBJ_SetSlot(p, 5, 7);
    WF2DMAP_OBJ_SetSlot(p, 8, 0);
    WF2DMAP_OBJ_SetSlot(p, 9, 4);
}

void WF2DMAP_OBJCMD_StartCmd8(char *p, Wf2dmapPos v, int n)
{
    WF2DMAP_OBJ_SetDestPos(p, *(Wf2dmapPairU16 *)&v);
    WF2DMAP_OBJ_SetPos(p, *(Wf2dmapPairU16 *)&v);
    WF2DMAP_OBJ_SetSlot(p, 6, n);
    WF2DMAP_OBJ_SetSlot(p, 5, 8);
    WF2DMAP_OBJ_SetSlot(p, 8, 0);
    WF2DMAP_OBJ_SetSlot(p, 9, 2);
}

void WF2DMAP_OBJCMD_StartCmd9(char *p, Wf2dmapPos v, int n)
{
    WF2DMAP_OBJ_SetDestPos(p, *(Wf2dmapPairU16 *)&v);
    WF2DMAP_OBJ_SetPos(p, *(Wf2dmapPairU16 *)&v);
    WF2DMAP_OBJ_SetSlot(p, 6, n);
    WF2DMAP_OBJ_SetSlot(p, 5, 9);
    WF2DMAP_OBJ_SetSlot(p, 8, 0);
    WF2DMAP_OBJ_SetSlot(p, 9, 4);
}

void WF2DMAP_OBJCMD_StartCmd10(char *p, Wf2dmapPos v, int n)
{
    WF2DMAP_OBJ_SetDestPos(p, *(Wf2dmapPairU16 *)&v);
    WF2DMAP_OBJ_SetPos(p, *(Wf2dmapPairU16 *)&v);
    WF2DMAP_OBJ_SetSlot(p, 6, n);
    WF2DMAP_OBJ_SetSlot(p, 5, 10);
    WF2DMAP_OBJ_SetSlot(p, 8, 0);
    WF2DMAP_OBJ_SetSlot(p, 9, 8);
}

void WF2DMAP_OBJCMD_StartCmd11(void *p, Wf2dmapPos v, int n)
{
    WF2DMAP_OBJ_SetDestPos(p, *(Wf2dmapPairU16 *)&v);
    WF2DMAP_OBJ_SetPos(p, *(Wf2dmapPairU16 *)&v);
    WF2DMAP_OBJ_SetSlot(p, 6, n);
    WF2DMAP_OBJ_SetSlot(p, 5, 11);
    WF2DMAP_OBJ_SetSlot(p, 8, 0);
    WF2DMAP_OBJ_SetSlot(p, 9, 16);
}

/*
 * extent: handed 021C51CA is the second push after 0F B4 at 021C51C8.
 */
int WF2DMAP_OBJCMD_StepNoop(void) { return 0; }

int WF2DMAP_OBJCMD_StepAdvance(void *p) { return WF2DMAP_OBJCMD_AdvanceTimer(p); }

int WF2DMAP_OBJCMD_StepAdvanceSnap(void *p)
{
    int r = WF2DMAP_OBJCMD_AdvanceTimer(p);
    if (r == 1) {
        Wf2dmapPos v = WF2DMAP_OBJ_GetPos(p);
        WF2DMAP_OBJ_SetDestPos(p, *(Wf2dmapPairU16 *)&v);
    }
    return r;
}

int WF2DMAP_OBJCMD_StepAdvanceSnap2(void *p)
{
    int r = WF2DMAP_OBJCMD_AdvanceTimer(p);
    if (r == 1) {
        Wf2dmapPos v = WF2DMAP_OBJ_GetPos(p);
        WF2DMAP_OBJ_SetDestPos(p, *(Wf2dmapPairU16 *)&v);
    }
    return r;
}

int WF2DMAP_OBJCMD_StepNoop2(void) { return 0; }

int WF2DMAP_OBJCMD_StepAdvance2(void *p) { return WF2DMAP_OBJCMD_AdvanceTimer(p); }

int WF2DMAP_OBJCMD_StepAdvance3(void *p) { return WF2DMAP_OBJCMD_AdvanceTimer(p); }

Wf2dmapPos WF2DMAP_OBJCMD_OffsetPos(Wf2dmapPos p,int i)
{
 return WF2DMAP_OBJ_OffsetPos(p,i);
}

int WF2DMAP_OBJCMD_AdvanceTimer(u8 *p)
{
 int a=WF2DMAP_OBJ_GetSlot(p,8), b=WF2DMAP_OBJ_GetSlot(p,9);
 if(a<b) { WF2DMAP_OBJ_SetSlot(p,8,a+1); if(a+1<b) return 0; }
 return 1;
}

void WF2DMAP_OBJCMD_Restart(char *p) { Wf2dmapPos v=WF2DMAP_OBJ_GetPos(p); WF2DMAP_OBJCMD_StartCmd0(p,v,WF2DMAP_OBJ_GetSlot((u8 *)p,6)); }

int WF2DMAP_OBJCMD_Dispatch(void *a, void *b, const u8 *desc, int *out) { return sWf2dmapSpawnCmdTable[*(u16 *)desc](WF2DMAP_OBJ_FindById2(b,desc[3]),a,b,desc,out); }

int WF2DMAP_OBJCMD_SpawnIdle04(u8 *p,int a,int b,const u8 *desc,u8 *out) { int v=WF2DMAP_OBJ_GetSlot(p,5);  if(v==0 || v==4) { WF2DMAP_OBJDRAW_FillSpawnDesc(out,p,((Wf2dmapSpawnCmd *)desc)->kind,desc[3],desc[2]); return 1; } return 0; }

int WF2DMAP_OBJCMD_SpawnIdleNew(u8 *p,int a,int b,const u8 *desc,u8 *out) { int v=WF2DMAP_OBJ_GetSlot(p,5); int w=WF2DMAP_OBJ_GetSlot(p,6); if(v==0 && w!=desc[2]) { WF2DMAP_OBJDRAW_FillSpawnDesc(out,p,((Wf2dmapSpawnCmd *)desc)->kind,desc[3],desc[2]); return 1; } return 0; }

int WF2DMAP_OBJCMD_SpawnIfFree(void *p, void *q, void *r, const u8 *s, void *t)
{
    int v = WF2DMAP_OBJ_GetSlot(p, 5);
    if (v == 0 && WF2DMAP_OBJCMD_IsTileOccupied(p, q, s[2]) != 1 && WF2DMAP_ACTOR_FIND_HasMatch(p, r, s[2]) != 1) {
        WF2DMAP_OBJDRAW_FillSpawnDesc(t, p, ((Wf2dmapSpawnCmd *)s)->kind, s[3], s[2]);
        return 1;
    }
    if (v == 0 && WF2DMAP_OBJ_GetSlot(p, 10) >= 8) {
        WF2DMAP_OBJDRAW_FillSpawnDesc(t, p, 5, s[3], s[2]);
        return 1;
    }
    return 0;
}

/*
 * Addresses are Black-image addresses.
 */
void WF2DMAP_OBJCMD_SpawnIfFreeThunk(int a, int b, int c, int d, int e)
{
    WF2DMAP_OBJCMD_SpawnIfFree((void *)a, (void *)b, (void *)c, (const u8 *)d, (void *)e);
}

int WF2DMAP_OBJCMD_SpawnIdle(u8 *p,int a,int b,const u8 *desc,u8 *out) { int v=WF2DMAP_OBJ_GetSlot(p,5);  if(v==0) { WF2DMAP_OBJDRAW_FillSpawnDesc(out,p,((Wf2dmapSpawnCmd *)desc)->kind,desc[3],desc[2]); return 1; } return 0; }

int WF2DMAP_OBJCMD_StepNoop3(void) { return 0; }

void WF2DMAP_OBJCMD_SpawnIfFreeThunk2(int a, int b, int c, int d, int e)
{
    WF2DMAP_OBJCMD_SpawnIfFree((void *)a, (void *)b, (void *)c, (const u8 *)d, (void *)e);
}

int WF2DMAP_OBJCMD_SpawnIdle2(u8 *p,int a,int b,const u8 *desc,u8 *out) { int v=WF2DMAP_OBJ_GetSlot(p,5);  if(v==0) { WF2DMAP_OBJDRAW_FillSpawnDesc(out,p,((Wf2dmapSpawnCmd *)desc)->kind,desc[3],desc[2]); return 1; } return 0; }

int WF2DMAP_OBJCMD_IsTileOccupied(void *p, void *q, int n)
{
    Wf2dmapPos b = WF2DMAP_OBJ_GetPos(p);
    Wf2dmapPos d = WF2DMAP_OBJ_OffsetPos(b, n);
    return WF2DMAP_MAP_IsCellBlocked(q, d.x / 16, d.y / 16);
}
