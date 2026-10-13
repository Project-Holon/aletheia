/*
 * function: WIFICLUB_IsFriendRequestFromPeer
 * address:  0x021BEE64
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUB_GetFriendStatus  0x021C23B8  thumb  ov099
 *   WIFICLUB_GetStatusActionState  0x021C27D0  thumb  ov099
 *   WIFICLUB_GetStatusActionArg  0x021C27D8  thumb  ov099
 *
 * True when the two objects - the one at +0x08 of b and the one WIFICLUB_GetFriendStatus
 * returns - agree under WIFICLUB_GetStatusActionArg after both have been released through
 * WIFICLUB_GetStatusActionState.
 */
#include "../include/Obj18261.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int WIFICLUB_GetFriendStatus(int i);
extern int WIFICLUB_GetStatusActionState(void *p);
extern int WIFICLUB_GetStatusActionArg(void *p);

BOOL WIFICLUB_IsFriendRequestFromPeer(void *a, char *b)
{
    void *x = ((struct Obj18261 *)b)->f8;
    void *y = (void *)WIFICLUB_GetFriendStatus((int)a);

    WIFICLUB_GetStatusActionState(x);
    WIFICLUB_GetStatusActionState(y);

    if (WIFICLUB_GetStatusActionArg(x) == WIFICLUB_GetStatusActionArg(y)) {
        return 1;
    }

    return 0;
}
