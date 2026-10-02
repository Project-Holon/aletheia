/*
 * function: func_021F3ADC
 * address:  0x021F3ADC
 * packet:   pkt_ov064_021F3ADC
 * region:   ov064
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_021F3BD8  0x021F3BD8  thumb  ov064
 */

extern void *func_0201210C(const void *p);
extern void *func_020122C0(void *owner, void *a, int (*callback)(void *), unsigned int size);
extern int func_021F3BD8(void *p);

void *func_021F3ADC(void *p)
{
    func_0201210C(p);
    return func_020122C0(p, 0, func_021F3BD8, 0);
}
