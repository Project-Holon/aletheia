/*
 * function: FLDMMDL_MOVE_GetHideEffect
 * address:  0x0219BF48
 * packet:   pkt_0219BF48
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
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17961.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_GetMoveProcWork(void *p);

int FLDMMDL_MOVE_GetHideEffect(u32 a)
{
return ((struct Obj17961 *)((u8 *)(FLDMMDL_GetMoveProcWork((void *)a))))->f4;
}

