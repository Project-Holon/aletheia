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
 *   CPSi_TcpReadRaw  0x0215AE18  arm  ov009
 *   MI_CpuCopy8  0x02082D44  arm
 *   CPSi_SocConsumeRaw  0x0215AF14  arm  ov009
 */

struct CPSSoc;

struct _CPSSoc;
extern unsigned char *CPSi_TcpReadRaw(unsigned long *len, char *soc);
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);
extern void CPSi_SocConsumeRaw(unsigned long len, struct _CPSSoc *soc);

static int func_02161BE8(unsigned char *d, int len, struct CPSSoc *soc)
{
    unsigned long thislen;
    unsigned char *s;

    do {
        s = CPSi_TcpReadRaw(&thislen, (char *)soc);
        if (thislen == 0)
            return -1;
        if (thislen > len)
            thislen = len;
        MI_CpuCopy8(s, d, thislen);
        CPSi_SocConsumeRaw(thislen, (struct _CPSSoc *)soc);
        len -= thislen;
        d += thislen;
    } while (len > 0);
    return 0;
}
