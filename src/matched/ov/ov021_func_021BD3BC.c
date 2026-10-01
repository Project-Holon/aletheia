/*
 * function: func_021BD3BC
 * address:  0x021BD3BC
 * packet:   pkt_ov021_021BD3BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD2D8  0x021BD2D8  thumb  ov021
 *   func_021BD3EC  0x021BD3EC  thumb  ov021
 *   func_021BD430  0x021BD430  thumb  ov021
 *   func_021BD5D4  0x021BD5D4  thumb  ov021
 *   func_021BD340  0x021BD340  thumb  ov021
 *   func_021BD47C  0x021BD47C  thumb  ov021
 */

extern int func_021BD2D8(void *p);
extern void func_021BD3EC(void *p);
extern void func_021BD430(void *p);
extern void func_021BD5D4(void *p);
extern int func_021BD340(void *p);
extern void func_021BD47C(void *p);

void func_021BD3BC(void *p)
{
    if (func_021BD2D8(p)) {
        func_021BD3EC(p);
        func_021BD430(p);
        func_021BD5D4(p);
        if (func_021BD340(p) == 1) {
            func_021BD47C(p);
        }
    }
}
