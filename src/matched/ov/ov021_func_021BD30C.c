/*
 * function: func_021BD30C
 * address:  0x021BD30C
 * packet:   pkt_ov021_021BD30C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD2C0  0x021BD2C0  thumb  ov021
 *   func_021BD2C8  0x021BD2C8  thumb  ov021
 *   func_021BD2B8  0x021BD2B8  thumb  ov021
 *   func_021BD604  0x021BD604  thumb  ov021
 */

extern void *func_021BD2C0(void *p);
extern void *func_021BD2C8(void *p);
extern void *func_021BD2B8(void *p);
extern void func_021BD604(void *a, void *b, void *c, void *d, void *e);

void func_021BD30C(char *p)
{
    void *a;
    void *b;

    a = func_021BD2C0(p);
    b = func_021BD2C8(p);
    func_021BD604(a, b, func_021BD2B8(p), p + 0x40, p + 0x41);
}
