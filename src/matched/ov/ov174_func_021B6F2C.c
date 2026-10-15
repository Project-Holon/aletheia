/*
 * function: LOCAL_TVT_CHARA_IsDone
 * address:  0x021B6F2C
 * packet:   pkt_021B6F2C
 * region:   ov174
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj24207.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int LOCAL_TVT_CHARA_IsDone(int unused, char *p)
{
    return ((struct Obj24207 *)p)->f8 == 5;
}
