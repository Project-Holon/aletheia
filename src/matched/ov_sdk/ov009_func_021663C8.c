/*
 * function: WCM_GetApEssid
 * address:  0x021663C8
 * packet:   pkt_ov009_021663C8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCM_GetApEssid (libwcm.TWL.HYB.a cpsif.o)
 *
 * symbols:
 *   WCMi_GetSystemWork  0x021657C8  arm  ov009
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *
 * Returns the connected AP ESSID and stores its length through the optional out pointer.
 */

typedef struct WCMWork {
    unsigned char pad0[0x12DD];
    unsigned char resetting;
    unsigned char phase;
    unsigned char pad1[0x0B];
    unsigned short essidLen;
    unsigned char essid[32];
} WCMWork;

extern int WCMi_GetSystemWork(void);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

unsigned char *WCM_GetApEssid(unsigned short *length)
{
    unsigned char *essid;
    unsigned short len;
    WCMWork *w;
    unsigned long e;

    essid = 0;
    len = 0;
    w = (WCMWork *)WCMi_GetSystemWork();
    e = OS_DisableInterrupts();
    if (w != 0) {
        if (w->phase == 9 && w->resetting == 0) {
            essid = w->essid;
            len = w->essidLen;
        }
    }
    OS_RestoreInterrupts(e);
    if (length != 0) {
        *length = len;
    }
    return essid;
}
