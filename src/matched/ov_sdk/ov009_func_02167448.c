/*
 * function: WcmWmcbEndScan
 * address:  0x02167448
 * packet:   pkt_ov009_02167448
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WcmWmcbEndScan (wmif.o)
 *
 * symbols:
 *   WCMi_SetPhase                    0x02165a4c arm
 *   WCMi_Notify                      0x021659b4 arm
 *   WcmWmReset                       0x02166e5c arm
 */

extern void WCMi_SetPhase(unsigned char phase);
extern void WCMi_Notify(short result, void *para0, void *para1, long para2);
extern void WcmWmReset(void);

static void WcmWmcbEndScan(void *arg)
{
    switch (*(unsigned short *)((char *)arg + 2)) {
    case 0:
        WCMi_SetPhase(3);
        WCMi_Notify(0, 0, 0, 0x3c5);
        break;
    case 1:
        WcmWmReset();
        break;
    case 2:
    case 3:
    case 4:
    default:
        WCMi_SetPhase(0xb);
        WCMi_Notify(7, 0, 0, 0x3d5);
        break;
    }
}
