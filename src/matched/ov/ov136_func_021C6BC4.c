/*
 * function: MB_SEQ_StateFlashWait
 * address:  0x021C6BC4
 * packet:   pkt_021C6BC4
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MB_SEQ_StepSelectFlash  0x021C5C84  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23617.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int MB_SEQ_StepSelectFlash(u8 *p);

int MB_SEQ_StateFlashWait(u8 *p)
{
    if (MB_SEQ_StepSelectFlash(p) == 0)
        return ((struct Obj23617 *)p)->f28;
    return 5;
}
