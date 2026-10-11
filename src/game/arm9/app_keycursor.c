/*
 * file:     app_keycursor.c
 * unit:     yes
 * function: func_020285A4, func_02028604, func_02028618, func_0202865C, func_020286C4, func_02028748, func_02028754, func_02028760, func_02028784, func_0202878C, func_02028794, func_020287A8, func_020287B4, func_020287CC, func_020287E4, func_020287F8, func_0202880C, func_02028828
 * address:  0x020285A4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734      0x02030734  arm
 *   func_020436FC      0x020436FC  arm
 *   app_keycursor_File 0x020A74F0  data
 *   func_020437DC  0x020437DC  arm
 *   func_020437E4  0x020437E4  arm
 *   func_02043AF4  0x02043AF4  arm
 *   func_020439A0  0x020439A0  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   sub_0201CE30   0x0201CE30  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_02045770  0x02045770  arm
 *   func_02045334  0x02045334  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02072D98  0x02072D98  arm
 */
#include "../../matched/include/Obj15795.h"

struct Bmp;
struct Descriptor;
struct Fader;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct KeyCursor {
    u32 *item;    /* 0x00 */
    u8   unk4;    /* 0x04 */
    u8   unk5;    /* 0x05 */
    u8   unk6;    /* 0x06 */
    u8   live : 1;   /* 0x07 bit 0 */
    u8   flip : 1;   /* 0x07 bit 1 */
    u16  id;      /* 0x08 */
};

typedef signed short   s16;

struct Bmp {
    void *pixels;
    u16   width;
    u16   height;
    u16   depth;
    u16   kind;
};

struct Ctx {
    void *f00;
    u8    f04;
    u8    f05;
    u8    f06;
    u8    b0 : 1;
    u8    b1 : 1;
    u8    b2 : 6;
    u16   f08;
};

typedef signed int     s32;

struct Obj {
    u32 pad_00[2];
    u32 field_08;
    u32 pad_0c;
    u16 field_10;
    u16 pad_12;
    u32 flags;
};

struct Fader {
    u8  unk00;
    u8  unk01;
    u8  unk02;
    u8  unk03;
    u16 unk04;
    u16 unk06;
    u8  unk08;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Bmp *func_020436FC(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern u16  func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern u32   sub_0201CE30(void *p);
extern u32   func_020362DC(void);
extern int func_02035C60(void);
extern void *func_02045770(struct Descriptor *p);
extern void func_02045334(struct Descriptor *d);
extern u32 func_020307B0(void *p);
extern void func_02072D98(u32 channel, u32 level);
struct KeyCursor *func_020285A4(u16 id, u32 live, u32 flip, u16 heap, void *pixels);
int func_02028604(int a0);
void func_02028618(struct Ctx *ctx, const struct Bmp *bmp, u32 color);
void func_0202865C(struct Ctx *ctx, const struct Bmp *bmp, u32 color);
void func_020286C4(struct Ctx *ctx, void *p, void *cell);
void func_02028748(struct Obj *obj, int n, int mask);
u32 func_02028754(struct Obj *obj, u32 n);
void *func_02028760(void *a, int v);
void func_02028784(void *ptr);
void func_0202878C(struct Fader *s);
void func_02028794(struct Fader *s, u8 level, u16 frames);
void func_020287A8(struct Fader *s, u8 mute);
void func_020287B4(struct Fader *s);
void func_020287CC(struct Fader *s, u8 target, u16 frames);
void func_020287E4(struct Fader *s, u8 level);
void func_020287F8(struct Fader *s);
u32 func_0202880C(struct Fader *s);
void func_02028828(struct Fader *s);
extern const char app_keycursor_File[];




/*
 * TU: app_keycursor.c (__FILE__ 0x020A74F0, line 149).
 */
struct KeyCursor *func_020285A4(u16 id, u32 live, u32 flip, u16 heap,
                                void *pixels)
{
    struct KeyCursor *k;

    k = func_02030734(heap, sizeof(struct KeyCursor), 1, app_keycursor_File,
                      149);

    k->id = id;
    k->live = live;
    k->flip = flip;
    k->item = (u32 *)func_020436FC(pixels, 2, 2, 0x20, heap);

    return k;
}





int func_02028604(int a0){ int t0 = func_020437AC((int)((struct Obj15795 *)((char *)((a0 + 0))))->f0); int t1 = func_020307B0((void *)((a0 + 0) + 0)); return t1; }





void func_02028618(struct Ctx *ctx, const struct Bmp *bmp, u32 color)
{
    u16 w = func_020437DC(bmp) - 11;
    u16 h = func_020437E4(bmp) - 9;

    func_02043AF4((struct Bmp *)bmp, (s16)w, (s16)(h + ctx->f04), 0xa, 7, (u8)color);
}



void func_0202865C(struct Ctx *ctx, const struct Bmp *bmp, u32 color)
{
    u16 w;
    u16 h;

    func_02028618(ctx, bmp, color);

    ctx->f05 = ctx->f05 + 1;
    if (ctx->f05 >= 8) {
        ctx->f05 = 0;
        ctx->f04 = ctx->f04 + 1;
        ctx->f04 = (s32)ctx->f04 % 3;
    }

    w = func_020437DC(bmp) - 11;
    h = func_020437E4(bmp) - 9;

    func_020439A0(ctx->f00, (struct Bmp *)bmp, 0, 2, w, h + ctx->f04, 0xa, 7, 0);
}



void func_020286C4(struct Ctx *ctx, void *p, void *cell)
{
    u32 mode = sub_0201CE30(p);

    switch (mode) {
    case 2:
        ctx->f06 = 0;
        return;
    case 1:
    {
        u32 r = 0;

        if (ctx->b0) {
            r = func_020362DC() & 3;
        }
        if (r == 0) {
            if (ctx->b1) {
                r = func_02035C60();
            }
        }
        if (r != 0) {
            ctx->f06 = 1;
            func_02028618(ctx, func_02045770(cell), ctx->f08);
            func_02045334(cell);
            return;
        }
        if (ctx->f06 != 0) {
            return;
        }
        func_0202865C(ctx, func_02045770(cell), ctx->f08);
        func_02045334(cell);
        return;
    }
    case 0:
        ctx->f06 = 0;
        return;
    }
}




/*
 * A pair of leaf accessors over a 32-bit flag word at offset 0x14: or
 * `mask << n` into it, and test bit `n`.  Neither calls anything.
 */
void func_02028748(struct Obj *obj, int n, int mask)
{
    obj->flags = obj->flags | (mask << n);
}


u32 func_02028754(struct Obj *obj, u32 n)
{
    return (obj->flags >> n) & 1;
}


void *func_02028760(void *a, int v)
{
    char *p = (char *)func_02030734((unsigned int)a, 0xa, 0, (const char *)0x020A7500, 0x42);
    func_020287B4((struct Fader *)p);
    *p = (char)v;
    return p;
}



void func_02028784(void *ptr)
{
    func_020307B0(ptr);
}



/*
 *           func_020287CC, func_020287E4, func_020287F8, func_0202880C,
 *           func_02028828
 *
 * The tail of player_volume_fader.c (its file string is carried by
 * func_02028760, outside this packet): a nine byte record holding a channel
 * id, a start and a target level, a duration and an elapsed count, and the
 * eight entry points that drive it.  func_0202880C is the interpolation,
 * func_02028828 is the "push the current level at the mixer" step every
 * mutator ends with, and func_020287F8 is the per-frame tick.
 *
 * The nine functions are one file because five of them are reached only from
 * inside it and two of those five are reached only through a tail call's pool
 * word, which is not a branch and therefore not a `label` witness
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  In one object they are
 * `local` and need no image evidence.  Nothing outside the file loses a
 * witness by the merge: the two externally called entry points, func_020287A8
 * and func_020287B4, are called with real branches from outside the packet
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).
 *
 * func_0202880C's division is the compiler's signed helper at 0x0209C0A4 and
 * not a shift, which is what says the operands are `int` rather than unsigned
 * (docs/idioms/runtime-helper-reloc.md).  The difference of the two levels is
 * the multiply's destination register, so the level pair is the left operand
 * of the multiply and the elapsed count the right
 * (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md).
 *
 * Its four locals also need their declaration order and their initialisation
 * order to disagree: declared elapsed, from, to, frames but assigned from, to,
 * elapsed, frames.  Declaration order picks the registers and initialisation
 * order picks the order of the four loads, and no single order gives both
 * (docs/idioms/declaration-order-picks-the-register-initialisation-order-picks-the-load.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202878C.c \
 *       --addr 0x0202878C --thumb
 */
void func_0202878C(struct Fader *s)
{
    func_020287F8(s);
}


void func_02028794(struct Fader *s, u8 level, u16 frames)
{
    if (frames == 0) {
        func_020287E4(s, level);
    } else {
        func_020287CC(s, level, frames);
    }
}


void func_020287A8(struct Fader *s, u8 mute)
{
    s->unk08 = mute;
    func_02028828(s);
}


void func_020287B4(struct Fader *s)
{
    s->unk00 = 0;
    s->unk01 = 0x7F;
    s->unk02 = 0x7F;
    s->unk04 = 0;
    s->unk06 = 0;
    s->unk08 = 0;
    func_02028828(s);
}


void func_020287CC(struct Fader *s, u8 target, u16 frames)
{
    s->unk01 = func_0202880C(s);
    s->unk02 = target;
    s->unk04 = frames;
    s->unk06 = 0;
}


void func_020287E4(struct Fader *s, u8 level)
{
    s->unk01 = level;
    s->unk02 = level;
    s->unk04 = 0;
    s->unk06 = 0;
    func_02028828(s);
}


void func_020287F8(struct Fader *s)
{
    if (s->unk06 < s->unk04) {
        s->unk06 = s->unk06 + 1;
        func_02028828(s);
    }
}


u32 func_0202880C(struct Fader *s)
{
    u16 elapsed;
    u8 from;
    u8 to;
    u16 frames;
    u32 level;

    from = s->unk01;
    to = s->unk02;
    elapsed = s->unk06;
    frames = s->unk04;
    level = from;
    if (elapsed != 0) {
        level = from + (to - from) * elapsed / frames;
    }
    return level;
}


void func_02028828(struct Fader *s)
{
    u32 level = func_0202880C(s);

    if (s->unk08 != 0) {
        level = 0;
    }
    func_02072D98(s->unk00, level);
}
