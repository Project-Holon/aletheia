/*
 * function: CPS_SocFlush
 * address:  0x0215B584
 * packet:   pkt_ov009_0215B584
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPS_SocFlush (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   g_02150FEC  0x02150FEC  data
 *   CPSi_SocWrite2  0x0215B3A0  arm  ov009
 */

extern char g_02150FEC[];
extern unsigned long CPSi_SocWrite2(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2);

void CPS_SocFlush(void)
{
    char *soc = *(char **)(*(char **)(g_02150FEC + 4) + 0xa4);

    if (soc != 0 && *(unsigned long *)(soc + 0x6c) != 0) {
        CPSi_SocWrite2(*(unsigned char **)(soc + 0x68), *(unsigned long *)(soc + 0x6c), 0, 0);
        *(unsigned long *)(soc + 0x6c) = 0;
    }
}
