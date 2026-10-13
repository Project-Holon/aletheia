/*
 * file:     btlv_finger_cursor.c
 * unit:     yes
 * function: func_02209A7C, func_02209B30, func_02209B60, func_02209C18, func_02209C2C, func_02209C30
 * address:  0x02209A7C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_0220AEFC     0x0220AEFC  data  ov094
 *   func_020490F4  0x020490F4  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_GetPaletteVramAddress  0x0204AEF4  arm
 *   PALANM_CopyHwPaletteToSlot  0x020216D4  thumb
 *   CLACT_CreateUnit  0x0204B100  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_021F86D4  0x021F86D4  thumb  ov094
 *   func_02030DA8  0x02030DA8  arm
 *   func_02209CC4  0x02209CC4  thumb  ov094
 *   d_0220AC10     0x0220AC10  data   ov094  a4
 *   CLACT_CreateAffineActor  0x0204B324  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_ApplyActorAnimCommand  0x0204BA00  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 *   CLACT_DeleteUnit  0x0204B1CC  arm  arm9
 *   CLACT_DeleteActor  0x0204B3B4  arm  arm9
 */
#include "../../matched/include/Obj10160.h"

struct PalAnmSlot;
struct Bank;
struct Node;
struct Actor;
struct Cmd;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    int h0;                 /* 0x00 */
    int pad04;
    void *task;             /* 0x08 */
    int h0c;                /* 0x0c */
    int h10;                /* 0x10 */
    int h14;                /* 0x14 */
    char pad18[0x2c - 0x18];
    u16 heap;               /* 0x2c */
} W;

typedef signed int     s32;

typedef struct {
    int h0;
    int f4;
    void *f8;
    int fc;
    int f10;
    int f14;
} P_02209B30;

typedef struct {
    u32 f0;
    void *h;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u16 f2c;
} P_02209B60;

typedef struct {
    u16 x;
    u16 y;
    u32 rest[5];
} Cfg;

typedef struct {
    u16 a;
    u16 b;
    void *p;
    void *cb;
} Msg;

typedef struct {
    char pad[0x28];
    int  val;
} Obj;

typedef struct {
    u32 f0;
    void *h;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    volatile u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    volatile u32 f28;
    u16 f2c;
} P_02209C30;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern int CLACT_GetPaletteVramAddress(u32 idx, u32 alternate);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void ARC_TOOL_DeleteHandle(void * h);
extern void *func_021F86D4(void);
extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 a3);
extern void func_02209CC4(void *a, void *b);
extern void func_02030EAC(struct Node *n);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern u32 func_020307B0(void *p);
extern struct Obj *CLACT_CreateAffineActor(u32 owner, u32 i, u32 j, u32 k, u32 e, u16 f, u16 g);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_ApplyActorAnimCommand(struct Actor *a, const struct Cmd *cmd);
extern void CLACT_DeleteActor(struct Obj *p);
W *func_02209A7C(void *a0, u32 b, u16 heap);
void func_02209B30(P_02209B30 *p);
int func_02209B60(P_02209B60 *p, u16 a, u16 b, u32 c, u32 e, u32 f);
void func_02209C18(char *p);
int func_02209C2C(Obj *o);
void func_02209C30(P_02209C30 *p);
extern char d_0220AEFC[];
extern Cfg d_0220AC10;


W *func_02209A7C(void *a0, u32 b, u16 heap)
{
    W *w;
    void *a;

    w = func_02030734(heap, 0x30, 1, d_0220AEFC, 0x52);
    a = func_020490F4(0xb, (u16)((heap & 0x7fff) | 0x8000));
    w->heap = heap;
    w->h0c = CLACT_RegisterCharacter(a, 0xd9, 0, 1, heap);
    w->h14 = CLACT_RegisterCellAnim(a, 0xdb, 0xdc, heap);
    w->h10 = CLACT_RegisterPaletteEx(a, 0xda, 1, (u16)(b << 5), 0, 1, heap);
    PALANM_CopyHwPaletteToSlot(a0, 3, (u16)(CLACT_GetPaletteVramAddress(w->h10, 1) >> 1), 0x20);
    w->h0 = (int)CLACT_CreateUnit(1, 0, heap);
    ARC_TOOL_DeleteHandle(a);
    w->task = func_02030DA8(func_021F86D4(), func_02209CC4, w, 0);
    return w;
}


void func_02209B30(P_02209B30 *p)
{
    func_02030EAC(p->f8);
    func_02209C18((char *)p);
    CLACT_ReleaseCharacter(p->fc);
    CLACT_ReleaseCellAnim(p->f14);
    CLACT_ReleasePalette(p->f10);
    CLACT_DeleteUnit((struct Bank *)p->h0);
    func_020307B0(p);
}


/*
 * The f24 store is written out in both arms (the cross-jumped-tail idiom):
 * then-arm `str` is cross-jumped onto the else-arm copy, giving beq/b/movs.
 */
int func_02209B60(P_02209B60 *p, u16 a, u16 b, u32 c, u32 e, u32 f)
{
    Cfg cfg = d_0220AC10;
    Msg msg;

    if (p->f28 != 0)
        return 0;
    if (p->h != 0) {
        func_02209C18((char *)p);
        p->h = 0;
    }
    cfg.x = a;
    cfg.y = b;
    p->h = CLACT_CreateAffineActor(p->f0, p->fc, p->f10, p->f14, (u32)(&cfg), 1, p->f2c);
    CLACT_SetActorAnimSeq(p->h, 0);
    CLACT_SetActorAnimFrame(p->h, 0);
    CLACT_SetActorAutoAnim(p->h, 1);
    CLACT_SetActorDrawEnable(p->h, 1);
    if (c != 0)
        p->f1c = c;
    else
        p->f1c = 1;
    if (f != 0)
        p->f24 = f;
    else
        p->f24 = 1;
    p->f18 = 0;
    p->f20 = e;
    p->f28 = 0;
    msg.p = p;
    msg.a = 0;
    msg.b = 0;
    msg.cb = (void *)func_02209C30;
    CLACT_ApplyActorAnimCommand(p->h, (const struct Cmd *)(&msg));
    return 1;
}


void func_02209C18(char *p)
{
    if (((struct Obj10160 *)p)->f4 != 0) {
        CLACT_DeleteActor(((struct Obj10160 *)p)->f4);
        ((struct Obj10160 *)p)->f4 = 0;
    }
}


/*
 * Returns the word at +0x28 of the object passed in r0.  A bare leaf
 * getter with no prologue.
 */
int func_02209C2C(Obj *o)
{
    return o->val;
}


/*
 * f18 and f28 are volatile: the original reloads f18 after each f28
 * store and keeps the store order.
 */
void func_02209C30(P_02209C30 *p)
{
    Msg m0;
    Msg m1;

    switch (p->f18) {
    case 0:
        if (--p->f1c == 0) {
            CLACT_SetActorAnimSeq(p->h, 1);
            p->f18++;
            m0.p = p;
            m0.a = 1;
            m0.b = p->f20;
            m0.cb = (void *)func_02209C30;
            CLACT_ApplyActorAnimCommand(p->h, (const struct Cmd *)(&m0));
            return;
        }
        break;
    case 1:
        p->f28 = 1;
        p->f18++;
        m1.p = p;
        m1.a = 2;
        m1.b = 0;
        m1.cb = (void *)func_02209C30;
        CLACT_ApplyActorAnimCommand(p->h, (const struct Cmd *)(&m1));
        return;
    case 2:
        CLACT_SetActorDrawEnable(p->h, 0);
        p->f28 = 0;
        p->f18++;
        break;
    case 3:
        break;
    }
}
