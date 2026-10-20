/*
 * file:     wifi_2dchar.c
 * unit:     yes
 * function: WIFI_2DCHAR_Create, WIFI_2DCHAR_Delete, WIFI_2DCHAR_SetupBmpCell, WIFI_2DCHAR_ReleaseCells, WIFI_2DCHAR_SetupCells, WIFI_2DCHAR_ReleaseBmpCells, WIFI_2DCHAR_RegisterBmp, WIFI_2DCHAR_ReleaseBmp, WIFI_2DCHAR_SpawnActor, WIFI_2DCHAR_DeleteActor, WIFI_2DCHAR_SetActorPos, WIFI_2DCHAR_SetActorDrawPriority, WIFI_2DCHAR_GetActorDrawPriority, WIFI_2DCHAR_SetActorDrawEnable, WIFI_2DCHAR_SetSubActorDrawEnable, WIFI_2DCHAR_GetActorDrawEnable, WIFI_2DCHAR_GetActorCellArgB, WIFI_2DCHAR_GetActorAnimId, WIFI_2DCHAR_SetActorAnimIndex, WIFI_2DCHAR_GetActorAnimSeqCount, WIFI_2DCHAR_SetSubActorPos, WIFI_2DCHAR_SetActorAnim, WIFI_2DCHAR_StepActorAnim, WIFI_2DCHAR_RegisterCellAnims, WIFI_2DCHAR_ReleaseCellAnims, WIFI_2DCHAR_GetCellIndex, WIFI_2DCHAR_IsBmpCellEnabled, WIFI_2DCHAR_RegisterCell, WIFI_2DCHAR_RegisterBmpCharCell, WIFI_2DCHAR_RegisterCharCell, WIFI_2DCHAR_ReleaseCell, WIFI_2DCHAR_ReleaseCellPair, WIFI_2DCHAR_ReleaseCellChar, WIFI_2DCHAR_IsCellUsed, WIFI_2DCHAR_RegisterBmpHandles, WIFI_2DCHAR_ReleaseBmpHandles, WIFI_2DCHAR_IsHandleValid, WIFI_2DCHAR_RegisterPalette, WIFI_2DCHAR_ReleasePalette, WIFI_2DCHAR_RegisterBmpAnims, WIFI_2DCHAR_ReleaseBmpAnims, WIFI_2DCHAR_FindFreeActor, WIFI_2DCHAR_StepActorAnimDispatch, WIFI_2DCHAR_SetAnimSeq, WIFI_2DCHAR_SetAnimSeq4, WIFI_2DCHAR_SetAnimSeqPlus5, WIFI_2DCHAR_AdvanceAnimSeq, WIFI_2DCHAR_SetAnimSeqPlus9, WIFI_2DCHAR_SetAnimSeqPlus5B, WIFI_2DCHAR_SetAnimSeqPlus5C, WIFI_2DCHAR_SetAnimSeqPlus5D, WIFI_2DCHAR_SetAnimSeqPlus5E, WIFI_2DCHAR_AddAnimFrame, WIFI_2DCHAR_AddAnimFrame2
 * address:  0x021C3EE0
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
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   sWifi2dcharFileName 0x021C6100 data a1
 *   WF2DMAP_MAP_IsEmpty 0x021C4790 thumb ov127
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   CLACT_SetActorPos 0x0204B528 arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   CLACT_GetActorDrawPriority  0x0204B838  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_GetActorDrawEnable  0x0204B3F4  arm
 *   CLACT_GetActorAnimSeqCount 0x0204B918 arm
 *   sWifi2dcharAnimStartTable  0x021C5FBC  data  a4
 *   sWifi2dcharAnimFrameCount 0x021C5FB0 data a4
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   sWifi2dcharAnimStepTable 0x021C5FE4 data a4
 *   CLACT_ChangeActorAnimSeq 0x0204B8A0 arm
 *   CLACT_AddActorAnimFrame 0x0204B8D4 arm
 */

struct ClactActor;
struct Node;
#include "../types.h"

/* One 20-byte cell of the 2D character layer: a character/palette pair, or a
 * cell animation slot. Addressed by the cell helpers below. */
typedef struct Wifi2dcharCell {
    u32 mode;      /* 0x00 */
    u32 handle;    /* 0x04: CLACT character or cell-anim handle, -1 when free */
    u32 owner;     /* 0x08: CLACT palette handle */
    u32 argA;      /* 0x0C */
    u32 argB;      /* 0x10 */
} Wifi2dcharCell;

/* One 24-byte actor record, elements of Wifi2dcharContext.actors. */
typedef struct Wifi2dcharActor {
    Wifi2dcharCell *rec;    /* 0x00: cell the actor was built from */
    void *actor;            /* 0x04 */
    void *subActor;         /* 0x08: second actor, drawn below the first */
    u32 animId;             /* 0x0C */
    u32 animSeq;            /* 0x10: current animation sequence */
    short animFrame;        /* 0x14 */
    u16 pad16;              /* 0x16 */
} Wifi2dcharActor;

/* The 2D character context (0x334 bytes). */
typedef struct Wifi2dcharContext {
    void *ownerA;                 /* 0x000 */
    void *ownerB;                 /* 0x004 */
    void *actors;                 /* 0x008: Wifi2dcharActor array */
    u32 actorCount;               /* 0x00C */
    Wifi2dcharCell cells[18];     /* 0x010: character/palette cells */
    u8 pad178[0x10];              /* 0x178 */
    Wifi2dcharCell cellAnims[17]; /* 0x188: cell animation slots 0..16 */
    u32 animHandle17;             /* 0x2DC: cell animation slot 17 */
    u32 bmpCharHandle;            /* 0x2E0: bitmap character handle */
    u32 bmpPaletteHandle;         /* 0x2E4: bitmap palette handle */
    u32 bmpAnimHandle;            /* 0x2E8: bitmap cell anim handle */
    u32 reserved2EC;                   /* 0x2EC */
    u32 bmpParam;                 /* 0x2F0 */
    u32 paletteHandle;            /* 0x2F4 */
    void *charHandle;             /* 0x2F8: CLACT cell/character resource */
    void *paletteSource;          /* 0x2FC: CLACT palette resource */
    u8 pad300[0x30];              /* 0x300 */
    u32 bmpCellSlot;                   /* 0x330 */
} Wifi2dcharContext;

/* Unsigned 16-bit point passed by value to CLACT_SetActorPos. */
typedef struct Wifi2dcharPoint { u16 x, y; } Wifi2dcharPoint;

/* 6-byte actor position passed to CLACT_CreateActor. */
typedef struct Wifi2dcharActorPos { s16 x, y, z; u8 a, b; } Wifi2dcharActorPos;

#ifdef __MWERKS__
#define GFL_HEAP_Alloc GFL_HEAP_Alloc_hdr
#endif
#include "../arm9/gfl_heap_wrap.h"
#ifdef __MWERKS__
#undef GFL_HEAP_Alloc
void * GFL_HEAP_Alloc(u16, u32, int, const char *, u16);
#endif
#ifdef __MWERKS__
#define ARC_TOOL_CreateHandle ARC_TOOL_CreateHandle_hdr
#endif
#include "../arm9/arc_tool.h"
#ifdef __MWERKS__
#undef ARC_TOOL_CreateHandle
void * ARC_TOOL_CreateHandle(unsigned int, u16);
#endif
#include "wf2dmap_map.h"
#include "../arm9/clact.h"
#include "../arm9/mi_memory.h"
struct Pt16;
Wifi2dcharContext *WIFI_2DCHAR_Create(void *a, void *b, u32 count, u32 heap);
void WIFI_2DCHAR_Delete(u8 *p);
void WIFI_2DCHAR_SetupBmpCell(u8 *p, int a, int b, int c, int d);
void WIFI_2DCHAR_ReleaseCells(u8 *p);
void WIFI_2DCHAR_SetupCells(u8 *p,int a,int b,int c,int d);
void WIFI_2DCHAR_ReleaseBmpCells(u8 *p);
void WIFI_2DCHAR_RegisterBmp(u8 *p, int a, int b, int c);
void WIFI_2DCHAR_ReleaseBmp(u8 *p);
u32 *WIFI_2DCHAR_SpawnActor(Wifi2dcharContext *ctx, const s16 *pos, int idx, u32 heap);
void WIFI_2DCHAR_DeleteActor(u8 *p);
void WIFI_2DCHAR_SetActorPos(u8 *p,int x,int y);
void WIFI_2DCHAR_SetActorDrawPriority(u8 *p, u32 v);
int WIFI_2DCHAR_GetActorDrawPriority(u8 *p);
void WIFI_2DCHAR_SetActorDrawEnable(char *p, int a);
void WIFI_2DCHAR_SetSubActorDrawEnable(char *p, int a);
int WIFI_2DCHAR_GetActorDrawEnable(char *p);
u32 WIFI_2DCHAR_GetActorCellArgB(u8 *p);
u32 WIFI_2DCHAR_GetActorAnimId(char *p);
void WIFI_2DCHAR_SetActorAnimIndex(char *p,u32 a);
int WIFI_2DCHAR_GetActorAnimSeqCount(char *p);
void WIFI_2DCHAR_SetSubActorPos(char *p,int x,int y);
void WIFI_2DCHAR_SetActorAnim(Wifi2dcharActor *p, int idx, int a);
void WIFI_2DCHAR_StepActorAnim(u8 *p);
void WIFI_2DCHAR_RegisterCellAnims(char *p, int unused, u32 heap);
void WIFI_2DCHAR_ReleaseCellAnims(char *p, int unused);
int WIFI_2DCHAR_GetCellIndex(int a);
int WIFI_2DCHAR_IsBmpCellEnabled(int unused0, int unused1);
void WIFI_2DCHAR_RegisterCell(char *p, int i, int a, int b, int c, int mode);
void WIFI_2DCHAR_RegisterBmpCharCell(Wifi2dcharContext *ctx, int i, u32 a, u32 b, u32 c);
void WIFI_2DCHAR_RegisterCharCell(u8 *p, int i, u32 a, u32 b, u32 c);
void WIFI_2DCHAR_ReleaseCell(char *p, int i);
void WIFI_2DCHAR_ReleaseCellPair(char *p,int i);
void WIFI_2DCHAR_ReleaseCellChar(u8 *p, int i);
int WIFI_2DCHAR_IsCellUsed(char *p, int i);
void WIFI_2DCHAR_RegisterBmpHandles(u8 *p, u32 a, u32 heap);
void WIFI_2DCHAR_ReleaseBmpHandles(char *p);
int WIFI_2DCHAR_IsHandleValid(int *p);
void WIFI_2DCHAR_RegisterPalette(u8 *p,u32 a,u32 b,u32 heap);
void WIFI_2DCHAR_ReleasePalette(u8 *p);
void WIFI_2DCHAR_RegisterBmpAnims(u8 *p,u32 heap);
void WIFI_2DCHAR_ReleaseBmpAnims(u8 *p);
void *WIFI_2DCHAR_FindFreeActor(u8 *p);
void WIFI_2DCHAR_StepActorAnimDispatch(u8 *p);
void WIFI_2DCHAR_SetAnimSeq(u8 *p, u32 i);
void WIFI_2DCHAR_SetAnimSeq4(u8 *p, u32 i);
void WIFI_2DCHAR_SetAnimSeqPlus5(u8 *p, u32 i);
void WIFI_2DCHAR_AdvanceAnimSeq(u8 *p, u32 i);
void WIFI_2DCHAR_SetAnimSeqPlus9(u8 *p, u32 i);
void WIFI_2DCHAR_SetAnimSeqPlus5B(u8 *p, u32 i);
void WIFI_2DCHAR_SetAnimSeqPlus5C(u8 *p, u32 i);
void WIFI_2DCHAR_SetAnimSeqPlus5D(u8 *p, u32 i);
void WIFI_2DCHAR_SetAnimSeqPlus5E(u8 *p, u32 i);
void WIFI_2DCHAR_AddAnimFrame(u8 *p);
void WIFI_2DCHAR_AddAnimFrame2(u8 *p);
extern const char sWifi2dcharFileName[];
extern const u8 sWifi2dcharAnimFrameCount[];

Wifi2dcharContext *WIFI_2DCHAR_Create(void *a, void *b, u32 count, u32 heap)
{
    Wifi2dcharContext *p;
    int i;
    p = GFL_HEAP_Alloc(heap, 820, 1, (char *)sWifi2dcharFileName, 339);
    p->ownerA = a;
    p->ownerB = b;
    p->charHandle = ARC_TOOL_CreateHandle(31, heap);
    p->paletteSource = ARC_TOOL_CreateHandle(32, heap);
    for (i = 0; i < 18; i++) p->cells[i].handle = -1;
    ((Wifi2dcharContext *)p)->bmpCharHandle = -1;
    ((Wifi2dcharContext *)p)->paletteHandle = -1;
    WIFI_2DCHAR_RegisterCellAnims((char *)p, 0, heap);
    p->actorCount = count;
    p->actors = GFL_HEAP_Alloc(heap, 24 * p->actorCount, 1, (char *)sWifi2dcharFileName, 379);
    return p;
}

void WIFI_2DCHAR_Delete(u8 *p)
{
    u32 i;
    for (i = 0; i < ((Wifi2dcharContext *)p)->actorCount; i++) {
        if (!WF2DMAP_MAP_IsEmpty((char *)(*(u8 * *)&((Wifi2dcharContext *)p)->actors + i * 24)))
            WIFI_2DCHAR_DeleteActor(*(u8 * *)&((Wifi2dcharContext *)p)->actors + i * 24);
    }
    WIFI_2DCHAR_ReleaseCellAnims((char *)p, 0);
    WIFI_2DCHAR_ReleaseCells(p);
    ARC_TOOL_DeleteHandle(((Wifi2dcharContext *)p)->charHandle);
    ARC_TOOL_DeleteHandle(((Wifi2dcharContext *)p)->paletteSource);
    GFL_HEAP_Free(((Wifi2dcharContext *)p)->actors);
    GFL_HEAP_Free(p);
}

void WIFI_2DCHAR_SetupBmpCell(u8 *p, int a, int b, int c, int d)
{
    WIFI_2DCHAR_IsBmpCellEnabled(a,c);
    WIFI_2DCHAR_RegisterCell((char *)p,WIFI_2DCHAR_GetCellIndex(a),b,c,d,0);
}

void WIFI_2DCHAR_ReleaseCells(u8 *p)
{
    int i;
    if (((Wifi2dcharContext *)p)->paletteHandle != (u32)-1) WIFI_2DCHAR_ReleaseBmpCells(p);
    for(i=0;i<18;i++) if(WIFI_2DCHAR_IsCellUsed((char *)p,i)==1)WIFI_2DCHAR_ReleaseCell((char *)p,i);
}

void WIFI_2DCHAR_SetupCells(u8 *p,int a,int b,int c,int d)
{
    int i;
    WIFI_2DCHAR_RegisterPalette(p,a,c,d);
    WIFI_2DCHAR_RegisterBmpAnims(p,d);
    for(i=0;i<16;i++)WIFI_2DCHAR_RegisterCell((char *)p,i,a,b,d,1);
}

void WIFI_2DCHAR_ReleaseBmpCells(u8 *p)
{
    int i;
    WIFI_2DCHAR_ReleasePalette(p);
    WIFI_2DCHAR_ReleaseBmpAnims(p);
    for (i=0; i<16; i++) WIFI_2DCHAR_ReleaseCell((char *)p, i);
}

/*
 * Addresses are Black-image addresses.
 */
void WIFI_2DCHAR_RegisterBmp(u8 *p, int a, int b, int c)
{
    WIFI_2DCHAR_RegisterBmpHandles(p, a, c);
    ((Wifi2dcharContext *)p)->bmpParam = b;
}

void WIFI_2DCHAR_ReleaseBmp(u8 *p)
{
    WIFI_2DCHAR_ReleaseBmpHandles((char *)p);
}

/*
 * note (2026-10-05, wD5 lane07): EXACT. Keys: a real record array (stride 0x14 at +0x10) keeps idx*0x14 spilled
 *   and recomputes owner+row per use; the 6/1 argument as a call in each if/else arm keeps the 6 from merging with
 *   the pos[3] offset constant; const pos lets the pos[3] load schedule above the e[1] store; off = 0x2E0 local.
 */
u32 *WIFI_2DCHAR_SpawnActor(Wifi2dcharContext *ctx, const s16 *pos, int idx, u32 heap)
{
    u32 *e = WIFI_2DCHAR_FindFreeActor((u8 *)ctx);
    Wifi2dcharActorPos l;
    int off;
    int ta;
    idx = WIFI_2DCHAR_GetCellIndex(idx);
    l.x = pos[0];
    l.y = pos[1];
    ta = pos[2];
    l.z = 0;
    l.a = ta;
    l.b = pos[3];
    e[1] = (uptr)CLACT_CreateActor((struct Unit *)ctx->ownerA, ctx->cells[idx].handle, ctx->cells[idx].owner,
                         ctx->cellAnims[idx].mode, (const struct ActorInitParam *)&l, 0, (u16)heap);
    CLACT_SetActorBgPriority((struct ClactActor *)e[1], (u8)pos[3]);
    if (ctx->cells[idx].argB == 1)
        CLACT_SetActorAnimIndex((struct ClactActor *)e[1], 6);
    else
        CLACT_SetActorAnimIndex((struct ClactActor *)e[1], 1);
    e[3] = 9;
    *(u16 *)(e + 5) = 0;
    e[4] = 1;
    e[0] = (uptr)&ctx->cells[idx];
    off = 0x2E0;
    if (WIFI_2DCHAR_IsHandleValid((int *)((u8 *)ctx + off))) {
        l.x = pos[0];
        l.y = pos[1];
        l.z = 0;
        l.a = *(u32 *)((u8 *)ctx + off + 0x10);
        l.b = 0;
        e[2] = (uptr)CLACT_CreateActor((struct Unit *)ctx->ownerA, *(u32 *)((u8 *)ctx + off), *(u32 *)((u8 *)ctx + off + 4),
                             *(u32 *)((u8 *)ctx + off + 8), (const struct ActorInitParam *)&l, 0, (u16)heap);
        CLACT_SetActorBgPriority((struct ClactActor *)e[2], (u8)pos[3]);
    } else {
        e[2] = 0;
    }
    return e;
}

void WIFI_2DCHAR_DeleteActor(u8 *p)
{
    if (((Wifi2dcharActor *)p)->subActor != 0) CLACT_DeleteActor(*(void * *)&((Wifi2dcharActor *)p)->subActor);
    CLACT_DeleteActor(*(void * *)&((Wifi2dcharActor *)p)->actor);
    MI_CpuFill8(p, 0, 24);
}

void WIFI_2DCHAR_SetActorPos(u8 *p,int x,int y)
{
    Wifi2dcharPoint pos;
    pos.x=x; pos.y=y;
    CLACT_SetActorPos((struct ClactActor *)(*(struct ClactActor * *)&((Wifi2dcharActor *)p)->actor), (const struct Pt16 *)&pos);
    if (((Wifi2dcharActor *)p)->subActor != 0) {
        pos.x=(s16)pos.x+8;
        pos.y=(s16)pos.y+14;
        CLACT_SetActorPos((struct ClactActor *)(*(struct ClactActor * *)&((Wifi2dcharActor *)p)->subActor), (const struct Pt16 *)&pos);
    }
}

void WIFI_2DCHAR_SetActorDrawPriority(u8 *p, u32 v)
{
    CLACT_SetActorDrawPriority(((Wifi2dcharActor *)p)->actor, (u8)v);
}

/*
 * Leaf of ov099 WIFICLUBACTOR_ShowMarkerAtActor's callee WF2DMAP_OBJDRAW_GetActorValue2 (a forwarder to here).
 */
int WIFI_2DCHAR_GetActorDrawPriority(u8 *p)
{
    return CLACT_GetActorDrawPriority((((Wifi2dcharActor *)p)->actor));
}

void WIFI_2DCHAR_SetActorDrawEnable(char *p, int a)
{
    CLACT_SetActorDrawEnable(((Wifi2dcharActor *)p)->actor, a);
    if (((Wifi2dcharActor *)p)->subActor != 0)
        CLACT_SetActorDrawEnable(((Wifi2dcharActor *)p)->subActor, a);
}

void WIFI_2DCHAR_SetSubActorDrawEnable(char *p, int a)
{
    if (((Wifi2dcharActor *)p)->subActor != 0)
        CLACT_SetActorDrawEnable(((Wifi2dcharActor *)p)->subActor, a);
}

/*
 * Unlabelled tail-call stub: ldr r0,[r0,#4]; ldr r3,=0x0204B3F4; bx r3.
 * Leaf of ov127 WF2DMAP_OBJDRAW_GetActorValue (blocker of ov099 WIFICLUBACTOR_AnimateWalkBob).
 */
int WIFI_2DCHAR_GetActorDrawEnable(char *p)
{
    return CLACT_GetActorDrawEnable(((Wifi2dcharActor *)p)->actor);
}

u32 WIFI_2DCHAR_GetActorCellArgB(u8 *p)
{
    return ((Wifi2dcharActor *)p)->rec->argB;
}

u32 WIFI_2DCHAR_GetActorAnimId(char *p) { return ((Wifi2dcharActor *)p)->animId; }

void WIFI_2DCHAR_SetActorAnimIndex(char *p,u32 a) { CLACT_SetActorAnimIndex(((Wifi2dcharActor *)p)->actor,a); }

int WIFI_2DCHAR_GetActorAnimSeqCount(char *p) { return CLACT_GetActorAnimSeqCount(((Wifi2dcharActor *)p)->actor); }

/*
 * extent: trailing 2-byte alignment padding only.
 */
void WIFI_2DCHAR_SetSubActorPos(char *p,int x,int y) { Wifi2dcharPoint pt; if(((Wifi2dcharActor *)p)->subActor) { pt.x=x+8; pt.y=y+14; CLACT_SetActorPos(((Wifi2dcharActor *)p)->subActor, (struct Pt16 *)&pt); } }

extern void (*sWifi2dcharAnimStartTable[])(Wifi2dcharActor *, int);

/*
 * lever: the indirect callback receives the object in r0 and payload in r1;
 * declaring both arguments preserves p and restores both store ordering and table register allocation.
 *
 * Addresses are Black-image addresses.
 */
void WIFI_2DCHAR_SetActorAnim(Wifi2dcharActor *p, int idx, int a)
{
    p->animFrame = 0;
    p->animId = idx;
    if (sWifi2dcharAnimStartTable[idx] != 0)
        sWifi2dcharAnimStartTable[idx](p,a);
}

void WIFI_2DCHAR_StepActorAnim(u8 *p) { int flag; int n; flag=0; n=sWifi2dcharAnimFrameCount[((Wifi2dcharActor *)p)->animId]; if(n==255) flag=1; else if(n>=((Wifi2dcharActor *)p)->animFrame+1) flag=1; if(flag==1) { WIFI_2DCHAR_StepActorAnimDispatch(p); ((Wifi2dcharActor *)p)->animFrame+=1; } }

void WIFI_2DCHAR_RegisterCellAnims(char *p, int unused, u32 heap) { int i; for(i=16;i<18;i++) { *(u32 *)((uptr)p+(u32)i*20+0x188)=CLACT_RegisterCellAnim(((Wifi2dcharContext *)p)->charHandle,(i-16)*2,(i-16)*2+1,(u16)heap); } }

void WIFI_2DCHAR_ReleaseCellAnims(char *p, int unused) { int i; char *q; for(i=16;i<18;i++) { q=(char *)((uptr)p+(u32)i*20); CLACT_ReleaseCellAnim(*(u32 *)(q+0x188)); *(u32 *)(q+0x188)=0; } }

int WIFI_2DCHAR_GetCellIndex(int a) { return a; }

int WIFI_2DCHAR_IsBmpCellEnabled(int unused0, int unused1) { return 1; }

void WIFI_2DCHAR_RegisterCell(char *p, int i, int a, int b, int c, int mode) { if(mode==0) WIFI_2DCHAR_RegisterBmpCharCell((Wifi2dcharContext *)p, i, a, b, c); else WIFI_2DCHAR_RegisterCharCell((u8 *)p,i,a,b,c); }

void WIFI_2DCHAR_RegisterBmpCharCell(Wifi2dcharContext *ctx, int i, u32 a, u32 b, u32 c)
{
    int n;
    n = (i - 16) * 2;
    ctx->cells[i].handle = CLACT_RegisterCharacter((void *)ctx->charHandle, n + 5, 0, a, c);
    ctx->cells[i].owner = CLACT_RegisterPaletteEx((void *)ctx->charHandle, n + 4, a, 256, 0, 2, c);
    ctx->cells[i].argA = a;
    ctx->cells[i].argB = b;
    ctx->cells[i].mode = 0;
}

void WIFI_2DCHAR_RegisterCharCell(u8 *p, int i, u32 a, u32 b, u32 c)
{
    Wifi2dcharContext *ctx;
    ctx = (Wifi2dcharContext *)p;
    ctx->cells[i].handle = CLACT_RegisterCharacter((void *)ctx->paletteSource, i + 1, 0, a, c);
    ctx->cells[i].owner = ctx->paletteHandle;
    ctx->cells[i].argA = a;
    ctx->cells[i].argB = b;
    ctx->cells[i].mode = 1;
}

void WIFI_2DCHAR_ReleaseCell(char *p, int i)
{
    if (*(int *)(p + i * 0x14 + 0x10) == 0)
        WIFI_2DCHAR_ReleaseCellPair(p, i);
    else
        WIFI_2DCHAR_ReleaseCellChar((u8 *)p, i);
}

void WIFI_2DCHAR_ReleaseCellPair(char *p,int i) { CLACT_ReleaseCharacter(*(u32 *)(p+20+(u32)i*20)); CLACT_ReleasePalette(*(u32 *)(p+24+(u32)i*20)); *(u32 *)(p+20+(u32)i*20)=-1; *(u32 *)(p+24+(u32)i*20)=-1; }

void WIFI_2DCHAR_ReleaseCellChar(u8 *p, int i)
{
    u32 *tbl = (u32 *)(p + 0x14 + i * 20);
    CLACT_ReleaseCharacter((uptr)((void *)*tbl));
    *tbl = (u32)-1;
}

int WIFI_2DCHAR_IsCellUsed(char *p, int i)
{
    if (*(int *)(p + i * 0x14 + 0x14) == -1)
        return 0;
    return 1;
}

/*
 * extent: two zero alignment bytes at 0x021C4512 follow the return.
 */
void WIFI_2DCHAR_RegisterBmpHandles(u8 *p, u32 a, u32 heap)
{
    int i;
    i = 16;
    if (WIFI_2DCHAR_IsCellUsed((char *)p, 16) == 1) {
        ((Wifi2dcharContext *)p)->bmpCellSlot = i;
    } else {
        i = 17;
        if (WIFI_2DCHAR_IsCellUsed((char *)p, 17) == 1)
        ((Wifi2dcharContext *)p)->bmpCellSlot = i;
    }
    ((Wifi2dcharContext *)p)->bmpAnimHandle = (u32)CLACT_RegisterCellAnim((void *)(((Wifi2dcharContext *)p)->charHandle), 9, 8, (u16)heap);
    ((Wifi2dcharContext *)p)->bmpCharHandle = CLACT_RegisterCharacter((void *)(((Wifi2dcharContext *)p)->charHandle), 11, 0, a, heap);
    ((Wifi2dcharContext *)p)->bmpPaletteHandle = CLACT_RegisterPaletteEx((void *)(((Wifi2dcharContext *)p)->charHandle), 10, a, 320, 0, 1, heap);
}

void WIFI_2DCHAR_ReleaseBmpHandles(char *p) { if(WIFI_2DCHAR_IsHandleValid((int *)(p+0x2e0))==1) { CLACT_ReleaseCharacter(((Wifi2dcharContext *)p)->bmpCharHandle); ((Wifi2dcharContext *)p)->bmpCharHandle=-1; CLACT_ReleasePalette(((Wifi2dcharContext *)p)->bmpPaletteHandle); ((Wifi2dcharContext *)p)->bmpPaletteHandle=-1; CLACT_ReleaseCellAnim(((Wifi2dcharContext *)p)->bmpAnimHandle); ((Wifi2dcharContext *)p)->bmpAnimHandle=-1; } }

int WIFI_2DCHAR_IsHandleValid(int *p)
{
    return *p != -1;
}

void WIFI_2DCHAR_RegisterPalette(u8 *p,u32 a,u32 b,u32 heap) { ((Wifi2dcharContext *)p)->paletteHandle=CLACT_RegisterPaletteEx(((Wifi2dcharContext *)p)->paletteSource,0,a,(u16)b,0,8,heap); }

void WIFI_2DCHAR_ReleasePalette(u8 *p)
{
    CLACT_ReleasePalette((u32)(((Wifi2dcharContext *)p)->paletteHandle));
    *(u32 *)&((Wifi2dcharContext *)p)->paletteHandle = (u32)-1;
}

/*
 * Extent remainder: 2-byte zero alignment padding.
 */
void WIFI_2DCHAR_RegisterBmpAnims(u8 *p,u32 heap) { int i; for(i=0;i<16;i++) *(u32 *)(p+i*20+392)=CLACT_RegisterCellAnim(((Wifi2dcharContext *)p)->paletteSource,i*2+17,i*2+18,(u16)heap); }

void WIFI_2DCHAR_ReleaseBmpAnims(u8 *p) { int i; for(i=0;i<16;i++){CLACT_ReleaseCellAnim(*(u32 *)(p+i*20+392));*(u32 *)(p+i*20+392)=-1;} }

void *WIFI_2DCHAR_FindFreeActor(u8 *p) { u32 i; for(i=0;i<((Wifi2dcharContext *)p)->actorCount;i++) { if(WF2DMAP_MAP_IsEmpty(*(char * *)&((Wifi2dcharContext *)p)->actors+i*24)==1) return *(char * *)&((Wifi2dcharContext *)p)->actors+i*24; } return 0; }

extern void (*const sWifi2dcharAnimStepTable[])(u8 *);

void WIFI_2DCHAR_StepActorAnimDispatch(u8 *p)
{
    void (*f)(u8 *);
    f = sWifi2dcharAnimStepTable[((Wifi2dcharActor *)p)->animId];
    if (f) f(p);
}

void WIFI_2DCHAR_SetAnimSeq(u8 *p, u32 i)
{
    ((Wifi2dcharActor *)p)->animSeq = i;
    CLACT_ChangeActorAnimSeq(((Wifi2dcharActor *)p)->actor, i);
}

void WIFI_2DCHAR_SetAnimSeq4(u8 *p, u32 i)
{
    ((Wifi2dcharActor *)p)->animSeq = i;
    CLACT_ChangeActorAnimSeq(((Wifi2dcharActor *)p)->actor, 4);
}

void WIFI_2DCHAR_SetAnimSeqPlus5(u8 *p, u32 i)
{
    ((Wifi2dcharActor *)p)->animSeq = i;
    CLACT_ChangeActorAnimSeq(((Wifi2dcharActor *)p)->actor, i + 5);
}

void WIFI_2DCHAR_AdvanceAnimSeq(u8 *p, u32 i)
{
    CLACT_ChangeActorAnimSeq(((Wifi2dcharActor *)p)->actor, ((Wifi2dcharActor *)p)->animSeq + 5);
    ((Wifi2dcharActor *)p)->animSeq = i;
}

void WIFI_2DCHAR_SetAnimSeqPlus9(u8 *p, u32 i)
{
    ((Wifi2dcharActor *)p)->animSeq = i;
    CLACT_ChangeActorAnimSeq(((Wifi2dcharActor *)p)->actor, i + 9);
}

void WIFI_2DCHAR_SetAnimSeqPlus5B(u8 *p, u32 i)
{
    ((Wifi2dcharActor *)p)->animSeq = i;
    CLACT_ChangeActorAnimSeq(((Wifi2dcharActor *)p)->actor, i + 5);
}

void WIFI_2DCHAR_SetAnimSeqPlus5C(u8 *p, u32 i)
{
    ((Wifi2dcharActor *)p)->animSeq = i;
    CLACT_ChangeActorAnimSeq(((Wifi2dcharActor *)p)->actor, i + 5);
}

void WIFI_2DCHAR_SetAnimSeqPlus5D(u8 *p, u32 i)
{
    ((Wifi2dcharActor *)p)->animSeq = i;
    CLACT_ChangeActorAnimSeq(((Wifi2dcharActor *)p)->actor, i + 5);
}

void WIFI_2DCHAR_SetAnimSeqPlus5E(u8 *p, u32 i)
{
    ((Wifi2dcharActor *)p)->animSeq = i;
    CLACT_ChangeActorAnimSeq(((Wifi2dcharActor *)p)->actor, i + 5);
}

void WIFI_2DCHAR_AddAnimFrame(u8 *p) { CLACT_AddActorAnimFrame(((Wifi2dcharActor *)p)->actor, 8192); }

void WIFI_2DCHAR_AddAnimFrame2(u8 *p) { CLACT_AddActorAnimFrame(((Wifi2dcharActor *)p)->actor, 8192); }
