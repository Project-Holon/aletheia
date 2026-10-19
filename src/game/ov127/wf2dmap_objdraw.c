/*
 * file:     wf2dmap_objdraw.c
 * unit:     yes
 * function: WF2DMAP_OBJDRAW_FillSpawnDesc, WF2DMAP_OBJDRAW_CreateAnimSeq, WF2DMAP_OBJDRAW_DeleteAnimSeq, WF2DMAP_OBJDRAW_DeleteSprite, WF2DMAP_OBJDRAW_ConfigureSprite, WF2DMAP_OBJDRAW_AddActor, WF2DMAP_OBJDRAW_RemoveActor, WF2DMAP_OBJDRAW_UpdateAllActors, WF2DMAP_OBJDRAW_UpdateActor, WF2DMAP_OBJDRAW_SetActive, WF2DMAP_OBJDRAW_SetFrameDefault, WF2DMAP_OBJDRAW_StepActorAnim, WF2DMAP_OBJDRAW_RestoreFrame, WF2DMAP_OBJDRAW_SetActorPos, WF2DMAP_OBJDRAW_GetActorDrawEnable, WF2DMAP_OBJDRAW_SetActorDrawEnable, WF2DMAP_OBJDRAW_SetSubActorDrawEnable, WF2DMAP_OBJDRAW_GetActorDrawPriority, WF2DMAP_OBJDRAW_SetFrameZero, WF2DMAP_OBJDRAW_GetDepth, WF2DMAP_OBJDRAW_SetSubActorPos, WF2DMAP_OBJDRAW_IsActorFree, WF2DMAP_OBJDRAW_AllocActor, WF2DMAP_OBJDRAW_GetFrameValue, WF2DMAP_OBJDRAW_GetOwnerPos, WF2DMAP_OBJDRAW_SetFrame, WF2DMAP_OBJDRAW_SetPosFromOwner, WF2DMAP_OBJDRAW_ClearPos
 * address:  0x021C5564
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
 *   WF2DMAP_OBJ_GetPos 0x021C4AC4 thumb ov127
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   WIFI_2DCHAR_Create 0x021C3EE0 thumb ov127
 *   WIFI_2DCHAR_SetupBmpCell 0x021C3FDC thumb ov127
 *   WIFI_2DCHAR_RegisterBmp 0x021C40A0 thumb ov127
 *   sWf2dmapObjdrawFileName 0x021C6130 data a1
 *   WIFI_2DCHAR_ReleaseBmp 0x021C40B4 thumb ov127
 *   WIFI_2DCHAR_Delete 0x021C3F80 thumb ov127
 *   GFL_HEAP_Free 0x020307B0 arm
 *   WIFI_2DCHAR_ReleaseCells 0x021C4010 thumb ov127
 *   WIFI_2DCHAR_SetupCells  0x021C4044  thumb
 *   WF2DMAP_OBJ_GetSlot 0x021C49A4 thumb ov127
 *   WIFI_2DCHAR_SpawnActor 0x021C40BC thumb ov127
 *   WIFI_2DCHAR_DeleteActor  0x021C41BC  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   WIFI_2DCHAR_SetActorPos 0x021C41DC thumb ov127
 *   WIFI_2DCHAR_SetActorDrawPriority 0x021C4214 thumb ov127
 *   WIFI_2DCHAR_StepActorAnim 0x021C42C4 thumb ov127
 *   WIFI_2DCHAR_GetActorDrawEnable  0x021C425C  thumb  ov127
 *   WIFI_2DCHAR_SetActorDrawEnable  0x021C4230  thumb  ov127
 *   WIFI_2DCHAR_SetSubActorDrawEnable  0x021C424C  thumb  ov127
 *   WIFI_2DCHAR_GetActorDrawPriority  0x021C4224  thumb  ov127
 *   WIFI_2DCHAR_SetSubActorPos  0x021C428C  thumb  ov127
 *   WIFI_2DCHAR_GetActorCellArgB  0x021C4268  thumb
 *   sWf2dmapSlotValues     0x021C60B6  data  a1
 *   WF2DMAP_OBJ_GetCurrentPos 0x021C4ADC thumb ov127
 *   WIFI_2DCHAR_GetActorAnimSeqCount 0x021C4280 thumb ov127
 *   WIFI_2DCHAR_GetActorAnimId 0x021C4270 thumb ov127
 *   WIFI_2DCHAR_SetActorAnim 0x021C42A8 thumb ov127
 *   WIFI_2DCHAR_SetActorAnimIndex 0x021C4274 thumb ov127
 *   sWf2dmapSlotFlags 0x021C60AC data a1
 *   WF2DMAP_SCRDRAW_SetPoint 0x021C59DC thumb ov127
 */
struct Wf2dmapActor;

#include "wf2dmap_obj_types.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef signed int     s32;

typedef signed char s8;

/* 12-byte animation sequence of one 2D map object. */
typedef struct Wf2dmapAnimSeq {
    void *sprite;           /* 0x00: CLACT sprite */
    void *frames;           /* 0x04: array of Wf2dmapActor, 20 bytes each */
    u16 frameCount;         /* 0x08 */
    u8 state;               /* 0x0A: 2 after creation */
    u8 mode;                /* 0x0B: passed to the sprite configure calls */
} Wf2dmapAnimSeq;

/* 20-byte actor entry of one animation frame. */
typedef struct Wf2dmapActor {
    void *owner;            /* 0x00: the animation sequence */
    void *actor;            /* 0x04: actor handle, 0 = free */
    u16 value5;             /* 0x08: cached owner parameter 5 */
    u16 value6;             /* 0x0A: cached owner parameter 6 */
    u16 value4;             /* 0x0C: cached owner parameter 4 */
    u16 prevActor;          /* 0x0E: actor handle saved when the frame changes */
    u16 prevValue5;         /* 0x10: value5 saved when the frame changes */
    u8 variant;             /* 0x12: depth variant flag (1 or other) */
    u8 active;              /* 0x13: 1 when the actor is live */
} Wf2dmapActor;

/* 8-byte spawn record written by FillSpawnDesc. */
typedef struct Wf2dmapSpawnDesc {
    u16 x;                  /* 0x00 */
    u16 y;                  /* 0x02 */
    u16 kind;               /* 0x04 */
    u8 value;               /* 0x06 */
    u8 index;               /* 0x07 */
} Wf2dmapSpawnDesc;

/* Unsigned 16-bit point returned by WF2DMAP_OBJ_GetPos. */
typedef struct Wf2dmapU16Point {
    u16 x, y;
} Wf2dmapU16Point;

/* Signed 16-bit pair passed by value. */
typedef struct Wf2dmapPair {
    s16 x;
    s16 y;
} Wf2dmapPair;

extern Wf2dmapU16Point WF2DMAP_OBJ_GetPos(void *);
extern void *GFL_HEAP_Alloc(u16, u32, int, const char *, u16);
struct Wifi2dcharContext;
extern struct Wifi2dcharContext *WIFI_2DCHAR_Create(void *, void *, u32, u32);
extern void WIFI_2DCHAR_SetupBmpCell(u8 *p, int a, int b, int c, int d);
extern void WIFI_2DCHAR_RegisterBmp(u8 *p, int a, int b, int c);
extern void WIFI_2DCHAR_ReleaseBmp(u8 *p);
extern void WIFI_2DCHAR_Delete(u8 *p);
extern u32 GFL_HEAP_Free(void *p);
extern void WIFI_2DCHAR_ReleaseCells(u8 *p);
extern void WIFI_2DCHAR_SetupCells(u8 *p, int a, int b, int c, int d);
extern int WF2DMAP_OBJ_GetSlot(u8 *p, unsigned int i);
extern u32 *WIFI_2DCHAR_SpawnActor(struct Wifi2dcharContext *ctx, s16 *pos, s32 idx, u32 heap);
extern void WIFI_2DCHAR_DeleteActor(u8 *p);
extern void MI_CpuFill8(void *, int, int);
extern void WIFI_2DCHAR_SetActorPos(u8 *p, int x, int y);
extern void WIFI_2DCHAR_SetActorDrawPriority(u8 *p, u32 v);
extern void WIFI_2DCHAR_StepActorAnim(u8 *p);
extern int WIFI_2DCHAR_GetActorDrawEnable(char *p);
extern void WIFI_2DCHAR_SetActorDrawEnable(char *p, int a);
extern void WIFI_2DCHAR_SetSubActorDrawEnable(char *p, int a);
extern int WIFI_2DCHAR_GetActorDrawPriority(u8 *p);
extern void WIFI_2DCHAR_SetSubActorPos(char *p, int x, int y);
extern int WIFI_2DCHAR_GetActorCellArgB(char *);
extern Wf2dmapPos WF2DMAP_OBJ_GetCurrentPos(char *);
extern int WIFI_2DCHAR_GetActorAnimSeqCount(char *p);
extern u32 WIFI_2DCHAR_GetActorAnimId(char *p);
struct Wifi2dcharActor;
extern void WIFI_2DCHAR_SetActorAnim(struct Wifi2dcharActor *p, s32 idx, s32 a);
extern void WIFI_2DCHAR_SetActorAnimIndex(char *p, u32 a);
struct Wf2dmapPoint;
extern void WF2DMAP_SCRDRAW_SetPoint(struct Wf2dmapPoint *p, s16 y, s16 x);
void WF2DMAP_OBJDRAW_FillSpawnDesc(u8 *out,void *p,int kind,int index,int value);
Wf2dmapAnimSeq *WF2DMAP_OBJDRAW_CreateAnimSeq(void *srcA, void *srcB, u32 count, void *palette, int animData, u32 mode, u32 heap);
void WF2DMAP_OBJDRAW_DeleteAnimSeq(u8 *p);
void WF2DMAP_OBJDRAW_DeleteSprite(void *p);
void WF2DMAP_OBJDRAW_ConfigureSprite(char *p, int a, int b);
u8 *WF2DMAP_OBJDRAW_AddActor(u8 *seq, void *resource, int variant, u32 heap);
void WF2DMAP_OBJDRAW_RemoveActor(u8 *p);
void WF2DMAP_OBJDRAW_UpdateAllActors(u8 *p);
void WF2DMAP_OBJDRAW_UpdateActor(u8 *p);
void WF2DMAP_OBJDRAW_SetActive(u8 *p, int v);
void WF2DMAP_OBJDRAW_SetFrameDefault(u8 *p);
void WF2DMAP_OBJDRAW_StepActorAnim(char *p);
void WF2DMAP_OBJDRAW_RestoreFrame(u8 *p);
void WF2DMAP_OBJDRAW_SetActorPos(char *p, Wf2dmapPair v);
int WF2DMAP_OBJDRAW_GetActorDrawEnable(char *p);
void WF2DMAP_OBJDRAW_SetActorDrawEnable(char *p, int a);
void WF2DMAP_OBJDRAW_SetSubActorDrawEnable(u8 *p, int a);
int WF2DMAP_OBJDRAW_GetActorDrawPriority(u8 *p);
void WF2DMAP_OBJDRAW_SetFrameZero(u8 *p, int b);
int WF2DMAP_OBJDRAW_GetDepth(int a,int b);
void WF2DMAP_OBJDRAW_SetSubActorPos(char *p, Wf2dmapPair v);
int WF2DMAP_OBJDRAW_IsActorFree(char *p);
char *WF2DMAP_OBJDRAW_AllocActor(u8 *seq);
int WF2DMAP_OBJDRAW_GetFrameValue(char *p, int b);
void WF2DMAP_OBJDRAW_GetOwnerPos(char *p,short *x,short *y);
void WF2DMAP_OBJDRAW_SetFrame(u8 *p, int n, int a);
void WF2DMAP_OBJDRAW_SetPosFromOwner(void *p, void *q);
void WF2DMAP_OBJDRAW_ClearPos(void *p);
extern const char sWf2dmapObjdrawFileName[];
extern unsigned char sWf2dmapSlotValues[];
extern u8 sWf2dmapSlotFlags[];




void WF2DMAP_OBJDRAW_FillSpawnDesc(u8 *out,void *p,int kind,int index,int value) { *(Wf2dmapU16Point *)out=WF2DMAP_OBJ_GetPos(p); ((Wf2dmapSpawnDesc *)out)->kind=kind; out[7]=index; out[6]=value; }




Wf2dmapAnimSeq *WF2DMAP_OBJDRAW_CreateAnimSeq(void *srcA, void *srcB, u32 count, void *palette, int animData, u32 mode, u32 heap)
{
    Wf2dmapAnimSeq *seq = GFL_HEAP_Alloc(heap, 12, 1, sWf2dmapObjdrawFileName, 161);
    seq->sprite = WIFI_2DCHAR_Create(srcA, srcB, count, heap);
    seq->frameCount = count;
    seq->frames = GFL_HEAP_Alloc(heap, 20 * seq->frameCount, 1, sWf2dmapObjdrawFileName, 168);
    seq->state = 2;
    seq->mode = mode;
    WIFI_2DCHAR_SetupBmpCell(seq->sprite, (int)palette, seq->mode, animData, heap);
    WIFI_2DCHAR_RegisterBmp(seq->sprite, seq->mode, 255, heap);
    return seq;
}




/*
 * extent: two zero alignment bytes at 021C5656 follow the return.
 */
void WF2DMAP_OBJDRAW_DeleteAnimSeq(u8 *p)
{
    int i;
    for (i = 0; i < ((Wf2dmapAnimSeq *)p)->frameCount; i++) {
        int offset = i * 20;
        if (!WF2DMAP_OBJDRAW_IsActorFree((char *)(*(u8 * *)&((Wf2dmapAnimSeq *)p)->frames+offset)))
            WF2DMAP_OBJDRAW_RemoveActor(*(u8 * *)&((Wf2dmapAnimSeq *)p)->frames+offset);
    }
    WIFI_2DCHAR_ReleaseBmp(((Wf2dmapAnimSeq *)p)->sprite);
    WF2DMAP_OBJDRAW_DeleteSprite(p);
    WIFI_2DCHAR_Delete(((Wf2dmapAnimSeq *)p)->sprite);
    GFL_HEAP_Free(((Wf2dmapAnimSeq *)p)->frames);
    GFL_HEAP_Free(p);
}




void WF2DMAP_OBJDRAW_DeleteSprite(void *p) { WIFI_2DCHAR_ReleaseCells(((Wf2dmapAnimSeq *)p)->sprite); }




/*
 * Addresses are Black-image addresses.
 */
void WF2DMAP_OBJDRAW_ConfigureSprite(char *p, int a, int b)
{
    WIFI_2DCHAR_SetupCells(((Wf2dmapAnimSeq *)p)->sprite, ((Wf2dmapAnimSeq *)p)->mode, a, 0, b);
}




u8 *WF2DMAP_OBJDRAW_AddActor(u8 *seq, void *resource, int variant, u32 heap)
{
    u8 *o = (u8 *)WF2DMAP_OBJDRAW_AllocActor((u8 *)seq);
    s16 pos[4];
    ((Wf2dmapActor *)o)->value5 = WF2DMAP_OBJ_GetSlot(resource, 5);
    ((Wf2dmapActor *)o)->value6 = WF2DMAP_OBJ_GetSlot(resource, 6);
    ((Wf2dmapActor *)o)->value4 = WF2DMAP_OBJ_GetSlot(resource, 4);
    ((Wf2dmapActor *)o)->owner = resource;
    o[18] = variant;
    o[19] = 1;
    ((Wf2dmapActor *)o)->prevActor = 0;
    ((Wf2dmapActor *)o)->prevValue5 = 0;
    pos[0] = WF2DMAP_OBJ_GetSlot(resource, 0);
    pos[1] = WF2DMAP_OBJ_GetSlot(resource, 1);
    pos[2] = WF2DMAP_OBJDRAW_GetDepth(pos[1], o[18]);
    pos[3] = ((Wf2dmapAnimSeq *)seq)->state;
    ((Wf2dmapActor *)o)->actor = WIFI_2DCHAR_SpawnActor(((Wf2dmapAnimSeq *)seq)->sprite, pos, WF2DMAP_OBJ_GetSlot(resource, 7), heap);
    WF2DMAP_OBJDRAW_UpdateActor(o);
    return o;
}






void WF2DMAP_OBJDRAW_RemoveActor(u8 *p)
{
    WIFI_2DCHAR_DeleteActor(((Wf2dmapActor *)p)->actor);
    MI_CpuFill8(p, 0, 0x14);
}




void WF2DMAP_OBJDRAW_UpdateAllActors(u8 *p) { int i,offset; for(i=0;i<((Wf2dmapAnimSeq *)p)->frameCount;i++) { offset=i*20; if(WF2DMAP_OBJDRAW_IsActorFree(*(char * *)&((Wf2dmapAnimSeq *)p)->frames+offset)==0) WF2DMAP_OBJDRAW_UpdateActor(*(u8 * *)&((Wf2dmapAnimSeq *)p)->frames+offset); } }




void WF2DMAP_OBJDRAW_UpdateActor(u8 *p)
{
    if (p[19]) {
        int a = WF2DMAP_OBJ_GetSlot(((Wf2dmapActor *)p)->owner, 5);
        int b = WF2DMAP_OBJ_GetSlot(((Wf2dmapActor *)p)->owner, 6);
        s16 c = WF2DMAP_OBJ_GetSlot(((Wf2dmapActor *)p)->owner, 8);
        s16 x, y;
        u16 d;
        if (((Wf2dmapActor *)p)->value5 != a || ((Wf2dmapActor *)p)->value6 != b || c == 0) {
            ((Wf2dmapActor *)p)->value5 = a;
            ((Wf2dmapActor *)p)->value6 = b;
            WF2DMAP_OBJDRAW_SetFrame(p, WF2DMAP_OBJDRAW_GetFrameValue(((Wf2dmapActor *)p)->actor, a), b);
        }
        WF2DMAP_OBJDRAW_GetOwnerPos((char *)p, &x, &y);
        WIFI_2DCHAR_SetActorPos(((Wf2dmapActor *)p)->actor, x, y);
        d = WF2DMAP_OBJDRAW_GetDepth(y, p[18]);
        WIFI_2DCHAR_SetActorDrawPriority(((Wf2dmapActor *)p)->actor, d);
        WIFI_2DCHAR_StepActorAnim(((Wf2dmapActor *)p)->actor);
    }
}





/*
 * Blocker of ov099 WIFICLUBACTOR_StartDespawn / WIFICLUBACTOR_StartTurn.
 */
void WF2DMAP_OBJDRAW_SetActive(u8 *p, int v)
{
    p[0x13] = v;
}





/*
 * Tail-call forwarder: (p) -> SetFrame(p, 1, p->u16 at +0xA).
 * Blocker of ov099 WIFICLUBACTOR_StartDespawn / WIFICLUBACTOR_StartTurn.
 */
void WF2DMAP_OBJDRAW_SetFrameDefault(u8 *p)
{
    WF2DMAP_OBJDRAW_SetFrame(p, 1, ((Wf2dmapActor *)p)->value6);
}





/*
 * Unlabelled tail-call stub: ldr r0,[r0,#4]; ldr r3,=WIFI_2DCHAR_StepActorAnim; bx r3.
 * Blocker of ov099 WIFICLUBACTOR_AnimateWalkBob.
 */
void WF2DMAP_OBJDRAW_StepActorAnim(char *p)
{
    WIFI_2DCHAR_StepActorAnim(((Wf2dmapActor *)p)->actor);
}




void WF2DMAP_OBJDRAW_RestoreFrame(u8 *p) { WF2DMAP_OBJDRAW_SetFrame(p,WF2DMAP_OBJDRAW_GetFrameValue(*(char * *)&((Wf2dmapActor *)p)->actor,((Wf2dmapActor *)p)->value5),((Wf2dmapActor *)p)->value6); WF2DMAP_OBJDRAW_UpdateActor(p); }





/*
 * Unlabelled: forwards a by-value {s16 x, y} pair to WIFI_2DCHAR_SetActorPos with the
 * pointer at +4.  Blocker of ov099 WIFICLUBACTOR_AnimateWalkBob / WIFICLUBACTOR_AnimateBounce.
 */
void WF2DMAP_OBJDRAW_SetActorPos(char *p, Wf2dmapPair v)
{
    WIFI_2DCHAR_SetActorPos(((Wf2dmapActor *)p)->actor, v.x, v.y);
}





/*
 * Unlabelled tail-call stub: ldr r0,[r0,#4]; ldr r3,=WIFI_2DCHAR_GetActorDrawEnable; bx r3.
 * Blocker of ov099 WIFICLUBACTOR_AnimateWalkBob.
 */
int WF2DMAP_OBJDRAW_GetActorDrawEnable(char *p)
{
    return WIFI_2DCHAR_GetActorDrawEnable(((Wf2dmapActor *)p)->actor);
}





void WF2DMAP_OBJDRAW_SetActorDrawEnable(char *p, int a)
{
    WIFI_2DCHAR_SetActorDrawEnable(((Wf2dmapActor *)p)->actor, a);
}





/*
 * Unlabelled 8-byte ov127 accessor veneer in a .word run (0x021C5834,
 * 0x021C5840, 0x021C584C, 0x021C5858 are four in a row): `ldr r0,[r0,#0];
 * ldr r3,=WIFI_2DCHAR_SetSubActorDrawEnable; bx r3`.  Blocker target of src/pending/
 * ov099_func_021B98E4.c.
 *
 * Addresses are Black-image addresses.
 */
void WF2DMAP_OBJDRAW_SetSubActorDrawEnable(u8 *p, int a)
{
    WIFI_2DCHAR_SetSubActorDrawEnable(*(char * *)&((Wf2dmapActor *)p)->actor, a);
}





/*
 * Unlabelled accessor veneer after WF2DMAP_OBJDRAW_SetSubActorDrawEnable (`ldr r0,[r0,#4]; ldr r3,=
 * WIFI_2DCHAR_GetActorDrawPriority; bx r3`).  Blocker of ov099 WIFICLUBACTOR_ShowMarkerAtActor.
 */
int WF2DMAP_OBJDRAW_GetActorDrawPriority(u8 *p)
{
    return WIFI_2DCHAR_GetActorDrawPriority(((Wf2dmapActor *)p)->actor);
}




void WF2DMAP_OBJDRAW_SetFrameZero(u8 *p, int b)
{
    WF2DMAP_OBJDRAW_SetFrame(p, 0, b);
    WIFI_2DCHAR_StepActorAnim(((Wf2dmapActor *)p)->actor);
}




int WF2DMAP_OBJDRAW_GetDepth(int a,int b) { if(b==1) return 250-a/4; else return 251-a/4; }




/*
 * Unlabelled: forwards a by-value {s16 x, y} pair to WIFI_2DCHAR_SetSubActorPos with the
 * pointer at +4.  Blocker of ov099 WIFICLUBACTOR_AnimateWalkBob / WIFICLUBACTOR_AnimateBounce.
 */
void WF2DMAP_OBJDRAW_SetSubActorPos(char *p, Wf2dmapPair v)
{
    WIFI_2DCHAR_SetSubActorPos(((Wf2dmapActor *)p)->actor, v.x, v.y);
}




int WF2DMAP_OBJDRAW_IsActorFree(char *p)
{
    return ((Wf2dmapActor *)p)->actor == 0;
}




char *WF2DMAP_OBJDRAW_AllocActor(u8 *seq) { int i,offset; for(i=0;i<((Wf2dmapAnimSeq *)seq)->frameCount;i++) { offset=i*20; if(WF2DMAP_OBJDRAW_IsActorFree(*(char * *)&((Wf2dmapAnimSeq *)seq)->frames+offset)==1) return *(char * *)&((Wf2dmapAnimSeq *)seq)->frames+offset; } return 0; }




int WF2DMAP_OBJDRAW_GetFrameValue(char *p, int b)
{
    if (WIFI_2DCHAR_GetActorCellArgB(p) == 2)
        return 0;
    return sWf2dmapSlotValues[b];
}




void WF2DMAP_OBJDRAW_GetOwnerPos(char *p,short *x,short *y) { Wf2dmapPos a=WF2DMAP_OBJ_GetCurrentPos(*(char * *)&((Wf2dmapActor *)p)->owner); *x=a.x; *y=a.y; }




void WF2DMAP_OBJDRAW_SetFrame(u8 *p, int n, int a)
{
    int v = WIFI_2DCHAR_GetActorAnimSeqCount(((Wf2dmapActor *)p)->actor);
    u16 old = WIFI_2DCHAR_GetActorAnimId(((Wf2dmapActor *)p)->actor);
    WIFI_2DCHAR_SetActorAnim(((Wf2dmapActor *)p)->actor, n, a);
    if (old != n) {
        if (sWf2dmapSlotFlags[n] == 1 && ((Wf2dmapActor *)p)->prevValue5 == n)
            WIFI_2DCHAR_SetActorAnimIndex(((Wf2dmapActor *)p)->actor, ((Wf2dmapActor *)p)->prevActor);
        if (sWf2dmapSlotFlags[old] == 1) {
            ((Wf2dmapActor *)p)->prevValue5 = old;
            ((Wf2dmapActor *)p)->prevActor = v;
        }
    }
}


void WF2DMAP_OBJDRAW_SetPosFromOwner(void *p, void *q)
{
    Wf2dmapPos v = WF2DMAP_OBJ_GetCurrentPos(q);
    WF2DMAP_SCRDRAW_SetPoint(p, v.y - 96, v.x - 112);
}


void WF2DMAP_OBJDRAW_ClearPos(void *p) { MI_CpuFill8(p, 0, 4); }
