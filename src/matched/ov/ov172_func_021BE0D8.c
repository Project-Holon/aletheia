/*
 * function: COMM_TVT_SYS_IsLaunchModeCall
 * address:  0x021BE0D8
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Test word 1 of the object behind +0x1f8 against 3.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24136.h"
#include "../include/Obj24137.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

int COMM_TVT_SYS_IsLaunchModeCall(void *p)
{
    void *q = ((struct Obj24136 *)p)->f1F8;
    if (((struct Obj24137 *)q)->f4 == 3) {
        return 1;
    }
    return 0;
}
