/*
 * function: func_021F49F8
 * address:  0x021F49F8
 * packet:   pkt_021F49F8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
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
 *
 * Load the screen's OBJ resources: the archive-0x60 cell, character,
 * palette and animation sets into the resource block at +0xBC0, the
 * OBJ palette from archive 7 at 0xA0 and a half-brightness copy of it
 * at 0x100, and from archive 0x1F the version-dependent set (files
 * 0x11/6/0xF/0x10 when func_02008550 reports 1, else 0xE/4/0xC/0xD).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

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

extern u8 d_02202BE0[];

extern void *func_020490F4(unsigned int id, u16 heap);
struct Cfg;
struct Sub0200852CObj;
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
typedef signed int     s32;
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern u32 func_0204ABF0(void *arc, u32 id, u32 a, u32 b, u32 heap);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void DC_FlushRange(void *p, u32 size);
extern void GX_LoadOBJPltt(const void *src, u32 offset, u32 size);
extern void func_020307B0(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

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
