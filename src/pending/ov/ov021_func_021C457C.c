/*
 * function: func_021C457C
 * address:  0x021C457C
 * packet:   pkt_ov021_021C457C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Every concrete byte matches. Blocker: func_0215A64C is an unlabelled ov010
 * Thumb leaf (ldr r0, [r0, #0x20]; ldr r0, [r0, #0x10]; bx lr) with no
 * witness; filing it needs an ov010 write outside this lane.
 *
 * symbols:
 *   func_021C1094  0x021C1094  thumb  ov021
 *   func_021C10A0  0x021C10A0  thumb  ov021
 *   func_0215A64C  0x0215A64C  thumb  ov010
 */

extern void *func_0215A64C(void *a);
extern int func_021C1094(void *x);
extern void func_021C10A0(void *x);

int func_021C457C(void *a, void *b)
{
    void *x = func_0215A64C(b);

    if (func_021C1094(x) == 1) {
        func_021C10A0(x);
        return 1;
    }
    return 0;
}
