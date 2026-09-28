/*
 * function: WCMi_WmifDisconnectAsync
 * address:  0x02166BD8
 * packet:   pkt_ov009_02166BD8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCMi_WmifDisconnectAsync (wmif.o)
 *
 * symbols:
 *   WCMi_GetSystemWork               0x021657c8 arm
 *   WM_EndDCF                        0x0208ffdc arm
 *   WCMi_SetPhase                    0x02165a4c arm
 *   WcmWmcbEndDCF                    0x021678ac arm
 */

struct WCMWork;

extern struct WCMWork *WCMi_GetSystemWork(void);
extern int WM_EndDCF(void (*callback)(void *));
extern void WCMi_SetPhase(unsigned char phase);
extern void WcmWmcbEndDCF(void *arg);

long WCMi_WmifDisconnectAsync(void)
{
    struct WCMWork *wcmw;
    int wmResult;

    wcmw = WCMi_GetSystemWork();
    wmResult = WM_EndDCF(WcmWmcbEndDCF);
    switch (wmResult) {
    case 2:
        WCMi_SetPhase(0xa);
        *(unsigned short *)((char *)wcmw + 0x12da) = 6;
        break;
    case 8:
        return 4;
    case 3:
    default:
        WCMi_SetPhase(0xb);
        return 7;
    }
    return 3;
}
