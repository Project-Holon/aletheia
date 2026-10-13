/*
 * function: NHTTPi_SocRecv
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
 *   NHTTPi_Request2Connection  0x021BEBE0  arm  ov114
 *   NHTTPi_SocRecv_sub  0x021B9ECC  arm  ov114
 *
 * Range submit: maps the sentinel answers of NHTTPi_SocRecv_sub onto the module's
 * -1001/-1002/0 return codes.  The null-guard return is the ELSE arm of the
 * first test, which sinks it out of line at 0x021B9FD0.
 */

typedef unsigned char u8;
typedef unsigned int u32;
u8 *NHTTPi_Request2Connection(int, int);
int NHTTPi_SocRecv_sub(void *, int, int, int, int);

int NHTTPi_SocRecv(int a, u32 *b, int c, int d, int e, int f)
{
    void *p = NHTTPi_Request2Connection(a, (int)b);
    int r;

    if (p != 0) {
        r = NHTTPi_SocRecv_sub(p, c, d, e, f);
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
