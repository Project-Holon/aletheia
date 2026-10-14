/*
 * function: WORLDTRADE_SEARCH_StateConfirmSearch
 * address: 0x021FE60C
 * packet: pkt_ov135_021FE60C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_SEARCH_PrintMessage 0x021FF318 thumb ov135
 *   WORLDTRADE_SEARCH_CompareRecords 0x021FF4D0 thumb ov135
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   WORLDTRADE_SUBLCD_UpdateSlotAnims 0x021FFBC8 thumb ov135
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj06518.h"
typedef unsigned int u32;
extern void WORLDTRADE_SEARCH_PrintMessage(unsigned char *p, u32 k, int b, int c, int d);
extern int WORLDTRADE_SEARCH_CompareRecords(void *, void *, u32, u32);
typedef unsigned char  u8;
extern void WORLDTRADE_SetNextState(u8 *p, u32 a, u32 b);
extern void WORLDTRADE_SUBLCD_UpdateSlotAnims(u8 *p);
extern void GFL_USE_PlaySeDefaultVolume(u32);
int WORLDTRADE_SEARCH_StateConfirmSearch(unsigned char *p)
{
    if (((struct Obj06518 *)p)->fB56 == 0) {
        WORLDTRADE_SEARCH_PrintMessage(p, 12, 1, 0, 0xf0f);
        WORLDTRADE_SetNextState(p, 23, 1);
    } else {
        if (WORLDTRADE_SEARCH_CompareRecords(p + 0xb56, p + 0xb5c, ((struct Obj06518 *)p)->fF84, ((struct Obj06518 *)p)->fB64)) {
            WORLDTRADE_SEARCH_PrintMessage(p, 39, 1, 0, 0xf0f);
            WORLDTRADE_SetNextState(p, 23, 1);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x63f);
            ((struct Obj06518 *)p)->f12E8 = 0x76;
            WORLDTRADE_SEARCH_PrintMessage(p, 13, 1, 0, 0xf0f);
            WORLDTRADE_SetNextState(p, 23, 17);
            if (((struct Obj06518 *)p)->fD0 > 0)
                WORLDTRADE_SUBLCD_UpdateSlotAnims(p);
        }
    }
    return 2;
}
