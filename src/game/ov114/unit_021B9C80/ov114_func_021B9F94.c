/*
 * function: func_021B9F94
 * address:  0x021B9F94
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BEBE0  0x021BEBE0  arm  ov114
 *   func_021B9ECC  0x021B9ECC  arm  ov114
 *
 * Range submit: maps the sentinel answers of func_021B9ECC onto the module's
 * -1001/-1002/0 return codes.  The null-guard return is the ELSE arm of the
 * first test, which sinks it out of line at 0x021B9FD0.
 */

typedef unsigned char u8;
typedef unsigned int u32;
u8 *func_021BEBE0(int, int);
int func_021B9ECC(void *, int, int, int, int);

int func_021B9F94(int a, u32 *b, int c, int d, int e, int f)
{
    void *p = func_021BEBE0(a, (int)b);
    int r;

    if (p != 0) {
        r = func_021B9ECC(p, c, d, e, f);
    } else {
        return -1001;
    }
    if (r >= 0)
        return r;
    if (*b != 0)
        return -1002;
    if (r == -56)
        return 0;
    return -1001;
}
