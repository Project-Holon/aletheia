/*
 * function: func_02186564
 * address:  0x02186564
 * packet:   pkt_ov023_02186564
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_02040588  0x02040588  arm
 */

typedef unsigned short u16;

typedef unsigned int   u32;
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_02040588(unsigned char which, unsigned char enable);

void func_02186564(void)
{
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
    func_02040588(0, 1);
    func_02040588(1, 1);
    func_02040588(2, 1);
    func_02040588(4, 1);
    func_02040588(5, 1);
    *(volatile u16 *)0x04000304 = *(volatile u16 *)0x04000304 & 0xFFFF7FFF;
}
