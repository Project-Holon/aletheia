/*
 * unit: yes
 * function: UN_SELECT_SceneStepMenuOut, UN_SELECT_Callback
 * address: 0x021BA21C
 * packet: pkt_ov218_021BA21C
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: parent-cleared ov218021BA238; lead EXACT*28B, no ARM9 blocker; independent ldrh/threshold/bx Thumb body fills remaining88B before A290.
 * volatile: VCOUNT04000006 read at A23A, SUB_BLDALPHA04001052 written at A244/A250/A25C/A268/A26E.
 * symbols:
 *   UN_SELECT_RequestBrightness 0x021B9944 thumb ov218
 *   UN_SELECT_DrawWindowBorder 0x021B9C74 thumb ov218
 *   UI_SCENE_SetNextScene 0x021B61F8 thumb ov067
 */
#include "../include/Obj26048.h"
extern void UN_SELECT_RequestBrightness(void);
typedef unsigned char  u8;
extern void UN_SELECT_DrawWindowBorder(u8 *p);
extern void UI_SCENE_SetNextScene(unsigned char *task, int value);
int UN_SELECT_SceneStepMenuOut(unsigned char *task, char *ctx)
{
    UN_SELECT_RequestBrightness();
    UN_SELECT_DrawWindowBorder(((struct Obj26048 *)ctx)->f28);
    UI_SCENE_SetNextScene(task, 0);
    return 1;
}
void UN_SELECT_Callback(void)
{
    int count = *(volatile unsigned short *)0x04000006;
    if (count >= 152)
        *(volatile unsigned short *)0x04001052 = 0x050b;
    else if (count >= 112)
        *(volatile unsigned short *)0x04001052 = 0x060a;
    else if (count >= 72)
        *(volatile unsigned short *)0x04001052 = 0x0709;
    else if (count >= 32)
        *(volatile unsigned short *)0x04001052 = 0x0808;
    else
        *(volatile unsigned short *)0x04001052 = 0x0a06;
}
