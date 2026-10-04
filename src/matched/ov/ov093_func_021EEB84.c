/*
 * function: func_021EEB84
 * address:  0x021EEB84
 * packet:   pkt_ov093_021EEB84
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D4B58  0x021D4B58  thumb  ov093
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

extern u32 func_021D4B58(u32 a, u32 b, u32 c);

u32 func_021EEB84(W *p)
{
    u16 *q;

    if (p->hi != 0) {
        q = &p->h10;
        return func_021D4B58(p->f0d, (u32)q, q[1] + 4);
    }
    return 1;
}
