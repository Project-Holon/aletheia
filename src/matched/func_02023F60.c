/*
 * function: func_02023F60
 * address:  0x02023F60
 * packet:   pkt_02023DDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D658  0x0207D658  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern void func_0207D658(u32 reg, u32 a1, u32 a2);
extern void func_02023F98(u32 mask);

void func_02023F60(u32 a0, u32 a1, u32 mask)
{
    if (mask & 1) {
        func_0207D658(0x04000050, a1, a0);
    }
    if (mask & 2) {
        func_0207D658(0x04001050, a1, a0);
    }
    func_02023F98(mask);
}
