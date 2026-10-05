/*
 * function: func_02154668
 * address:  0x02154668
 * packet:   pkt_ov000_02154668
 * region:   ov000
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Thumb tail call through r3 (ldr r3, =target; bx r3). Labelled in wave D8.
 *
 * symbols:
 *   func_02154670  0x02154670  thumb ov000
 */

extern void *func_02154670(void *p);

void *func_02154668(void *p)
{
    return func_02154670(p);
}
