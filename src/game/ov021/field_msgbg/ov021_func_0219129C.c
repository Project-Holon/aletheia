/*
 * function: func_0219129C
 * address:  0x0219129C
 * packet:   pkt_ov021_0219129C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021911B8  0x021911B8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Ent {
    u32 f00;
    u32 f04;
    u32 f08;
    u8  pad[0x28];
} Ent;

extern void func_021911B8(u8 *base, Ent *e, int idx, u32 c, u32 d, u32 f, u32 g);

Ent *func_0219129C(u8 *base, int idx, u32 c, u32 d, u32 f, u32 g)
{
    Ent *e;

    if (idx < 3) {
        e = (Ent *)(base + 0xC0) + idx;
        if (e->f08 == 0) {
            func_021911B8(base, e, idx, c, d, f, g);
            return e;
        }
    }
    return 0;
}
