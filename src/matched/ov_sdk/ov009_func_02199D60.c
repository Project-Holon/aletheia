/*
 * function: func_02199D60
 * address:  0x02199D60
 * packet:   pkt_ov009_02199D60
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ResolveServers (natneg.o)
 *
 * symbols:
 *   func_02199D1C  0x02199D1C  arm  ov009
 *   g_021AE698  0x021AE698  data
 *   g_021A5CB0  0x021A5CB0  data
 *   g_021A5CCC  0x021A5CCC  data
 *   g_021A5CE8  0x021A5CE8  data
 */

typedef struct {
    int pad0;
    char *natneg3Override;
    int pad8[4];
    char *natneg2Override;
    char *natneg1Override;
    int pad20;
    int natneg3IP;
    int natneg2IP;
    int natneg1IP;
} NatnegGlobals;

extern NatnegGlobals g_021AE698;
extern char g_021A5CB0[];
extern char g_021A5CCC[];
extern char g_021A5CE8[];
extern unsigned int func_02199D1C(char *overrideHostname, char *defaultHostname);

int func_02199D60(void)
{
    if (!g_021AE698.natneg1IP)
        g_021AE698.natneg1IP = func_02199D1C(g_021AE698.natneg1Override, g_021A5CB0);
    if (!g_021AE698.natneg2IP)
        g_021AE698.natneg2IP = func_02199D1C(g_021AE698.natneg2Override, g_021A5CCC);
    if (!g_021AE698.natneg3IP)
        g_021AE698.natneg3IP = func_02199D1C(g_021AE698.natneg3Override, g_021A5CE8);
    if (g_021AE698.natneg1IP == 0 || g_021AE698.natneg2IP == 0 || g_021AE698.natneg3IP == 0)
        return 0;
    return 1;
}
