/*
 * function: CPS_TcpConnect
 * address:  0x0215AC60
 * packet:   pkt_ov009_0215AC60
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPS_TcpConnect (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   g_02150FEC  0x02150FEC  data
 *   CPSi_SslConnect  0x02162968  arm  ov009
 *   CPSi_TcpConnectRaw  0x0215ABB0  arm  ov009
 */

extern char g_02150FEC[];
struct CPSSoc;
struct Soc;
extern unsigned long CPSi_SslConnect(struct CPSSoc *soc);
extern unsigned long CPSi_TcpConnectRaw(struct Soc *soc);

unsigned long CPS_TcpConnect(void)
{
    char *soc = *(char **)(*(char **)(g_02150FEC + 4) + 0xa4);

    if (soc != 0) {
        if (*(unsigned char *)(soc + 9) != 0)
            return CPSi_SslConnect((struct CPSSoc *)soc);
        return CPSi_TcpConnectRaw((struct Soc *)soc);
    }
    return 1;
}
