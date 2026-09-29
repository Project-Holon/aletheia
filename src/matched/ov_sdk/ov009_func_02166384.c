/*
 * function: func_02166384
 * address:  0x02166384
 * packet:   pkt_ov009_02166384
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCM_GetApMacAddress (libwcm.TWL.HYB.a cpsif.o)
 *
 * symbols:
 *   func_021657C8  0x021657C8  arm  ov009
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *
 * Returns the connected AP BSSID from the WCM work area, or 0 when not connected.
 */

typedef struct WCMWork {
    unsigned char pad0[0x12DD];
    unsigned char resetting;
    unsigned char phase;
    unsigned char pad1[5];
    unsigned char bssid[6];
} WCMWork;

extern WCMWork *func_021657C8(void);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

unsigned char *func_02166384(void)
{
    unsigned char *mac;
    WCMWork *w;
    unsigned long e;

    mac = 0;
    w = func_021657C8();
    e = OS_DisableInterrupts();
    if (w != 0) {
        if (w->phase == 9 && w->resetting == 0) {
            mac = w->bssid;
        }
    }
    OS_RestoreInterrupts(e);
    return mac;
}
