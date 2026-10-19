/*
 * function: DWCi_CheckDWCServer
 * address:  0x02173BE4
 * packet:   pkt_ov009_02173BE4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CheckDWCServer (dwc_match.o)
 *
 * symbols:
 *   SBServerGetIntValueA  0x0219E120  arm  ov009
 *   g_021A21A4     0x021A21A4  data
 *   g_021A21B0     0x021A21B0  data
 *   g_021A2170     0x021A2170  data
 *   g_021A2164     0x021A2164  data
 *   g_021A20A4     0x021A20A4  data
 */

extern char g_021A21A4[];
extern char g_021A21B0[];
extern char g_021A2170[];
extern char g_021A2164[];
extern char g_021A20A4[];
struct SBServer;
extern int SBServerGetIntValueA(struct SBServer *server, char *key, int idefault);

int DWCi_CheckDWCServer(void *server)
{
    if (SBServerGetIntValueA(server, g_021A21A4, -1) == -1)
        return 0;
    if (SBServerGetIntValueA(server, g_021A21B0, -1) == -1)
        return 0;
    if (SBServerGetIntValueA(server, g_021A2170, -1) == -1)
        return 0;
    if (SBServerGetIntValueA(server, g_021A2164, -1) == -1)
        return 0;
    return SBServerGetIntValueA(server, g_021A20A4, 0);
}
