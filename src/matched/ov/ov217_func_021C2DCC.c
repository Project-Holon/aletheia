/*
 * function: func_021C2DCC
 * address:  0x021C2DCC
 * packet:   pkt_021C2DCC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

extern void func_02082BCC(void *, int, int);

void func_021C2DCC(char *p)
{
    u16 t = *(u16 *)p;
    func_02082BCC(p, 0, 0x20);
    *(u16 *)p = t;
}
