/*
 * function: func_02155160
 * address:  0x02155160
 * packet:   pkt_ov009_02155160
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled 4-byte forwarder at the very start of ov009 ("ldr r3, =func_02156DFC;
 * bx r3" plus its pool word); the listing prints it as .word data.  Its
 * only reference is the pointer word 0x02155161 at ov009 0x021A1B80, the
 * first slot of the overlay's function table.
 *
 * symbols:
 *   func_02156DFC  0x02156DFC  thumb  ov009
 */

extern void func_02156DFC(int a);

void func_02155160(int a)
{
    func_02156DFC(a);
}
