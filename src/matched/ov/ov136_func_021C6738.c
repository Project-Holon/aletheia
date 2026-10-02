/*
 * function: func_021C6738
 * address:  0x021C6738
 * packet:   pkt_ov136_021C6738
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4         0x020490F4  arm
 */

typedef unsigned char u8;
extern void *func_020490F4(int, int);
void func_021C6738(u8 *p)
{
    *(void **)(p + 0x290) = func_020490F4(7, 0x66);
}
