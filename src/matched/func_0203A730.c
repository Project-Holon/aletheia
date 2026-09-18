/*
 * function: func_0203A730
 * address:  0x0203A730
 * packet:   pkt_0203A574
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203A67C  0x0203A67C  arm
 *
 * Third word of the object func_0203A67C returns, or 0 when there is none.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A730.c \
 *       --func func_0203A730 --addr 0x0203A730 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 *func_0203A67C(void);

u32 func_0203A730(void)
{
    u32 *q;

    q = func_0203A67C();
    return q ? q[2] : 0;
}
