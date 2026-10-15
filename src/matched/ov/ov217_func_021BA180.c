/*
 * function: RESEARCH_TOP_StartCommand
 * address:  0x021BA180
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Set +0x18, clear +0x1c, +0x20 and +0x80.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00511.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void RESEARCH_TOP_StartCommand(void *p, u32 v)
{
    ((struct Obj00511 *)p)->f18 = v;
    ((struct Obj00511 *)p)->f1C = 0;
    ((struct Obj00511 *)p)->f20 = 0;
    ((struct Obj00511 *)p)->f80 = 0;
}
