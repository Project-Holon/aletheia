/*
 * function: DWC_SendUnreliable
 * address:  0x02177044
 * packet:   pkt_ov009_02177044
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_SendUnreliable (libdwcmatch.TWL.HYB.a dwc_transport.o)
 *
 * symbols:
 *   DWCi_IsError   0x02059F38  arm
 *   DWC_IsValidAID  0x0216B94C  arm  ov009
 *   DWC_GetMyAID   0x0216B838  arm  ov009
 *   DWCi_SendUnreliable  0x02177848  arm  ov009
 *   gDwcTransInfo      0x021AB180  data
 */

#include "../include/G_TransInfo.h"

typedef struct TransInfo TransInfo;

extern int DWCi_IsError(void);
extern int DWC_IsValidAID(int aid);
extern unsigned char DWC_GetMyAID(void);
extern void DWCi_SendUnreliable(int myaid, int aid, void *buffer, int size, int flag);
extern struct TransInfo *gDwcTransInfo;

int DWC_SendUnreliable(unsigned char aid, void *buffer, int size)
{
    if (DWCi_IsError() != 0)
        return 0;
    if (DWC_IsValidAID(aid) == 0)
        return 0;
    if (size > 0x5B6)
        return 0;
    DWCi_SendUnreliable(DWC_GetMyAID(), aid, buffer, size, 1);
    if (gDwcTransInfo->sendCallback != 0)
        gDwcTransInfo->sendCallback(size, aid, gDwcTransInfo->sendCallbackParam);
    return 1;
}
