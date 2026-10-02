/*
 * function: func_021F376C
 * address:  0x021F376C
 * packet:   pkt_ov059_021F376C
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897A0  0x021897A0  thumb  ov021
 *   func_021BE418  0x021BE418  thumb  ov021
 */

extern void *func_02188D2C(void *p);
extern void func_021897A0(unsigned char *p, int id);
extern void func_021BE418(unsigned char *p, unsigned short i);

void func_021F376C(unsigned char *p)
{
    void *s;
    s = func_02188D2C(p);
    func_021897A0(p, 1);
    func_021BE418(s, 0);
}
