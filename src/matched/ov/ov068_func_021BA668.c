/*
 * function: OPTION_MENU_IsButtonFinished
 * address:  0x021BA668
 * packet:   pkt_021BA668
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   APP_TASKMENU_WIN_IsFinish  0x02028230  thumb
 *   OPTION_MENU_ResetButtons  0x021BA694  thumb
 */
#include "../include/Obj13140.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
extern void OPTION_MENU_ResetButtons(u8 *p);

u32 OPTION_MENU_IsButtonFinished(u8 *p)
{
    u32 r = 0;

    if (((struct Obj13140 *)p)->f10 != 0) {
        u32 t = ((struct Obj13140 *)p)->fC;

        if (t != 3) {
            r = APP_TASKMENU_WIN_IsFinish((u8 *)(*(u32 *)(p + t * 4 + 0x34)));
            if (r != 0) {
                OPTION_MENU_ResetButtons(p);
            }
        }
    }
    return r;
}
