/*
 * function: BTLV_CORE_GetInputResultFlag
 * address:  0x021EA04C
 * packet:   pkt_021EA04C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_GetInputResultFlag   0x021EA04C  thumb ov093
 *
 * ldrb at #0x157 (pool constant)
 */
#include "../include/Obj18477.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u8 BTLV_CORE_GetInputResultFlag(u8 *p)
{
    return ((struct Obj18477 *)p)->f157;
}
