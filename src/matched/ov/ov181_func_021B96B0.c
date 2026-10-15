/*
 * function: STAFF_ROLL_CheckWipeDone
 * address:  0x021B96B0
 * packet:   pkt_021B96B0
 * region:   ov181
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 */
#include "../include/Obj24499.h"

typedef unsigned int   u32;
extern u32 WIPE_SYS_EndCheck(void);

int STAFF_ROLL_CheckWipeDone(char *p)
{
    if (WIPE_SYS_EndCheck() == 1)
        return ((struct Obj24499 *)p)->f2F0;
    return 1;
}
