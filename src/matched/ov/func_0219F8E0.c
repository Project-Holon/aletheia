/*
 * function: FLDMMDL_DRAW_DeleteFixedState
 * address:  0x0219F8E0
 * packet:   pkt_0219F8E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_GetDrawProcWork  0x0216D6F0  thumb  ov010
 *   FLDMMDL_BLACT_DeleteActorMmdl  0x0219C8D4  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17981.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_GetDrawProcWork(void *p);
extern u32 FLDMMDL_BLACT_DeleteActorMmdl(u32, u32);

int FLDMMDL_DRAW_DeleteFixedState(u32 a, u32 b, u32 c, u32 d)
{
return FLDMMDL_BLACT_DeleteActorMmdl(a, ((struct Obj17981 *)((u8 *)(FLDMMDL_GetDrawProcWork((void *)a))))->f0);
}

