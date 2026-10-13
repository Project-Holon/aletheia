/*
 * function: FLDMMDL_DRAW_GetBlactIdFixedState
 * address:  0x0219FB20
 * packet:   pkt_0219FB20
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
 *   FLDMMDL_GetDrawProcWork  0x0216D6F0  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17982.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_GetDrawProcWork(void *p);

int FLDMMDL_DRAW_GetBlactIdFixedState(u32 a, u32 b, u32 c, u32 d)
{
return ((struct Obj17982 *)((u8 *)(FLDMMDL_GetDrawProcWork((void *)a))))->f0;
}

