/*
 * function: DWCi_EncSessionShutdown
 * address:  0x021CA1B4
 * packet:   pkt_ov114_021CA1B4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_EncSessionShutdown (dwc_encsession.o)
 *
 * symbols:
 *   DWC_Free       0x0205A1B0  arm
 *   DWCi_GsFree    0x0205A29C  arm
 *   DWC_ShutdownGHTTP  0x021BF57C  arm  ov114
 *   gDwcEncSession     0x021CF7AC  data
 */

#include "../include/G_Session.h"

typedef struct {
    int state;
    int active;
    char pad0[0x4c];
    void *buf;
    char pad1[8];
    void *gs;
    void *gs2;
} Session;
extern struct Session gDwcEncSession;
extern void DWC_Free(int name, void *ptr, int size);
extern void DWCi_GsFree(void *ptr);
extern int DWC_ShutdownGHTTP(void);

void DWCi_EncSessionShutdown(void)
{
    if (gDwcEncSession.isinitialized == 0) {
        return;
    }
    if (gDwcEncSession.request != 0) {
        DWC_Free(8, gDwcEncSession.request, 0);
        gDwcEncSession.request = 0;
    }
    if (gDwcEncSession.resbuf != 0) {
        DWCi_GsFree(gDwcEncSession.resbuf);
        gDwcEncSession.resbuflen = 0;
        gDwcEncSession.resbuf = 0;
    }
    DWC_ShutdownGHTTP();
    gDwcEncSession.state = 2;
    gDwcEncSession.isinitialized = 0;
}
