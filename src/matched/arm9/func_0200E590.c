/*
 * function: func_0200E590
 * address:  0x0200E590
 * packet:   pkt_0200E590
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the 0x5C8-byte save block (func_0200E588 returns its size):
 * a tail call to MI_CpuFill8(p, 0, 0x5C8).
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */

extern void MI_CpuFill8(void *dst, unsigned char val, unsigned long size);

void func_0200E590(void *p)
{
    MI_CpuFill8(p, 0, 0x5C8);
}
