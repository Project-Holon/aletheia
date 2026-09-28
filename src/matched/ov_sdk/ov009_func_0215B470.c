/*
 * function: func_0215B470
 * address:  0x0215B470
 * packet:   pkt_ov009_0215B470
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPS_SocWrite (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   func_0215B3A0  0x0215B3A0  arm  ov009
 *   func_02083194  0x02083194  arm
 *   g_02150FEC  0x02150FEC  data
 */

extern char g_02150FEC[];
extern unsigned long func_0215B3A0(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2);
extern void func_02083194(void *src, void *dst, unsigned long size);

unsigned long func_0215B470(unsigned char *buf, unsigned long len)
{
    char *soc = *(char **)(*(char **)(g_02150FEC + 4) + 0xa4);
    unsigned long pend;
    unsigned long n;
    unsigned long left;

    if (soc != 0) {
        pend = *(unsigned long *)(soc + 0x6c);
        if (pend != 0) {
            n = func_0215B3A0(*(unsigned char **)(soc + 0x68), pend, buf, len);
            left = *(unsigned long *)(soc + 0x6c);
            if (n >= left) {
                *(unsigned long *)(soc + 0x6c) = 0;
                return n - left;
            }
            func_02083194(*(unsigned char **)(soc + 0x68) + n, *(unsigned char **)(soc + 0x68), left - n);
            *(unsigned long *)(soc + 0x6c) = *(unsigned long *)(soc + 0x6c) - n;
            return 0;
        }
        return func_0215B3A0(buf, len, 0, 0);
    }
    return 0;
}
