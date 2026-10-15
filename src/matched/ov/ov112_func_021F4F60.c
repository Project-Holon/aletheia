/*
 * function: MUSICAL_MCSS_GetOffset
 * address: 0x021F4F60
 * packet: pkt_ov112_021F4F60
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: fourteen-byte body, two zero padding bytes, existing matched ov112_func_021F4F70 follows.
 */
#include "../include/Obj13828.h"
typedef unsigned char u8;
typedef signed char s8;
typedef struct { int x, y; } Offset;
void MUSICAL_MCSS_GetOffset(u8 *p, Offset *out)
{
    out->x = ((struct Obj13828 *)p)->f4;
    out->y = ((struct Obj13828 *)p)->f5;
}
