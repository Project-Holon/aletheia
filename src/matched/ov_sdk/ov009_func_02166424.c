/*
 * function: WCM_SetRecvDCFCallback
 * address:  0x02166424
 * packet:   pkt_ov009_02166424
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCM_SetRecvDCFCallback (libwcm.TWL.HYB.a cpsif.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   gWcmCpsifWork  0x021AA7DC  data ov009
 *
 * Installs the DCF receive callback in the CPS interface work under a critical section.
 */

#include "../include/G_ov009_021AA7DC.h"

extern struct G_ov009_021AA7DC gWcmCpsifWork;
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

void WCM_SetRecvDCFCallback(void (*callback)(unsigned char *, unsigned char *, unsigned char *, long))
{
    unsigned long e;

    e = OS_DisableInterrupts();
    gWcmCpsifWork.recvCb = callback;
    OS_RestoreInterrupts(e);
}
