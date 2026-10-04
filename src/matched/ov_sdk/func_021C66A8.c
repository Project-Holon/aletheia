/*
 * function: func_021C66A8
 * address:  0x021C66A8
 * packet:   pkt_021C66A8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C66A8   0x021C66A8  arm
 *   func_021BD1D4   0x021BD1D4  arm  ov016
 *   dat_021DB458    0x021DB458  data
 *   dat_0207E51C    0x0207E51C  data
 *   dat_021DB46C    0x021DB46C  data
 *   dat_0207F0B8    0x0207F0B8  data
 *   dat_021DB484    0x021DB484  data
 *   dat_0207E3D0    0x0207E3D0  data
 *   dat_021DB49C    0x021DB49C  data
 *   dat_0207EB78    0x0207EB78  data

 *
 * Load 4 tilemaps through func_021BD1D4, then set the low two bits of five
 * halfword registers (the 0x04001008/0x04000008 pair and their +2 neighbours).
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

extern void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern unsigned short dat_021DB458[];
extern unsigned short dat_0207E51C[];
extern unsigned short dat_021DB46C[];
extern unsigned short dat_0207F0B8[];
extern unsigned short dat_021DB484[];
extern unsigned short dat_0207E3D0[];
extern unsigned short dat_021DB49C[];
extern unsigned short dat_0207EB78[];

void func_021C66A8(void)
{
    u16 *p;

    func_021BD1D4((char *)((int)dat_021DB458), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207E51C));
    func_021BD1D4((char *)((int)dat_021DB46C), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207F0B8));
    func_021BD1D4((char *)((int)dat_021DB484), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207E3D0));
    func_021BD1D4((char *)((int)dat_021DB49C), (void (*)(void *, long unsigned int,  long unsigned int))((int)dat_0207EB78));
    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x04000008;
    p[0] = (p[0] & ~3) | 2;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}
