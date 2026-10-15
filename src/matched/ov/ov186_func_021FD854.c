/*
 * function: BR_UTIL_RunHandles
 * address: 0x021FD854
 * packet: pkt_ov186_021FD854
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Blocker leaf for ov183 021E1D48 and 021E20F8, parent cleared.
 * symbols:
 *   BR_UTIL_RunTask 0x021FD71C thumb ov186
 */
#include "../include/Obj24845.h"
typedef unsigned char  u8;
extern void BR_UTIL_RunTask(u8 *p);
void BR_UTIL_RunHandles(char *p)
{
    BR_UTIL_RunTask((u8 *)(((struct Obj24845 *)p)->f10));
}
