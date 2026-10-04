/*
 * function: func_021666C8
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
 *   func_021657C8  0x021657C8  arm  ov009
 *   func_02166784  0x02166784  arm  ov009
 *   func_02166710  0x02166710  arm  ov009
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
extern int func_021657C8(void);
extern unsigned char func_02166784(void);
extern WMLinkLevel func_02166710(unsigned char rssi);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

WMLinkLevel func_021666C8(void)
{
    unsigned long e;
    WCMWork *w;
    WMLinkLevel ret;

    e = OS_DisableInterrupts();
    w = (WCMWork *)func_021657C8();
    ret = WM_LINK_LEVEL_0;
    if (w != 0 && w->phase == 9) {
        ret = func_02166710(func_02166784());
    }
    OS_RestoreInterrupts(e);
    return ret;
}
