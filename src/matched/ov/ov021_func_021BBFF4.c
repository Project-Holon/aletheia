/*
 * function: func_021BBFF4
 * address:  0x021BBFF4
 * packet:   pkt_ov021_021BBFF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef struct { u32 w[5]; } Blk;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0C;
    u32 f10;
    Blk blk;
    u32 f28;
    u32 f2C;
} Obj;

extern u32 *func_021AC1AC(u32 a);
extern void func_0216E1A4(u32, u32 *);

void func_021BBFF4(u32 a, Obj *o)
{
    u32 *p = func_021AC1AC(a);

    o->blk = *(Blk *)p;
    o->f0C = 0x40;
    o->f00 = 0;
    o->f08 = 0;
    if (o->blk.w[1] == 2) {
        o->f0C = 0;
    }
    func_0216E1A4(p[2], &o->f2C);
}
