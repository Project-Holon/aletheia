/*
 * function: func_021EC048
 * address:  0x021EC048
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Tail call with the table word at the pooled offset.
 */



extern void func_0204B800(int, int);
void func_021EC048(char *p, int i, int c)
{
    func_0204B800(*(int *)(p + i * 4 + 0x9E74), (unsigned char)c);
}
