/*
 * function: BILLBOARD_ACT_GetSlotBoardId
 * address:  0x02050330
 * packet:   pkt_02050330
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj08868.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u16 BILLBOARD_ACT_GetSlotBoardId(u8 *p, int i)
{
    return *(u16 *)(*(u8 * *)&((struct Obj08868 *)p)->fC + i * 8);
}
