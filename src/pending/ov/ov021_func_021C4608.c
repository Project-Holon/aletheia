/*
 * function: func_021C4608
 * address:  0x021C4608
 * packet:   pkt_ov021_021C4608
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
 *   func_021C12C4  0x021C12C4  thumb  ov021
 *   func_021C12D0  0x021C12D0  thumb  ov021
 *   func_0215A64C  0x0215A64C  thumb  ov010
 */

extern void *func_0215A64C(void *a);
extern int func_021C12C4(void *x);
extern void func_021C12D0(void *x);

int func_021C4608(void *a, void *b)
{
    void *x = func_0215A64C(b);

    if (func_021C12C4(x) == 1) {
        func_021C12D0(x);
        return 1;
    }
    return 0;
}
