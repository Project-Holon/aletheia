/*
 * function: WIFICLUBACTOR_GetActorId
 * address:  0x021B9A50
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C49A4  0x021C49A4  thumb  ov127
 *
 * Calls the ov127 routine on the pointer at +0x00 and truncates the answer to a byte.
 */
#include "../include/Obj18147.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int func_021C49A4(u8 *p, unsigned int i);

u8 WIFICLUBACTOR_GetActorId(char *p)
{
    return (u8)func_021C49A4(((struct Obj18147 *)p)->f0, 4);
}
