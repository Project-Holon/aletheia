/*
 * function: WORLDTRADE_DEPOSIT_StateLevelMenuInput
 * address: 0x021F7DD0
 * packet: pkt_ov135_021F7DD0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_INPUT_MenuUpdate 0x021F99F0 thumb ov135
 *   WORLDTRADE_DEPOSIT_CheckGenderEvent 0x021F7B9C thumb ov135
 *   WORLDTRADE_DEPOSIT_GetLevelBracket 0x021F882C thumb ov135
 *   WORLDTRADE_DEPOSIT_GetConditionIndex 0x021F886C thumb ov135
 *   WORLDTRADE_DEPOSIT_DrawRequestWindow 0x021F81C8 thumb ov135
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb  arm9
 */
#include "../include/Obj01942.h"
#include "../include/Obj23389.h"
typedef unsigned char u8;
extern int WORLDTRADE_INPUT_MenuUpdate(void *p);
extern void BMP_MENUWORK_DrawWindowBorder(void *p, unsigned kind);
extern int WORLDTRADE_DEPOSIT_CheckGenderEvent(u8 *p, int event);
extern void WORLDTRADE_DEPOSIT_GetLevelBracket(u8 *dst, int i, int kind);
extern int WORLDTRADE_DEPOSIT_GetConditionIndex(int x, int y, int which);
typedef unsigned int   u32;
extern void WORLDTRADE_DEPOSIT_DrawRequestWindow(void *bank, void *names, int unused, u8 *win, u32 index, int mode, int place, void *g);
int WORLDTRADE_DEPOSIT_StateLevelMenuInput(u8 *p)
{
    unsigned result = WORLDTRADE_INPUT_MenuUpdate(((struct Obj01942 *)p)->fDE4);
    switch (result) {
    case 12: case (unsigned)-2:
        BMP_MENUWORK_DrawWindowBorder(((struct Obj01942 *)p)->fD40, 0);
        if (WORLDTRADE_DEPOSIT_CheckGenderEvent(p + 0xB50, ((struct Obj23389 *)(*(u8 * *)&((struct Obj01942 *)p)->fE00))->f20)) {
            ((struct Obj01942 *)p)->f28 = 0;
        } else {
            ((struct Obj01942 *)p)->f28 = 7;
        }
        break;
    case (unsigned)-1:
        break;
    default:
        WORLDTRADE_DEPOSIT_GetLevelBracket(p + 0xB50, result, 0);
        ((struct Obj01942 *)p)->f28 = 13;
        result = WORLDTRADE_DEPOSIT_GetConditionIndex(((struct Obj01942 *)p)->fB53, ((struct Obj01942 *)p)->fB54, 0);
        WORLDTRADE_DEPOSIT_DrawRequestWindow(((struct Obj01942 *)p)->fB6C, ((struct Obj01942 *)p)->fB70, (int)(((struct Obj01942 *)p)->fB68), p + 0xD90, ((struct Obj01942 *)p)->fB50, ((struct Obj01942 *)p)->fB52, result, p + 0xFA0);
        break;
    }
    return 2;
}
