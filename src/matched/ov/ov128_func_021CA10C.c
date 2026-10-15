/*
 * function: WF2DMAP_TOUCH_DeletePalAnims
 * address:  0x021CA10C
 * packet:   pkt_021CA10C
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202EA20  0x0202EA20  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00725.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Obj0202EA20;
extern u32 func_0202EA20(struct Obj0202EA20 *p);

void WF2DMAP_TOUCH_DeletePalAnims(u8 *p)
{
    func_0202EA20(((struct Obj00725 *)p)->f188);
    func_0202EA20(((struct Obj00725 *)p)->f184);
}
