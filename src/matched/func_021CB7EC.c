/*
 * function: func_021CB7EC
 * address:  0x021CB7EC
 * packet:   pkt_021CB7EC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CB7EC   0x021CB7EC  arm
 *   func_021BD1D4   0x021BD1D4  arm  ov016
 *   dat_021DB6C4    0x021DB6C4  data
 *   dat_021DB6DC    0x021DB6DC  data
 *   dat_021DB6F4    0x021DB6F4  data
 *   dat_0207F0B8    0x0207F0B8  data
 *   dat_0207E3D0    0x0207E3D0  data
 *   dat_0207EB78    0x0207EB78  data
 *
 * Load three tilemaps through func_021BD1D4, then set the low two bits of five
 * halfword registers (the 0x04001008/0x04000008 pair and their +2 neighbours).
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

extern void func_021BD1D4(int, int);
extern unsigned short dat_021DB6C4[];
extern unsigned short dat_021DB6DC[];
extern unsigned short dat_021DB6F4[];
extern unsigned short dat_0207F0B8[];
extern unsigned short dat_0207E3D0[];
extern unsigned short dat_0207EB78[];

void func_021CB7EC(void)
{
    u16 *p;

    func_021BD1D4((int)dat_021DB6C4, (int)dat_0207F0B8);
    func_021BD1D4((int)dat_021DB6DC, (int)dat_0207E3D0);
    func_021BD1D4((int)dat_021DB6F4, (int)dat_0207EB78);

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x04000008;
    p[0] = (p[0] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}
