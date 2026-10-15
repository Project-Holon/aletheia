/*
 * function: MUSICAL_MCSS_GetElemPtr
 * address:  0x021F4F54
 * packet:   pkt_ov112_021F4F54
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj22530.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

u8 *MUSICAL_MCSS_GetElemPtr(u8 *p, int i) { return *(u8 * *)&((struct Obj22530 *)p)->f4 + i * 0xc; }
