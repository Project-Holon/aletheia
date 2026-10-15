/*
 * function: UN_SELECT_GetFont
 * address:  0x021B9C88
 * packet:   pkt_021B9C88
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Unlabelled leaf in ov218, printed as a .word run right before the next
 * function at 0x021B9C8C; four-byte word getter.  Blocker target of
 * UN_SELECT_SceneStepMessage (pkt_021BA0B0), whose ov218 hint then covers it.
 */
#include "../include/Obj26043.h"

typedef unsigned int u32;

u32 UN_SELECT_GetFont(char *p)
{
    return ((struct Obj26043 *)p)->f8;
}
