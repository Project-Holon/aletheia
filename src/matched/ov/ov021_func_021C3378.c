/*
 * function: func_021C3378
 * address:  0x021C3378
 * packet:   pkt_ov021_021C3378
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Advances the timer; on completion stops it and closes the record.
 *
 * symbols:
 *   func_0200BD48  0x0200BD48  thumb
 *   func_021C385C  0x021C385C  thumb  ov021
 *   func_0200BC10  0x0200BC10  thumb
 *   func_021C33A4  0x021C33A4  thumb  ov021
 */

extern void func_0200BD48(void *a, int b);
extern int func_021C385C(void **p);
extern void func_0200BC10(void *a);
extern void func_021C33A4(void *a);

int func_021C3378(void **p)
{
    func_0200BD48(p[2], 1);
    if (func_021C385C(p) == 1) {
        func_0200BC10(p[2]);
        func_021C33A4(p[1]);
        return 1;
    }
    return 0;
}
