/*
 * function: func_021EBD90
 * address:  0x021EBD90
 * packet:   pkt_ov093_021EBD90
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EB670  0x021EB670  thumb  ov093
 *   d_021F38D0  0x021F38D0  data  a4
 */

typedef unsigned char u8;

extern int func_021EB670(u8 *, int *);
extern int (*const d_021F38D0[])(u8 *, int *);


int func_021EBD90(int *a, u8 *b)
{
    if (b[0x150] != 0)
        return func_021EB670(b, a);
    if (b[0x14f] < 3) {
        if (d_021F38D0[b[0x14f]](b, a) != 0) {
            b[0x14f] = b[0x14f] + 1;
            *a = 0;
        }
        return 0;
    }
    return 1;
}
