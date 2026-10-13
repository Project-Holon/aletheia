/*
 * function: FLDMMDL_BLACT_GetEntryHookFlag
 * address:  0x0219C648
 * packet:   pkt_0219C648
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
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17967.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_SysGetBlActCont(void *p);
extern void *FLDMMDL_GetMmdlSys(void *a0);

int FLDMMDL_BLACT_GetEntryHookFlag(u32 a)
{
return ((struct Obj17967 *)((u8 *)(FLDMMDL_SysGetBlActCont(FLDMMDL_GetMmdlSys((void *)a)))))->f0;
}

