/*
 * function: func_02173408
 * address:  0x02173408
 * packet:   pkt_ov012_02173408
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     unlabelled leaf (prints as .word in ov012.s); called from
 *           ov019 func_0217E904.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 */

typedef unsigned char u8;

void func_02082BCC(void *p, int v, int n);

void func_02173408(u8 *w)
{
    func_02082BCC(w + 0x2910, 0, 0x578);
}
