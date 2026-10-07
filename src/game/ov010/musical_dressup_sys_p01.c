/*
 * file:     musical_dressup_sys_p01.c
 * unit:     yes
 * function: func_02155478, func_021559E4
 * address:  0x02155478
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_0203A574  0x0203A574  arm
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0200F83C  0x0200F83C  thumb
 *   func_0200FA84  0x0200FA84  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_02013090  0x02013090  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02013790  0x02013790  thumb
 *   func_020137C0  0x020137C0  thumb
 *   func_02013864  0x02013864  thumb
 *   func_02013894  0x02013894  thumb
 *   func_020137F0  0x020137F0  thumb
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02013128  0x02013128  thumb
 *   func_02013980  0x02013980  thumb
 *   func_02005C44  0x02005C44  thumb
 *   func_02005D28  0x02005D28  thumb
 *   func_02005D90  0x02005D90  thumb
 *   func_020130B4  0x020130B4  thumb
 *   func_0203D378  0x0203D378  arm
 *   func_020124AC  0x020124AC  thumb
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_020145CC  0x020145CC  thumb
 *   func_0203D0D0  0x0203D0D0  arm
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_021550A0  0x021550A0  thumb  ov008
 *   func_0215518C  0x0215518C  thumb  ov010
 *   func_02155224  0x02155224  thumb  ov010
 *   func_02155244  0x02155244  thumb  ov010
 *   func_02155328  0x02155328  thumb  ov010
 *   func_02155A4C  0x02155A4C  thumb  ov010
 *   func_02155A6C  0x02155A6C  thumb  ov010
 *   ov008_id       0x00000008  data
 *   ov021_id       0x00000015  data
 *   ov093_id       0x0000005D  data
 *   ov100_id       0x00000064  data
 *   ov101_id       0x00000065  data
 *   ov119_id       0x00000077  data
 *   ov195_id       0x000000C3  data
 *   d_021D3FE8     0x021D3FE8  data  ov021
 *   d_021BB6A4     0x021BB6A4  data  ov100
 *   d_021F03C4     0x021F03C4  data  ov093
 *   d_021E75D8     0x021E75D8  data  ov119
 *   d_02172700     0x02172700  data  a1
 *   d_02208C40     0x02208C40  data  ov195
 *   d_021B74AC     0x021B74AC  data  ov101
 *   d_0216FEE0     0x0216FEE0  data
 *   func_020122C0  0x020122C0  thumb
 *   func_0201232C  0x0201232C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0201A920  0x0201A920  thumb
 */
#include "../../matched/include/Obj05876.h"

struct Desc;
struct Entry;
struct Evt;
struct IcaAnime;
struct Link;
struct ZoneData;
struct Ctx;
struct Big;
struct Obj;
struct Party;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef volatile u16 vu16;

typedef struct { u32 v[4]; } Tbl4;

struct Info {
    u8 pad00[4];
    u32 f04;
    u8 pad08[0x1a];
    u8 f22;
};

struct Req {
    u32 f00;
    u32 f04;
    u16 f08;
    u8 b0a;
    u8 b0b;
    u32 f0c;
    u32 f10;
};

struct Arg {
    struct Info *info;
    void *slots;
    u32 flag;
};

struct Ctx {
    void *f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    struct Req *f28;
    u8 pad2c[0x0c];
    void *f38;
    void *f3c[4];
    u32 f4c;
    u32 f50;
    u32 f54;
    int f58;
    void *f5c;
    u32 f60;
    void *f64;
    void *f68[4];
    u8 b78[4];
    u32 f7c;
    u8 b80[8];
    struct Info *f88;
    u8 slot[0x40];
    u32 fcc;
    u32 fd0;
    u32 fd4;
    u32 fd8;
    u32 fdc;
    void *fe0;
    u32 fe4;
};

typedef signed int     s32;

typedef struct Task {
    void *f00;
    void *f04;
    u8 pad08[0x30];
    void *f38;
    void *f3c[4];
    u8 pad4c[4];
} Task;

extern void *func_0201210C(const struct Ctx *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_020144DC(int a0, int a1);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern void func_0203A574(u32 a, u32 b, u32 c, u32 d);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *p, u32 lo, u32 hi);
extern u32 func_02039CB4(struct Link *p, u32 lo, u32 hi);
extern u32 func_0200FB24(void);
extern u32 func_0200FBB0(void);
extern void func_0200F83C(void);
extern void func_0200FA84(void);
extern void func_0200FBA0(void);
extern void *func_02013090(u32 heap);
extern void *func_02012F2C(int *p);
extern void func_02013790(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void func_020137C0(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void func_02013864(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void func_02013894(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void func_020137F0(u32 p0, u32 p1, u32 p2, u32 p3, u8 p4, u16 p5);
extern u32 func_0203D1A4(struct Link *p);
extern void func_02013128(void *p, void *src, int i);
extern void func_02013980(struct ZoneData *o, u32 heap);
extern u16 func_02005C44(void);
extern void func_02005D28(void);
extern void func_02005D90(u32 a, u16 b);
extern int func_020130B4(int a0);
extern u32 func_0203D378(void);
extern struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern int func_0203CD98(void);
extern int func_0203CEAC(int a0);
extern void *func_020145CC(void *w);
extern void func_0203D0D0(void);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void *func_021550A0(void *a, const int *p);
extern void func_0215518C(int mode, struct Ctx *ctx);
extern void func_02155224(struct Ctx *ctx);
extern void func_02155244(struct Ctx *ctx, void *party);
extern void func_02155328(struct Ctx *ctx, void *party);
extern void func_02155A4C(struct Ctx *ctx);
extern void func_02155A6C(struct Ctx *ctx);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void func_0201232C(char *p, int a1, int a2);
extern void *func_020124E8(struct Obj *p);
extern void *func_02012EBC(struct Big *p);
extern struct Party *func_0201A920(u32 heap);
int func_02155478(void *proc, int *seq, struct Ctx *ctx);
void *func_021559E4(void *a, int b, void *c, int d);
extern u8 ov008_id[];
extern u8 ov021_id[];
extern u8 ov093_id[];
extern u8 ov100_id[];
extern u8 ov101_id[];
extern u8 ov119_id[];
extern u8 ov195_id[];
extern u8 d_021D3FE8[];
extern u8 d_021BB6A4[];
extern u8 d_021F03C4[];
extern u8 d_021E75D8[];
extern const char d_02172700[];
extern u8 d_02208C40[];
extern u8 d_021B74AC[];
extern const Tbl4 d_0216FEE0;


/*
 * The ov010 main sequence: a 28-state machine over *seq that loads the
 * sub-overlays (21, 100, 119, 195, 101, 8, 93) as child procs, sets up the
 * party/slot records at +0x8c through func_0215518C/func_02155328/
 * func_02155244, runs the fade and wireless-sync waits, and tears
 * everything down in states 21 to 23.
 *
 * Byte-correct (1388 bytes, every concrete byte), 97 of 97 relocations
 * resolved. 2026-10-05 (wave D9): EXACT. The six proc-data words got the
 * token of the overlay that holds each one on its `data` symbols line
 * (ov021, ov100, ov093, ov119, ov195, ov101), each an overlay this function
 * loads. Source unchanged.
 * Shape levers that closed it (they also settled the ctx/seq register
 * swap): case 18 writes the fe4 = 0 / (*seq)++ tail in both arms;
 * case 19 writes (*seq)++ in both arms; state 10 writes the
 * func_02005D90 call in each arm.
 */
int func_02155478(void *proc, int *seq, struct Ctx *ctx)
{
    Tbl4 tbl;
    struct Arg arg;
    void *w;
    void *h;
    struct Req *req;

    w = ctx->f00;
    h = func_0201210C(w);
    switch (*seq) {
    case 0:
        func_02012374(proc, (struct Evt **)func_021BE8D4(w, (int)h, 0, 0));
        (*seq)++;
        break;
    case 1:
        func_02012374(proc, (struct Evt **)func_020144DC((int)w, (int)h));
        *seq = 2;
        break;
    case 2:
        func_020120B4(w, (u32)ov021_id, d_021D3FE8, ctx);
        (*seq)++;
        break;
    case 3:
        if (func_020120F0(w) == 0) {
            if (ctx->f50 == 8) {
                *seq = 24;
            } else if (ctx->f50 == 12) {
                *seq = 21;
            } else {
                (*seq)++;
            }
        }
        break;
    case 4:
        (*seq)++;
        break;
    case 5:
        func_0215518C(ctx->f58, ctx);
        ctx->f60 = ctx->f04;
        ctx->f64 = ctx->f38;
        ctx->f68[0] = ctx->f3c[0];
        ctx->f68[1] = ctx->f3c[1];
        ctx->f68[2] = ctx->f3c[2];
        ctx->f68[3] = ctx->f3c[3];
        ctx->f7c = ctx->f50;
        func_020120B4(w, (u32)ov100_id, d_021BB6A4, &ctx->f60);
        (*seq)++;
        break;
    case 6:
        if (func_020120F0(w) == 0) {
            ctx->f50 = ctx->f7c;
            switch (ctx->f50) {
            case 7:
                *seq = 20;
                break;
            case 12:
                *seq = 20;
                break;
            case 13:
                *seq = 2;
                break;
            case 6:
                ctx->f10 = 0;
                *seq = 13;
                break;
            default:
                *seq = 7;
                break;
            }
        }
        break;
    case 7:
        func_02034AC4((u32)ov093_id);
        func_0203A574(0x100, (u32)d_021F03C4, 9, 0);
        func_02039C68((struct Link *)func_020399A8(), 0x6e, 12);
        (*seq)++;
        break;
    case 8:
        if (func_02039CB4((struct Link *)func_020399A8(), 0x6e, 12))
            (*seq)++;
        if (func_0200FB24()) {
            if (func_0200FBB0() == 1)
                func_0200F83C();
            else
                func_0200FA84();
            func_02034A5C((u32)ov093_id);
            *seq = 20;
        }
        break;
    case 9:
        ctx->f88 = func_02013090(4);
        ctx->fe0 = func_02012F2C((int *)ctx->f04);
        ctx->fd8 = 0;
        switch (ctx->f50) {
        case 0:
            break;
        case 1:
            ctx->fd0 = 1;
            ctx->fd4 = 2;
            func_02013790((u32)ctx->f88, ctx->f04, (u32)func_020399A8(), 1, 4);
            break;
        case 2:
            ctx->fd0 = 1;
            ctx->fd4 = 6;
            func_020137C0((u32)ctx->f88, ctx->f04, (u32)func_020399A8(), 1, 4);
            break;
        case 3:
            ctx->fd0 = 1;
            ctx->fd4 = 10;
            func_02013864((u32)ctx->f88, ctx->f04, (u32)func_020399A8(), 1, 4);
            break;
        case 4:
            ctx->fd0 = 1;
            ctx->fd4 = 14;
            func_02013894((u32)ctx->f88, ctx->f04, (u32)func_020399A8(), 1, 4);
            break;
        case 5:
            tbl = d_0216FEE0;
            ctx->fd0 = 3;
            ctx->fd4 = 18;
            func_020137F0((u32)ctx->f88, ctx->f04, (u32)func_020399A8(), 1,
                          tbl.v[ctx->b78[func_0203D1A4((struct Link *)func_020399A8())]], 4);
            ctx->f88->f22 = 1;
            ctx->f88->f04 = 1;
            func_02155224(ctx);
            break;
        }
        func_02013128(ctx->f88, ctx->f38, 0);
        func_02013980((struct ZoneData *)ctx->f88, 1);
        ctx->f54 = func_02005C44();
        func_02005D28();
        func_02039C68((struct Link *)func_020399A8(), 10, 12);
        (*seq)++;
        break;
    case 10:
        if (func_0200FB24()) {
            func_020130B4((int)ctx->f88);
            ctx->f88 = 0;
            if (func_0200FBB0() == 1)
                func_0200F83C();
            else
                func_0200FA84();
            func_02034A5C((u32)ov093_id);
            *seq = 20;
        } else if (func_02039CB4((struct Link *)func_020399A8(), 10, 12)) {
            if (func_0203D378())
                func_02005D90(0x48B, 0xFFFF);
            else
                func_02005D90(0x48C, 0xFFFF);
            (*seq)++;
        }
        break;
    case 11:
        func_02155328(ctx, w);
        func_02034A5C((u32)ov093_id);
        arg.info = ctx->f88;
        arg.slots = ctx->slot;
        arg.flag = 1;
        func_02012374(proc, (struct Evt **)func_020124AC(w, (u32)ov008_id, (void *)func_021550A0, (u32)(&arg)));
        (*seq)++;
        break;
    case 12:
        if (func_020120F0(w) == 0) {
            func_02155244(ctx, func_020120F4(w));
            func_020130B4((int)ctx->f88);
            ctx->f88 = 0;
            func_02005D28();
            func_02155A6C(ctx);
            *seq = 17;
        }
        break;
    case 13:
        ctx->f1c = ctx->f04;
        ctx->f24 = (u32)ctx->f38;
        func_020120B4(w, (u32)ov119_id, d_021E75D8, &ctx->f08);
        (*seq)++;
        break;
    case 14:
        if (func_020120F0(w) == 0) {
            if (ctx->f10 == 1)
                *seq = 15;
            else
                *seq = 17;
        }
        break;
    case 15:
        req = func_02030734(4, 0x14, 0, d_02172700, 0x219);
        req->f00 = ctx->f04;
        req->f04 = ctx->f24;
        req->f08 = ctx->f14;
        req->b0a = 0;
        req->b0b = ctx->f18;
        req->f0c = 1;
        req->f10 = 0;
        ctx->f28 = req;
        func_020120B4(w, (u32)ov195_id, d_02208C40, req);
        (*seq)++;
        break;
    case 16:
        if (func_020120F0(w) == 0) {
            func_020307B0(ctx->f28);
            ctx->f10 = 1;
            *seq = 13;
        }
        break;
    case 17:
        if (func_0203CD98() && func_0200FB24() == 0)
            func_02039C68((struct Link *)func_020399A8(), 0xdc, 12);
        (*seq)++;
        break;
    case 18:
        if (func_0203CD98() && func_0200FB24() == 0) {
            if (func_02039CB4((struct Link *)func_020399A8(), 0xdc, 12) == 0)
                break;
            ctx->fe4 = 0;
            (*seq)++;
        } else {
            ctx->fe4 = 0;
            (*seq)++;
        }
        break;
    case 19:
        if (func_0203CD98()) {
            ctx->fe4++;
            if (ctx->fe4 < 60)
                break;
            func_0203CEAC(0);
            (*seq)++;
        } else {
            (*seq)++;
        }
        break;
    case 20:
        if (func_0203CD98() == 0) {
            func_0200FBA0();
            *seq = 21;
        }
        break;
    case 21:
        func_02155A6C(ctx);
        func_02012374(proc, func_020145CC(w));
        (*seq)++;
        break;
    case 22:
        func_02012374(proc, (struct Evt **)func_021BE92C(w, (int)h, 0, 0, 1, 0, 0));
        (*seq)++;
        break;
    case 23:
        func_0203D0D0();
        func_02155A4C(ctx);
        return 1;
    case 24:
        (*seq)++;
        break;
    case 25:
        (*seq)++;
        break;
    case 26:
        ctx->f5c = ctx->f00;
        func_020120B4(w, (u32)ov101_id, d_021B74AC, &ctx->f5c);
        (*seq)++;
        break;
    case 27:
        if (func_020120F0(w) == 0) {
            *(vu16 *)0x04000304 |= 0x8000;
            *seq = 20;
        }
        break;
    }
    return 0;
}


void *func_021559E4(void *a, int b, void *c, int d)
{
    Task *t;
    int i;

    if (d != 0)
        c = func_020122C0(a, 0, func_02155478, 0xE8);
    else
        func_0201232C(c, (int)func_02155478, 0xE8);
    t = func_020124E8(c);
    ((struct Obj05876 *)t)->f4C = func_02012EBC(func_020120F4(a));
    t->f04 = func_020120F4(a);
    t->f00 = a;
    for (i = 0; i < 4; i++)
        t->f3c[i] = func_0201A920(4);
    t->f38 = func_0201A920(4);
    return c;
}
