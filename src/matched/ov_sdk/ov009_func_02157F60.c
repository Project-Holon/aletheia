/*
 * function: arprequest
 * address:  0x02157F60
 * packet:   pkt_ov009_02157F60
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      arprequest (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   send_arprequest  0x02157E54  arm  ov009
 *   OS_Sleep  0x02085A38  arm
 *   inq_arpcache  0x02157D8C  arm  ov009
 *   gCpsRetryDelays  0x021A1CA8  data
 *   gCpsNetVars  0x021A826C  data
 */

extern unsigned long gCpsRetryDelays[];
extern char gCpsNetVars[];
extern void send_arprequest(unsigned long ip);
extern void OS_Sleep(unsigned long msec);
extern unsigned char *inq_arpcache(unsigned long ip);

unsigned long arprequest(unsigned long ip)
{
    unsigned long retry1;
    unsigned long retry2;
    unsigned long r;

    for (retry1 = 0; retry1 < 6; retry1++) {
        send_arprequest(ip);
        for (retry2 = 0; retry2 < gCpsRetryDelays[retry1] / 100; retry2++) {
            if (*(unsigned long *)(gCpsNetVars + 0x50) == 0)
                return 0;
            OS_Sleep(100);
            r = (long unsigned int)inq_arpcache(ip);
            if (r != 0)
                return r;
        }
    }
    return 0;
}
