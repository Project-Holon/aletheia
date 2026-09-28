/*
 * function: func_021803BC
 * address:  0x021803BC
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Bounded copy helper used by gpiProcessSearch: measure src with the ARM9
 * length helper, clamp to n-1, copy, NUL-terminate, return the byte count.
 * (A strlcpy-shaped helper.)
 *
 * symbols:
 *   func_0209477C  0x0209477C  arm
 *   func_02092344  0x02092344  arm
 */

extern int func_0209477C(const char *s);
extern void func_02092344(void *dst, const void *src, int n);

int func_021803BC(char *dst, const char *src, unsigned int n)
{
    unsigned int len = func_0209477C(src);

    if (len > n - 1)
        len = n - 1;
    func_02092344(dst, src, len);
    dst[len] = 0;
    return len;
}
