/*
 * function: func_021B9414
 * address:  0x021B9414
 * packet:   pkt_ov106_021B9414
 * region:   ov106
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Computes a two-word source position into out[] from the mode at o->f14:
 *   0: plain copy of the o->fc / o->f10 pair (an 8-byte struct assignment,
 *      which is why the image loads both words before either store);
 *   1: half of both func_020437DC and func_020437E4 minus half of the
 *      func_0201D304 / func_0201D42C probes of o->f18, added to o->fc / o->f10;
 *   2: only the second axis (func_020437E4 vs func_0201D42C), o->fc passes.
 *
 * symbols:
 *   func_020437DC  0x020437DC  arm
 *   func_020437E4  0x020437E4  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_0201D42C  0x0201D42C  thumb
 */

typedef unsigned int u32;

typedef struct {
    int x;
    int y;
} Pair;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
} Obj_021B9414;

extern u32 func_020437DC(int x);
extern u32 func_020437E4(int x);
extern u32 func_0201D304(int a, int b, int c);
extern u32 func_0201D42C(int a, int b);

void func_021B9414(Obj_021B9414 *o, int b, int *out)
{
    switch (o->f14) {
    case 0: {
        Pair *p = (Pair *)out;
        Pair *s = (Pair *)((char *)o + 0xc);
        *p = *s;
        return;
    }
    case 1: {
        u32 x = func_020437DC(o->f0) >> 1;
        u32 y = func_020437E4(o->f0) >> 1;
        x -= func_0201D304(o->f18, b, 0) >> 1;
        y -= func_0201D42C(o->f18, b) >> 1;
        out[0] = x + o->fc;
        out[1] = y + o->f10;
        return;
    }
    case 2: {
        u32 y = func_020437E4(o->f0) >> 1;
        u32 ny = y - (func_0201D42C(o->f18, b) >> 1);
        out[0] = o->fc;
        out[1] = ny + o->f10;
        return;
    }
    }
}
