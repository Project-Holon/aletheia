/*
 * function: FIELDMAP_DeleteMmdlSys
 * address:  0x021892B4
 * packet:   pkt_021892B4
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
 *   FLDMMDL_SysPushAll  0x0216D2AC  thumb  ov010
 *   FLDMMDL_DeleteSysProc  0x0216CD50  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09172.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FLDMMDL_DeleteSysProc(int a0);
extern void FLDMMDL_SysPushAll(u32 x);

int FIELDMAP_DeleteMmdlSys(u8 *a)
{
FLDMMDL_SysPushAll(((struct Obj09172 *)((u8 *)(a)))->f38);
FLDMMDL_DeleteSysProc(((struct Obj09172 *)((u8 *)(a)))->f38);
((struct Obj09172 *)((u8 *)(a)))->f38 = 0;
return 0;
}

