/*
 * function: func_021EEC20
 * address:  0x021EEC20
 * packet:   pkt_ov093_021EEC20
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D4C6C  0x021D4C6C  thumb  ov093
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

extern u16 func_021D4C6C(u8 **out);

u16 func_021EEC20(W *p, u8 **out)
{
    u8 *q;
    u8 *r;

    if (p->hi != 0) {
        func_021D4C6C(&q);
        r = q;
        *out = r + 4;
        return *(u16 *)(r + 2);
    }
    *out = p->d;
    return p->h12;
}
