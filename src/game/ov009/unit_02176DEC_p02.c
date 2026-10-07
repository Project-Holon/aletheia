/*
 * file:     unit_02176DEC_p02.c
 * unit:     yes
 * function: func_02176FD4, func_02177044
 * address:  0x02176FD4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWC_GetMyAID                   0x0216B838  arm ov009
 *   DWC_SendReliable               0x02176E90  arm ov009
 *   func_02059F38   0x02059F38  arm
 *   DWC_IsValidAID  0x0216B94C  arm  ov009
 *   func_0216B838   0x0216B838  arm  ov009
 *   DWCi_SendUnreliable  0x02177848  arm  ov009
 *   g_021AB180      0x021AB180  data
 */
#include "../../matched/include/G_TransInfo.h"

typedef struct TransInfo TransInfo;

extern unsigned char DWC_GetMyAID(void);
extern int DWC_SendReliable(unsigned char aid, void *buffer, int size);
extern int func_02059F38(void);
extern int DWC_IsValidAID(int aid);
extern unsigned char func_0216B838(void);
extern void DWCi_SendUnreliable(int myaid, int aid, void *buffer, int size, int flag);
unsigned long func_02176FD4(unsigned long bitmap, void *buffer, int size);
int func_02177044(unsigned char aid, void *buffer, int size);
extern struct TransInfo *g_021AB180;


/*
 * sdk:      DWC_SendReliableBitmap (dwc_transport.o)
 *
 * Closed (w5_nm): the bit is the conditional expression
 * `(aid != 0) ? (1 << aid) : 1`, which keeps the two constant 1s in separate
 * registers (r7 for the zero case, r8 for the shift); the statement form with
 * a later `if (aid == 0) aidbit = 1;` shared one register.
 */
unsigned long func_02176FD4(unsigned long bitmap, void *buffer, int size)
{
    unsigned long aidbit;
    unsigned char aid;

    for (aid = 0; aid < 32; aid++) {
        aidbit = (aid != 0) ? (1 << aid) : 1;
        if ((bitmap & aidbit) == 0)
            continue;
        if (aid == DWC_GetMyAID())
            continue;
        if (DWC_SendReliable(aid, buffer, size) == 0)
            bitmap &= ~aidbit;
    }
    return bitmap;
}


/*
 * sdk:      DWC_SendUnreliable (libdwcmatch.TWL.HYB.a dwc_transport.o)
 */
int func_02177044(unsigned char aid, void *buffer, int size)
{
    if (func_02059F38() != 0)
        return 0;
    if (DWC_IsValidAID(aid) == 0)
        return 0;
    if (size > 0x5B6)
        return 0;
    DWCi_SendUnreliable(func_0216B838(), aid, buffer, size, 1);
    if (g_021AB180->sendCallback != 0)
        g_021AB180->sendCallback(size, aid, g_021AB180->sendCallbackParam);
    return 1;
}
