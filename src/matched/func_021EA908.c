/*
 * function: func_021EA908
 * address:  0x021EA908
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DF110  0x021DF110  thumb  ov170
 *
 * candidate func_021EA908: xor bit
 */


extern void func_021DF110(int, int);
void func_021EA908(int p, int bit)
{
    *(int *)(*(int *)(p + 0x2c) + 0xA174) ^= 1 << bit;
    func_021DF110(p, *(int *)(*(int *)(p + 0x2c) + 0xA174));
}

