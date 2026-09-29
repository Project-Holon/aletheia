/*
 * function: func_021D0824
 * address:  0x021D0824
 * packet:   pkt_ov021_021D0824
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021D0914  0x021D0914  thumb  ov021
 */

typedef short s16;
typedef long long s64;

extern void func_0216D88C(int a, int *out);
extern int func_021D0914(int a, s16 *v);

void func_021D0824(int *p, int a)
{
    s16 v[3];
    int k;

    p[0] = 1;
    p[1] = 0;
    func_0216D88C(a, p + 2);
    if (func_021D0914(a, v) == 0) {
        k = 0xE000;
    } else {
        k = 1 << 14;
    }
    p[3] += 0x7000;
    p[2] += (int)(((s64)v[0] * k + 0x800) >> 12);
    p[4] += (int)(((s64)v[2] * k + 0x800) >> 12);
}
