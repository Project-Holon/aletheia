/*
 * function: func_021C57E8
 * address:  0x021C57E8
 * packet:   pkt_ov127_021C57E8
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub: ldr r0,[r0,#4]; ldr r3,=func_021C42C4; bx r3.
 * Blocker of ov099 func_021BA2D4.
 *
 * symbols:
 *   func_021C42C4  0x021C42C4  thumb  ov127
 */

typedef unsigned char  u8;
extern void func_021C42C4(u8 *p);

void func_021C57E8(char *p)
{
    func_021C42C4(*(void **)(p + 4));
}
