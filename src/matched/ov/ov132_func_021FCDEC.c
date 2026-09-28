/*
 * function: func_021FCDEC
 * address:  0x021FCDEC
 * packet:   pkt_021FCDEC
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *
 * Addresses are Black-image addresses.
 */

extern int func_020399A8(int);
extern void func_02039C68(int, int, int);

void func_021FCDEC(int a, int b)
{
    func_02039C68(func_020399A8(a), b, 0x11);
}
