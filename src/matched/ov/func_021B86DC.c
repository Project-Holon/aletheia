/*
 * function: func_021B86DC
 * address:  0x021B86DC
 * packet:   pkt_021B86DC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B86DC   0x021B86DC  thumb ov093
 *
 * double deref u16
 */
#include "../include/Obj18129.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u16 func_021B86DC(void **p)
{
    return ((struct Obj18129 *)((u8 *)*p))->f1A;
}
