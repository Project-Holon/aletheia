/*
 * function: func_021BD43C
 * address:  0x021BD43C
 * packet:   pkt_021BD43C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   (none)
 *
 * Tail call to func_021BD404: the pool word at 0x021BD440 is 0x021BD405, the
 * thumb-bit-set address, and the body is ldr r3, [pc, #0] / bx r3.
 *
 * BLOCKED.  Harness gap: match.py resolves the ABS32 pool word through the
 * `label` class and writes the even function address 0x021BD404, so exactly
 * one byte (the pool word's low byte) differs from the original 0x021BD405.
 * The same shape with a thumb target that carries an independent witness
 * (func_021BD7FC / func_021BD808) closes EXACT, so only the ov208-internal
 * thumb label is affected.
 */

extern void func_021BD404(void);

void func_021BD43C(void)
{
    func_021BD404();
}
