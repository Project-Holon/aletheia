/*
 * function: func_02161BE8
 * address:  0x02161BE8
 * packet:   pkt_ov009_02161BE8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      tcp_read_raw_nbytes (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   func_0215AE18  0x0215AE18  arm  ov009
 *   func_02082D44  0x02082D44  arm
 *   func_0215AF14  0x0215AF14  arm  ov009
 */

struct CPSSoc;

extern unsigned char *func_0215AE18(unsigned long *len, struct CPSSoc *soc);
extern void func_02082D44(const void *srcp, void *dstp, unsigned long size);
extern void func_0215AF14(unsigned long len, struct CPSSoc *soc);

static int func_02161BE8(unsigned char *d, int len, struct CPSSoc *soc)
{
    unsigned long thislen;
    unsigned char *s;

    do {
        s = func_0215AE18(&thislen, soc);
        if (thislen == 0)
            return -1;
        if (thislen > len)
            thislen = len;
        func_02082D44(s, d, thislen);
        func_0215AF14(thislen, soc);
        len -= thislen;
        d += thislen;
    } while (len > 0);
    return 0;
}
