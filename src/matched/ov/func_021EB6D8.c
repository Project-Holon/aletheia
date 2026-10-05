/*
 * function: func_021EB6D8
 * address:  0x021EB6D8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EB378  0x021EB378  thumb  ov170
 *
 * Range call with a fixed span and the caller's fourth value.
 */



extern void func_021EB378(char *p, int idx, unsigned msg, unsigned short frame, unsigned short col, int icon);
void func_021EB6D8(int a, int b, int c, int d)
{
    func_021EB378((char *)a, b, c, 0, 0x3d80, d);
}
