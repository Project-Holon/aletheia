/*
 * function: FLDMMDL_SysGetG3dObjCont
 * address:  0x0216D528
 * packet:   pkt_0216D528
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Getter: word at +0x28.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17783.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
u32 FLDMMDL_SysGetG3dObjCont(u8 *p)
{
return ((struct Obj17783 *)p)->f28;
}
