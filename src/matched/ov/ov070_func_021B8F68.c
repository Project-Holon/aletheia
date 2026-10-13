/*
 * function: ITEMMENU_IsCheckModeAllowed
 * address: 0x021B8F68
 * packet: pkt_ov070_021B8F68
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent follower 021B8F90 is already filed separately; no unit here.
 * symbols:
 *   GAME_DATA_GetIntrudeCount 0x02012B70 thumb
 */
#include "../include/Obj09879.h"
typedef unsigned char  u8;
struct BigObj;
extern int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
int ITEMMENU_IsCheckModeAllowed(char *p, int value)
{
    if (((struct Obj09879 *)p)->f10 == 3 || ((struct Obj09879 *)p)->f10 == 1)
        return 0;
    if (GAME_DATA_GetIntrudeCount((const struct BigObj *)(((struct Obj09879 *)p)->f0)) == 1 && value == 4)
        return 0;
    return 1;
}
