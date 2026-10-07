/*
 * file:     demo3d_graphic_p04.c
 * unit:     yes
 * function: func_021BE13C, func_021BE148, func_021BE158, func_021BE160, func_021BE4B4, func_021BE508
 * address:  0x021BE13C
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02047970 0x02047970 arm
 *   func_0204EA64 0x0204EA64 arm
 *   func_02048AC4 0x02048AC4 arm
 *   func_02030734 0x02030734 arm
 *   func_020113F0 0x020113F0 thumb
 *   func_021BE7A8 0x021BE7A8 thumb ov203
 *   FX_Div 0x0207C768 arm
 *   _ll_mul 0x0209C054 arm
 *   func_02048A24 0x02048A24 arm
 *   func_02048B9C 0x02048B9C arm
 *   func_02048BB0 0x02048BB0 arm
 *   func_021BE63C 0x021BE63C thumb ov203
 *   func_021BE920 0x021BE920 thumb ov203
 *   func_021BE938 0x021BE938 thumb ov203
 *   func_0204E8C0 0x0204E8C0 arm
 *   func_02005654 0x02005654 thumb
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   func_021BE7D8 0x021BE7D8 thumb ov203
 *   func_021BE7BC 0x021BE7BC thumb ov203
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_020115EC 0x020115EC thumb
 *   func_02047CFC 0x02047CFC arm
 *   func_021BE7F0 0x021BE7F0 thumb ov203
 *   func_021BE874 0x021BE874 thumb ov203
 *   func_02047E88 0x02047E88 arm
 *   func_021BE85C 0x021BE85C thumb ov203
 *   func_02048A18 0x02048A18 arm
 *   func_0204779C 0x0204779C arm
 *   func_020477A4 0x020477A4 arm
 *   func_0204784C 0x0204784C arm
 *   func_021BF7C0 0x021BF7C0 thumb ov203
 *   _s32_div_f 0x0209C0A4 arm
 *   FX_SinCosTable_ 0x020A1B38 data
 *   d_021C3CE0 0x021C3CE0 data a1
 *   d_021BFCE0 0x021BFCE0 data a4
 *   d_021BFCD4 0x021BFCD4 data a4
 *   d_021BFCEC 0x021BFCEC data a4
 *   func_021BF810 0x021BF810 thumb ov203
 *   func_0200566C 0x0200566C thumb
 *   func_0204EA0C 0x0204EA0C arm
 *   func_02011558 0x02011558 thumb
 *   func_020480E4 0x020480E4 arm
 *   func_02047E54 0x02047E54 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0204EA38 0x0204EA38 arm
 *   func_02048BA8 0x02048BA8 arm
 *   func_02048BBC 0x02048BBC arm
 */
#include "../../matched/include/Obj03354.h"

struct Config;
struct Context;
struct G3dSys;
struct Light;
struct Record;
struct IcaAnime;
struct AnmCtl;
struct Ctx;
struct Rec;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef long long s64;

typedef int fx32;

typedef struct { fx32 x, y, z; } VecFx32;

struct Cfg {
    u32 f0, f4, f8;
    u8 fc, fd, fe;
    u8 sec : 7, bit7 : 1;
};

struct Cam {
    u8 pad0[8];
    fx32 f8, fc, f10, f14, f18, f1c;
};

struct Ctx {
    u32 owner, id, f8, fc, f10, f14, f18, f1c;
    void *f20;
    u32 f24, f28, f2c;
    u32 z30[6];
    u8 mtx[0x24];
    u32 f6c;
    u16 *f70;
    struct Cam *f74;
    u32 f78, f7c;
    u8 b80, b81, b82, b83, b84, b85;
};

typedef signed int     s32;

extern void func_02047964(void *);
extern void func_020479D8(void);
extern void func_02047970(void);
extern void func_0204EA64(void);
extern u32 func_02048AC4(void *ptr);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern int func_020113F0(int row, int col);
extern u32 func_021BE7A8(u32 id);
extern fx32 FX_Div(fx32, fx32);
extern void *func_02048A24(int, int, int, int, int, int, int, int, VecFx32 *, VecFx32 *, VecFx32 *, int);
extern void func_02048B9C(struct Light *l, u32 *out);
extern void func_02048BB0(struct Light *l, u32 *out);
extern void func_021BE63C(struct Context *ctx, struct Config *cfg, const struct Record *record, u16 heap);
extern u32 func_021BE920(u32);
extern int func_021BE938(void *a);
extern void func_0204E8C0(u32);
extern int func_02005654(int a, int b);
extern void MTX_Identity33_(void *);
extern u8 func_021BE7D8(unsigned x);
extern u32 func_021BE7BC(u32, u32, int);
extern int _ffltu(u32);
extern int _fadd(int, int);
extern int _fsub(int, int);
extern int _ffix(int);
extern void func_020115EC(struct IcaAnime *p, signed int v);
extern u32 func_02047CFC(u16, u16, u32);
extern void *func_021BE7F0(u32);
extern void func_021BE874(char *ctx, const char *config, u8 type);
extern u16 func_02047E88(u32, void *);
extern void func_021BE85C(char *a);
extern u32 func_02048A18(u8 *a0, int i);
extern int func_0204779C(int *p);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
extern u32 func_021BF7C0(struct Ctx *, u32);
extern void func_021BF810(char *p);
extern void func_0200566C(void);
extern int func_0204EA0C(void);
extern void func_02011558(struct IcaAnime *p);
extern void func_020480E4(struct Ctx *c, u32 i);
extern void func_02047E54(struct Rec *p);
extern u32 func_020307B0(void *p);
extern u32 func_0204EA38(void);
extern void func_02048BA8(struct Light *,u32);
extern void func_02048BBC(struct Light *,u32);
void func_021BE13C(void *a);
void func_021BE148(void *p);
void func_021BE150(void);
void func_021BE158(void *p);
struct Ctx *func_021BE160(void *owner, struct Cfg *cfg, u16 heap);
void func_021BE4B4(char *ctx, int b, int c, u32 d);
void func_021BE508(char *p,struct Light *q);
extern const char d_021C3CE0[];
extern const s16 FX_SinCosTable_[];
extern VecFx32 d_021BFCE0;
extern VecFx32 d_021BFCD4;
extern VecFx32 d_021BFCEC;


void func_021BE13C(void *a)
{
    func_02047964(a);
    func_020479D8();
}

void func_021BE148(void *p){func_02047970();}

/*
 * leaf: solely blocks assigned 021BDF24; parent cleared ownership.
 * extent: three 8-byte wrappers; ends at peer-owned 021BE160, which is excluded.
 */
void func_021BE150(void){func_0204EA64();}

void func_021BE158(void *p){func_02048AC4(p);}


static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}


/*
 * 2026-10-05 (integrator): the angle divisor is the plain literal 360 and the alloc size the literal 0x88; mwcc derives 0x168 from the live 0x88 itself (`adds r7,#0xE0`), so the earlier `sz` local was not needed. EXACT in c99 and c.
 * note: 2026-10-05 wave P2 lane Q3 (pengy share, user-approved). Levers: heap is a u16
 *   parameter (entry spill of r2 first, raw reload at every use); cam written as
 *   `cam = ctx->f74 = func_021BE7A8(...)` (store to ctx first, then the local slot sp+0x24);
 *   cnt is a signed int (ble guard); ortho bounds as in ov088 021B9C2C (FX_Mul/FX_Div,
 *   top = FX_Div(t, c), bottom = -FX_Div(t, c)). The angle divisor is written sz + 0xE0:
 *   the original keeps 0x88 live in r7 (alloc size) and derives 0x168 from it with
 *   adds #0xE0; flagged for the integrator as an odd but listing-forced form.
 */
struct Ctx *func_021BE160(void *owner, struct Cfg *cfg, u16 heap)
{
    struct Ctx *ctx;

    int ang, right, d, w, top, t, s, j, near, mid, far, bottom;
    struct Cam *cam;
    int c, q;
    int i, k, n, r;
    int left;
    int cnt;
    void *e;
    u32 h;

    ctx = func_02030734(heap, 0x88, 1, d_021C3CE0, 0x79);
    ctx->owner = (u32)owner;
    ctx->id = cfg->f4;
    ctx->f78 = ctx->id;
    ctx->b80 = cfg->fc;
    ctx->f7c = cfg->f8;
    ctx->b81 = func_020113F0((u8)cfg->sec, (u8)cfg->fd);
    ctx->b82 = cfg->bit7;
    ctx->b83 = cfg->fd;
    ctx->b84 = cfg->fe;
    ctx->b85 = cfg->sec;
    cam = ctx->f74 = (struct Cam *)func_021BE7A8(ctx->id);
    q = (((cam->fc >> 12) / 2) << 16) / 360;
    c = FX_SinCosTable_[(q >> 4) * 2 + 1];
    far = cam->f1c;
    mid = cam->f18;
    near = cam->f14;
    q = (((cam->f8 >> 12) / 2) << 16) / 360;
    s = FX_SinCosTable_[(q >> 4) * 2];
    t = FX_Mul(near, s);
    top = FX_Div(t, c);
    bottom = -FX_Div(t, c);
    w = FX_Mul(near, 0x1555);
    d = 0x1000;
    right = FX_Div(FX_Mul(FX_Div(w, d), s), c);
    left = -FX_Div(FX_Mul(FX_Div(w, d), s), c);
    ctx->f20 = func_02048A24(1, top, bottom, left, right, near, mid, far,
                             &d_021BFCE0, &d_021BFCD4, &d_021BFCEC, heap);
    func_02048B9C(ctx->f20, &ctx->f24);
    func_02048BB0(ctx->f20, &ctx->f28);
    func_021BE63C((struct Context *)ctx, (struct Config *)cfg, (const struct Record *)ctx->f74, heap);
    ctx->f14 = func_021BE920(ctx->id);
    ctx->f10 = func_021BE938((void *)ctx->id);
    if (ctx->f10) {
        func_0204E8C0(heap);
        func_02005654((int)func_021BE150, 0);
    }
    ctx->z30[0] = 0;
    ctx->z30[1] = 0;
    ctx->z30[2] = 0;
    ctx->z30[3] = 0x1000;
    ctx->z30[4] = 0x1000;
    ctx->z30[5] = 0x1000;
    MTX_Identity33_(ctx->mtx);
    ctx->f2c = func_021BE7D8(ctx->id);
    ctx->f70 = func_02030734(heap, ctx->f2c * 2, 1, d_021C3CE0, 0xB7);
    ctx->f18 = func_021BE7BC(ctx->id, heap, 10);
    if (ctx->f7c)
        r = _fadd(0x3f000000, _ffltu(ctx->f7c << 12));
    else
        r = _fsub(_ffltu(ctx->f7c << 12), 0x3f000000);
    func_020115EC((struct IcaAnime *)ctx->f18, _ffix(r));
    n = ctx->f2c * 6;
    ctx->f1c = func_02047CFC((u16)n, (u16)n, heap);
    e = func_021BE7F0(heap);
    for (i = 0; i < ctx->f2c; i++) {
        func_021BE874(e, (const char *)(&ctx->f78), i);
        ctx->f70[i] = func_02047E88(ctx->f1c, e);
    }
    func_021BE85C(e);
    for (j = 0; j < ctx->f2c; j++) {
        h = func_02048A18((u8 *)ctx->f1c, (u16)ctx->f70[j]);
        cnt = func_0204779C((int *)h);
        for (k = 0; k < cnt; k++) {
            if (ctx->f7c)
                r = _fadd(0x3f000000, _ffltu(ctx->f7c << 12));
            else
                r = _fsub(_ffltu(ctx->f7c << 12), 0x3f000000);
            ang = _ffix(r);
            func_020477A4((struct G3dSys *)h, (u16)k);
            func_0204784C((struct AnmCtl *)h, k, &ang);
        }
    }
    ctx->f6c = func_021BF7C0(ctx, heap);
    return ctx;
}

void func_021BE4B4(char *ctx, int b, int c, u32 d)
{
    unsigned i;
    func_021BF810(((struct Obj03354 *)ctx)->f6C);
    func_021BE158(((struct Obj03354 *)ctx)->f20);
    if (((struct Obj03354 *)ctx)->f10) {
        func_0200566C();
        func_0204EA0C();
    }
    func_02011558(((struct Obj03354 *)ctx)->f18);
    for (i = 0; i < ((struct Obj03354 *)ctx)->f2C; i++) {
        func_020480E4(((struct Obj03354 *)ctx)->f1C, (*(unsigned short **)(ctx + 0x70))[i]);
    }
    func_02047E54(((struct Obj03354 *)ctx)->f1C);
    func_020307B0(((struct Obj03354 *)ctx)->f70);
    func_020307B0(ctx);
}

/*
 * extent: 46-byte body plus two-byte alignment at 0x021BE536.
 * blocked: ARM9 0x02048BA8 and 0x02048BBC; existing matched unit_02048AD0.c contains their bodies but omits both from function:.
 * spelling: loads repeated in explicit branch arms reproduce cmp-before-base-load; shared-base and offset ternary differ.
 *   0x02048BA8 ARM EXACT, dsi/1.1p1 -O4,p, verified without --region:
 *   void func_02048BA8(struct Light *p,u32 v) { *(u32 *)((char *)p+4)=v; }
 *   0x02048BBC ARM EXACT, dsi/1.1p1 -O4,p, verified without --region:
 *   void func_02048BBC(struct Light *p,u32 v) { *(u32 *)((char *)p+8)=v; }
 */
void func_021BE508(char *p,struct Light *q)
{
    int x;
    if(func_0204EA38()==0)x=*(short *)(*(char **)(p+0x74)+0x20);
    else x=*(short *)(*(char **)(p+0x74)+0x22);
    func_02048BA8(q,x+*(u32 *)(p+0x24));
    func_02048BBC(q,x+*(u32 *)(p+0x28));
}
