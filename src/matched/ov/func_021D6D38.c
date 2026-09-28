/*
 * function: func_021D6D38
 * address:  0x021D6D38
 * packet:   pkt_021D6D38
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02082BCC  0x02082BCC  arm
 *
 * Addresses are Black-image addresses.
 */

extern void func_020307B0(void *);
extern void func_02082BCC(void *, int, int);

void func_021D6D38(void *p)
{
    func_020307B0(*(void **)((char *)p + 8));
    func_02082BCC(p, 0, 0x10);
}
