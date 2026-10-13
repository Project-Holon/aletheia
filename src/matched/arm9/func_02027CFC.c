/*
 * function: APP_TASKMENU_SetCursorPos
 * address:  0x02027CFC
 * packet:   pkt_02027CFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020355C4 0x020355C4  arm
 *   APP_TASKMENU_SetWinActive 0x02027B30  thumb
 */
#include "../include/Obj06917.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 func_020355C4(void);
struct S;
extern void APP_TASKMENU_SetWinActive(u32 a0, struct S *s, int mode);

void APP_TASKMENU_SetCursorPos(u8 *p, int sel)
{
    int i;

    *p = sel;
    if (func_020355C4() != 0) {
        return;
    }
    i = 0;
    while (i < ((struct Obj06917 *)p)->f24) {
        if (i == sel) {
            APP_TASKMENU_SetWinActive((*(u32 **)(p + 0x18))[i], (struct S *)(((struct Obj06917 *)p)->f34), 1);
        } else {
            APP_TASKMENU_SetWinActive((*(u32 **)(p + 0x18))[i], (struct S *)(((struct Obj06917 *)p)->f34), 0);
        }
        i++;
    }
}
