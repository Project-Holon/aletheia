/*
 * function: func_021C5840
 * address:  0x021C5840
 * packet:   pkt_ov127_021C5840
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub: ldr r0,[r0,#4]; ldr r3,=func_021C4230; bx r3.
 * (ov093 labels a different function at this address.)
 * Blocker of ov099 func_021BA2D4.
 *
 * symbols:
 *   func_021C4230  0x021C4230  thumb  ov127
 */

extern void func_021C4230(void *p, int a);

void func_021C5840(char *p, int a)
{
    func_021C4230(*(void **)(p + 4), a);
}
