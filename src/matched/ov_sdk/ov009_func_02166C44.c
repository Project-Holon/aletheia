/*
 * function: func_02166C44
 * address:  0x02166C44
 * packet:   pkt_ov009_02166C44
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCMi_WmifTerminateAsync (libwcm.TWL.HYB.a wmif.o)
 *
 * symbols:
 *   WCMi_GetSystemWork  0x021657C8  arm  ov009
 *   WMi_GetStatusAddress  0x0208E9C8  arm
 *   DC_InvalidateRange  0x020862B8  arm
 *   WM_Finish  0x0208E2B8  arm
 *   WCMi_SetPhase  0x02165A4C  arm  ov009
 *   func_0208F2A0  0x0208F2A0  arm
 *   func_0208F328  0x0208F328  arm
 *   WM_Reset  0x0208F400  arm
 *   func_02166F24  0x02166F24  arm  ov009
 *   func_021679C0  0x021679C0  arm  ov009
 *
 * Terminates the WM link by walking the WM state down: finish, disable, power off or reset, then maps the result to a WCM result.
 */

typedef struct WCMWork {
    unsigned char pad0[0x12DA];
    unsigned short notify;
    unsigned char pad1[1];
    unsigned char resetting;
} WCMWork;

typedef struct WMStatus {
    unsigned short state;
} WMStatus;

extern int WCMi_GetSystemWork(void);
extern WMStatus *WMi_GetStatusAddress(void);
extern void DC_InvalidateRange(void *startAddr, unsigned long nBytes);
extern long WM_Finish(void);
extern void WCMi_SetPhase(unsigned char phase);
extern long func_0208F2A0(void (*callback)(void *));
extern long func_0208F328(void (*callback)(void *));
extern long WM_Reset(void (*callback)(void *));
extern void func_02166F24(void *arg);
extern void func_021679C0(void *arg);

long func_02166C44(void)
{
    WCMWork *wcmw;
    long wmResult;
    WMStatus *ws;

    wcmw = (WCMWork *)WCMi_GetSystemWork();
    ws = WMi_GetStatusAddress();
    DC_InvalidateRange(ws, 2);
    switch (ws->state) {
    case 0:
        wmResult = WM_Finish();
        if (wmResult == 0) {
            WCMi_SetPhase(1);
            wcmw->notify = 0;
            return 0;
        }
        break;
    case 1:
        wmResult = func_0208F2A0(func_02166F24);
        break;
    case 2:
        wmResult = func_0208F328(func_02166F24);
        break;
    default:
        wcmw->resetting = 1;
        wmResult = WM_Reset(func_021679C0);
        break;
    }
    switch (wmResult) {
    case 2:
        WCMi_SetPhase(13);
        wcmw->notify = 9;
        break;
    case 8:
        return 4;
    case 3:
    default:
        WCMi_SetPhase(11);
        return 7;
    }
    return 3;
}
