/*
 * function: DRAW_SYSTEM_DeleteCanvas
 * address:  0x021B6C34
 * packet:   pkt_021B6868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Frees the +0x10 pointer with the ARM9 releaser, then the object itself.
 *
 * symbols:
 *   GFL_NET_FreeAligned  0x0203D7FC  arm
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24067.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void GFL_NET_FreeAligned(void *p);
extern u32 func_020307B0(void *p);

void DRAW_SYSTEM_DeleteCanvas(char *p)
{
    GFL_NET_FreeAligned(((struct Obj24067 *)p)->f10);
    func_020307B0(p);
}
