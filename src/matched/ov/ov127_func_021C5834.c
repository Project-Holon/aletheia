/*
 * function: func_021C5834
 * address:  0x021C5834
 * packet:   pkt_ov127_021C5834
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub: ldr r0,[r0,#4]; ldr r3,=func_021C425C; bx r3.
 * Blocker of ov099 func_021BA2D4.
 *
 * symbols:
 *   func_021C425C  0x021C425C  thumb  ov127
 */

extern int func_021C425C(char *p);

int func_021C5834(char *p)
{
    return func_021C425C(*(void **)(p + 4));
}
