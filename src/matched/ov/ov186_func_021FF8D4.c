/*
 * function: BR_NET_IsFatal
 * address:  0x021FF8D4
 * packet:   pkt_021FF8D4
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj24864.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int BR_NET_IsFatal(char *p)
{
    return ((struct Obj24864 *)p)->f5DC;
}
