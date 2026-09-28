/*
 * function: func_021EBB1C
 * address:  0x021EBB1C
 * packet:   pkt_ov170_021EBB1C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EBA84 0x021EBA84 thumb
 *
 * Prints message 0x16 into window i.
 */

extern void func_021EBA84(unsigned char *p, int msg, int i);

void func_021EBB1C(unsigned char *p, int i)
{
    func_021EBA84(p, 0x16, i);
}
