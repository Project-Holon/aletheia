/*
 * function: WORLDTRADE_TITLE_HandleSelection
 * address: 0x0220053C
 * packet: pkt_ov135_0220053C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_SetStateAndReturn 0x021F4EC0 thumb ov135
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   WORLDTRADE_QueryGameData 0x021F4ED4 thumb ov135
 *   WORLDTRADE_TITLE_PrintMessage 0x022009A4 thumb ov135
 *   WORLDTRADE_TITLE_PrintMessageSub 0x02200A10 thumb ov135
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj01749.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WORLDTRADE_SetStateAndReturn(u8 *, u32, u32);
extern void WORLDTRADE_SetNextState(u8 *, u32, u32);
extern int WORLDTRADE_QueryGameData(void);
extern void WORLDTRADE_TITLE_PrintMessage(u8 *p, u32 n, int a2, int a3, int a4);
extern void WORLDTRADE_TITLE_PrintMessageSub(u8 *, int, int, int, int);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void WORLDTRADE_TITLE_HandleSelection(u8 *p, int mode)
{
    switch (mode) {
    case 0:
        if (((struct Obj01749 *)p)->f32 == 0) {
            WORLDTRADE_SetStateAndReturn(p, 5, 5);
            ((struct Obj01749 *)p)->f28 = 9;
        } else if (((struct Obj01749 *)p)->f36 == 0) {
            WORLDTRADE_SetStateAndReturn(p, 7, 11);
            ((struct Obj01749 *)p)->f18 = 2;
            ((struct Obj01749 *)p)->f28 = 9;
            ((struct Obj01749 *)p)->f36 = 0xE10;
        } else {
            WORLDTRADE_TITLE_PrintMessage(p, 40, 1, 0, 0xF0F);
            WORLDTRADE_SetNextState(p, 11, 5);
            GFL_USE_PlaySeDefaultVolume(0x557);
            ((struct Obj01749 *)p)->fDFC = 0;
        }
        break;
    case 1:
        ((struct Obj01749 *)p)->fE1A = 0;
        WORLDTRADE_SetStateAndReturn(p, 4, 13);
        ((struct Obj01749 *)p)->f28 = 9;
        break;
    case 2:
        WORLDTRADE_TITLE_PrintMessageSub(p, 7, WORLDTRADE_QueryGameData(), 0, 0xF0F);
        WORLDTRADE_SetNextState(p, 10, 12);
        break;
    }
}
