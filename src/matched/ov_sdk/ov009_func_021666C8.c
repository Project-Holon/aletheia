/*
 * function: WCM_GetLinkLevel
 * address:  0x021666C8
 * packet:   pkt_ov009_021666C8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCM_GetLinkLevel (libwcm.TWL.HYB.a util.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   WCMi_GetSystemWork  0x021657C8  arm  ov009
 *   WCMi_GetRssiAverage  0x02166784  arm  ov009
 *   WCM_CalcLinkLevel  0x02166710  arm  ov009
 *   OS_RestoreInterrupts  0x0208799C  arm
 *
 * Returns the current link level from the averaged RSSI while connected, else level 0.
 */

typedef enum WMLinkLevel {
    WM_LINK_LEVEL_0 = 0,
    WM_LINK_LEVEL_1 = 1,
    WM_LINK_LEVEL_2 = 2,
    WM_LINK_LEVEL_3 = 3
} WMLinkLevel;

typedef struct WCMWork {
    unsigned char pad0[0x12DE];
    unsigned char phase;
} WCMWork;

extern unsigned long OS_DisableInterrupts(void);
extern int WCMi_GetSystemWork(void);
extern unsigned char WCMi_GetRssiAverage(void);
extern WMLinkLevel WCM_CalcLinkLevel(unsigned char rssi);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

WMLinkLevel WCM_GetLinkLevel(void)
{
    unsigned long e;
    WCMWork *w;
    WMLinkLevel ret;

    e = OS_DisableInterrupts();
    w = (WCMWork *)WCMi_GetSystemWork();
    ret = WM_LINK_LEVEL_0;
    if (w != 0 && w->phase == 9) {
        ret = WCM_CalcLinkLevel(WCMi_GetRssiAverage());
    }
    OS_RestoreInterrupts(e);
    return ret;
}
