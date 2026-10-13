/*
 * function: FIELD_MSGBG_DrawTalkSys
 * address:  0x0219047C
 * packet:   pkt_ov021_0219047C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TALKMSGWIN_Draw  0x02194764  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19583.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern void TALKMSGWIN_Draw(void *p);

void FIELD_MSGBG_DrawTalkSys(u8 *p)
{
    void *q = ((struct Obj19583 *)p)->f15C;
    if (q != 0)
        TALKMSGWIN_Draw(q);
}
