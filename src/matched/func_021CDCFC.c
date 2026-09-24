/*
 * function: func_021CDCFC
 * address:  0x021CDCFC
 * packet:   pkt_021CDCFC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CDCFC   0x021CDCFC  arm
 *   func_021BD1D4   0x021BD1D4  arm  ov016
 *   dat_021DB83C    0x021DB83C  data
 *   dat_021DB854    0x021DB854  data
 *   dat_021DB86C    0x021DB86C  data
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
extern unsigned short dat_021DB83C[];
extern unsigned short dat_021DB854[];
extern unsigned short dat_021DB86C[];
extern unsigned short dat_0207F0B8[];
extern unsigned short dat_0207E3D0[];
extern unsigned short dat_0207EB78[];

void func_021CDCFC(void)
{
    u16 *p;

    func_021BD1D4((int)dat_021DB83C, (int)dat_0207F0B8);
    func_021BD1D4((int)dat_021DB854, (int)dat_0207E3D0);
    func_021BD1D4((int)dat_021DB86C, (int)dat_0207EB78);

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x04000008;
    p[0] = (p[0] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}
