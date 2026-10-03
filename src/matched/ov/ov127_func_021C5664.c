/*
 * function: func_021C5664
 * address:  0x021C5664
 * packet:   pkt_021C5664
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C4044  0x021C4044  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
extern void func_021C4044(u8 *p, int a, int b, int c, int d);

void func_021C5664(char *p, int a, int b)
{
    func_021C4044(*(void **)p, *(unsigned char *)(p + 0xb), a, 0, b);
}
