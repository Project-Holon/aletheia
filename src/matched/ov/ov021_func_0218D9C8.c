/*
 * function: FIELD_G3D_MAPPER_ClearHitList
 * address:  0x0218D9C8
 * packet:   pkt_ov021_0218D9C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_G3D_MAPPER_ClearHit  0x0218D9B8  thumb
 */
#include "../include/Obj19551.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern int FIELD_G3D_MAPPER_ClearHit(u32 a);

void FIELD_G3D_MAPPER_ClearHitList(u8 *p)
{
    int i;
    for (i = 0; i < 16; i++)
        FIELD_G3D_MAPPER_ClearHit((u32)(p + i * 16));
    ((struct Obj19551 *)p)->f100 = 0;
}
