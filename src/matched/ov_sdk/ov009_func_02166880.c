/*
 * function: func_02166880
 * address:  0x02166880
 * packet:   pkt_ov009_02166880
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCMi_WmifStartupAsync (libwcm.TWL.HYB.a wmif.o)
 *
 * symbols:
 *   WCMi_GetSystemWork    0x021657C8  arm  ov009
 *   WM_Init          0x0208E010  arm
 *   WCMi_SetPhase    0x02165A4C  arm  ov009
 *   func_0208EAC8    0x0208EAC8  arm
 *   OS_GetMacAddress 0x02087C6C  arm
 *   func_021665CC    0x021665CC  arm  ov009
 *   func_0208F224    0x0208F224  arm
 *   func_02166EB0    0x02166EB0  arm  ov009
 *   func_02166F24    0x02166F24  arm  ov009
 */

typedef struct WCMWork {
    unsigned char pad0[0x12C0];
    unsigned long dmaNo;
    unsigned char pad1[0x12DA - 0x12C4];
    unsigned short wmState;
    unsigned char pad3;
    unsigned char resetting;
    unsigned char phase;
    unsigned char pad2[0x13A0 - 0x12DF];
    unsigned char wmSysBuf[1];
} WCMWork;

extern int WCMi_GetSystemWork(void);
extern long WM_Init(void *wmSysBuf, unsigned short dmaNo);
extern void WCMi_SetPhase(unsigned char phase);
extern long func_0208EAC8(void (*callback)(void *));
extern void OS_GetMacAddress(unsigned char *macAddress);
extern void func_021665CC(unsigned char *macAddress);
extern int func_0208F224(char *path);
extern void func_02166EB0(void *arg);
extern void func_02166F24(void *arg);

long func_02166880(void)
{
    unsigned char macAddress[6];
    WCMWork *wcmw;
    long wmResult;

    wcmw = (WCMWork *)WCMi_GetSystemWork();
    wmResult = WM_Init(wcmw->wmSysBuf, wcmw->dmaNo);
    switch (wmResult) {
    case 3:
        WCMi_SetPhase(0xb);
        return 7;
    case 4:
        return 5;
    case 1:
    case 2:
    case 5:
    case 6:
    default:
        WCMi_SetPhase(0xb);
        return 7;
    case 0:
        break;
    }
    if (func_0208EAC8(func_02166EB0) != 0) {
        WCMi_SetPhase(0xb);
        return 7;
    }
    OS_GetMacAddress(macAddress);
    func_021665CC(macAddress);
    wmResult = func_0208F224((char *)func_02166F24);
    switch (wmResult) {
    case 2:
        WCMi_SetPhase(2);
        wcmw->wmState = 1;
        break;
    case 8:
        WCMi_SetPhase(0xc);
        return 1;
    case 3:
    default:
        WCMi_SetPhase(0xb);
        return 7;
    }
    return 3;
}
