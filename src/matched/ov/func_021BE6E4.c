/*
 * function: func_021BE6E4
 * address:  0x021BE6E4
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DWC_RAP_SetOwnStatus  0x0215683C  thumb  ov009
 *
 * Hands the pointer at +0x08 to the ov009 routine with selector 0x20.
 */
#include "../include/Obj00008.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int DWC_RAP_SetOwnStatus(char *a, int b);

void func_021BE6E4(char *s)
{
    DWC_RAP_SetOwnStatus(((struct Obj00008 *)s)->f8, 0x20);
}
