/*
 * function: FLDMMDL_SysGetResArcHandle
 * address:  0x0216D518
 * packet:   pkt_0216D518
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the word field at +0x10.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */
#include "../include/Obj17780.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;


u32 FLDMMDL_SysGetResArcHandle(u8 *p)
{
    return ((struct Obj17780 *)p)->f10;
}

