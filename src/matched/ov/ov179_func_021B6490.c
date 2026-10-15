/*
 * function: CDEMO_SCENE_GetResult
 * address:  0x021B6490
 * packet:   pkt_021B6490
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 */
#include "../include/Obj24472.h"
typedef unsigned int u32;

extern u32 WIPE_SYS_EndCheck(void);

u32 CDEMO_SCENE_GetResult(char *p)
{
    if (WIPE_SYS_EndCheck() == 1)
        return ((struct Obj24472 *)p)->f6054;
    return 2;
}
