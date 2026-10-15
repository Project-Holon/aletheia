/*
 * function: WF2DMAP_SCENE_ResetState
 * address:  0x021D8AF4
 * packet:   pkt_021D8AF4
 * region:   ov129
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj08136.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void WF2DMAP_SCENE_ResetState(char *p, int v)
{
    ((struct Obj08136 *)p)->f22C = v;
    ((struct Obj08136 *)p)->f230 = 0;
    ((struct Obj08136 *)p)->f234 = 0;
    ((struct Obj08136 *)p)->f238 = 0;
}
