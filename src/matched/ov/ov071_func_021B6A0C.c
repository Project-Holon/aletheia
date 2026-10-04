/*
 * function: func_021B6A0C
 * address:  0x021B6A0C
 * packet:   pkt_ov071_021B6A0C
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The 0/1 flag keeps its bne-to-one polarity only as an enum ternary
 * (a-flag-ternary-over-enum-constants-keeps-the-bne-to-one-polarity.md);
 * `case 2:` shares its arm with `default:` (the dead `cmp r6, #2; b`).
 *
 * symbols:
 *   func_02043678  0x02043678  arm
 *   func_0204B294  0x0204B294  arm
 *   func_020255A0  0x020255A0  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_02045808  0x02045808  arm
 *   d_021BA80C     0x021BA80C  data  a2
 *   d_021BA814     0x021BA814  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

typedef enum { B_FALSE, B_TRUE } Bool;

struct Point {
    s16 x;
    s16 y;
    u16 f4;
    u8 f6;
    u8 f7;
};

struct Param {
    void *bmp;
    s16 x;
    s16 y;
    u32 f8;
    u32 fc;
    u8 f10;
    u8 f11;
    u16 f12;
    u32 f14;
};

typedef struct {
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4c;
} Res;

typedef struct {
    u8 pad0[8];
    void *f8;
    void *fc;
    u8 pad10[4];
    u32 f14;
    u8 pad18[0x10];
    void *f28;
    void *f2c;
    u8 pad30[0x10];
    Res res[1];
} Ctx;

typedef struct {
    void *act;
    void *grid;
    void *bmp;
    u8 on;
} Out;

extern const struct Point d_021BA80C;
extern const struct Param d_021BA814;

struct Bmp;
struct Grid;
struct MsgBank;
struct Sys;
struct U16Vec;
struct WordSet;
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u32 heap);
struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
struct PrintSys;
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_02045808(struct U16Vec *vec);

void func_021B6A0C(Ctx *a, Out *b, int c, int d, int e, int f, int g, void *h)
{
    struct Point pt = d_021BA80C;
    struct Param param = d_021BA814;
    u32 w;
    void *bmp;
    void *s;
    void *t;
    int x;

    switch (d) {
    case 0:
        w = 0x16;
        pt.f4 = 0;
        param.x = e - 0x58;
        break;
    case 1:
        w = 0x12;
        pt.f4 = 1;
        param.x = e - 0x48;
        break;
    case 2:
    default:
        w = 0xc;
        pt.f4 = 8;
        param.x = e - 0x30;
        break;
    }
    bmp = func_02043678(w, 2, 0x20, 0x61);
    b->bmp = bmp;
    pt.x = e;
    pt.y = f;
    param.y = f - 8;
    param.bmp = bmp;
    param.f8 = a->res[c].f4c;
    x = c == 0 ? B_FALSE : B_TRUE;
    param.f14 = x;
    param.f12 = x;
    b->act = func_0204B294((void *)a->f14, a->res[c].f44, a->res[c].f40, a->res[c].f48, &pt, x, 0x61);
    b->grid = func_020255A0(a->f2c, &param);
    s = func_02045EC0(a->f28, g);
    if (h) {
        t = func_020457B0(0x80, 0x61);
        func_0201F250(h, t, s);
        func_0201C6FC(a->f8, (u32)b->bmp, 0, 0, t, (u32)a->fc);
        func_02045808(t);
    } else {
        func_0201C6FC(a->f8, (u32)b->bmp, 0, 0, s, (u32)a->fc);
    }
    func_02045808(s);
    b->on = 1;
}
