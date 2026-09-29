/*
 * function: func_021F4020
 * address:  0x021F4020
 * packet:   pkt_ov046_021F4020
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 */

typedef unsigned int u32;
extern u32 func_02188C7C(u32);
extern int func_0216DD1C(u32, int *, int *);
extern int func_0216D588(int);

int func_021F4020(u32 a, int b)
{
    int s1 = 0;
    int s0;
    u32 it = func_02188C7C(a);

    while (func_0216DD1C(it, &s0, &s1) == 1) {
        if (b == func_0216D588(s0))
            return s0;
    }
    return 0;
}
