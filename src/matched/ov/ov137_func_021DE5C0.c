/*
 * function: GURU2_RECEIPT_ClearMessageFrame
 * address:  0x021DE5C0
 * packet:   pkt_021DE5C0
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23734.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);

void GURU2_RECEIPT_ClearMessageFrame(u8 *p)
{
    BMP_MENUWORK_DrawWindowBorder(((struct Obj23734 *)p)->fD4, 0);
}
