/*
 * function: func_021EEF68
 * address:  0x021EEF68
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EE408  0x021EE408  thumb  ov170
 *
 * Run the attached handler unless the key is 0x21.
 */



extern void func_021EE408(int);
void func_021EEF68(int a, int b)
{
    if (b != 0x21)
        func_021EE408(a);
}
