/*
 * function: WCMi_NwmifBeginSearchAsync
 * address:  0x02731AF0
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   WCMi_GetSystemWork  0x021657C8  arm  ov009
 *   WCMi_SetPhase  0x02165A4C  arm  ov009
 *   func_020862B8  0x020862B8  arm  twl
 *   NWM_StartScanEx  0x02703088  arm  twl
 *   WcmEditScanExParam  0x02732B70  arm  twl
 *   WcmNwmcbScanEx  0x027323A8  arm  twl
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct NetWork {
    u8 pad0[0x12da];
    u16 phase;
    u8 pad1[2];
    u8 state;
    u8 pad2[0x43a0 - 0x12df];
    u32 sendBuf;
    u16 sendLen;
    u8 pad3[0x43e0 - 0x43a6];
    u32 sendCount;
} NetWork;

extern NetWork *WCMi_GetSystemWork(void);
extern void WCMi_SetPhase(u8 phase);
extern void func_020862B8(u32 buf, u32 len);
extern int NWM_StartScanEx(void *cb, void *buf);
extern void WcmEditScanExParam(u32 a, u32 b, u32 c);
extern void WcmNwmcbScanEx(void);

int WCMi_NwmifBeginSearchAsync(u32 a, u32 b, u32 c)
{
    NetWork *w = WCMi_GetSystemWork();

    switch (w->state) {
    case 5:
        WcmEditScanExParam(a, b, c);
        return 2;
    case 6:
        WcmEditScanExParam(a, b, c);
        return 0;
    default:
        return 1;
    case 3:
        WcmEditScanExParam(a, b, c);
        func_020862B8(w->sendBuf, w->sendLen);
        w->sendCount++;
        switch (NWM_StartScanEx(WcmNwmcbScanEx, &w->sendBuf)) {
        case 2:
            WCMi_SetPhase(5);
            w->phase = 3;
            return 3;
        case 6:
            return 4;
        case 3:
        default:
            WCMi_SetPhase(11);
            return 7;
        }
    }
}
