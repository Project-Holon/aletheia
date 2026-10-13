/*
 * function: func_021676E4
 * address:  0x021676E4
 * packet:   pkt_ov009_021676E4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WcmWmcbDisconnect (libwcm.TWL.HYB.a wmif.o)
 *
 * symbols:
 *   WCMi_GetSystemWork  0x021657C8  arm  ov009
 *   WCMi_SetPhase  0x02165A4C  arm  ov009
 *   func_02166E5C  0x02166E5C  arm  ov009
 *   func_021659B4  0x021659B4  arm  ov009
 *
 * WM disconnect completion callback: on success finishes the reset or reports the disconnect result, otherwise moves to the failure phase and notifies.
 */

typedef struct WMCallback {
    unsigned short apiid;
    unsigned short errcode;
} WMCallback;

typedef struct WCMWork {
    unsigned char pad0[0x12DE];
    unsigned char phase;
    unsigned char pad1[0x22E8 - 0x12DF];
    unsigned short field22E8;
} WCMWork;

extern int WCMi_GetSystemWork(void);
extern void WCMi_SetPhase(unsigned char phase);
extern void func_02166E5C(void);
extern void func_021659B4(short result, void *para0, void *para1, long para2);

void func_021676E4(void *arg)
{
    WCMWork *wcmw;

    wcmw = (WCMWork *)WCMi_GetSystemWork();
    switch (((WMCallback *)arg)->errcode) {
    case 0:
        if (wcmw->phase == 12) {
            WCMi_SetPhase(10);
            func_02166E5C();
            return;
        }
        wcmw->field22E8 = 0;
        WCMi_SetPhase(3);
        func_021659B4(0, (unsigned char *)wcmw + 0x12E0, 0, 0x481);
        return;
    case 1:
    case 3:
        WCMi_SetPhase(10);
        func_02166E5C();
        return;
    case 2:
    case 4:
    default:
        WCMi_SetPhase(11);
        func_021659B4(7, (unsigned char *)wcmw + 0x12E0, 0, 0x493);
        return;
    }
}
