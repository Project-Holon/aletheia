/*
 * function: FLDMMDL_SysSetBlActCont
 * address:  0x0216D51C
 * packet:   pkt_0216D51C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores the word field at +0x24.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */
#include "../include/Obj17781.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;


void FLDMMDL_SysSetBlActCont(u8 *p, u32 v)
{
    ((struct Obj17781 *)p)->f24 = v;
}

