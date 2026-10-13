/*
 * function: FIELD_ENCOUNT_CalcEncountRate
 * address:  0x021A94B0
 * packet:   pkt_ov021_021A94B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
 *   func_0209C2B0  0x0209C2B0  arm
 *   GPOWER_ApplyEncountRate  0x02010FB0  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj {
    u8 pad00[0x18];
    u16 f18;
    u8 pad1A[0xE];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 4;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
};

extern u32 func_0209C2B0(u32 a, u32 b);
extern u32 GPOWER_ApplyEncountRate(u32 v);

u32 FIELD_ENCOUNT_CalcEncountRate(struct Obj *o, u32 unused, u32 n)
{
    u32 v = n;

    if (o->b1) {
        if (o->b8) {
            v = v * 2;
        }
        if (v > 100) {
            v = 100;
        }
        return v;
    }
    if (o->b6) {
        v = v * 2;
    } else if (o->b7) {
        v = v >> 1;
    }
    if (o->f18 == 0xE0 || o->f18 == 0x140) {
        v = func_0209C2B0(n * 2, 3);
    }
    if (v > 100) {
        v = 100;
    }
    return GPOWER_ApplyEncountRate(v);
}
