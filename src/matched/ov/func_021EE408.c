/*
 * function: func_021EE408
 * address:  0x021EE408
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EE3E4  0x021EE3E4  thumb  ov170
 *   func_021ECC1C  0x021ECC1C  thumb  ov170
 *
 * Update the sub-object, then rebuild the panel.
 */



extern void func_021EE3E4(int);
extern void func_021ECC1C(int);
void func_021EE408(int p)
{
    func_021EE3E4(p);
    func_021ECC1C(p);
}
