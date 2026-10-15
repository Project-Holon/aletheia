/*
 * function: MUSICAL_MCSS_GetRenderFieldB
 * address:  0x021F53B4
 * packet:   pkt_ov112_021F53B4
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   MUSICAL_MCSS_GetFieldE  0x021F6290  thumb  ov112
 */
#include "../include/Obj10304.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void MUSICAL_MCSS_GetFieldE(u8 *p);

void MUSICAL_MCSS_GetRenderFieldB(int a) {
    MUSICAL_MCSS_GetFieldE((u8 *)(((struct Obj10304 *)a)->fC));
    if (((struct Obj10304 *)a)->f10 != 0) {
        MUSICAL_MCSS_GetFieldE((u8 *)(((struct Obj10304 *)a)->f10));
    }
}
