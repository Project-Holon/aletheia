/*
 * function: func_02183E50
 * address:  0x02183E50
 * packet:   pkt_02156B70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clear 0x104 bytes at `c`, then fill `c+4` with up to 0x200 bytes through
 * func_021837A4; the byte count it reports is rounded up to a word count and
 * stored at c[0].  Returns 1 when the object validates, 0 when the fill loop
 * reports nothing produced.
 */

typedef unsigned int u32;

extern void func_020923B0(void *p, int c, int n);
extern int func_021837A4(void *a, int b, void *p, int n, u32 *out);
extern int func_0217E934(void *p);

int func_02183E50(void *a, int b, int *c)
{
    u32 n = 0;
    u32 k;

    func_020923B0(c, 0, 0x104);
    if (func_021837A4(a, b, c + 1, 0x200, &n) == 0)
        return 0;

    k = n >> 2;
    c[0] = k;
    if (n & 3)
        c[0] = k + 1;

    if (func_0217E934(c) == 0)
        return 0;
    return 1;
}
