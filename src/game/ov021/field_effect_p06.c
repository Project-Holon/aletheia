/*
 * file:     field_effect_p06.c
 * unit:     yes
 * function: func_021AA3E0, func_021AA3FC, func_021AA42C, func_021AA490, func_021AA548, func_021AA5CC, func_021AA69C, func_021AA6E0, func_021AA6F8, func_021AA728, func_021AA778, func_021AA77C, func_021AA794, func_021AA7AC, func_021AA7CC, func_021AA7DC, func_021AA80C, func_021AA8EC, func_021AA8F8
 * address:  0x021AA3E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021938F4  0x021938F4  thumb  ov021
 *   func_020056EC  0x020056EC  thumb
 *   func_0207C7B4  0x0207C7B4  arm
 *   _ll_mul        0x0209C054  arm
 *   func_02010FB0  0x02010FB0  thumb
 *   data_021DDFA4  0x021DDFA4  data
 *   func_02013144  0x02013144  thumb
 *   func_0201347C  0x0201347C  thumb
 *   func_020173EC  0x020173EC  thumb
 *   func_0201A920  0x0201A920  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021A96B8  0x021A96B8  thumb
 *   func_021AA304  0x021AA304  thumb
 *   func_021A9780  0x021A9780  thumb
 *   func_020130C4  0x020130C4  thumb
 *   func_0202A230  0x0202A230  thumb
 *   func_0202A420  0x0202A420  thumb
 *   func_02013734  0x02013734  thumb
 *   func_02013644  0x02013644  thumb
 *   func_020136E0  0x020136E0  thumb
 *   func_02013610  0x02013610  thumb
 *   func_02013678  0x02013678  thumb
 *   func_020136AC  0x020136AC  thumb
 *   func_02188C6C  0x02188C6C  thumb
 *   func_021A1BF4  0x021A1BF4  thumb
 *   func_0209C2B0  0x0209C2B0  arm
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021A3074  0x021A3074  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   d_021DDFB4  0x021DDFB4  data  a4
 *   func_02082BCC  0x02082BCC  arm
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021AAB74  0x021AAB74  thumb  ov021
 *   func_021AAB54  0x021AAB54  thumb  ov021
 *   func_021AAFFC  0x021AAFFC  thumb  ov021
 *   d_021D8E70  0x021D8E70  data  a4
 *   func_02012A38  0x02012A38  thumb
 *   func_02012974  0x02012974  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02159C48  0x02159C48  thumb  ov010
 *   func_02159BD4  0x02159BD4  thumb  ov010
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C234  0x0200C234  thumb
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021AABC4  0x021AABC4  thumb  ov021
 *   func_02005728  0x02005728  thumb
 *   func_021AABEC  0x021AABEC  thumb  ov021
 *   func_021AACD4  0x021AACD4  thumb  ov021
 *   func_021AAE34  0x021AAE34  thumb  ov021
 *   func_021AAFA0  0x021AAFA0  thumb  ov021
 *   func_021AAF54  0x021AAF54  thumb
 */
#include "../../matched/include/Obj18071.h"
#include "../../matched/include/Obj07219.h"
#include "../../matched/include/Obj09585.h"
#include "../../matched/include/Obj18072.h"

struct Party;
struct PartyMon;
struct Slot14;
struct Obj020136E0;
struct Obj02013734;
struct BigObj;
struct Blk34;
struct Obj00020;
struct Actor;
struct VecFx32;
struct Self;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

struct Tab { u8 pad00[0xC]; u8 *f0C; };

typedef long long fx64;

typedef int fx32;

struct Ctx_021AA3E0 { void *f00; u8 pad04[4]; void *f08; };

struct Unit {
    u8 pad00[8];
    int f08;
    u8 pad0C[0x1C];
    u32 b0 : 5;
    u32 b5 : 1;
};

struct Info { u32 f00; u32 f04; u8 f08; u8 f09; u16 f0A; u8 f0C; u8 f0D; u8 pad0E[2]; };

struct Slot14 { u8 raw[0x14]; };

struct Pos { u16 x, y, z; u16 f06; u32 f08; };

typedef struct {
    u8 a;
    u8 b;
} Pair;

typedef struct {
    u8 pad[7];
    u8 k : 7;
    u8 hi : 1;
} R;

typedef struct {
    int pad[3];
    R *fc;
} S;

typedef struct {
    char pad[0x5b8];
    u16 a;
    u16 b;
} D;

struct Mon {
    u8 pad00[7];
    u8 lo : 7;
    u8 b7 : 1;
};

struct Entry {
    u8 pad00[0x1D];
    u8 flags : 4;
};

struct Enc {
    u8 pad00[4];
    u16 f04;
    u8 pad06[0x5B4];
    u16 f5BA;
};

struct Ctx_021AA7DC {
    void *f00;
    int f04;
    void *f08;
    struct Mon *f0C;
    struct Enc *f10;
};

extern int func_021938F4(unsigned char *p);
extern u32 func_020056EC(u32 range);
extern fx32 func_0207C7B4(fx32 x);
extern u32 func_02010FB0(u32 v);
extern struct Party *func_0201A920(u32 heap);
extern u32 func_020173EC(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_021AA304(struct Info *out, void *a1, void *a2);
extern void func_0201347C(u8 *a0, void *a1, u32 a2, u32 a3, u32 a4, u16 a5);
extern void func_02013144(char *p, int v);
extern u32 func_020307B0(void *p);
extern void func_021A96B8(void *mon, const struct Unit *u, struct Slot14 *s);
extern void func_021A9780(void *mon, const struct Unit *u, void *src);
extern void func_020130C4(u8 *p);
extern u32 func_0202A230(void *a, u32 idx);
extern u32 func_0202A420(u32 key);
extern void func_02013734(struct Obj02013734 *o, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_020136E0(struct Obj020136E0 *o, u32 a1, u32 a2, u32 a3, u32 a4, u16 a5);
extern void func_02013644(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern void func_02013610(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern void func_02013678(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern void func_020136AC(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern u32 func_02188C6C(u8 *p);
extern u16 func_021A1BF4(u8 *p);
extern u32 func_0209C2B0(u32 a, u32 b);
extern void *func_021A3074(u8 *p);
extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern int func_0216D83C(void *p);
extern int func_0216D854(void *p);
extern int func_0216D86C(void *p);
extern u32 func_02082BCC(u32, u32, u32, u32);
extern u32 func_02188CD0(u8 *p);
extern u32 func_021AAB74(u32, u32);
extern u32 func_021AAB54(u32, u32, u32, u32);
extern u32 func_021AAFFC(u32);
extern u32 func_02012A38(const struct BigObj *p);
extern u32 func_02012974(const struct BigObj *p);
extern u16 func_02188C9C(u8 *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern int func_02159C48(int a0, int a1, int a2);
extern int func_02159BD4(int a0, int a1, int a2);
extern void *func_02012F08(int *p);
extern u32 func_0200C234(struct Blk34 *p, u32 bit);
extern u32 func_02188CFC(u8 *p);
extern int func_021AABC4(struct Entry *p, struct Enc *e);
extern u32 func_02005728(u32 v);
extern void func_021AABEC(u8 *p);
extern void func_021AACD4(void **ctx, struct Enc *e);
extern void func_021AAE34(struct Ctx_021AA7DC *ctx, struct Enc *e);
extern void func_021AAFA0(u8 *p, u32 v);
extern int func_021AAF54(struct Self *self);
int func_021AA3E0(struct Tab *t, int i, int add);
int func_021AA3FC(void *a0, void *p, u32 rate);
int func_021AA42C(void *a, void *b);
void func_021AA490(struct Ctx_021AA3E0 *ctx, struct Unit *u, void *a2, u16 heap, struct Slot14 *slots);
void func_021AA548(struct Ctx_021AA3E0 *ctx, void *a1, void *a2, u16 heap, void *src);
void func_021AA5CC(struct Ctx_021AA3E0 *ctx, void *a1, u32 mode, u32 flag, void *mon, u32 a5, u16 heap);
u8 func_021AA69C(void *p);
u32 func_021AA6E0(void);
void func_021AA6F8(struct Pos *p, void *q);
void func_021AA728(struct Pos *p, void *q);
u32 func_021AA778(u8 *p);
void *func_021AA77C(int heap);
int func_021AA794(void *a, u32 b, u32 c, u32 d);
int func_021AA7AC(u32 a, u32 b);
int func_021AA7CC(u32 a, u32 b, u32 c, u32 d);
void func_021AA7DC(S *s, D *d);
void func_021AA80C(struct Ctx_021AA7DC *ctx);
void func_021AA8EC(u8 *p);
void func_021AA8F8(struct Self *a0);
extern const char data_021DDFA4[];
extern char d_021DDFB4[];
extern const Pair d_021D8E70[];




/*
 * Addresses are Black-image addresses.
 */
int func_021AA3E0(struct Tab *t, int i, int add)
{
    int v;

    if (i >= 7)
        return 0;
    v = t->f0C[i];
    if (v > 0)
        v += add;
    if (v < 0)
        v = 0;
    return v;
}




int func_021AA3FC(void *a0, void *p, u32 rate)
{
    u32 r;

    if (rate > 100)
        rate = 100;
    r = func_021AA778(p);
    if (r == 0)
        return 0;
    if (r == 1)
        rate = 1;
    if (func_021AA6E0() <= rate)
        return 1;
    return 0;
}




static inline fx32 FX_MUL(fx32 v1, fx32 v2)
{
    return (fx32)(((fx64)v1 * v2 + 0x800LL) >> 12);
}




int func_021AA42C(void *a, void *b)
{
    int n = func_021AA778(a);
    int m = func_021938F4(b);
    int rnd = func_020056EC(100);
    fx32 sq = func_0207C7B4(m << 12);
    fx32 t = FX_MUL((n - 1) << 12, sq);

    t = FX_MUL(t, 0x4000);
    return (int)func_02010FB0((int)(t >> 12)) > rnd;
}




void func_021AA490(struct Ctx_021AA3E0 *ctx, struct Unit *u, void *a2, u16 heap, struct Slot14 *slots)
{
    struct Info info;
    void *party = func_0201A920(heap);
    void *mon = func_02030734(heap, func_020173EC(), 1, data_021DDFA4, 0x285);
    int i;

    for (i = 0; i < (u8)u->b5 + 1; i++) {
        func_021A96B8(mon, u, &slots[i]);
        func_0201A98C(party, mon);
    }
    func_021AA304(&info, ctx->f08, ctx->f00);
    func_0201347C(a2, ctx->f08, (u32)party, (u32)(&info), u->b5, heap);
    if (u->f08 == 1)
        func_02013144(a2, 0x20);
    func_020307B0(mon);
    func_020307B0(party);
}




void func_021AA548(struct Ctx_021AA3E0 *ctx, void *a1, void *a2, u16 heap, void *src)
{
    struct Info info;
    void *party = func_0201A920(heap);
    void *mon = func_02030734((u16)((heap & 0x7FFF) | 0x8000), func_020173EC(), 1, data_021DDFA4, 0x2A4);

    func_021A9780(mon, a1, src);
    func_0201A98C(party, mon);
    func_021AA304(&info, ctx->f08, ctx->f00);
    func_0201347C(a2, ctx->f08, (u32)party, (u32)(&info), 0, heap);
    func_02013144(a2, 8);
    func_020307B0(mon);
    func_020307B0(party);
}




void func_021AA5CC(struct Ctx_021AA3E0 *ctx, void *a1, u32 mode, u32 flag, void *mon, u32 a5, u16 heap)
{
    struct Info info;
    void *x = ctx->f08;
    u32 r;

    func_020130C4(a1);
    func_021AA304(&info, ctx->f08, ctx->f00);
    r = func_0202A420(func_0202A230(mon, 1));
    if (r != 0x11) {
        info.f04 = r;
    }
    switch (mode) {
    case 1:
        if (flag) {
            func_02013734(a1, (u32)x, (u32)(&info), flag, (u32)mon, a5, heap);
        } else {
            func_02013644(a1, (u32)x, (u32)(&info), (u32)mon, heap);
        }
        return;
    case 0:
        if (a5) {
            func_020136E0(a1, (u32)x, (u32)(&info), (u32)mon, a5, heap);
        } else {
            func_02013610(a1, (u32)x, (u32)(&info), (u32)mon, heap);
        }
        return;
    case 2:
        func_02013678(a1, (u32)x, (u32)(&info), (u32)mon, heap);
        return;
    case 3:
        func_020136AC(a1, (u32)x, (u32)(&info), (u32)mon, heap);
        return;
    }
}




u8 func_021AA69C(void *p)
{
    switch (func_021A1BF4((u8 *)func_02188C6C(p))) {
    case 2:
    case 6:
    case 7:
        return 2;
    case 3:
    case 12:
        return 4;
    case 4:
    case 5:
        return 3;
    }
    return 0;
}




u32 func_021AA6E0(void)
{
    return func_0209C2B0(func_020056EC(0xFFFF), 0x290);
}




void func_021AA6F8(struct Pos *p, void *q)
{
    void *o = func_021A3074(q);

    MI_CpuFill8(p, 0, sizeof(*p));
    p->x = func_0216D83C(o);
    p->y = func_0216D854(o);
    p->z = func_0216D86C(o);
}




void func_021AA728(struct Pos *p, void *q)
{
    void *o = func_021A3074(q);

    if (p->f06 != 0) {
        if (p->f08 < 0xA000)
            p->f08++;
        return;
    }
    if (p->x != func_0216D83C(o) || p->y != func_0216D854(o) || p->z != func_0216D86C(o)) {
        p->f06 = 1;
        p->f08++;
    }
}




/*
 * Loads the 32-bit word at byte +0x8 of the object.
 */
u32 func_021AA778(u8 *p)
{
    return ((struct Obj18071 *)p)->f8;
}




void *func_021AA77C(int heap)
{
    return func_02030734(heap, 0x5c0, 1, d_021DDFB4, 0x6e);
}




/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AA794(void *a, u32 b, u32 c, u32 d)
{
func_02082BCC((u32)a, 0, (23 << 6), d);
return func_020307B0(a);
}




int func_021AA7AC(u32 a, u32 b)
{
((struct Obj09585 *)((u8 *)(b)))->f0 = func_02188CD0((u8 *)(*(u32 *)&((struct Obj07219 *)((u8 *)(a)))->f0));
func_021AA7DC((S *)a, (D *)b);
return func_021AAB74(a, b);
}




int func_021AA7CC(u32 a, u32 b, u32 c, u32 d)
{
func_021AAB54(a, b, c, d);
return func_021AAFFC(b);
}



void func_021AA7DC(S *s, D *d)
{
    unsigned int k = s->fc->k;
    if (k > 2) {
        k = 0;
    }
    d->a = d_021D8E70[k].a;
    d->b = d_021D8E70[k].b;
}



void func_021AA80C(struct Ctx_021AA7DC *ctx)
{
    struct Enc *e = ctx->f10;
    struct Entry *p = (struct Entry *)func_02012A38(ctx->f08);
    void *m;
    u16 id;
    s32 pos[3];
    int r;

    if (ctx == 0 || ctx->f0C == 0 || !ctx->f0C->b7)
        return;
    m = (void *)func_02012974(ctx->f08);
    if (ctx->f00 == 0 || m == 0)
        return;
    id = func_02188C9C(ctx->f00);
    func_0216D88C(func_021A3074(func_02188CB4(ctx->f00)), (struct VecFx32 *)pos);
    if (func_02159C48((int)m, pos[0], pos[2]) == 0)
        return;
    r = func_02159BD4((int)m, pos[0], pos[2]);
    if (id == 0xFFFF || r == 0xFFFF || id != r)
        return;
    if (func_0200C234(func_02012F08(ctx->f08), 0) == 0)
        return;
    if (func_02188CFC(ctx->f00) != 0)
        return;
    if (p->flags != 0)
        return;
    if (func_021AABC4(p, e) == 0)
        return;
    if (func_02005728(1000) >= e->f5BA * 10) {
        func_021AABEC((u8 *)p);
        return;
    }
    func_021AACD4((void **)ctx, e);
    if (e->f04 != 0)
        func_021AAE34((struct Ctx_021AA7DC *)ctx, e);
}



/*
 * Tail call with the object and the word at +0x10.
 *
 * Addresses are Black-image addresses.
 */
void func_021AA8EC(u8 *p)
{
    func_021AAFA0(p, ((struct Obj18072 *)p)->f10);
}



/*
 * Tail-call thunk: forwards to func_021AAF54 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021AA8F8(struct Self *a0)
{
    func_021AAF54(a0);
}
