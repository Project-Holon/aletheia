/*
 * function: WCMi_WmifCleanupAsync
 * address:  0x021669B8
 * packet:   pkt_ov009_021669B8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCMi_WmifCleanupAsync (wmif.o)
 *
 * symbols:
 *   WCMi_GetSystemWork               0x021657c8 arm
 *   WM_PowerOff                      0x0208f328 arm
 *   WCMi_SetPhase                    0x02165a4c arm
 *   WcmWmcbCommon                    0x02166f24 arm
 */

struct WCMWork;

extern struct WCMWork *WCMi_GetSystemWork(void);
extern int WM_PowerOff(void (*callback)(void *));
extern void WCMi_SetPhase(unsigned char phase);
extern void WcmWmcbCommon(void *arg);

long WCMi_WmifCleanupAsync(void)
{
    struct WCMWork *wcmw;
    int wmResult;

    wcmw = WCMi_GetSystemWork();
    wmResult = WM_PowerOff(WcmWmcbCommon);
    switch (wmResult) {
    case 2:
        WCMi_SetPhase(4);
        *(unsigned short *)((char *)wcmw + 0x12da) = 2;
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
