/*
 * function: SCRCMD_WORK_SetMsgWindow
 * address:  0x0215A614
 * packet:   pkt_0215A614
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Setter: word at +0xfc of the object whose pointer sits at +0x20.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17663.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
void SCRCMD_WORK_SetMsgWindow(u8 *p, u32 v)
{
*(u32 *)((u8 *)((struct Obj17663 *)p)->f20 + 0xfc) = v;
}
