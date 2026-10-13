/*
 * function: MONOLITH_TOOL_SLOT_SELECT_FreeMsgWindow
 * address:  0x021B7994
 * packet:   pkt_ov071_021B7994
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to BMP_WIN_Delete on the pointer loaded from offset 0.
 *
 * symbols:
 *   BMP_WIN_Delete  0x020452E8  arm
 */
#include "../include/Obj20695.h"

struct Descriptor;
typedef unsigned int   u32;
void MONOLITH_TOOL_SLOT_SELECT_FreeMsgWindow(void *p)
{
    u32 BMP_WIN_Delete(struct Descriptor *d);
    BMP_WIN_Delete(((struct Obj20695 *)p)->f0);
}
