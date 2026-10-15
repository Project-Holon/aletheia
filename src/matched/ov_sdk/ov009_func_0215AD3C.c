/*
 * function: CPS_TcpClose
 * address:  0x0215AD3C
 * packet:   pkt_ov009_0215AD3C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPS_TcpClose (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   CPSi_SslClose  0x02162E5C  arm  ov009
 *   func_020870D0  0x020870D0  arm
 *   func_02157390  0x02157390  arm  ov009
 *   g_02150FEC  0x02150FEC  data
 *   g_021A826C  0x021A826C  data
 */

extern char g_02150FEC[];
extern char g_021A826C[];
extern void CPSi_SslClose(void *soc);
extern unsigned long long func_020870D0(void);
extern void func_02157390(void);

void CPS_TcpClose(void)
{
    unsigned long start;
    char *soc = *(char **)(*(char **)(g_02150FEC + 4) + 0xa4);

    if (soc == 0)
        return;
    if (*(unsigned char *)(soc + 9) != 0)
        CPSi_SslClose(soc);
    start = (unsigned long)(func_020870D0() >> 16);
    while ((*(int (**)(void))(g_021A826C + 0x18))() != 0 && *(unsigned char *)(soc + 8) != 0 &&
           (int)((unsigned long)(func_020870D0() >> 16) - start) < 0x27)
        func_02157390();
    *(unsigned char *)(soc + 8) = 0;
}
