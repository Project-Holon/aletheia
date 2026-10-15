/*
 * function: BR_BTN_SetAnimMode
 * address: 0x021FAD18
 * packet: pkt_ov186_021FAD18
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_BTN_AnimMove 0x021FAFD0 thumb ov186
 *   BR_BTN_AnimMoveRow 0x021FB058 thumb ov186
 *   BR_BTN_AnimFlyOut 0x021FB0E8 thumb ov186
 *   BR_BTN_AnimFlyIn 0x021FB1EC thumb ov186
 *   BR_BTN_AnimMove2 0x021FB2F0 thumb ov186
 */
#include "../include/Obj03891.h"
extern int BR_BTN_AnimMove(char *), BR_BTN_AnimMoveRow(char *), BR_BTN_AnimFlyOut(char *), BR_BTN_AnimFlyIn(char *), BR_BTN_AnimMove2(char *);
void BR_BTN_SetAnimMode(char *ctx, int mode, const int *target)
{
    ((struct Obj03891 *)ctx)->f1C = 0;
    if (target) {
        ((struct Obj03891 *)ctx)->f14 = target[0];
        ((struct Obj03891 *)ctx)->f18 = target[1];
    }
    switch (mode) {
    case 0: *(int (**)(char *))(ctx + 0x10) = BR_BTN_AnimMove; break;
    case 1: *(int (**)(char *))(ctx + 0x10) = BR_BTN_AnimMoveRow; break;
    case 2: *(int (**)(char *))(ctx + 0x10) = BR_BTN_AnimFlyOut; break;
    case 3: *(int (**)(char *))(ctx + 0x10) = BR_BTN_AnimFlyIn; break;
    case 4: *(int (**)(char *))(ctx + 0x10) = BR_BTN_AnimMove2; break;
    }
}
