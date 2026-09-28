/*
 * function: WcmWmReset
 * address:  0x02166E5C
 * packet:   pkt_ov009_02166E5C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WcmWmReset (wmif.o)
 *
 * symbols:
 *   WCMi_GetSystemWork               0x021657c8 arm
 *   WM_Reset                         0x0208f400 arm
 *   WCMi_SetPhase                    0x02165a4c arm
 *   WCMi_Notify                      0x021659b4 arm
 *   WcmWmcbReset                     0x021679c0 arm
 */

struct WCMWork {
    unsigned char pad[0x12dd];
    unsigned char flag;
};

extern struct WCMWork *WCMi_GetSystemWork(void);
extern int WM_Reset(void (*callback)(void *));
extern void WCMi_SetPhase(unsigned char phase);
extern void WCMi_Notify(short result, void *para0, void *para1, long para2);
extern void WcmWmcbReset(void *arg);

static void WcmWmReset(void)
{
    struct WCMWork *wcmw;
    int wmResult;

    wcmw = WCMi_GetSystemWork();
    if (wcmw->flag != 0)
        return;
    wcmw->flag = 1;
    wmResult = WM_Reset(WcmWmcbReset);
    if (wmResult == 2)
        return;
    WCMi_SetPhase(0xb);
    WCMi_Notify(7, 0, 0, 0x24f);
}
