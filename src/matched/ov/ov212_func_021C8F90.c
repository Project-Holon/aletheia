/*
 * function: ZUKAN_SetResumeState
 * address:  0x021C8F90
 * packet:   pkt_021C8F90
 * region:   ov212
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj25651.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int ZUKAN_SetResumeState(char *p, int v)
{
    ((struct Obj25651 *)p)->f20 = v;
    return 0;
}
