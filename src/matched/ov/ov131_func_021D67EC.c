/*
 * function: P_STA_SUB_LoadArcGraphics
 * address:  0x021D67EC
 * packet:   pkt_021D67EC
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020498F4  0x020498F4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

typedef unsigned int   u32;
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

void P_STA_SUB_LoadArcGraphics(u16 *p, int a, void *b)
{
    func_020498F4(b, 0x3e, 2, 0, 0, 0, *p);
}
