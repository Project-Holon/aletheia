/*
 * function: FIELD_CAMERA_HasDelay
 * address:  0x0218F0F8
 * packet:   pkt_ov021_0218F0F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj01653.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

int FIELD_CAMERA_HasDelay(u8 *a)
{
    if (*(u32 *)&((struct Obj01653 *)a)->f1C == 0)
        return 0;
    if (*(u32 *)&((struct Obj01653 *)a)->fEC != 0)
        return 1;
    return 0;
}
