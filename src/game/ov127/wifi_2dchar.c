/*
 * file:     wifi_2dchar.c
 * unit:     yes
 * function: func_021C3EE0, func_021C3F80, func_021C3FDC, func_021C4010, func_021C4044, func_021C4080, func_021C40A0, func_021C40B4, func_021C40BC, func_021C41BC, func_021C41DC, func_021C4214, func_021C4224, func_021C4230, func_021C424C, func_021C425C, func_021C4268, func_021C4270, func_021C4274, func_021C4280, func_021C428C, func_021C42A8, func_021C42C4, func_021C42FC, func_021C4330, func_021C4354, func_021C4358, func_021C435C, func_021C4380, func_021C43E4, func_021C4424, func_021C4440, func_021C4464, func_021C447C, func_021C4494, func_021C4514, func_021C4550, func_021C4564, func_021C4594, func_021C45AC, func_021C45E0, func_021C4604, func_021C4634, func_021C4680
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
 *   func_02030734 0x02030734 arm
 *   func_020490F4 0x020490F4 arm
 *   d_021C6100 0x021C6100 data a1
 *   WF2DMAP_MAP_IsEmpty 0x021C4790 thumb ov127
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
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
 *   tbl_021C5FBC  0x021C5FBC  data  a4
 *   d_021C5FB0 0x021C5FB0 data a4
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   d_021C5FE4 0x021C5FE4 data a4
 *   CLACT_ChangeActorAnimSeq 0x0204B8A0 arm
 *   CLACT_AddActorAnimFrame 0x0204B8D4 arm
 */
#include "../../matched/include/Obj02839.h"
#include "../../matched/include/Obj05371.h"
#include "../../matched/include/Obj23013.h"
#include "../../matched/include/Obj03277.h"
#include "../../matched/include/Obj10462.h"
#include "../../matched/include/Obj10463.h"
#include "../../matched/include/Obj23014.h"
#include "../../matched/include/Obj23015.h"
#include "../../matched/include/Obj10464.h"
#include "../../matched/include/Obj14015.h"
#include "../../matched/include/Obj23016.h"
#include "../../matched/include/Obj23017.h"
#include "../../matched/include/Obj23018.h"
#include "../../matched/include/Obj23019.h"
#include "../../matched/include/Obj23020.h"
#include "../../matched/include/Obj23021.h"
#include "../../matched/include/Obj14016.h"
#include "../../matched/include/Obj10465.h"
#include "../../matched/include/Obj23022.h"
#include "../../matched/include/Obj14018.h"
#include "../../matched/include/Obj05372.h"
#include "../../matched/include/Obj10466.h"
#include "../../matched/include/Obj14020.h"
#include "../../matched/include/Obj10467.h"
#include "../../matched/include/Obj14021.h"
#include "../../matched/include/Obj14022.h"
#include "../../matched/include/Obj14023.h"
#include "../../matched/include/Obj23024.h"
#include "../../matched/include/Obj10468.h"
#include "../../matched/include/Obj14024.h"
#include "../../matched/include/Obj14025.h"
#include "../../matched/include/Obj14026.h"
#include "../../matched/include/Obj14027.h"
#include "../../matched/include/Obj14028.h"
#include "../../matched/include/Obj23025.h"
#include "../../matched/include/Obj23026.h"

struct Obj;
struct Actor;
struct Node;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 mode, handle, owner, a, b; } Entry;

typedef struct { void *a, *b, *items; u32 count; Entry entries[18]; u8 gap[384]; void *h0, *h1; u8 rest[52]; } Context;

typedef signed short s16;

typedef signed int     s32;

typedef struct { s16 x, y, z; u8 a, b; } Pos;

typedef struct { u32 f0, f4, f8, fC, f10; } Rec;

typedef struct {
    u32 h0;
    u8 pad4[0xC];
    Rec rec[18];        /* +0x010 */
    u8 pad178[0x10];
    Rec res[1];         /* +0x188, indexed by idx */
} Own;

typedef struct Pt_021C3EE0 {u16 x,y;} Pt_021C3EE0;

typedef struct Pt_021C4214 { u16 x,y; } Pt_021C4214;

struct obj {
    int pad0[3];
    int idx;
    int pad1;
    u16 f14;
};

typedef struct { u8 pad[16]; Entry entries[18]; u8 gap[384]; u32 source; } Context_021C4380;

typedef struct { u8 pad[16]; Entry entries[18]; u8 gap[380]; u32 owner; u32 gap2; u32 source; } Context_021C43E4;

typedef signed char s8;

extern void *func_02030734(u16, u32, int, const char *, u16);
extern void *func_020490F4(unsigned int id, u16 heap);
extern int WF2DMAP_MAP_IsEmpty(char *p);
extern void ARC_TOOL_DeleteHandle(u32);
extern u32 func_020307B0(void *p);
extern struct Obj *CLACT_CreateActor(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void CLACT_SetActorBgPriority(u32, u32);
extern void CLACT_SetActorAnimIndex(int a0, int a1);
extern void CLACT_DeleteActor(struct Obj *);
extern void MI_CpuFill8(void *, int, int);
extern void CLACT_SetActorPos(struct Actor *, const struct Pt_021C3EE0 *);
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern int CLACT_GetActorDrawPriority(int a0);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern u16 CLACT_GetActorAnimSeqCount(struct Obj *p);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void CLACT_ReleaseCellAnim(u32);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleasePalette(u32);
extern void CLACT_ChangeActorAnimSeq(struct Obj *p, u16 v);
extern void CLACT_AddActorAnimFrame(struct Obj *p, u32 arg);
Context *func_021C3EE0(void *a, void *b, u32 count, u32 heap);
void func_021C3F80(u8 *p);
void func_021C3FDC(u8 *p, int a, int b, int c, int d);
void func_021C4010(u8 *p);
void func_021C4044(u8 *p,int a,int b,int c,int d);
void func_021C4080(u8 *p);
void func_021C40A0(u8 *p, int a, int b, int c);
void func_021C40B4(u8 *p);
u32 *func_021C40BC(Own *owner, const s16 *pos, int idx, u32 heap);
void func_021C41BC(u8 *p);
void func_021C41DC(u8 *p,int x,int y);
void func_021C4214(u8 *p, u32 v);
int func_021C4224(u8 *p);
void func_021C4230(char *p, int a);
void func_021C424C(char *p, int a);
int func_021C425C(char *p);
void *func_021C4268(u8 *p);
u32 func_021C4270(char *p);
void func_021C4274(char *p,u32 a);
int func_021C4280(char *p);
void func_021C428C(char *p,int x,int y);
void func_021C42A8(struct obj *p, int idx, int a);
void func_021C42C4(u8 *p);
void func_021C42FC(char *p, int unused, u32 heap);
void func_021C4330(char *p, int a1);
int func_021C4354(int a);
int func_021C4358(int a0, int a1);
void func_021C435C(char *p, int i, int a, int b, int c, int mode);
void func_021C4380(Context_021C4380 *ctx, int i, u32 a, u32 b, u32 c);
void func_021C43E4(u8 *p, int i, u32 a, u32 b, u32 c);
void func_021C4424(char *p, int i);
void func_021C4440(char *p,int i);
void func_021C4464(u8 *p, int i);
int func_021C447C(char *p, int i);
void func_021C4494(u8 *p, u32 a, u32 heap);
void func_021C4514(char *p);
int func_021C4550(int *p);
void func_021C4564(u8 *p,u32 a,u32 b,u32 heap);
void func_021C4594(u8 *p);
void func_021C45AC(u8 *p,u32 heap);
void func_021C45E0(u8 *p);
void *func_021C4604(u8 *p);
void func_021C4634(u8 *p);
void func_021C464C(u8 *p, u32 i);
void func_021C465C(u8 *p, u32 i);
void func_021C466C(u8 *p, u32 i);
void func_021C4680(u8 *p, u32 i);
void func_021C4698(u8 *p, u32 i);
void func_021C46AC(u8 *p, u32 i);
void func_021C46C0(u8 *p, u32 i);
void func_021C46D4(u8 *p, u32 i);
void func_021C46E8(u8 *p, u32 i);
void func_021C46FC(u8 *p);
void func_021C470C(u8 *p);
extern const char d_021C6100[];
extern const u8 d_021C5FB0[];



Context *func_021C3EE0(void *a, void *b, u32 count, u32 heap)
{
    Context *p;
    int i;
    p = func_02030734(heap, 820, 1, d_021C6100, 339);
    p->a = a;
    p->b = b;
    p->h0 = func_020490F4(31, heap);
    p->h1 = func_020490F4(32, heap);
    for (i = 0; i < 18; i++) p->entries[i].handle = -1;
    ((struct Obj02839 *)p)->f2E0 = -1;
    ((struct Obj02839 *)p)->f2F4 = -1;
    func_021C42FC((char *)p, 0, heap);
    p->count = count;
    p->items = func_02030734(heap, 24 * p->count, 1, d_021C6100, 379);
    return p;
}



void func_021C3F80(u8 *p)
{
    u32 i;
    for (i = 0; i < ((struct Obj05371 *)p)->fC; i++) {
        if (!WF2DMAP_MAP_IsEmpty((char *)(*(u8 * *)&((struct Obj05371 *)p)->f8 + i * 24)))
            func_021C41BC(*(u8 * *)&((struct Obj05371 *)p)->f8 + i * 24);
    }
    func_021C4330((char *)p, 0);
    func_021C4010(p);
    ARC_TOOL_DeleteHandle(((struct Obj05371 *)p)->f2F8);
    ARC_TOOL_DeleteHandle(((struct Obj05371 *)p)->f2FC);
    func_020307B0(((struct Obj05371 *)p)->f8);
    func_020307B0(p);
}



void func_021C3FDC(u8 *p, int a, int b, int c, int d)
{
    func_021C4358(a,c);
    func_021C435C((char *)p,func_021C4354(a),b,c,d,0);
}



void func_021C4010(u8 *p)
{
    int i;
    if (((struct Obj23013 *)p)->f2F4 != (u32)-1) func_021C4080(p);
    for(i=0;i<18;i++) if(func_021C447C((char *)p,i)==1)func_021C4424((char *)p,i);
}



void func_021C4044(u8 *p,int a,int b,int c,int d)
{
    int i;
    func_021C4564(p,a,c,d);
    func_021C45AC(p,d);
    for(i=0;i<16;i++)func_021C435C((char *)p,i,a,b,d,1);
}



void func_021C4080(u8 *p)
{
    int i;
    func_021C4594(p);
    func_021C45E0(p);
    for (i=0; i<16; i++) func_021C4424((char *)p, i);
}




/*
 * Addresses are Black-image addresses.
 */
void func_021C40A0(u8 *p, int a, int b, int c)
{
    func_021C4494(p, a, c);
    ((struct Obj03277 *)p)->f2F0 = b;
}



void func_021C40B4(u8 *p)
{
    func_021C4514((char *)p);
}



/*
 * note (2026-10-05, wD5 lane07): EXACT. Keys: a real record array (stride 0x14 at +0x10) keeps idx*0x14 spilled
 *   and recomputes owner+row per use; the 6/1 argument as a call in each if/else arm keeps the 6 from merging with
 *   the pos[3] offset constant; const pos lets the pos[3] load schedule above the e[1] store; off = 0x2E0 local.
 */
u32 *func_021C40BC(Own *owner, const s16 *pos, int idx, u32 heap)
{
    u32 *e = func_021C4604((u8 *)owner);
    Pos l;
    int off;
    int ta;
    idx = func_021C4354(idx);
    l.x = pos[0];
    l.y = pos[1];
    ta = pos[2];
    l.z = 0;
    l.a = ta;
    l.b = pos[3];
    e[1] = (u32)CLACT_CreateActor((void *)owner->h0, owner->rec[idx].f4, owner->rec[idx].f8,
                         owner->res[idx].f0, &l, 0, (u16)heap);
    CLACT_SetActorBgPriority(e[1], (u8)pos[3]);
    if (owner->rec[idx].f10 == 1)
        CLACT_SetActorAnimIndex(e[1], 6);
    else
        CLACT_SetActorAnimIndex(e[1], 1);
    e[3] = 9;
    *(u16 *)(e + 5) = 0;
    e[4] = 1;
    e[0] = (u32)&owner->rec[idx];
    off = 0x2E0;
    if (func_021C4550((int *)((u8 *)owner + off))) {
        l.x = pos[0];
        l.y = pos[1];
        l.z = 0;
        l.a = *(u32 *)((u8 *)owner + off + 0x10);
        l.b = 0;
        e[2] = (u32)CLACT_CreateActor((void *)owner->h0, *(u32 *)((u8 *)owner + off), *(u32 *)((u8 *)owner + off + 4),
                             *(u32 *)((u8 *)owner + off + 8), &l, 0, (u16)heap);
        CLACT_SetActorBgPriority(e[2], (u8)pos[3]);
    } else {
        e[2] = 0;
    }
    return e;
}



void func_021C41BC(u8 *p)
{
    if (((struct Obj10462 *)p)->f8 != 0) CLACT_DeleteActor(*(struct Obj * *)&((struct Obj10462 *)p)->f8);
    CLACT_DeleteActor(*(struct Obj * *)&((struct Obj10462 *)p)->f4);
    MI_CpuFill8(p, 0, 24);
}



void func_021C41DC(u8 *p,int x,int y)
{
    Pt_021C3EE0 pos;
    pos.x=x; pos.y=y;
    CLACT_SetActorPos(*(struct Actor * *)&((struct Obj10463 *)p)->f4, (const struct Pt_021C3EE0 *)&pos);
    if (((struct Obj10463 *)p)->f8 != 0) {
        pos.x=(s16)pos.x+8;
        pos.y=(s16)pos.y+14;
        CLACT_SetActorPos(*(struct Actor * *)&((struct Obj10463 *)p)->f8, (const struct Pt_021C3EE0 *)&pos);
    }
}




void func_021C4214(u8 *p, u32 v)
{
    CLACT_SetActorDrawPriority(((struct Obj23014 *)p)->f4, (u8)v);
}




/*
 * Leaf of ov099 func_021B989C's callee WF2DMAP_OBJDRAW_GetActorValue2 (a forwarder to here).
 */
int func_021C4224(u8 *p)
{
    return CLACT_GetActorDrawPriority((int)(((struct Obj23015 *)p)->f4));
}




void func_021C4230(char *p, int a)
{
    CLACT_SetActorDrawEnable(((struct Obj10464 *)p)->f4, a);
    if (((struct Obj10464 *)p)->f8 != 0)
        CLACT_SetActorDrawEnable(((struct Obj10464 *)p)->f8, a);
}




void func_021C424C(char *p, int a)
{
    if (((struct Obj14015 *)p)->f8 != 0)
        CLACT_SetActorDrawEnable(((struct Obj14015 *)p)->f8, a);
}




/*
 * Unlabelled tail-call stub: ldr r0,[r0,#4]; ldr r3,=0x0204B3F4; bx r3.
 * Leaf of ov127 WF2DMAP_OBJDRAW_GetActorValue (blocker of ov099 func_021BA2D4).
 */
int func_021C425C(char *p)
{
    return CLACT_GetActorDrawEnable(((struct Obj23016 *)p)->f4);
}



void *func_021C4268(u8 *p)
{
    return ((struct Obj23018 *)(*(u8 * *)&((struct Obj23017 *)p)->f0))->f10;
}




u32 func_021C4270(char *p) { return ((struct Obj23019 *)p)->fC; }



void func_021C4274(char *p,u32 a) { CLACT_SetActorAnimIndex(((struct Obj23020 *)p)->f4,a); }



int func_021C4280(char *p) { return CLACT_GetActorAnimSeqCount(((struct Obj23021 *)p)->f4); }



/*
 * extent: trailing 2-byte alignment padding only.
 */
void func_021C428C(char *p,int x,int y) { Pt_021C4214 pt; if(((struct Obj14016 *)p)->f8) { pt.x=x+8; pt.y=y+14; CLACT_SetActorPos(((struct Obj14016 *)p)->f8, (const struct Pt_021C3EE0 *)&pt); } }




extern void (*tbl_021C5FBC[])(struct obj *, int);




/*
 * lever: the indirect callback receives the object in r0 and payload in r1;
 * declaring both arguments preserves p and restores both store ordering and table register allocation.
 *
 * Addresses are Black-image addresses.
 */
void func_021C42A8(struct obj *p, int idx, int a)
{
    p->f14 = 0;
    p->idx = idx;
    if (tbl_021C5FBC[idx] != 0)
        tbl_021C5FBC[idx](p,a);
}






void func_021C42C4(u8 *p) { int flag; int n; flag=0; n=d_021C5FB0[((struct Obj10465 *)p)->fC]; if(n==255) flag=1; else if(n>=((struct Obj10465 *)p)->f14+1) flag=1; if(flag==1) { func_021C4634(p); ((struct Obj10465 *)p)->f14+=1; } }






void func_021C42FC(char *p, int unused, u32 heap) { int i; for(i=16;i<18;i++) { *(u32 *)((u32)p+(u32)i*20+0x188)=CLACT_RegisterCellAnim(((struct Obj23022 *)p)->f2F8,(i-16)*2,(i-16)*2+1,(u16)heap); } }






void func_021C4330(char *p, int a1) { int i; char *q; for(i=16;i<18;i++) { q=(char *)((u32)p+(u32)i*20); CLACT_ReleaseCellAnim(((struct Obj14018 *)q)->f188); ((struct Obj14018 *)q)->f188=0; } }







int func_021C4354(int a) { return a; }







int func_021C4358(int a0, int a1) { return 1; }





void func_021C435C(char *p, int i, int a, int b, int c, int mode) { if(mode==0) func_021C4380((Context_021C4380 *)p, i, a, b, c); else func_021C43E4((u8 *)p,i,a,b,c); }





void func_021C4380(Context_021C4380 *ctx, int i, u32 a, u32 b, u32 c)
{
    int n;
    n = (i - 16) * 2;
    ctx->entries[i].handle = CLACT_RegisterCharacter((void *)ctx->source, n + 5, 0, a, c);
    ctx->entries[i].owner = CLACT_RegisterPaletteEx((void *)ctx->source, n + 4, a, 256, 0, 2, c);
    ctx->entries[i].a = a;
    ctx->entries[i].b = b;
    ctx->entries[i].mode = 0;
}





void func_021C43E4(u8 *p, int i, u32 a, u32 b, u32 c)
{
    Context_021C43E4 *ctx;
    ctx = (Context_021C43E4 *)p;
    ctx->entries[i].handle = CLACT_RegisterCharacter((void *)ctx->source, i + 1, 0, a, c);
    ctx->entries[i].owner = ctx->owner;
    ctx->entries[i].a = a;
    ctx->entries[i].b = b;
    ctx->entries[i].mode = 1;
}





void func_021C4424(char *p, int i)
{
    if (*(int *)(p + i * 0x14 + 0x10) == 0)
        func_021C4440(p, i);
    else
        func_021C4464((u8 *)p, i);
}




void func_021C4440(char *p,int i) { CLACT_ReleaseCharacter(*(u32 *)(p+20+(u32)i*20)); CLACT_ReleasePalette(*(u32 *)(p+24+(u32)i*20)); *(u32 *)(p+20+(u32)i*20)=-1; *(u32 *)(p+24+(u32)i*20)=-1; }





void func_021C4464(u8 *p, int i)
{
    u32 *tbl = (u32 *)(p + 0x14 + i * 20);
    CLACT_ReleaseCharacter((u32)((void *)*tbl));
    *tbl = (u32)-1;
}




int func_021C447C(char *p, int i)
{
    if (*(int *)(p + i * 0x14 + 0x14) == -1)
        return 0;
    return 1;
}



/*
 * extent: two zero alignment bytes at 0x021C4512 follow the return.
 */
void func_021C4494(u8 *p, u32 a, u32 heap)
{
    int i;
    i = 16;
    if (func_021C447C((char *)p, 16) == 1) {
        ((struct Obj03277 *)p)->f330 = i;
    } else {
        i = 17;
        if (func_021C447C((char *)p, 17) == 1)
        ((struct Obj03277 *)p)->f330 = i;
    }
    ((struct Obj03277 *)p)->f2E8 = (u32)CLACT_RegisterCellAnim((void *)(((struct Obj03277 *)p)->f2F8), 9, 8, (u16)heap);
    ((struct Obj03277 *)p)->f2E0 = CLACT_RegisterCharacter((void *)(((struct Obj03277 *)p)->f2F8), 11, 0, a, heap);
    ((struct Obj03277 *)p)->f2E4 = CLACT_RegisterPaletteEx((void *)(((struct Obj03277 *)p)->f2F8), 10, a, 320, 0, 1, heap);
}



void func_021C4514(char *p) { if(func_021C4550((int *)(p+0x2e0))==1) { CLACT_ReleaseCharacter(((struct Obj05372 *)p)->f2E0); ((struct Obj05372 *)p)->f2E0=-1; CLACT_ReleasePalette(((struct Obj05372 *)p)->f2E4); ((struct Obj05372 *)p)->f2E4=-1; CLACT_ReleaseCellAnim(((struct Obj05372 *)p)->f2E8); ((struct Obj05372 *)p)->f2E8=-1; } }




int func_021C4550(int *p)
{
    return *p != -1;
}



void func_021C4564(u8 *p,u32 a,u32 b,u32 heap) { ((struct Obj10466 *)p)->f2F4=CLACT_RegisterPaletteEx(((struct Obj10466 *)p)->f2FC,0,a,(u16)b,0,8,heap); }




void func_021C4594(u8 *p)
{
    CLACT_ReleasePalette((u32)(((struct Obj14020 *)p)->f2F4));
    *(u32 *)&((struct Obj14020 *)p)->f2F4 = (u32)-1;
}



/*
 * Extent remainder: 2-byte zero alignment padding.
 */
void func_021C45AC(u8 *p,u32 heap) { int i; for(i=0;i<16;i++) *(u32 *)(p+i*20+392)=CLACT_RegisterCellAnim(((struct Obj10466 *)p)->f2FC,i*2+17,i*2+18,(u16)heap); }



void func_021C45E0(u8 *p) { int i; for(i=0;i<16;i++){CLACT_ReleaseCellAnim(*(u32 *)(p+i*20+392));*(u32 *)(p+i*20+392)=-1;} }



void *func_021C4604(u8 *p) { u32 i; for(i=0;i<((struct Obj10467 *)p)->fC;i++) { if(WF2DMAP_MAP_IsEmpty(*(char * *)&((struct Obj10467 *)p)->f8+i*24)==1) return *(char * *)&((struct Obj10467 *)p)->f8+i*24; } return 0; }



extern void (*const d_021C5FE4[])(u8 *);



void func_021C4634(u8 *p)
{
    void (*f)(u8 *);
    f = d_021C5FE4[((struct Obj23024 *)p)->fC];
    if (f) f(p);
}



void func_021C464C(u8 *p, u32 i)
{
    ((struct Obj14021 *)p)->f10 = i;
    CLACT_ChangeActorAnimSeq(((struct Obj14021 *)p)->f4, i);
}



void func_021C465C(u8 *p, u32 i)
{
    ((struct Obj14022 *)p)->f10 = i;
    CLACT_ChangeActorAnimSeq(((struct Obj14022 *)p)->f4, 4);
}



void func_021C466C(u8 *p, u32 i)
{
    ((struct Obj14023 *)p)->f10 = i;
    CLACT_ChangeActorAnimSeq(((struct Obj14023 *)p)->f4, i + 5);
}



void func_021C4680(u8 *p, u32 i)
{
    CLACT_ChangeActorAnimSeq(((struct Obj10468 *)p)->f4, ((struct Obj10468 *)p)->f10 + 5);
    ((struct Obj10468 *)p)->f10 = i;
}



void func_021C4698(u8 *p, u32 i)
{
    ((struct Obj14024 *)p)->f10 = i;
    CLACT_ChangeActorAnimSeq(((struct Obj14024 *)p)->f4, i + 9);
}



void func_021C46AC(u8 *p, u32 i)
{
    ((struct Obj14025 *)p)->f10 = i;
    CLACT_ChangeActorAnimSeq(((struct Obj14025 *)p)->f4, i + 5);
}



void func_021C46C0(u8 *p, u32 i)
{
    ((struct Obj14026 *)p)->f10 = i;
    CLACT_ChangeActorAnimSeq(((struct Obj14026 *)p)->f4, i + 5);
}



void func_021C46D4(u8 *p, u32 i)
{
    ((struct Obj14027 *)p)->f10 = i;
    CLACT_ChangeActorAnimSeq(((struct Obj14027 *)p)->f4, i + 5);
}



void func_021C46E8(u8 *p, u32 i)
{
    ((struct Obj14028 *)p)->f10 = i;
    CLACT_ChangeActorAnimSeq(((struct Obj14028 *)p)->f4, i + 5);
}



void func_021C46FC(u8 *p) { CLACT_AddActorAnimFrame(((struct Obj23025 *)p)->f4, 8192); }



void func_021C470C(u8 *p) { CLACT_AddActorAnimFrame(((struct Obj23026 *)p)->f4, 8192); }
