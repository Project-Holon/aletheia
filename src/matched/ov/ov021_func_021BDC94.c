/*
 * function: func_021BDC94
 * address:  0x021BDC94
 * packet:   pkt_ov021_021BDC94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_021BDD58  0x021BDD58  thumb  ov021
 *   func_021BDD7C  0x021BDD7C  thumb  ov021
 *   func_021BDD9C  0x021BDD9C  thumb  ov021
 */

extern void *func_02188C84(void *a);
extern void *func_021BDD58(void *a);
extern void func_021BDD7C(void *r, void *a);
extern void func_021BDD9C(void *r, void *x);

void *func_021BDC94(void *a)
{
    void *x = func_02188C84(a);
    void *r = func_021BDD58(x);

    func_021BDD7C(r, a);
    func_021BDD9C(r, x);
    return r;
}
