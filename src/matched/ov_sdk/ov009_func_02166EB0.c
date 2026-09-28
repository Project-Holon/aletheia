/*
 * function: WcmWmcbIndication
 * address:  0x02166EB0
 * packet:   pkt_ov009_02166EB0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WcmWmcbIndication (wmif.o)
 *
 * symbols:
 *   WCMi_GetSystemWork               0x021657c8 arm
 *   WCMi_SetPhase                    0x02165a4c arm
 *   WcmWmReset                       0x02166e5c arm
 */

struct WCMWork;

extern struct WCMWork *WCMi_GetSystemWork(void);
extern void WCMi_SetPhase(unsigned char phase);
extern void WcmWmReset(void);

static void WcmWmcbIndication(void *arg)
{
    struct WCMWork *wcmw = WCMi_GetSystemWork();

    if (*(unsigned short *)((char *)arg + 2) != 8 ||
        *(unsigned short *)((char *)arg + 4) != 0x16 ||
        *(unsigned short *)((char *)arg + 6) != 0x25)
        return;
    switch (*(unsigned char *)((char *)wcmw + 0x12de) - 8) {
    case 0:
        WCMi_SetPhase(0xc);
        break;
    case 1:
    case 4:
        WcmWmReset();
        break;
    case 2:
        WCMi_SetPhase(0xc);
        break;
    case 3:
        break;
    }
}
