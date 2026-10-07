/*
 * file:     worldtrade_box_p02.c
 * unit:     yes
 * function: func_021F4894, func_021F489C, func_021F49A4, func_021F49A8, func_021F49F8
 * address:  0x021F4894
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
 *   func_020307B0  0x020307B0  arm
 *   func_02008550  0x02008550  thumb
 *   func_0204AC18  0x0204AC18  arm
 *   d_02202BE0     0x02202BE0  data
 */
#define ASSERT(x) if (!(x)) func_02034714(str_02203B08, 0, str_02203B08)
struct DispVram;
struct Cfg;
struct Sub0200852CObj;
struct Bank;
typedef signed char s8;

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

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
} Args;

typedef struct {
    Args *args;
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
extern u32 func_020307B0(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
void func_021F4894(const struct DispVram *a0);
void func_021F489C(Work *p, Args *args);
void func_021F49A4(void *a0);
void func_021F49A8(void);
void func_021F49F8(Obj *p, u32 mode);
extern const char str_02203B08[];
extern u8 d_02202BE0[];


void func_021F4894(const struct DispVram *a0)
{
    func_020433E0(a0);
}


void func_021F489C(Work *p, Args *args)
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
