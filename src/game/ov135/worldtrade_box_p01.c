/*
 * file:     worldtrade_box_p01.c
 * unit:     yes
 * function: func_021F4580, func_021F46A8, func_021F47C0, func_021F4864, func_021F4894, func_021F489C, func_021F49A4, func_021F49A8, func_021F49F8, func_021F4BCC, func_021F4BE0, func_021F4BF8, func_021F4CE4, func_021F4D14
 * address:  0x021F4580
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02202608  0x02202608  thumb
 *   func_022026D8  0x022026D8  thumb
 *   func_021F5074  0x021F5074  thumb
 *   g_02203F80  0x02203F80  data
 *   str_02203AF8  0x02203AF8  data  a1
 *   ov114_id  0x00000072  data
 *   ov067_id  0x00000043  data
 *   func_0203CD98 0x0203CD98 arm
 *   func_0205D074 0x0205D074 arm
 *   func_021F4EB4 0x021F4EB4 thumb ov135
 *   func_020370F4 0x020370F4 arm
 *   func_021C7C1C 0x021C7C1C arm ov114
 *   func_02031330 0x02031330 arm
 *   func_02030D28 0x02030D28 arm
 *   func_02202770 0x02202770 thumb ov135
 *   func_020221A4 0x020221A4 thumb
 *   func_021FF6A4 0x021FF6A4 thumb ov135
 *   func_021FFB20 0x021FFB20 thumb ov135
 *   func_021F4F84 0x021F4F84 thumb ov135
 *   func_0204A600 0x0204A600 arm
 *   d_02203A80 0x02203A80 data a4
 *   func_021F50EC 0x021F50EC thumb ov135
 *   func_02045C04 0x02045C04 arm
 *   func_02030DA4 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0203133C 0x0203133C arm
 *   func_02202744 0x02202744 thumb ov135
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021F4EC0  0x021F4EC0  thumb
 *   str_02203B08  0x02203B08  data  a1
 *   func_020490F4  0x020490F4  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_02049F34  0x02049F34  arm
 *   DC_FlushRange  0x020862F0  arm
 *   GX_LoadOBJPltt 0x0207E51C  arm
 *   func_02008550  0x02008550  thumb
 *   func_0204AC18  0x0204AC18  arm
 *   d_02202BE0     0x02202BE0  data
 *   func_02034714 0x02034714 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02027F60 0x02027F60 thumb
 *   func_02027778 0x02027778 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_021F5008 0x021F5008 thumb ov135
 *   data_02202BC8 0x02202BC8 data a4
 *   func_02027858 0x02027858 thumb
 *   func_02027FD8 0x02027FD8 thumb
 *   func_02027974 0x02027974 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021F5060 0x021F5060 thumb ov135
 */
#include "../../matched/include/Obj02853.h"
#include "../../matched/include/Obj02854.h"
#include "../../matched/include/Obj02489.h"
#include "../../matched/include/Obj00045.h"

#define ASSERT(x) if (!(x)) func_02034714(str_02203B08, 0, str_02203B08)
struct Ctx;
struct MsgBank;
struct WordSet;
struct Obj0203159C;
struct Rec;
struct S020314B8;
struct S020315D4;
struct DispVram;
struct Cfg;
struct Sub0200852CObj;
struct Bank;
struct R;
struct U16Vec;
struct TaskMenu;
struct TaskMenuTmpl;
struct TaskMenuState;
typedef signed char s8;

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef struct {
    u8 pad0[0x20];
    u32 x20;
} Args_021F4580;

typedef struct {
    u8 pad0[0xB68];
    void *words;
    void *msg[5];
    u8 padB80[0xEA8 - 0xB80];
    void *mon;
    u8 padEAC[0xF94 - 0xEAC];
    void *rec;
    u8 padF98[0xF9C - 0xF98];
    void *recMem;
    u8 ctx[0x12F0 - 0xFA0];
    void *save;
    u8 pad12F4[0x132C - 0x12F4];
} Work_021F4580;

typedef struct { int (*init)(u8 *, int); int (*update)(u8 *, int); int (*finish)(u8 *, int); } Handler;

typedef void (*Cb)(void *p);

typedef struct {
    u8 pad0[0xEBC];
    Cb once;
    Cb every;
} Work_021F4864;

typedef struct {
    void *a0;
    void *a4;
    void *a8;
    void *aC;
    u8 pad10[4];
    void *a14;
    void *a18;
    void *a1C;
    void *a20;
    void *a24;
    u8 pad28[0x3C - 0x28];
    void *a3C;
} Args_021F4894;

typedef struct {
    Args_021F4894 *args;
    u8 pad4[0x10 - 4];
    u32 x10;
    u8 pad14[0xC0 - 0x14];
    u16 xC0;
    u8 padC2[0xC4 - 0xC2];
    u16 box;
    u8 padC6[0xB56 - 0xC6];
    u16 xB56;
    u8 xB58;
    u8 xB59;
    u8 xB5A;
    u8 padB5B;
    u16 xB5C;
    u8 padB5E[0xDF8 - 0xB5E];
    u32 xDF8;
    u8 padDFC[0xE18 - 0xDFC];
    u16 xE18;
    u16 xE1A;
    u8 padE1C[0xEB0 - 0xE1C];
    u16 xEB0;
    u16 xEB2;
    u8 padEB4[0xF84 - 0xEB4];
    u32 xF84;
} Work;

typedef volatile u32 vu32;

typedef volatile u16 vu16;

typedef struct {
    u8 pad0[0xC];
    u16 *data;
} PlttData;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2C;
    u32 f30;
} Res;

typedef struct {
    u8 pad0[0x1C];
    void *f1C;
} Ctx;

typedef struct {
    Ctx *ctx;
    u8 pad4[0xBC0 - 4];
    Res res;
} Obj;

typedef void (*Fn)(void);

typedef struct { void *text; u32 b,c; } Item;

typedef struct { Item item[2]; } Items;

typedef struct { u32 heap; u8 count,pad[3]; Item *items; u32 mode; u8 a,b,c,d; } Menu;

extern int func_02034AC4(s32 handle);
extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void *func_02202608(u32 heap);
extern void *func_02031324(int a0);
extern u32 func_02030CB0(u32 n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void func_022026D8(void *ctx, u32 arg);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_0204335C(u32 keep);
extern void func_021F5074(Work_021F4580 *p);
extern void func_02005DE4(void *p);
extern void func_02005D28(void);
extern int func_0203CD98(void);
extern int func_0205D074(void);
extern int func_021F4EB4(void);
extern u32 func_020370F4(u32);
extern void func_021C7C1C(void);
extern u32 func_02031330(void *);
extern void func_02030D28(struct Ctx *c);
extern void func_02202770(void *);
extern u32 func_020221A4(void);
extern void func_021FF6A4(u8 *);
extern void func_021FFB20(u8 *, int, int);
extern void func_021F4F84(u8 *);
extern void func_0204A600(void *);
extern void func_021F50EC(u8 *);
extern unsigned int func_02045C04(struct Rec *rec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern void func_02030DA4(void *);
extern u32 func_020307B0(void *p);
extern void func_0203133C(struct S020314B8 *p);
extern void func_02202744(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_02034A5C(s32 handle);
extern void func_020419E4(void);
extern void func_0204A648(void);
extern void func_020433E0(const struct DispVram *c);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void DC_FlushRange(void *p, u32 size);
extern void GX_LoadOBJPltt(const void *src, u32 offset, u32 size);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void func_020434DC(u32 a, u32 b);
extern void func_02043598(u32 a, u32 b);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern void func_021F5008(u32 x);
extern void func_02027858(struct TaskMenu *m);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_02027974(void *);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *);
extern void func_021F5060(void);
int func_021F4580(void *proc, int *seq, Args_021F4580 *args);
int func_021F46A8(void *unused0, int *state, void *unused2, u8 *p);
int func_021F47C0(void *ctx, int unused1, int unused2, u8 *p);
void func_021F4864(void *unused, Work_021F4864 *p);
void func_021F4894(const struct DispVram *a0);
void func_021F489C(Work *p, Args_021F4894 *args);
void func_021F49A4(void *a0);
void func_021F49A8(void);
void func_021F49F8(Obj *p, u32 mode);
void func_021F4BCC(u8 *p);
void func_021F4BE0(u32 a, u32 b, u32 c, u32 d, u8 e);
void func_021F4BF8(u8 *p,int b,int unused,int a,int c,u8 flag);
void func_021F4CE4(char *p);
int func_021F4D14(char *p);
extern u8 ov114_id[];
extern u8 ov067_id[];
extern Work_021F4580 *g_02203F80;
extern const char str_02203AF8[];
extern const Handler d_02203A80[];
extern const char str_02203B08[];
extern u8 d_02202BE0[];
extern const Items data_02202BC8;




int func_021F4580(void *proc, int *seq, Args_021F4580 *args)
{
    Work_021F4580 *p;

    func_02034AC4((u32)ov114_id);
    func_02034AC4((u32)ov067_id);
    func_0203064C(1, 0x48, 0x30100);
    p = func_0203159C(proc, sizeof(Work_021F4580), 0x48);
    func_02082BCC(p, 0, sizeof(Work_021F4580));
    g_02203F80 = p;
    p->mon = func_02202608(0x48);
    p->save = func_02031324(0x48);
    p->recMem = func_02030734(0x48, func_02030CB0(8), 0, str_02203AF8, 0xA1);
    p->rec = func_02030CBC(8, p->recMem);
    func_022026D8(p->ctx, args->x20);
    p->words = func_0201EC74(0xB, 0x40, 0x48);
    p->msg[0] = func_02045B38(0, 2, 0xD0, 0x48);
    p->msg[2] = func_02045B38(0, 2, 0xD1, 0x48);
    p->msg[3] = func_02045B38(0, 2, 0xE8, 0x48);
    p->msg[1] = func_02045B38(0, 2, 0x46, 0x48);
    p->msg[4] = func_02045B38(0, 2, 0xE7, 0x48);
    func_021F489C((Work *)p, (Args_021F4894 *)args);
    func_0204335C(0);
    func_021F5074(p);
    func_02005DE4(0);
    func_02005D28();
    return 1;
}



int func_021F46A8(void *unused0, int *state, void *unused2, u8 *p)
{
    if (func_0203CD98() != 0) {
        func_0205D074();
        func_020370F4(func_021F4EB4());
    }
    func_021C7C1C();
    ((struct Obj02853 *)p)->f12F4 = func_02031330(((struct Obj02853 *)p)->f12F0);
    func_02030D28(((struct Obj02853 *)p)->fF94);
    func_02202770(p + 0xfa0);
    switch (*state) {
    case 0:
        *state = d_02203A80[*(u32 *)(p + 16)].init(p, *state);
        func_021F49A8();
        break;
    case 1:
        if (func_020221A4() != 0) *state = 2;
        break;
    case 2:
        *state = d_02203A80[*(u32 *)(p + 16)].update(p, *state);
        break;
    case 3:
        if (func_020221A4() != 0) {
            *state = d_02203A80[*(u32 *)(p + 16)].finish(p, *state);
            if (((struct Obj02853 *)p)->fB8 != 0) {
                func_021FF6A4(p);
                func_021FFB20(p, ((struct Obj02853 *)p)->fD0, 0);
                ((struct Obj02853 *)p)->fB8 = 0;
            }
        }
        break;
    case 4:
        *state = 5;
        break;
    case 5:
        return 1;
    }
    func_021F4F84(p);
    if (*(u32 *)&((struct Obj02853 *)p)->fBC0 != 0) func_0204A600(((struct Obj02853 *)p)->fBC0);
    if (((struct Obj02853 *)p)->f12E8 > 0) ((struct Obj02853 *)p)->f12E8 -= 1;
    return 0;
}



int func_021F47C0(void *ctx, int unused1, int unused2, u8 *p)
{
    func_02005D28();
    func_021F50EC(p);
    func_021F49A4(p);
    func_02045C04(((struct Obj02854 *)p)->fB70);
    func_02045C04(((struct Obj02854 *)p)->fB78);
    func_02045C04(((struct Obj02854 *)p)->fB74);
    func_02045C04(((struct Obj02854 *)p)->fB6C);
    func_02045C04(((struct Obj02854 *)p)->fB7C);
    func_0201ED04(((struct Obj02854 *)p)->fB68);
    func_02030DA4(((struct Obj02854 *)p)->fF94);
    func_020307B0(((struct Obj02854 *)p)->fF9C);
    func_0203133C(((struct Obj02854 *)p)->f12F0);
    func_020307B0(((struct Obj02854 *)p)->fEA8);
    func_02202744(p + 0xfa0);
    func_020315D4(ctx);
    func_020306F0(0x48);
    func_02034A5C((unsigned int)ov067_id);
    func_02034A5C((unsigned int)ov114_id);
    return 1;
}




void func_021F4864(void *unused, Work_021F4864 *p)
{
    func_020419E4();
    func_0204A648();
    if (p->once != 0) {
        p->once(p);
        p->once = 0;
    }
    if (p->every != 0) {
        p->every(p);
    }
}




void func_021F4894(const struct DispVram *a0)
{
    func_020433E0(a0);
}




void func_021F489C(Work *p, Args_021F4894 *args)
{
    ASSERT(args->a3C);
    ASSERT(args->a0);
    ASSERT(args->a4);
    ASSERT(args->a8);
    ASSERT(args->aC);
    ASSERT(args->a14);
    ASSERT(args->a18);
    ASSERT(args->a1C);
    ASSERT(args->a20);
    ASSERT(args->a24);
    p->args = args;
    p->x10 = 0;
    func_021F4EC0((u8 *)p, 0, 0x13);
    p->xC0 = 0;
    p->xB56 = 0;
    p->xB58 = 3;
    p->xB59 = 0;
    p->xB5A = 0;
    p->xB5C = 0;
    p->xE18 = 0;
    p->box = 0xFF;
    p->xEB0 = 0;
    p->xEB2 = 0;
    p->xE1A = 0;
    p->xDF8 = 0;
    p->xF84 = 0;
}



/*
 * Empty stub: a bare `bx lr`, the overlay's no-op placeholder body.
 */
void func_021F49A4(void *a0)
{
}




static inline void SetWnd0InsidePlane(int wnd, int effect)
{
    u32 tmp = (*(vu16 *)0x04000048 & ~0x3F) | wnd;

    if (effect) {
        tmp |= 0x20;
    }
    *(vu16 *)0x04000048 = (u16)tmp;
}




static inline void SetWndOutsidePlane(int wnd, int effect)
{
    u32 tmp = (*(vu16 *)0x0400004A & ~0x3F) | wnd;

    if (effect) {
        tmp |= 0x20;
    }
    *(vu16 *)0x0400004A = (u16)tmp;
}




void func_021F49A8(void)
{
    *(vu32 *)0x04001000 &= ~0xE000;
    *(vu32 *)0x04000000 = (*(vu32 *)0x04000000 & ~0xE000) | 0x2000;
    SetWnd0InsidePlane(0x1F, 0);
    SetWndOutsidePlane(0x1F, 1);
    *(vu16 *)0x04000040 = 0xF0FF;
    *(vu16 *)0x04000044 = 0x10;
}




/*
 * Load the screen's OBJ resources: the archive-0x60 cell, character,
 * palette and animation sets into the resource block at +0xBC0, the
 * OBJ palette from archive 7 at 0xA0 and a half-brightness copy of it
 * at 0x100, and from archive 0x1F the version-dependent set (files
 * 0x11/6/0xF/0x10 when func_02008550 reports 1, else 0xE/4/0xC/0xD).
 */
void func_021F49F8(Obj *p, u32 mode)
{
    void *arc;
    void *buf;
    PlttData *pd;
    int i;
    u16 *d;
    u32 anm;
    u32 cell;
    u32 pal;
    u32 chr;

    arc = func_020490F4(0x60, 0x48);
    func_0204A48C((const struct Cfg *)d_02202BE0, mode, 0x48);
    p->res.f0 = (u32)func_0204B100(0x60, 0, 0x48);
    p->res.f4 = func_0204A6C8(arc, 0x11, 1, 0, 0x48);
    p->res.f8 = func_0204ABF0(arc, 8, 0, 0, 0x48);
    p->res.fC = func_0204AF28(arc, 0x12, 0x13, 0x48);
    p->res.f28 = func_0204A6C8(arc, 0x27, 1, 0, 0x48);
    p->res.f30 = func_0204AF28(arc, 0x28, 0x29, 0x48);
    p->res.f10 = func_0204A6C8(arc, 0x24, 1, 1, 0x48);
    p->res.f14 = func_0204ABF0(arc, 7, 1, 0, 0x48);
    p->res.f18 = func_0204AF28(arc, 0x25, 0x26, 0x48);
    func_02049238(arc);

    buf = func_02049F34(7, 0, (u32)(&pd), 0x48);
    DC_FlushRange(pd->data, 0x60);
    GX_LoadOBJPltt(pd->data, 0xA0, 0x60);
    d = pd->data;
    for (i = 0; i < 0x30; i++) {
        u16 c = d[i];
        d[i] = ((((c >> 10) & 0x1f) / 2) << 10) | ((((c >> 5) & 0x1f) / 2) << 5) | ((c & 0x1f) / 2);
    }
    DC_FlushRange(pd->data, 0x60);
    GX_LoadOBJPltt(pd->data, 0x100, 0x60);
    func_020307B0(buf);

    if ((u8)(u32)func_02008550(p->ctx->f1C) == 1) {
        chr = 0x11;
        anm = 0x10;
        cell = 0xF;
        pal = 6;
    } else {
        chr = 0xE;
        anm = 0xD;
        cell = 0xC;
        pal = 4;
    }
    arc = func_020490F4(0x1f, 0x48);
    p->res.f1C = func_0204A6C8(arc, chr, 0, 1, 0x48);
    p->res.f20 = func_0204AC18(arc, pal, 1, 0, 0, 1, 0x48);
    p->res.f24 = func_0204AF28(arc, cell, anm, 0x48);
    func_02049238(arc);
}



/*
 * Release the 0x10 channel on both hardware blocks.
 */
void func_021F4BCC(u8 *p)
{
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}



/*
 * Forward four register arguments plus a zero and the u8 stack argument.
 */
void func_021F4BE0(u32 a, u32 b, u32 c, u32 d, u8 e)
{
    func_021F4BF8((u8 *)a, b, c, d, 0, e);
}


void func_021F4BF8(u8 *p,int b,int unused,int a,int c,u8 flag)
{
    Items items;
    Menu menu;
    int on;
    if (*(u32 *)&((struct Obj02489 *)p)->fE04) func_02034714(str_02203B08,0,str_02203B08);
    if (*(u32 *)&((struct Obj02489 *)p)->fE08) func_02034714(str_02203B08,0,str_02203B08);
    ((struct Obj02489 *)p)->fE04=func_02027F60((u8)c,(u8)a,((struct Obj02489 *)p)->fFA0,((struct Obj02489 *)p)->fFAC,0x48);
    items=data_02202BC8;
    on=0;
    func_02082BCC(&menu,0,20);
    items.item[0].text=func_02045EC0(((struct Obj02489 *)p)->fB6C,63);
    items.item[1].text=func_02045EC0(((struct Obj02489 *)p)->fB6C,64);
    menu.heap=0x48;
    menu.count=2;
    menu.items=items.item;
    menu.mode=1;
    menu.a=0x20;
    menu.b=b;
    menu.c=8;
    menu.d=3;
    ((struct Obj02489 *)p)->fE08=func_02027778((struct TaskMenuTmpl *)(&menu),((struct Obj02489 *)p)->fE04);
    func_02045808(items.item[0].text);
    func_02045808(items.item[1].text);
    if (flag) {
        if(c<=3) on=1;
        func_021F5008(on);
    }
}


void func_021F4CE4(char *p) { if(((struct Obj00045 *)p)->fE08) { func_02027858(((struct Obj00045 *)p)->fE08); ((struct Obj00045 *)p)->fE08=0; } if(((struct Obj00045 *)p)->fE04) { func_02027FD8(((struct Obj00045 *)p)->fE04); ((struct Obj00045 *)p)->fE04=0; } }


int func_021F4D14(char *p) { int result; result=0; if(((struct Obj00045 *)p)->fE08) { func_02027974(((struct Obj00045 *)p)->fE08); if(func_020279E8(((struct Obj00045 *)p)->fE08)) { result=func_02027A04(((struct Obj00045 *)p)->fE08); if(result==0) result=1; else if(result==1) result=2; func_021F5060(); } } return result; }
