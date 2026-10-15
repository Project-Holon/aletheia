/*
 * function: WF2DMAP_MAP_IsEmpty
 * address:  0x021C4790
 * packet:   pkt_021C4790
 * region:   ov127
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj23032.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int WF2DMAP_MAP_IsEmpty(char *p)
{
    return ((struct Obj23032 *)p)->f4 == 0;
}
