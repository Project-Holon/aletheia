/*
 * function: func_021BD43C
 * address:  0x021BD43C
 * packet:   pkt_021BD43C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD404  0x021BD404  thumb  ov208
 *
 * Tail call to func_021BD404: the pool word at 0x021BD440 is 0x021BD405, the
 * thumb-bit-set address, and the body is ldr r3, [pc, #0] / bx r3.
 *
 * The earlier "harness gap" note was wrong: without a `symbols:` line the
 * address was only `label`-attested (an outside branch), and the writer then
 * emitted the even 0x021BD404.  Declaring the target `thumb ov208` in the
 * symbols block makes the low (thumb) bit stick and the pool word closes
 * byte-exact.
 */

extern void func_021BD404(void);

void func_021BD43C(void)
{
    func_021BD404();
}
