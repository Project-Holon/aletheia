/*
 * function: func_021B9164
 * address:  0x021B9164
 * packet:   pkt_ov021_021B9164
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: only residue is the constant 2 for h0 taking r1 while 0 takes r3 early (original materialises 2 in r3 first, then 0 in r3). Tried h0-first, chained zeros, a zero local, reordering x24/x1c; short h0 also leaves 6 bytes.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x2C];
    void *x2c;
} Src;

typedef struct {
    u16 h0;
    u16 h2;
    int x4;
    u16 h8;
    u16 ha;
    int xc;
    int x10;
    int x14;
    int x18;
    void *x1c;
    int x20;
    Src *x24;
    u8 *x28;
    u8 b2c;
    u8 pad2d[5];
    u8 b32;
    u8 b33;
    u8 pad34[0x40];
    u8 b74;
    u8 pad75[3];
    u8 *x78;
} Obj;

void func_021B9164(Obj *o, Src *s, u8 *b)
{
    o->x24 = s;
    o->x1c = s->x2c;
    o->h0 = 2;
    o->b33 = 0;
    o->b32 = 0;
    o->b2c = 0;
    o->x78 = b;
    o->x4 = 0;
    o->xc = 0;
    o->x14 = 0;
    o->x20 = 0;
    o->x28 = b + 0x50;
    o->b74 = 0;
    o->h8 = 0;
}
