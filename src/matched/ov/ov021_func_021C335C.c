/*
 * function: func_021C335C
 * address:  0x021C335C
 * packet:   pkt_ov021_021C335C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stops the running timer and closes the record.
 *
 * symbols:
 *   func_0200BCA0  0x0200BCA0  thumb
 *   func_0200BC20  0x0200BC20  thumb
 *   func_021C33E0  0x021C33E0  thumb  ov021
 */

struct Obj11233;
extern int func_0200BCA0(struct Obj11233 *p);
struct Obj11232;
extern void func_0200BC20(struct Obj11232 *p);
extern void func_021C33E0(void *a);

void func_021C335C(void **p)
{
    if (func_0200BCA0(p[2]) == 1) {
        func_0200BC20(p[2]);
        func_021C33E0(p[1]);
    }
}
