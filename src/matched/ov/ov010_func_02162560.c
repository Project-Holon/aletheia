/*
 * function: EVENTDATA_SYSTEM_GetConnectCount
 * address:  0x02162560
 * packet:   pkt_ov010_02162560
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf getter: the halfword at +0x16.  Blocker of ov061
 * func_021F388C.
 */
#include "../include/Obj18958.h"

typedef unsigned char  u8;
typedef unsigned short u16;

u16 EVENTDATA_SYSTEM_GetConnectCount(u8 *p)
{
    return ((struct Obj18958 *)p)->f16;
}
