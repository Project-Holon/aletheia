/*
 * function: func_0218B2E8
 * address:  0x0218B2E8
 * packet:   pkt_ov021_0218B2E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626B0  0x021626B0  thumb  ov010
 *   func_02185360  0x02185360  thumb  ov020
 */

typedef unsigned short u16;

extern void *func_021625CC(char *p, unsigned i);
extern u16 func_021626B0(void *b, void *q);
extern void *func_02185360(void *p, int u, int a, int b);

int func_0218B2E8(char *p, void *x, int a, int *b)
{
    void *obj = func_021625CC(*(void **)(p + 0xc), (u16)a);
    return (int)func_02185360(*(void **)(p + 4), (int)x, (int)obj, func_021626B0(obj, b));
}
