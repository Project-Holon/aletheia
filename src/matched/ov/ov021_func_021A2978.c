/*
 * function: WEATHER_TASK_LoadArchive
 * address:  0x021A2978
 * packet:   pkt_ov021_021A2978
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 */
#include "../include/Obj19755.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void *func_020490F4(unsigned int id, unsigned int heap);

void WEATHER_TASK_LoadArchive(u8 *p, u16 *q, u32 c, u32 a3)
{
    if (q[1] != 0 || q[2] != 0)
        ((struct Obj19755 *)p)->f10 = func_020490F4(q[0], c);
}
