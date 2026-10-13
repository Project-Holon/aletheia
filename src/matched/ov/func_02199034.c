/*
 * function: func_02199034
 * address:  0x02199034
 * packet:   pkt_02199034
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
 *   FLDMMDL_InitMoveCmdWork  0x0216D6BC  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17953.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_SetDrawStatus(u32, u32);
extern void *FLDMMDL_InitMoveCmdWork(int a0, int a1, int a2);

int func_02199034(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj17953 *)((u8 *)(FLDMMDL_InitMoveCmdWork(a, 4, c))))->f2 = c;
return FLDMMDL_SetDrawStatus(a, b);
}

