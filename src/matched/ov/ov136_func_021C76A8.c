/*
 * function: MB_SEQ_DeleteTouchSelect
 * address:  0x021C76A8
 * packet:   pkt_ov136_021C76A8
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CURSOR_MOVE_Delete  0x02025D14  thumb
 */
#include "../include/Obj23661.h"
#include "../include/Obj23662.h"

typedef unsigned char u8;
typedef unsigned int   u32;
extern u32 CURSOR_MOVE_Delete(void *a0);
void MB_SEQ_DeleteTouchSelect(u8 *p)
{
    CURSOR_MOVE_Delete(((struct Obj23662 *)(*(u8 * *)&((struct Obj23661 *)p)->f8))->f294);
}
