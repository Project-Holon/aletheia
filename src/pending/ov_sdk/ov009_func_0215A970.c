/*
 * function: func_0215A970
 * address:  0x0215A970
 * packet:   pkt_ov009_0215A970
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker:  28 of 168 bytes differ, register naming only: original keeps the
 *           thread-list head in r0 and the port base in r2, the compile puts them
 *           in lr and r1. Tried all declaration orders and a hoisted head local.
 *
 * sdk:      CPS_SocGetEport (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   g_02150FEC  0x02150FEC  data
 *   g_021A826C  0x021A826C  data
 */

struct net_vars {
    char pad[6];
    unsigned short eport;
};

extern char g_02150FEC[];
extern struct net_vars g_021A826C;

unsigned short func_0215A970(void)
{
    unsigned long conflict;
    char *soc;
    char *t;

    do {
        conflict = 0;
        g_021A826C.eport = g_021A826C.eport + 1;
        if (g_021A826C.eport < 0x400 || g_021A826C.eport >= 5000)
            g_021A826C.eport = 0x400;
        for (t = *(char **)(g_02150FEC + 8); t != 0; t = *(char **)(t + 0x68)) {
            soc = *(char **)(t + 0xa4);
            if (soc != 0 && *(unsigned long *)soc != 0) {
                if (*(unsigned short *)(soc + 0xa) == g_021A826C.eport) {
                    conflict = 1;
                    break;
                }
            }
        }
    } while (conflict != 0);
    return g_021A826C.eport;
}
