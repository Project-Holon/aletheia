/*
 * function: func_021BB11C
 * address:  0x021BB11C
 * packet:   pkt_ov021_021BB11C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void func_020307B0(void *p);

void func_021BB11C(u32 *p)
{
    if (p[0] != 0) {
        func_020307B0((void *)p[3]);
        func_020307B0((void *)p[0]);
        p[2] = 0;
        p[3] = 0;
        p[0] = 0;
    }
}
