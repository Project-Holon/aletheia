/*
 * function: func_0215AEB0
 * address:  0x0215AEB0
 * packet:   pkt_ov009_0215AEB0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPS_SocRead (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   func_0215ADC4  0x0215ADC4  arm  ov009
 *   func_021629BC  0x021629BC  arm  ov009
 *   func_0215AE18  0x0215AE18  arm  ov009
 *   g_02150FEC  0x02150FEC  data
 */

extern char g_02150FEC[];
struct CPSSoc;
struct soc;
extern unsigned char *func_0215ADC4(unsigned long *len, struct soc *soc);
extern unsigned char *func_021629BC(unsigned long *len, struct CPSSoc *soc);
extern unsigned char *func_0215AE18(unsigned long *len, char *soc);

unsigned char *func_0215AEB0(unsigned long *len)
{
    char *soc = *(char **)(*(char **)(g_02150FEC + 4) + 0xa4);

    if (soc != 0) {
        if (*(unsigned char *)(soc + 8) == 10 || *(unsigned char *)(soc + 8) == 11)
            return func_0215ADC4(len, (struct soc *)soc);
        if (*(unsigned char *)(soc + 9) != 0)
            return func_021629BC(len, (struct CPSSoc *)soc);
        return func_0215AE18(len, soc);
    }
    *len = 0;
    return 0;
}
