/*
 * function: func_021C457C
 * address:  0x021C457C
 * packet:   pkt_ov021_021C457C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   func_021C1094  0x021C1094  thumb  ov021
 *   func_021C10A0  0x021C10A0  thumb  ov021
 *   func_0215A64C  0x0215A64C  thumb  ov010
 */

extern void *func_0215A64C(void *a);
extern int func_021C1094(void *x);
typedef unsigned int   u32;
extern int func_021C10A0(u32 a);

int func_021C457C(void *a, void *b)
{
    void *x = func_0215A64C(b);

    if (func_021C1094(x) == 1) {
        func_021C10A0((u32)x);
        return 1;
    }
    return 0;
}
