/*
 * function: func_021B8F90
 * address:  0x021B8F90
 * packet:   pkt_ov070_021B8F90
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub (00 4b 18 47 + pool word) after func_021B8F68;
 * installed as a callback by func_021B7250 and at 0x021B85E0.
 *
 * symbols:
 *   func_021B8AF4  0x021B8AF4  thumb  ov070
 */

extern void func_021B8AF4(void *o);

void func_021B8F90(void *o)
{
    func_021B8AF4(o);
}
