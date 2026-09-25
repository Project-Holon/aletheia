/*
 * function: func_021D7B34
 * address:  0x021D7B34
 * packet:   pkt_021D7B34
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */

extern void func_020307B0(void *);

void func_021D7B34(int a, char *p)
{
    func_020307B0(*(void **)(p + 8));
    func_020307B0(p);
}
