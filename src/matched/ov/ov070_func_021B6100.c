/*
 * unit: yes
 * function: ITEMMENU_SetTask, ITEMMENU_ForceRedrawList
 * address: 0x021B6100
 * packet: pkt_ov070_021B6100
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_SetRepeatSpeed 0x02036270 arm
 *   ITEMMENU_RedrawList 0x021B6138 thumb ov070
 */
#include "../include/Obj00002.h"
#include "../include/Obj20659.h"
extern int KEY_SetRepeatSpeed(int a0, int a1);
extern void ITEMMENU_RedrawList(char *p);
void ITEMMENU_SetTask(char *p, int k)
{
    *(int *)&((struct Obj00002 *)p)->f4F8 = k;
    KEY_SetRepeatSpeed(((struct Obj00002 *)p)->f86C, ((struct Obj00002 *)p)->f870);
}
void ITEMMENU_ForceRedrawList(char *p)
{
    ((struct Obj20659 *)p)->f818 = 0xFFFF;
    ITEMMENU_RedrawList(p);
}
