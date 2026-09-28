/*
 * function: func_0215AC60
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
 *   func_02162968  0x02162968  arm  ov009
 *   func_0215ABB0  0x0215ABB0  arm  ov009
 */

extern char g_02150FEC[];
extern unsigned long func_02162968(void *soc);
extern unsigned long func_0215ABB0(void *soc);

unsigned long func_0215AC60(void)
{
    char *soc = *(char **)(*(char **)(g_02150FEC + 4) + 0xa4);

    if (soc != 0) {
        if (*(unsigned char *)(soc + 9) != 0)
            return func_02162968(soc);
        return func_0215ABB0(soc);
    }
    return 1;
}
