/*
 * function: func_021D1BD8
 * address:  0x021D1BD8
 * packet:   pkt_ov021_021D1BD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_021A0ED4  0x021A0ED4  thumb  ov021
 *   func_021A0F30  0x021A0F30  thumb  ov021
 *   func_02159168  0x02159168  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 func_02158F58(u32 a);
extern u32 func_02188CCC(u32 a);
extern int func_021A0ED4(u32 a);
extern void func_021A0F30(u32 a, u32 b);
extern void func_02159168(u32 a);

int func_021D1BD8(u32 *a, int *seq)
{
    u32 r4;

    r4 = func_02188CCC(((u32 *)func_02158F58(a[2]))[1]);
    switch (*seq) {
    case 0:
        if (func_021A0ED4(r4)) {
            func_021A0F30(r4, 0);
            func_02159168(8);
            (*seq)++;
        }
        break;
    case 1:
        if (func_021A0ED4(r4)) {
            return 1;
        }
        break;
    }
    return 0;
}
