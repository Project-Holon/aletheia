/*
 * file:     wm_ks.c
 * function: WM_StartKeySharing, WM_EndKeySharing
 * address:  0x02090B9C
 * packet:   pkt_02090B9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   WM_StartDataSharing 0x0209004C arm
 *   WM_EndDataSharing  0x0209028C  arm
 */

#include "../types.h"
#include "../sdk_wm.h"

struct WMDataSharingInfo;

#include "wm_ds.h"
struct WMDataSharingInfo;

WMErrCode WM_EndKeySharing(void *dsInfo);
WMErrCode WM_StartKeySharing(void *dsInfo, u16 port)
{
    return WM_StartDataSharing(dsInfo, port, 0xFFFF, 2, 1);
}

WMErrCode WM_EndKeySharing(void *dsInfo)
{
    return WM_EndDataSharing(dsInfo);
}
