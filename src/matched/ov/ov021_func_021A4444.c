/*
 * function: func_021A4444
 * address:  0x021A4444
 * packet:   pkt_ov021_021A4444
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A44C8  0x021A44C8  thumb  ov021
 *   func_021A48C8  0x021A48C8  thumb  ov021
 *   func_021A4B00  0x021A4B00  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021A3974(u32);
extern int func_021A44C8(u8 *, u32);
extern int func_021A48C8(u8 *, u32);
extern int func_021A4B00(u8 *, u32);

int func_021A4444(u8 *p, u32 s)
{
    int r;

    r = 0;
    switch (func_021A3974(*(u32 *)(p + 0xc))) {
    case 0:
        r = func_021A44C8(p, s);
        break;
    case 1:
        r = func_021A48C8(p, s);
        break;
    case 2:
    case 3:
        r = func_021A4B00(p, s);
        break;
    }
    return r;
}
