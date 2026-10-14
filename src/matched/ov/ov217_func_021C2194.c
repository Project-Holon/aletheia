/*
 * function: ARROW_IsComplete
 * address:  0x021C2194
 * packet:   pkt_ov217_021C2194
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj26020.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

u32 ARROW_IsComplete(void *p)
{
    s32 i;
    for (i = 0; i < ((struct Obj26020 *)p)->f298; i++) {
        if (*(u32 *)((char *)p + 0x28 + i * 0x18) == 0)
            return 0;
    }
    return 1;
}
