/*
 * function: FLDMMDL_DRAW_InitDirState
 * address:  0x0219FE9C
 * packet:   pkt_0219FE9C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17985.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 MI_CpuFill8(u32, u32, u32, u32);

int FLDMMDL_DRAW_InitDirState(u32 a, u32 b, u32 c, u32 d)
{
MI_CpuFill8(a, 0, 4, d);
((struct Obj17985 *)((u8 *)(a)))->f0 = 8;
return 8;
}

