/*
 * function: FLDMMDL_G3DOBJ_GetObjCtrl
 * address:  0x0219D49C
 * packet:   pkt_0219D49C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * FLDMMDL_SysGetG3dObjCont (0x0216D528) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetG3dObjCont  0x0216D528  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17972.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_SysGetG3dObjCont(u32);
extern void *FLDMMDL_GetMmdlSys(void *a0);

u32 FLDMMDL_G3DOBJ_GetObjCtrl(u32 a)
{
return ((struct Obj17972 *)((u8 *)(FLDMMDL_SysGetG3dObjCont((u32)FLDMMDL_GetMmdlSys((void *)a)))))->f4;
}

