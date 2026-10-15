/*
 * function: ResolveServers
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
 *   ResolveServer  0x02199D1C  arm  ov009
 *   gNatnegGlobals  0x021AE698  data
 *   gNatNegServer1Name  0x021A5CB0  data
 *   gNatNegServer2Name  0x021A5CCC  data
 *   gNatNegServer3Name  0x021A5CE8  data
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

extern NatnegGlobals gNatnegGlobals;
extern char gNatNegServer1Name[];
extern char gNatNegServer2Name[];
extern char gNatNegServer3Name[];
extern unsigned int ResolveServer(char *overrideHostname, char *defaultHostname);

int ResolveServers(void)
{
    if (!gNatnegGlobals.natneg1IP)
        gNatnegGlobals.natneg1IP = ResolveServer(gNatnegGlobals.natneg1Override, gNatNegServer1Name);
    if (!gNatnegGlobals.natneg2IP)
        gNatnegGlobals.natneg2IP = ResolveServer(gNatnegGlobals.natneg2Override, gNatNegServer2Name);
    if (!gNatnegGlobals.natneg3IP)
        gNatnegGlobals.natneg3IP = ResolveServer(gNatnegGlobals.natneg3Override, gNatNegServer3Name);
    if (gNatnegGlobals.natneg1IP == 0 || gNatnegGlobals.natneg2IP == 0 || gNatnegGlobals.natneg3IP == 0)
        return 0;
    return 1;
}
