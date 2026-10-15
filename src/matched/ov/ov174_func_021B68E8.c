/*
 * function: LOCAL_TVT_SYS_IsPrintIdle
 * address:  0x021B68E8
 * packet:   pkt_021B68E8
 * region:   ov174
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj24201.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int LOCAL_TVT_SYS_IsPrintIdle(char *p)
{
    return ((struct Obj24201 *)p)->f64 == 0;
}
