/*
 * function: func_021F9CA4
 * address:  0x021F9CA4
 * packet:   pkt_021F9CA4
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 */

extern void func_02082BCC(void *, int, int);

void func_021F9CA4(void *p)
{
    func_02082BCC(p, 0, 0x10);
    *(int *)((char *)p + 0xc) = -1;
}
