/*
 * function: func_021D94A0
 * address:  0x021D94A0
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Arm or re-arm the three receivers depending on the object state.
 *
 * symbols:
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021E36D8  0x021E36D8  thumb  ov119
 *   func_021E2438  0x021E2438  thumb  ov119
 *   func_021E62D4  0x021E62D4  thumb  ov119
 */

extern int func_021D8AA8(void *p);
extern void func_021E36D8(void *p, int a);
extern void func_021E2438(void *p, int a);
extern void func_021E62D4(void *p, int a, int i);

void func_021D94A0(void *p, int a)
{
    int i;

    if (func_021D8AA8(p) == 0) {
        func_021E36D8(p, a);
        func_021E2438(p, a);
        return;
    }
    for (i = 0; i < 3; i++)
        func_021E62D4(p, a, i);
}

