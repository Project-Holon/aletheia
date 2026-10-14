/*
 * function: ZUKAN_DETAIL_AREA_SetIconsAlphaMode
 * address:  0x021C252C
 * packet:   pkt_ov208_021C252C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorObjMode  0x0204B688  arm
 *   ov208_func_021BC518  0x021BC518  thumb  ov208
 */
#include "../include/Obj10905.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct Actor;
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void ov208_func_021BC518(u32 blend);

void ZUKAN_DETAIL_AREA_SetIconsAlphaMode(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (((u32 *)(p + 0x5c))[i] != 0)
            CLACT_SetActorObjMode((struct Actor *)(((u32 *)(p + 0x5c))[i]), 1);
    }
    ov208_func_021BC518(((struct Obj10905 *)p)->f41C);
}
