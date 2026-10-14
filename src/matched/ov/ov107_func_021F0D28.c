/*
 * function: MB_PARENT_SYS_GetState
 * address:  0x021F0D28
 * packet:   pkt_ov107_021F0D28
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gMbParentSys  0x021F6EAC  data
 */

#include "../include/G_Masks.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern struct Masks gMbParentSys;
u16 MB_PARENT_SYS_GetState(void) { return *(u16 *)(((u8 *)&gMbParentSys) + 8); }
