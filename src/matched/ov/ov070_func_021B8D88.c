/*
 * function: ITEMMENU_TaskWaitPocketTabPress
 * address: 0x021B8D88
 * packet: pkt_ov070_021B8D88
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ITEMMENU_SetTask 0x021B6100 thumb ov070
 */
#include "../include/Obj00002.h"
typedef unsigned short u16;
typedef void (*Callback)(void *);
extern void ITEMMENU_SetTask(char *p, int k);
void ITEMMENU_TaskWaitPocketTabPress(char *p)
{
    if (((struct Obj00002 *)p)->f866 == 0) {
        ((struct Obj00002 *)p)->f864 = 0;
        ITEMMENU_SetTask(p, (int)(*(Callback *)&((struct Obj00002 *)p)->f868));
    } else {
        ((struct Obj00002 *)p)->f866 -= 1;
    }
}
