/*
 * function: func_021DF404
 * address:  0x021DF404
 * packet:   pkt_ov093_021DF404
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8408  0x021C8408  thumb  ov093
 */
typedef unsigned char u8;
extern int func_021D775C(int);
extern void func_021C8408(u8 *, int);
void func_021DF404(int a, u8 *b, int c)
{
    if (c == func_021D775C(2))
        func_021C8408(b, c);
}
