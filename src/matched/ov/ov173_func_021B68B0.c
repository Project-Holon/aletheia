/*
 * function: func_021B68B0
 * address:  0x021B68B0
 * packet:   pkt_021B68B0
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 */
#include "../include/Obj24152.h"

typedef unsigned int   u32;
extern u32 WIPE_SYS_EndCheck(void);

int func_021B68B0(int *p)
{
    if (WIPE_SYS_EndCheck() == 1)
        return ((struct Obj24152 *)p)->f1B0;
    return 0;
}
