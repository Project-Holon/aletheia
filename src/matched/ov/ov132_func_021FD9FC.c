/*
 * function: func_021FD9FC
 * address:  0x021FD9FC
 * packet:   pkt_021FD9FC
 * region:   ov132
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj23306.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int func_021FD9FC(char *p)
{
    unsigned int i = ((struct Obj23306 *)p)->f180;

    if (i < 4)
        return *(u8 *)(p + i * 0x30 + 0x72);
    return 4;
}
