/*
 * function: WCMi_GetNextScanChannel
 * address:  0x02165918
 * packet:   pkt_ov009_02165918
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCMi_GetNextScanChannel (libwcm.TWL.HYB.a system.o)
 *
 * symbols:
 *   func_0216576C  0x0216576C  arm  ov009
 *   g_021AA7D4  0x021AA7D4  data ov009
 *
 * Finds the next channel after the given one that is enabled in the scan mask and allowed by the region, wrapping over 13 channels.
 */

#include "../include/G_WCMState.h"

typedef struct WCMWork {
    unsigned char pad0[0x12D4];
    unsigned long scanMask;
} WCMWork;

typedef struct WCMState WCMState;

extern struct WCMState g_021AA7D4;
extern unsigned short func_0216576C(void);

unsigned short WCMi_GetNextScanChannel(unsigned short channel)
{
    long i;

    for (i = 0; i < 13; i++) {
        if ((((WCMWork *)g_021AA7D4.work)->scanMask & (1 << ((channel + i) % 13 + 1))) != 0) {
            if ((func_0216576C() & (1 << ((channel + i) % 13))) != 0) {
                break;
            }
        }
    }
    return (unsigned short)((channel + i) % 13 + 1);
}
