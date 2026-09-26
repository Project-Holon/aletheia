/*
 * function: func_021DFE00
 * address:  0x021DFE00
 * packet:   pkt_021DFE00
 * region:   ov228
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker:  size-exact and byte-correct; func_02033494/020334B0 have no
 *           witness anywhere outside this range (not in symbols_sdk.json,
 *           no traced func_ start), so those two calls stay wildcarded.
 *
 * symbols:
 *   func_02033494  0x02033494  arm
 *   func_020334B0  0x020334B0  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef unsigned short u16;

extern u16 func_02033494(u32, void *, u32);
extern int func_020334B0(u16, u16 *);

int func_021DFE00(u8 *p)
{
    u16 v;

    switch (p[0x379]) {
    case 0:
    case 2:
        *(u16 *)(p + 0x37C) =
            func_02033494(p[0x37A] == 0 ? 0x7F800 : 0x7FC00, p, 0x374);
        p[0x379] = p[0x379] + 1;
        break;
    case 1:
    case 3:
        if (func_020334B0(*(u16 *)(p + 0x37C), &v) == 1) {
            p[0x37A] = p[0x37A] ^ 1;
            p[0x379] = p[0x379] + 1;
        }
        break;
    default:
        *(u32 *)(p + 0x374) = 0;
        p[0x378] = 1;
        return 1;
    }
    return 0;
}
