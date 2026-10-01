/*
 * function: func_02018198
 * address:  0x02018198
 * packet:   pkt_02018198
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb tail-call stub after func_020180FC (ldr r3, =func_020181A0;
 * bx r3). Filed as the witness for ov021 func_021C4340.
 *
 * symbols:
 *   func_020181A0  0x020181A0  thumb
 */

extern void func_020181A0(void *mon);

void func_02018198(void *mon)
{
    func_020181A0(mon);
}
