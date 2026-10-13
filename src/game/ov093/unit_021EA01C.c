/*
 * file:     unit_021EA01C.c
 * unit:     yes
 * function: func_021EA01C, func_021EA030, func_021EA044, func_021EA04C, func_021EA058, func_021EA0A0, func_021EA0E4, func_021EA0F4, func_021EA120, func_021EA160, func_021EA1B8, func_021EA1F0, func_021EA230, func_021EA280, func_021EA2BC, func_021EA32C, func_021EA354, func_021EA384, func_021EA3A0, func_021EA3B8, func_021EA3D4, func_021EA3E8, func_021EA3F8, func_021EA40C, func_021EA428, func_021EA438, func_021EA448, func_021EA458, func_021EA478, func_021EA488, func_021EA4C4, func_021EA504, func_021EA55C, func_021EA5E4, func_021EA5F0, func_021EA600, func_021EA614, func_021EA638, func_021EA65C, func_021EA678, func_021EA694, func_021EA6B0, func_021EA6F4, func_021EA710, func_021EA720, func_021EA730, func_021EA758, func_021EA768, func_021EA778, func_021EA788, func_021EA798, func_021EA7A8, func_021EA7B8, func_021EA7C8, func_021EA7D8, func_021EA7E8, func_021EA7FC, func_021EA814, func_021EA824, func_021EA838, func_021EA850, func_021EA868, func_021EA878, func_021EA888, func_021EA8A4, func_021EA8B4, func_021EA8D4, func_021EA8E4, func_021EA8F4, func_021EA904, func_021EA950, func_021EA990, func_021EAA00
 * address:  0x021EA01C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0689B514  0x0689B514  thumb
 *   MYITEM_SAVEDATA_SetBattlePocketCursors  0x020082B8  thumb
 *   MYITEM_SAVEDATA_SetLastBattleItem  0x020082D4  thumb
 *   BTL_MAIN_GetViewPosOfSlot  0x021B8E70  thumb  ov093
 *   func_021ED118  0x021ED118  thumb  ov093
 *   func_021ED1B0   0x021ED1B0  thumb  ov093
 *   func_021E9100  0x021E9100  thumb  ov093
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   func_021ED208  0x021ED208  thumb  ov093
 *   func_021ED250  0x021ED250  thumb  ov093
 *   func_021ED268  0x021ED268  thumb  ov093
 *   func_021ED280  0x021ED280  thumb  ov093
 *   BTL_MAIN_GetTrainerSlotOfPoke  0x021B8D8C  thumb  ov093
 *   func_021ECF68  0x021ECF68  thumb  ov093
 *   func_021EAF00  0x021EAF00  thumb  ov093
 *   func_021F7F1C  0x021F7F1C  thumb  ov094
 *   func_021F853C  0x021F853C  thumb  ov094
 *   func_021F7E74  0x021F7E74  thumb  ov094
 *   func_021F7E84  0x021F7E84  thumb  ov094
 *   func_021ED494  0x021ED494  thumb  ov093
 *   func_021ED4D0   0x021ED4D0  thumb  ov093
 *   func_021F7A28  0x021F7A28  thumb  ov094
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021F7AAC  0x021F7AAC  thumb  ov094
 *   func_021ED294  0x021ED294  thumb  ov093
 *   func_021ED2BC   0x021ED2BC  thumb  ov093
 *   func_021ED2D0   0x021ED2D0  thumb  ov093
 *   func_021ED304   0x021ED304  thumb  ov093
 *   func_021ED318  0x021ED318  thumb  ov093
 *   func_021ED374   0x021ED374  thumb  ov093
 *   BTL_SIDE_GetPokeAtPos  0x021B98AC  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021ED3D4  0x021ED3D4  thumb  ov093
 *   func_021ED450  0x021ED450  thumb  ov093
 *   BTL_MSG_FormatWithSide  0x021EEE80  thumb  ov093
 *   BTL_MSG_DispatchTagged  0x021EEEF4  thumb  ov093
 *   BTL_MSG_GetUiString  0x021EF694  thumb  ov093
 *   BTL_MSG_BuildUiString  0x021EF6A8  thumb  ov093
 *   BTL_MSG_BuildTrainerString  0x021EF6E8  thumb  ov093
 *   BTL_MSG_BuildItemUse  0x021EF5E8  thumb  ov093
 *   BTL_MSG_BuildPlainEntry  0x021EF664  thumb  ov093
 *   STRBUF_Copy  0x02045838  arm
 *   func_0202A298  0x0202A298  thumb
 *   func_0202A310  0x0202A310  thumb
 *   func_021ECF50   0x021ECF50  thumb  ov093
 *   func_021ECEB8  0x021ECEB8  thumb  ov093
 *   func_021ECE60   0x021ECE60  thumb  ov093
 *   func_021EDA5C   0x021EDA5C  thumb  ov093
 *   func_021EDA94   0x021EDA94  thumb  ov093
 *   func_021EDAB0   0x021EDAB0  thumb  ov093
 *   func_021EDAE0   0x021EDAE0  thumb  ov093
 *   func_021EDB00   0x021EDB00  thumb  ov093
 *   func_021EDB20   0x021EDB20  thumb  ov093
 *   func_021F8A40  0x021F8A40  thumb  ov094
 *   BTLV_SCU_PrintWaitMessage  0x021EE200  thumb  ov093
 *   BTLV_SCU_UpdateWaitMessage   0x021EE21C  thumb  ov093
 *   func_021F8A78  0x021F8A78  thumb  ov094
 *   BTLV_SCU_NoOp  0x021EE224  thumb  ov093
 *   func_021ED56C   0x021ED56C  thumb  ov093
 *   func_021ED57C   0x021ED57C  thumb  ov093
 *   func_021ED590   0x021ED590  thumb  ov093
 *   func_021ED5D8   0x021ED5D8  thumb  ov093
 *   func_021ED6BC  0x021ED6BC  thumb  ov093
 *   func_021ED714   0x021ED714  thumb  ov093
 *   func_021ED660  0x021ED660  thumb  ov093
 *   func_021ED8AC   0x021ED8AC  thumb  ov093
 *   func_021ED8D8   0x021ED8D8  thumb  ov093
 *   BTL_MAIN_GetClientTrainerIndex  0x021B8BEC  thumb  ov093
 *   func_021F84B4  0x021F84B4  thumb  ov094
 *   func_021ED4E4  0x021ED4E4  thumb  ov093
 *   func_021ED510  0x021ED510  thumb  ov093
 *   BTL_SIDE_GetSlotOfClientThunk  0x021B9AF8  thumb  ov093
 */
#include "../../matched/include/Obj12164.h"
#include "../../matched/include/Obj18477.h"
#include "../../matched/include/Obj04374.h"
#include "../../matched/include/Obj07842.h"
#include "../../matched/include/Obj10108.h"
#include "../../matched/include/Obj10109.h"
#include "../../matched/include/Obj07843.h"
#include "../../matched/include/Obj10111.h"
#include "../../matched/include/Obj13556.h"
#include "../../matched/include/Obj06283.h"
#include "../../matched/include/Obj13557.h"
#include "../../matched/include/Obj04377.h"
#include "../../matched/include/Obj07844.h"
#include "../../matched/include/Obj13558.h"
#include "../../matched/include/Obj21561.h"
#include "../../matched/include/Obj13559.h"
#include "../../matched/include/Obj13560.h"
#include "../../matched/include/Obj10113.h"
#include "../../matched/include/Obj21562.h"
#include "../../matched/include/Obj21563.h"
#include "../../matched/include/Obj01899.h"
#include "../../matched/include/Obj13561.h"
#include "../../matched/include/Obj07846.h"
#include "../../matched/include/Obj21566.h"
#include "../../matched/include/Obj21567.h"
#include "../../matched/include/Obj13562.h"
#include "../../matched/include/Obj13563.h"
#include "../../matched/include/Obj13564.h"
#include "../../matched/include/Obj10115.h"

struct MyItemSave;
struct T;
struct U16Vec;
struct H_021EA01C;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

/* 021EA044  movs r1,#0x4b; lsls r1,#2; ldrb r0,[r0,r1] */
struct QV { u8 pad[0x12c]; u8 v; };

typedef struct { u32 f0; u8 pad[60]; } E64;

struct S_021EA0F4 {
    u8 pad00[0x1c];
    u32 f1c;
    u32 f20;
    void *f24;
    int f28;
};

struct S_021EA120 {
    u8 pad00[0x1c];
    int (*f1c)(void *, void *);
    int (*f20)(void *, void *);
    void *f24;
    int f28;
};

struct S_021EA1B8 {
    u8 pad00[4];
    u8 *f04;
    u8 pad08[0x1c - 8];
    u32 f1c;
    u32 f20;
    void *f24;
    int f28;
};

struct S_021EA1F0 {
    u8 pad00[0x1c];
    int (*f1c)(void *, void *);
    int (*f20)(void *, void *);
    void *f24;
    int f28;
};

struct S_021EA488 {
    u8 pad00[8];
    char *const *f08;
    u8 pad0c[0x1c - 0xc];
    u32 f1c;
    u32 f20;
    void *f24;
    int f28;
};

struct S_021EA4C4 {
    u8 pad00[0x1c];
    int (*f1c)(void *, void *);
    int (*f20)(void *, void *);
    void *f24;
    int f28;
};

struct H_021EA01C {
    u16 h0;
    u8 b2;
    u8 op : 4;
    u8 hi : 4;
    int f4;
    int f8;
};

struct H_021EA614 {
    u8 b0[2];
    u8 b2;
};

typedef struct {
    u32 pad[7];
    int (*cb1)(void *, u32);   /* 0x1c */
    int (*cb2)(void *, u32);   /* 0x20 */
    u32 arg;                   /* 0x24 */
    u32 obj;                   /* 0x28 */
} CbSlot;

extern void MYITEM_SAVEDATA_SetBattlePocketCursors(struct MyItemSave *p, const s16 *a, const s16 *b);
extern void MYITEM_SAVEDATA_SetLastBattleItem(struct MyItemSave *p, u16 a, u16 b);
extern u8 BTL_MAIN_GetViewPosOfSlot(u8 *p, u32 k);
extern void func_021ED118(u8 *p, int a, int b, u32 c, u32 d, int e, u8 f);
extern u8 *func_021E9100(u8 *p, int n);
extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern void func_021ED208(char *p, u8 k, u16 a, int flag);
extern int func_021ED250(char *p);
extern void func_021ED268(u8 *p, u8 k, u32 x);
extern int func_021ED280(char *p);
extern int BTL_MAIN_GetTrainerSlotOfPoke(void *p, void *a, u32 b);
extern int func_021ECF68(struct T *p);
extern void func_021EAF00(u8 *p, int a);
extern int func_021F7F1C(int i);
extern int func_021F853C(int i);
extern void func_021F7E74(u32 a);
extern void func_021F7E84(u32 a);
extern void func_021ED494(char *p, int a, u32 b);
extern void func_021F7A28(int a, u32 b);
extern int func_021F7EB4(void);
extern void func_021F7AAC(int a, int b, u32 c);
extern void func_021ED294(u8 *p, int k, u32 x);
extern void func_021ED318(char *p, u16 k, u16 a, int flag);
extern u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void func_021ED3D4(char *p, u8 k, int a, u8 b, int flag);
extern int func_021ED450(u8 *p);
extern void BTL_MSG_FormatWithSide(u32 a, u16 k, u32 *p);
extern void BTL_MSG_DispatchTagged(u32 a, u16 b, u32 c);
extern void BTL_MSG_GetUiString(u32 a, u32 b);
extern void BTL_MSG_BuildUiString(u32 a, u32 b, u32 c);
extern void BTL_MSG_BuildTrainerString(u32 a, u32 b, u32 c);
extern void BTL_MSG_BuildItemUse(u32 a, u8 b, u16 c);
extern void BTL_MSG_BuildPlainEntry(int a, u16 b, int c);
void STRBUF_Copy(struct U16Vec *dst, struct U16Vec *src);
extern u32 func_0202A298(u32 key, u32 want, u32 heap);
extern void func_0202A310(int key, int want, void *dest, u32 heap);
extern void func_021ECEB8(u8 *a, u32 b, u16 s, u32 c);
extern void func_021F8A40(int a);
extern void BTLV_SCU_PrintWaitMessage(u8 *p);
extern int BTLV_SCU_UpdateWaitMessage(u8 *p);
extern void func_021F8A78(void);
extern void BTLV_SCU_NoOp(char *p);
extern void func_021ED56C(int a, int b);
extern int func_021ED57C(int a, int b);
extern void func_021ED6BC(char *p, u32 k, u32 a);
extern void func_021ED660(char *p, u32 k, u32 a, u32 b);
extern u8 BTL_MAIN_GetClientTrainerIndex(u8 *p, u32 k, u8 n);
extern void func_021F84B4(u32 a, u32 b);
extern void func_021ED4E4(u8 *p, int a, int b);
extern int func_021ED510(u8 *p, int a, int b);
extern char *BTL_SIDE_GetSlotOfClientThunk(char *p, int i);
extern void func_0689B514(void *a, u8 *t);
u16 func_021EA01C(u8 *p);
u8 func_021EA030(u8 *p);
u8 func_021EA044(struct QV *p);
u8 func_021EA04C(u8 *p);
void func_021EA058(char *p);
void func_021EA0A0(u32 *p, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u8 s7);
int func_021EA0E4(u32 *p);
void func_021EA0F4(struct S_021EA0F4 *s, u32 a, u32 b, u32 c);
int func_021EA120(struct S_021EA120 *s);
int func_021EA160(int *st, char *ctx);
void func_021EA1B8(struct S_021EA1B8 *s, u32 a, int b, int c);
int func_021EA1F0(struct S_021EA1F0 *s);
int func_021EA230(int *st, char *ctx);
void func_021EA280(char *ctx, u32 n, int b, const u8 *c, u16 e);
int func_021EA2BC(char *ctx);
void func_021EA32C(u8 *p, int k);
void func_021EA354(void *ctx, int a, int b);
void func_021EA384(char *ctx, int a);
int func_021EA3A0(u32 *p);
void func_021EA3B8(char *ctx, int a, int b);
int func_021EA3D4(void);
void func_021EA3E8(void *ctx, int a, int b, u32 c);
int func_021EA3F8(int a);
void func_021EA40C(char *ctx, int a);
int func_021EA428(u32 *p);
void func_021EA438(u32 *p, u32 a2);
int func_021EA448(u32 *p);
void func_021EA458(char *ctx, u16 a, u16 b);
int func_021EA478(u32 *p);
void func_021EA488(struct S_021EA488 *s, u8 a, u8 b, u8 c);
int func_021EA4C4(struct S_021EA4C4 *s);
int func_021EA504(int *st, char *ctx);
void func_021EA55C(struct H_021EA01C *p, int a);
void func_021EA5E4(unsigned char *p, void *src);
void func_021EA5F0(char *p, struct H_021EA01C *h);
void func_021EA600(char *p);
void func_021EA614(char *p, struct H_021EA614 *h);
void func_021EA638(char *p, struct H_021EA614 *h, int c);
void func_021EA65C(char *p, struct H_021EA614 *h);
void func_021EA678(char *p, u16 k, int *c);
void func_021EA694(char *p, u16 k, int *c);
int func_021EA6B0(char *p, u16 a, u16 b);
void func_021EA6F4(void *p, u8 b, u16 c);
int func_021EA710(u32 *p);
int func_021EA720(u32 *p);
void func_021EA730(char *p, u32 a, u16 b, u32 c);
void func_021EA758(u32 *p, u32 a2);
void func_021EA768(u32 *p, u32 a2, u32 a3);
int func_021EA778(u32 *p, u32 a2);
void func_021EA788(u32 *p, u32 a2);
int func_021EA798(u32 *p, u32 a2);
void func_021EA7A8(u32 *p, u32 a2);
int func_021EA7B8(u32 *p, u32 a2);
void func_021EA7C8(void *ctx, int a);
void func_021EA7D8(void *ctx, int a);
int func_021EA7E8(void *w, int v);
void func_021EA7FC(char *p);
int func_021EA814(u32 *p);
void func_021EA824(char *p);
void func_021EA838(u32 *p, u32 k);
int func_021EA850(u32 *p, u32 k);
void func_021EA868(u32 *p, u32 a2, u32 a3);
int func_021EA878(u32 *p);
void func_021EA888(char *ctx, int a);
int func_021EA8A4(u32 *p);
void func_021EA8B4(char *ctx, u32 a, u32 b);
int func_021EA8D4(u32 *p);
void func_021EA8E4(u32 *p);
int func_021EA8F4(u32 *p);
void func_021EA904(u32 *p, u32 a, u32 b, u32 c, u8 d, u8 e);
int func_021EA950(CbSlot *s);
int func_021EA990(int *st, u8 *b);
void func_021EAA00(u8 *p, u8 v);


/* 021EA01C  if (p[0xe1]) return *(u16 *)(p + 0xde); return 0; */
/*
 * Leaf with no calls and no pool; 10 instructions, 20 bytes: adds r1, r0, #0; adds r1, #0xe1; ldrb r1, [r1]; cmp r1, #0; beq loc_021EA02C; adds r0, #0xde; ldrh r0, [r0]; bx lr; movs r0, #0; bx lr.
 */
u16 func_021EA01C(u8 *p)
{
    if (p[0xe1] != 0)
        return ((struct Obj12164 *)p)->fDE;
    return 0;
}


/* 021EA030  if (p[0xe1]) return p[0xe0]; return 0; */
/*
 * Leaf with no calls and no pool; 10 instructions, 20 bytes: adds r1, r0, #0; adds r1, #0xe1; ldrb r1, [r1]; cmp r1, #0; beq loc_021EA040; adds r0, #0xe0; ldrb r0, [r0]; bx lr; movs r0, #0; bx lr.
 */
u8 func_021EA030(u8 *p)
{
    if (p[0xe1] != 0)
        return p[0xe0];
    return 0;
}


/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0x4b; lsls r1, r1, #2; ldrb r0, [r0, r1]; bx lr.
 */
u8 func_021EA044(struct QV *p) { return p->v; }


/*
 * ldrb at #0x157 (pool constant)
 */
u8 func_021EA04C(u8 *p)
{
    return ((struct Obj18477 *)p)->f157;
}


void func_021EA058(char *p)
{
    if (((struct Obj04374 *)p)->fDE != 0 && ((struct Obj04374 *)p)->f12C != 6 && ((struct Obj04374 *)p)->fD0 != 1) {
        MYITEM_SAVEDATA_SetBattlePocketCursors(((struct Obj04374 *)p)->fE4, (s16 *)(p + 0xf8), (s16 *)(p + 0x100));
        MYITEM_SAVEDATA_SetLastBattleItem(((struct Obj04374 *)p)->fE4, ((struct Obj04374 *)p)->fDE, ((struct Obj04374 *)p)->fF2);
    }
}


void func_021EA0A0(u32 *p, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u8 s7)
{
    u32 r7;
    u32 r2;

    r7 = BTL_MAIN_GetViewPosOfSlot((u8 *)p[0], a1);
    if (a2 != 6) {
        r2 = BTL_MAIN_GetViewPosOfSlot((u8 *)p[0], a2);
    } else {
        r2 = 0xff;
    }
    func_021ED118((u8 *)p[0x5f], r7, r2, a3, s5, s6, s7);
}


/*
 * Indexed-dispatch thunk (o18's 23-member shape): the member's whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base; only the scratch register, the index constant and the tail target differ. Tail call T(p[i]) with the index materialised as a scaled immediate.
 */
int func_021EA0E4(u32 *p) { return func_021ED1B0(p[0x5f]); }


void func_021EA0F4(struct S_021EA0F4 *s, u32 a, u32 b, u32 c)
{
    u8 *t;

    t = func_021E9100((u8 *)s, 0xc);
    ((struct Obj07842 *)t)->f4 = c;
    t[0xa] = b;
    ((struct Obj07842 *)t)->f8 = 0;
    ((struct Obj07842 *)t)->f0 = a;
    s->f1c = 0;
    s->f20 = (u32)func_021EA160;
    s->f24 = s;
    s->f28 = 0;
}


int func_021EA120(struct S_021EA120 *s)
{
    if (s->f1c != 0) {
        if (s->f1c((char *)s + 0x28, s->f24) != 0) {
            s->f1c = 0;
            s->f28 = 0;
        }
        return 0;
    }
    if (s->f20 != 0) {
        if (s->f20((char *)s + 0x28, s->f24) != 0) {
            s->f20 = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}


int func_021EA160(int *st, char *ctx)
{
    u8 *t;

    t = func_021E9100((u8 *)ctx, 0xc);
    switch (*st) {
    case 0:
        func_021ED208(*(char * *)&((struct Obj10108 *)ctx)->f17C, t[0xa], ((struct Obj10109 *)t)->f0, BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj10108 *)ctx)->f4));
        func_021EA32C((u8 *)ctx, ((struct Obj10109 *)t)->f4);
        *st = *st + 1;
        break;
    case 1:
        if (func_021ED250(*(char * *)&((struct Obj10108 *)ctx)->f17C) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}


void func_021EA1B8(struct S_021EA1B8 *s, u32 a, int b, int c)
{
    u8 *t;

    if (BTL_CLIENT_IsMainStepActive(s->f04) == 0) {
        t = func_021E9100((u8 *)s, 0xc);
        ((struct Obj07843 *)t)->f4 = c;
        t[0xa] = b;
        ((struct Obj07843 *)t)->f8 = 0;
        ((struct Obj07843 *)t)->f0 = a;
        s->f1c = 0;
        s->f20 = (u32)func_021EA230;
        s->f24 = s;
        s->f28 = 0;
    }
}


int func_021EA1F0(struct S_021EA1F0 *s)
{
    if (s->f1c != 0) {
        if (s->f1c((char *)s + 0x28, s->f24) != 0) {
            s->f1c = 0;
            s->f28 = 0;
        }
        return 0;
    }
    if (s->f20 != 0) {
        if (s->f20((char *)s + 0x28, s->f24) != 0) {
            s->f20 = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}


int func_021EA230(int *st, char *ctx)
{
    u8 *t;

    t = func_021E9100((u8 *)ctx, 0xc);
    switch (*st) {
    case 0:
        func_021ED268((u8 *)(*(char * *)&((struct Obj13556 *)ctx)->f17C), t[0xa], ((struct Obj10111 *)t)->f0);
        func_021EA32C((u8 *)ctx, ((struct Obj10111 *)t)->f4);
        *st = *st + 1;
        break;
    case 1:
        if (func_021ED280(*(char * *)&((struct Obj13556 *)ctx)->f17C) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}


void func_021EA280(char *ctx, u32 n, int b, const u8 *c, u16 e)
{
    u8 *t;
    u32 i;

    t = func_021E9100((u8 *)ctx, 0x14);
    ((struct Obj06283 *)t)->fC = b;
    t[6] = n;
    ((struct Obj06283 *)t)->f10 = e;
    ((struct Obj06283 *)t)->f8 = 0;
    for (i = 0; i < n; i++) {
        t[i] = BTL_MAIN_GetTrainerSlotOfPoke(((struct Obj13557 *)ctx)->f0, ((struct Obj13557 *)ctx)->f8, c[i]);
    }
}


int func_021EA2BC(char *ctx)
{
    u8 *t;
    u32 f;
    u32 i;

    t = func_021E9100((u8 *)ctx, 0x14);
    switch (((struct Obj04377 *)t)->f8) {
    case 0:
        f = BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj07844 *)ctx)->f4);
        for (i = 0; i < t[6]; i++) {
            func_021ED208(*(char * *)&((struct Obj07844 *)ctx)->f17C, t[i], ((struct Obj04377 *)t)->f10, f);
        }
        func_021EA32C((u8 *)ctx, ((struct Obj04377 *)t)->fC);
        ((struct Obj04377 *)t)->f8 = ((struct Obj04377 *)t)->f8 + 1;
        break;
    case 1:
        if (func_021ED250(*(char * *)&((struct Obj07844 *)ctx)->f17C) != 0) {
            if (func_021ECF68((struct T *)(*(char * *)&((struct Obj07844 *)ctx)->f17C)) != 0) {
                return 1;
            }
        }
        break;
    }
    return 0;
}


void func_021EA32C(u8 *p, int k)
{
    int v;

    switch (k) {
    case 2:
        v = 0x563;
        break;
    case 3:
        v = 0x565;
        break;
    default:
        v = 0x564;
        break;
    }
    func_021EAF00(p, v);
}


/*
 * note:     2026-10-03: byte-correct. The three callees are unlabelled Thumb tail-call stubs in
 *           ov094 (ov093 window does not hold them; the ov094 hint is right). Witnesses filed
 *           EXACT: src/matched/ov/ov094_func_021F853C.c, ov094_func_021F7E74.c,
 *           ov094_func_021F7E84.c. Once the integrator creates their shards, the `matched`
 *           class resolves the three sites through the ov094 hint; re-verify and file EXACT.
 */
void func_021EA354(void *ctx, int a, int b)
{
    if (func_021F7F1C(a) != 0) {
        if (b != func_021F853C(a)) {
            if (b == 1) {
                func_021F7E74(a);
            } else {
                func_021F7E84(a);
            }
        }
    }
}


void func_021EA384(char *ctx, int a)
{
    func_021ED494(*(char * *)&((struct Obj13558 *)ctx)->f17C, a, BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj13558 *)ctx)->f4));
}


/*
 * Wrapper family member; the body is the hand-checked shape of the family's first instance with only the member's constants substituted, per the family uniformity assertion in o36/report.md.
 */
int func_021EA3A0(u32 *p) { return func_021ED4D0(p[0x5f]) != 0; }


void func_021EA3B8(char *ctx, int a, int b)
{
    if (BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj21561 *)ctx)->f4) == 0) {
        func_021F7A28(a, b);
    }
}


int func_021EA3D4(void)
{
    if (func_021F7EB4() == 0) {
        return 1;
    }
    return 0;
}


void func_021EA3E8(void *ctx, int a, int b, u32 c)
{
    func_021F7AAC(a, b, c);
}


int func_021EA3F8(int a)
{
    if (func_021F7EB4() == 0) {
        return 1;
    }
    return 0;
}


void func_021EA40C(char *ctx, int a)
{
    func_021ED294((u8 *)(*(char * *)&((struct Obj13559 *)ctx)->f17C), a, BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj13559 *)ctx)->f4));
}


int func_021EA428(u32 *p) { return func_021ED2BC(p[0x5f]); }


void func_021EA438(u32 *p, u32 a2) { func_021ED2D0(p[0x5f], a2); }


int func_021EA448(u32 *p) { return func_021ED304(p[0x5f]); }


void func_021EA458(char *ctx, u16 a, u16 b)
{
    func_021ED318(*(char * *)&((struct Obj13560 *)ctx)->f17C, a, b, BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj13560 *)ctx)->f4));
}


/*
 * Indexed-dispatch thunk (o18's 23-member shape): the whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base, and one argument means the index temp is r1.  Tail call T(p[0x5f]).  The pool word names a mid-stream entry point that no listing labels, so the site caps at MATCH until the TARGET is filed; func_021ED374 is an EXACT entry in this shard, which the `matched` class accepts as the witness (brief rule 10), and the call site then attests with no change of its own.
 */
int func_021EA478(u32 *p) { return func_021ED374(p[0x5f]); }


void func_021EA488(struct S_021EA488 *s, u8 a, u8 b, u8 c)
{
    u8 *t;
    u8 *o;

    t = func_021E9100((u8 *)s, 4);
    o = BTL_SIDE_GetPokeAtPos(s->f08, a);
    t[1] = b;
    t[2] = c;
    t[0] = a;
    t[3] = BTL_POKEPARAM_GetPokeId(o);
    s->f1c = 0;
    s->f20 = (u32)func_021EA504;
    s->f24 = s;
    s->f28 = 0;
}


int func_021EA4C4(struct S_021EA4C4 *s)
{
    if (s->f1c != 0) {
        if (s->f1c((char *)s + 0x28, s->f24) != 0) {
            s->f1c = 0;
            s->f28 = 0;
        }
        return 0;
    }
    if (s->f20 != 0) {
        if (s->f20((char *)s + 0x28, s->f24) != 0) {
            s->f20 = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}


int func_021EA504(int *st, char *ctx)
{
    u8 *t;

    t = func_021E9100((u8 *)ctx, 4);
    switch (*st) {
    case 0:
        func_021ED3D4(*(char * *)&((struct Obj10113 *)ctx)->f17C, t[0], t[1], t[2], BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj10113 *)ctx)->f4));
        *st = *st + 1;
        break;
    case 1:
        if (func_021ED450((u8 *)(*(char * *)&((struct Obj10113 *)ctx)->f17C)) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}


void func_021EA55C(struct H_021EA01C *p, int a)
{
    switch (p->op) {
    case 1:
        BTL_MSG_FormatWithSide(a, p->h0, (u32 *)(&p->f4));
        break;
    case 2:
        BTL_MSG_DispatchTagged(a, p->h0, (u32)(&p->f4));
        break;
    case 3:
        BTL_MSG_GetUiString(a, p->h0);
        break;
    case 5:
        BTL_MSG_BuildUiString(a, p->h0, (u32)(&p->f4));
        break;
    case 6:
        BTL_MSG_BuildTrainerString(a, p->h0, (u32)(&p->f4));
        break;
    case 4:
        BTL_MSG_BuildItemUse(a, p->f4, p->f8);
        break;
    case 7:
        BTL_MSG_BuildPlainEntry(a, p->f4, p->f8);
        break;
    }
}


void func_021EA5E4(unsigned char *p, void *src)
{
    STRBUF_Copy(((struct Obj21562 *)p)->fAC, src);
}


void func_021EA5F0(char *p, struct H_021EA01C *h)
{
    func_021EA55C((struct H_021EA01C *)h, ((struct Obj21563 *)p)->fAC);
}


void func_021EA600(char *p)
{
    func_021EA730(p, ((struct Obj01899 *)p)->fAC, 0x50, 0);
}


void func_021EA614(char *p, struct H_021EA614 *h)
{
    func_021EA55C((struct H_021EA01C *)h, ((struct Obj01899 *)p)->fAC);
    func_021EA730(p, ((struct Obj01899 *)p)->fAC, h->b2, 0);
}


void func_021EA638(char *p, struct H_021EA614 *h, int c)
{
    func_021EA55C((struct H_021EA01C *)h, ((struct Obj01899 *)p)->fAC);
    func_021EA730(p, ((struct Obj01899 *)p)->fAC, h->b2, c);
}


void func_021EA65C(char *p, struct H_021EA614 *h)
{
    func_021EA55C((struct H_021EA01C *)h, *(int *)&((struct Obj13561 *)p)->fAC);
    func_021EA758((u32 *)p, ((struct Obj13561 *)p)->fAC);
}


void func_021EA678(char *p, u16 k, int *c)
{
    BTL_MSG_FormatWithSide(((struct Obj01899 *)p)->fAC, k, (unsigned int *)c);
    func_021EA730(p, ((struct Obj01899 *)p)->fAC, 0x50, 0);
}


void func_021EA694(char *p, u16 k, int *c)
{
    BTL_MSG_DispatchTagged(((struct Obj01899 *)p)->fAC, k, (unsigned int)c);
    func_021EA730(p, ((struct Obj01899 *)p)->fAC, 0x50, 0);
}


int func_021EA6B0(char *p, u16 a, u16 b)
{
    if (func_0202A298(a, b, ((struct Obj07846 *)p)->f184) != 0) {
        func_0202A310(a, b, ((struct Obj07846 *)p)->fAC, ((struct Obj07846 *)p)->f184);
        func_021EA730(p, *(int *)&((struct Obj07846 *)p)->fAC, 0x50, 0);
    } else {
        return 0;
    }
    return 1;
}


void func_021EA6F4(void *p, u8 b, u16 c)
{
    BTL_MSG_BuildItemUse(*(u32 *)&((struct Obj01899 *)p)->fAC, b, c);
    func_021EA730(p, ((struct Obj01899 *)p)->fAC, 0x50, 0);
}


int func_021EA710(u32 *p) { return func_021ECF68((struct T *)p[0x5f]); }


/*
 * Indexed-dispatch thunk (o18's 23-member shape): the whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base, and one argument means the index temp is r1.  Tail call T(p[0x5f]).  The pool word names a mid-stream entry point that no listing labels, so the site caps at MATCH until the TARGET is filed; func_021ECF50 is an EXACT entry in this shard, which the `matched` class accepts as the witness (brief rule 10), and the call site then attests with no change of its own.
 */
int func_021EA720(u32 *p) { return func_021ECF50(p[0x5f]); }


void func_021EA730(char *p, u32 a, u16 b, u32 c)
{
    if (BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj01899 *)p)->f4) == 0) {
        func_021ECEB8(*(u8 * *)&((struct Obj01899 *)p)->f17C, a, b, c);
    }
}


void func_021EA758(u32 *p, u32 a2) { func_021ECE60(p[0x5f], a2); }


void func_021EA768(u32 *p, u32 a2, u32 a3) { func_021EDA5C(p[0x5f], a2, a3); }


int func_021EA778(u32 *p, u32 a2) { return func_021EDA94(p[0x5f], a2); }


void func_021EA788(u32 *p, u32 a2) { func_021EDAB0(p[0x5f], a2); }


int func_021EA798(u32 *p, u32 a2) { return func_021EDAE0(p[0x5f], a2); }


void func_021EA7A8(u32 *p, u32 a2) { func_021EDB00(p[0x5f], a2); }


int func_021EA7B8(u32 *p, u32 a2) { return func_021EDB20(p[0x5f], a2); }


void func_021EA7C8(void *ctx, int a)
{
    func_021F7A28(a, 0x262);
}


void func_021EA7D8(void *ctx, int a)
{
    func_021F7A28(a, 0x261);
}


int func_021EA7E8(void *w, int v)
{
    if (func_021F7EB4() == 0) {
        return 1;
    }
    return 0;
}


void func_021EA7FC(char *p)
{
    func_021F8A40(3);
    BTLV_SCU_PrintWaitMessage((u8 *)(*(char * *)&((struct Obj21566 *)p)->f17C));
}


/*
 * Indexed-dispatch thunk (o18's 23-member shape): the whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base, and one argument means the index temp is r1.  Tail call T(p[0x5f]).  The pool word names a mid-stream entry point that no listing labels, so the site caps at MATCH until the TARGET is filed; BTLV_SCU_UpdateWaitMessage is an EXACT entry in this shard, which the `matched` class accepts as the witness (brief rule 10), and the call site then attests with no change of its own.
 */
int func_021EA814(u32 *p) { return BTLV_SCU_UpdateWaitMessage((u8 *)p[0x5f]); }


void func_021EA824(char *p)
{
    func_021F8A78();
    BTLV_SCU_NoOp(*(char * *)&((struct Obj21567 *)p)->f17C);
}


void func_021EA838(u32 *p, u32 k) { func_021ED56C(p[0x5f], BTL_MAIN_GetViewPosOfSlot((u8 *)p[0], k)); }


int func_021EA850(u32 *p, u32 k) { return func_021ED57C(p[0x5f], BTL_MAIN_GetViewPosOfSlot((u8 *)p[0], k)); }


void func_021EA868(u32 *p, u32 a2, u32 a3) { func_021ED590(p[0x5f], a2, a3); }


int func_021EA878(u32 *p) { return func_021ED5D8(p[0x5f]); }


void func_021EA888(char *ctx, int a)
{
    func_021ED6BC(*(char * *)&((struct Obj13562 *)ctx)->f17C, a, BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj13562 *)ctx)->f4));
}


/*
 * Indexed-dispatch thunk (o18's 23-member shape): the whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base, and one argument means the index temp is r1.  Tail call T(p[0x5f]).  The pool word names a mid-stream entry point that no listing labels, so the site caps at MATCH until the TARGET is filed; func_021ED714 is an EXACT entry in this shard, which the `matched` class accepts as the witness (brief rule 10), and the call site then attests with no change of its own.
 */
int func_021EA8A4(u32 *p) { return func_021ED714(p[0x5f]); }


void func_021EA8B4(char *ctx, u32 a, u32 b)
{
    func_021ED660(*(char * *)&((struct Obj13563 *)ctx)->f17C, a, b, BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj13563 *)ctx)->f4));
}


int func_021EA8D4(u32 *p) { return func_021ED714(p[0x5f]); }


void func_021EA8E4(u32 *p) { func_021ED8AC(p[0x5f]); }


/*
 * Indexed-dispatch thunk (o18's 23-member shape): the whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base, and one argument means the index temp is r1.  Tail call T(p[0x5f]).  The pool word names a mid-stream entry point that no listing labels, so the site caps at MATCH until the TARGET is filed; func_021ED8D8 is an EXACT entry in this shard, which the `matched` class accepts as the witness (brief rule 10), and the call site then attests with no change of its own.
 */
int func_021EA8F4(u32 *p) { return func_021ED8D8(p[0x5f]); }


void func_021EA904(u32 *p, u32 a, u32 b, u32 c, u8 d, u8 e)
{
    u8 *t;

    t = func_021E9100((u8 *)p, 7);
    t[0] = a;
    t[1] = b;
    t[2] = c;
    t[3] = d;
    t[4] = e;
    t[5] = BTL_MAIN_GetClientTrainerIndex((u8 *)p[0], a, d);
    t[6] = BTL_MAIN_GetClientTrainerIndex((u8 *)p[0], a, e);
    p[7] = 0;
    p[8] = (u32)func_021EA990;
    p[9] = (u32)p;
    p[10] = 0;
}


int func_021EA950(CbSlot *s)
{
    if (s->cb1 != 0) {
        if (s->cb1(&s->obj, s->arg) != 0) {
            s->cb1 = 0;
            s->obj = 0;
        }
        return 0;
    }
    if (s->cb2 != 0) {
        if (s->cb2(&s->obj, s->arg) != 0) {
            s->cb2 = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}


int func_021EA990(int *st, u8 *b)
{
    u8 *t = func_021E9100(b, 7);

    switch (*st) {
    case 0:
        func_021F84B4(t[1], t[2]);
        func_021EAF00(b, 0x57b);
        *st = *st + 1;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021ED4E4((u8 *)(((struct Obj13564 *)b)->f17C), t[5], t[6]);
            *st = *st + 1;
        }
        break;
    case 2:
        if (func_021ED510((u8 *)(((struct Obj13564 *)b)->f17C), t[5], t[6]) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}


void func_021EAA00(u8 *p, u8 v)
{
    u8 *t;

    t = func_021E9100(p, 0x3c);
    BTL_SIDE_GetSlotOfClientThunk(*(char * *)&((struct Obj10115 *)p)->f8, p[0xc]);
    func_0689B514(((struct Obj10115 *)p)->f180, t);
}
