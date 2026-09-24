/*
 * function: func_021DCFFC
 * address:  0x021DCFFC
 * packet:   pkt_021DCFFC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Tail call: clears the second and third arguments to 0 and 0x20 and
 *  *  hands r0 straight to 0x02082BCC (arm9); no lr save, so the call is a
 *  *  pooled `ldr r3; bx r3`.
 */

typedef unsigned long u32;

extern void func_02082BCC(void *p, int a, int len);

void func_021DCFFC(void *p)
{
    func_02082BCC(p, 0, 0x20);
}

