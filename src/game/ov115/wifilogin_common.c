/*
 * file:     wifilogin_common.c
 * unit:     yes
 * function: WIFILOGIN_COMMON_IsCancelInput, WIFILOGIN_COMMON_SetStateHandler, WIFILOGIN_COMMON_CheckLocalAid, WIFILOGIN_COMMON_GetSessionId, WIFILOGIN_COMMON_GetMaxPlayers, WIFILOGIN_COMMON_IsSameId
 * address:  0x021D4240
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   gWifiloginDialogId 0x021D6640 data a4
 */
#include "ov115_types.h"

#include "../types.h"

#include "../arm9/key.h"
#include "../arm9/touchpanel.h"
#include "../arm9/net_handle.h"
#include "../arm9/net_system.h"
int WIFILOGIN_COMMON_IsCancelInput(u8 *p);
void WIFILOGIN_COMMON_SetStateHandler(u8 *p, u32 handler);
void WIFILOGIN_COMMON_CheckLocalAid(u32 localAid, u32 unused1, u32 unused2, u8 *state, u32 handle);

/* True when the pad or the touch panel asks the login to move on. */
int WIFILOGIN_COMMON_IsCancelInput(u8 *p) { if(KEY_GetTrg()&3) return 1; if(((struct WifiloginWork *)p)->state->mode && TOUCHPANEL_GetTrg()) return 1; return 0; }

/* Install the callback the login state machine runs each frame. */
void WIFILOGIN_COMMON_SetStateHandler(u8 *p, u32 handler) { ((struct WifiloginWork *)p)->stateHandler = handler; }

/* Flag the state when this console's aid is not the one the handle reports. */
void WIFILOGIN_COMMON_CheckLocalAid(u32 localAid, u32 unused1, u32 unused2, u8 *state, u32 handle)
{
    if (handle == (u32)GFL_NET_HANDLE_GetCurrentHandle() && localAid != GFL_NET_SYSTEM_GetCurrentAid()) {
        ((struct WifiloginState *)state)->aidMismatch = 1;
    }
}

extern u8 gWifiloginDialogId[];
u8 *WIFILOGIN_COMMON_GetSessionId(void)
{
    return gWifiloginDialogId;
}

int WIFILOGIN_COMMON_GetMaxPlayers(void)
{
    return 4;
}

int WIFILOGIN_COMMON_IsSameId(int a, int b)
{
    if (a == b)
        return 1;
    return 0;
}
