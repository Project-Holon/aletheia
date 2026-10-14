/*
 * function: WORLDTRADE_SEARCH_StateShowEmptyHistoryMessage
 * address: 0x021FE84C
 * packet: pkt_ov135_021FE84C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_SEARCH_PrintMessage 0x021FF318 thumb ov135
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj14175.h"
extern void WORLDTRADE_SEARCH_PrintMessage(unsigned char *p, unsigned int k, int b, int c, int d);
typedef unsigned char  u8;
extern void WORLDTRADE_SetNextState(u8 *p, unsigned int a, unsigned int b);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
int WORLDTRADE_SEARCH_StateShowEmptyHistoryMessage(char *p)
{
    if (((struct Obj14175 *)p)->fD0 == 0) {
        WORLDTRADE_SEARCH_PrintMessage((unsigned char *)p, 14, 1, 0, 0xf0f);
        WORLDTRADE_SetNextState((u8 *)p, 23, 1);
        GFL_USE_PlaySeDefaultVolume(0x557);
    } else {
        WORLDTRADE_SEARCH_PrintMessage((unsigned char *)p, 36, 1, 0, 0xf0f);
        WORLDTRADE_SetNextState((u8 *)p, 23, 21);
        ((struct Obj14175 *)p)->fDFC = 0;
    }
    return 2;
}
