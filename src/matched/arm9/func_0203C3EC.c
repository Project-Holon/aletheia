/*
 * function: GFL_NET_STATE_GetWifiState
 * address:  0x0203C3EC
 * packet:   pkt_0203C3EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM leaf (saves no register, so disasm.py gives it no func_
 * label): a channel-id classifier that reads the pointer at _pNetState, then
 * the u32 at +8 of the record, and maps five distinct table addresses to
 * 0/1/3/4/5 (anything else returns 2).
 *
 * The five constants sit in their own pool words at 0x0203C450..0x0203C460
 * and are each loaded with `ldr` from pc, so they are link-time absolute
 * (R_ARM_ABS32) values that the compiler cannot fold against one another.
 * They are spelled as the addresses of the matched arm9 functions that live
 * at those addresses, taken as integers, so each becomes its own relocation
 * and no `sub`/constant-fold is possible.
 *
 * symbols:
 *   GFL_NET_STATE_GetWifiState  0x0203C3EC  arm
 *   _pNetState     0x021469DC  data  a4
 *   GFL_NET_STATE_WifiLoginMain  0x0203C0F4  arm
 *   GFL_NET_STATE_WifiStopError  0x0203C0B4  arm
 *   GFL_NET_STATE_WifiErrorWait  0x0203C068  arm
 *   GFL_NET_STATE_WifiLoggedOut  0x0203C060  arm
 *   GFL_NET_STATE_WifiFatal  0x0203C064  arm
 */

#include "../include/G_Sys.h"

typedef struct Hdr021469DC {
    unsigned int pad0;
    unsigned int pad4;
    unsigned int v8;
} Hdr021469DC;

extern struct Sys *_pNetState;
extern void GFL_NET_STATE_WifiLoginMain(void *p);
extern void GFL_NET_STATE_WifiStopError(void);
extern void GFL_NET_STATE_WifiErrorWait(void);
extern void GFL_NET_STATE_WifiLoggedOut(void);
extern void GFL_NET_STATE_WifiFatal(void);

int GFL_NET_STATE_GetWifiState(void)
{
    Hdr021469DC **pp = (Hdr021469DC **)(&(*(unsigned int *)&_pNetState));
    unsigned int v = (*pp)->v8;

    if (v == (unsigned int)(void *)GFL_NET_STATE_WifiLoginMain) {
        return 0;
    }
    if (v == (unsigned int)(void *)GFL_NET_STATE_WifiStopError) {
        return 1;
    }
    if (v == (unsigned int)(void *)GFL_NET_STATE_WifiErrorWait) {
        return 3;
    }
    if (v == (unsigned int)(void *)GFL_NET_STATE_WifiLoggedOut) {
        return 4;
    }
    if (v == (unsigned int)(void *)GFL_NET_STATE_WifiFatal) {
        return 5;
    }
    return 2;
}
