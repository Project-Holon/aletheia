/*
 * file:     field_effect_p15.c
 * unit:     yes
 * function: func_021AA3E0, func_021AA3FC, func_021AA42C, func_021AA490, func_021AA548, func_021AA5CC, func_021AA69C, func_021AA6E0
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
 *   func_021AA778  0x021AA778  thumb
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
 */
struct Party;
struct PartyMon;
struct Slot14;
struct Obj020136E0;
struct Obj02013734;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

struct Tab { u8 pad00[0xC]; u8 *f0C; };

typedef long long fx64;

typedef int fx32;

struct Ctx { void *f00; u8 pad04[4]; void *f08; };

struct Unit {
    u8 pad00[8];
    int f08;
    u8 pad0C[0x1C];
    u32 b0 : 5;
    u32 b5 : 1;
};

struct Info { u32 f00; u32 f04; u8 f08; u8 f09; u16 f0A; u8 f0C; u8 f0D; u8 pad0E[2]; };

struct Slot14 { u8 raw[0x14]; };

extern u32 func_021AA778(u8 *p);
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
int func_021AA3E0(struct Tab *t, int i, int add);
int func_021AA3FC(void *a0, void *p, u32 rate);
int func_021AA42C(void *a, void *b);
void func_021AA490(struct Ctx *ctx, struct Unit *u, void *a2, u16 heap, struct Slot14 *slots);
void func_021AA548(struct Ctx *ctx, void *a1, void *a2, u16 heap, void *src);
void func_021AA5CC(struct Ctx *ctx, void *a1, u32 mode, u32 flag, void *mon, u32 a5, u16 heap);
u8 func_021AA69C(void *p);
u32 func_021AA6E0(void);
extern const char data_021DDFA4[];


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


void func_021AA490(struct Ctx *ctx, struct Unit *u, void *a2, u16 heap, struct Slot14 *slots)
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


void func_021AA548(struct Ctx *ctx, void *a1, void *a2, u16 heap, void *src)
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


void func_021AA5CC(struct Ctx *ctx, void *a1, u32 mode, u32 flag, void *mon, u32 a5, u16 heap)
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
