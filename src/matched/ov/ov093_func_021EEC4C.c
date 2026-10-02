/*
 * function: func_021EEC4C
 * address:  0x021EEC4C
 * packet:   pkt_ov093_021EEC4C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D4C84  0x021D4C84  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[4];
    u32 w4;
    u32 w8;
    u8 st : 4;
    u8 hi : 4;
    u8 f0d;
    u8 mode;
    u8 f0f;
    u16 h10;
    u16 h12;
    u8 d[1];
} W;

extern u32 func_021D4C84(u32 a, u32 b);

u32 func_021EEC4C(W *p, u32 a, u32 b)
{
    if (p->hi != 0)
        return func_021D4C84(a, b);
    if (p->st == 0) {
        p->w4 = a;
        p->w8 = b;
        p->st = 1;
    }
    return 1;
}
