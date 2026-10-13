/*
 * function: FIELD_MSGBG_RewriteMenuFunc
 * address:  0x02190A14
 * packet:   pkt_ov021_02190A14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save): forwards p->f10 to BMP_MENULIST_Redraw.
 *
 * symbols:
 *   BMP_MENULIST_Redraw  0x02020234  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19590.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void BMP_MENULIST_Redraw(u8 *p);

void FIELD_MSGBG_RewriteMenuFunc(u8 *p)
{
    BMP_MENULIST_Redraw((u8 *)(((struct Obj19590 *)p)->f10));
}
