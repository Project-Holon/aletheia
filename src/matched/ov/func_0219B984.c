/*
 * function: FLDMMDL_MOVE_UpdatePlayerTracking
 * address:  0x0219B984
 * packet:   pkt_0219B984
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
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysSearchPlayer  0x0216DEE0  thumb  ov010
 *   FLDMMDL_MOVE_StartPlayerTracking  0x0219B9B0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05008.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern void *FLDMMDL_SysSearchPlayer(void *a0);
extern void FLDMMDL_MOVE_StartPlayerTracking(u32 a, u8 *s);

int FLDMMDL_MOVE_UpdatePlayerTracking(u32 a, u32 b)
{
if (FLDMMDL_SysSearchPlayer((void *)FLDMMDL_GetMmdlSys((void *)a)) == 0) {
    ((struct Obj05008 *)((u8 *)(b)))->f1 = 0;
    return 0;
}
if (((struct Obj05008 *)((u8 *)(b)))->f1 == 0) {
    FLDMMDL_MOVE_StartPlayerTracking(a, (u8 *)b);
}
return 1;
}

