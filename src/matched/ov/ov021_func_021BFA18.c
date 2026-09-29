/*
 * function: func_021BFA18
 * address:  0x021BFA18
 * packet:   pkt_ov021_021BFA18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE92C 0x021BE92C thumb ov021
 *   func_021BE9A0 0x021BE9A0 thumb ov021
 *   func_021BFA5C 0x021BFA5C thumb ov021
 */

typedef unsigned char u8;

extern void *func_021BE92C(int, int, int, int, int, int, int);
extern void *func_021BE9A0(int, int, int, int, void (*)(u8 *), int *);
extern void func_021BFA5C(u8 *);

void *func_021BFA18(int *q)
{
    int c = q[23];
    int a = q[0];
    int b = q[1];

    if (c != 0) {
        return func_021BE9A0(a, b, (u8)q[24], (u8)q[25], func_021BFA5C, q);
    }
    return func_021BE92C(a, b, 1, 1, 1, 0, 0);
}
