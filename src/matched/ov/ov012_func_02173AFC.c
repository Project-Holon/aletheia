/*
 * function: func_02173AFC
 * address:  0x02173AFC
 * packet:   pkt_ov012_02173AFC
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *
 * Opens with push {r0-r3} before the listing's func_02173AFE label: the
 * address of the register parameter is taken. Blocker of ov019
 * func_0217BE64's two calls.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 func_020399A8(void);
extern int func_0203D3A8(u32 a, u32 b, u32 c, void *d);

int func_02173AFC(int v)
{
    return func_0203D3A8(func_020399A8(), 0x1404, 4, &v);
}
