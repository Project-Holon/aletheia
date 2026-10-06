/*
 * function: func_021B6E1C
 * address:  0x021B6E1C
 * packet:   pkt_ov071_021B6E1C
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The 0/1 flag is written in each if/else arm (param.f14 and param.f12 stores), so the
 * param address stays in r0 across the diamond and tail merging rebuilds the join. Callee
 * types from matched definitions (02043678 returns Bmp *, 020255A0 Grid *, 02045EC0 void *,
 * 020457B0 U16Vec *). Twin ov071 021B6A0C. final push 2026-10-05 G7L5.
 * symbols:
 *   func_02043678  0x02043678  arm
 *   func_020255A0  0x020255A0  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_02045808  0x02045808  arm
 *   d_021BA82C     0x021BA82C  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

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
    u8 pad10[0x18];
    void *f28;
    void *f2c;
    u8 pad30[0x10];
    Res res[1];
} Ctx;

typedef struct {
    void *bmp;
    void *grid;
    u8 on;
} Out;

extern const struct Param d_021BA82C;

struct Bmp;
struct Grid;
struct MsgBank;
struct Sys;
struct U16Vec;
struct WordSet;
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
struct PrintSys;
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_02045808(struct U16Vec *vec);

void func_021B6E1C(Ctx *a, Out *b, int c, int x, int y, int w, int h, int g, void *ws)
{
    struct Param param = d_021BA82C;
    void *bmp;
    void *s;
    void *t;

    bmp = func_02043678(w, h, 0x20, 0x61);
    b->bmp = bmp;
    param.x = x - (w / 2) * 8;
    param.y = y - (h / 2) * 8;
    param.bmp = bmp;
    param.f8 = a->res[c].f4c;
    if (c == 0) {
        param.f14 = 0;
        param.f12 = 0;
    } else {
        param.f14 = 1;
        param.f12 = 1;
    }
    b->grid = func_020255A0(a->f2c, &param);
    s = func_02045EC0(a->f28, g);
    if (ws) {
        t = func_020457B0(0x80, 0x61);
        func_0201F250(ws, t, s);
        func_0201C6FC(a->f8, (u32)b->bmp, 0, 0, t, (u32)a->fc);
        func_02045808(t);
    } else {
        func_0201C6FC(a->f8, (u32)b->bmp, 0, 0, s, (u32)a->fc);
    }
    func_02045808(s);
    b->on = 1;
}
