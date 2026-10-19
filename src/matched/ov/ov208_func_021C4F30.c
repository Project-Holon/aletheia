/*
 * function: ZUKAN_DETAIL_FORM_UpdateBgScrollForState
 * address:  0x021C4F30
 * packet:   pkt_ov208_021C4F30
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_ChangeScroll  0x02041EE4  arm
 */
#include "../include/Obj14663.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void BG_SYS_ChangeScroll(u32 index, u32 a, u32 b);

void ZUKAN_DETAIL_FORM_UpdateBgScrollForState(void *unused, u8 *p)
{
    switch (((struct Obj14663 *)p)->f6B8) {
    case 0:
        BG_SYS_ChangeScroll(2, 0, -0x40);
        break;
    case 4:
        if (((struct Obj14663 *)p)->f548 >= 2)
            BG_SYS_ChangeScroll(2, 0, 0);
        else
            BG_SYS_ChangeScroll(2, 0, -0x40);
        break;
    }
}
