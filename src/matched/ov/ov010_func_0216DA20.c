/*
 * function: func_0216DA20
 * address: 0x0216DA20
 * packet: pkt_ov010_0216DA20
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0216D67C 0x0216D67C thumb ov010
 *   func_0216D4D4 0x0216D4D4 thumb ov010
 */

extern void *func_0216D67C(void *p);
extern int func_0216D4D4(void *p, unsigned int v);
int func_0216DA20(void *p, unsigned int v)
{
    return func_0216D4D4(func_0216D67C(p), v);
}
