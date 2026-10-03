/*
 * function: func_021D1AEC
 * address:  0x021D1AEC
 * packet:   pkt_ov021_021D1AEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A0ED4  0x021A0ED4  thumb  ov021
 *   func_021A0F30  0x021A0F30  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern int func_021A0ED4(u32 a);
extern int func_021A0F30(u32 a, u32 b);

int func_021D1AEC(int a, int *seq, u32 *c)
{
    switch (*seq) {
    case 0:
        if (func_021A0ED4(c[0])) {
            func_021A0F30(c[0], c[1]);
            (*seq)++;
        }
        break;
    case 1:
        if (func_021A0ED4(c[0])) {
            return 1;
        }
        break;
    }
    return 0;
}
