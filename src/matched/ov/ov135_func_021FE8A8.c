/*
 * function: WORLDTRADE_SEARCH_StateCountdownMessage
 * address: 0x021FE8A8
 * packet: pkt_ov135_021FE8A8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_SEARCH_PrintMessage 0x021FF318 thumb ov135
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 */
#include "../include/Obj14176.h"
extern void WORLDTRADE_SEARCH_PrintMessage(unsigned char *p, unsigned int k, int b, int c, int d);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void WORLDTRADE_SetNextState(u8 *p, u32 a, u32 b);
int WORLDTRADE_SEARCH_StateCountdownMessage(char *p)
{
    if (++((struct Obj14176 *)p)->fDFC > 45) {
        WORLDTRADE_SEARCH_PrintMessage((unsigned char *)p, 38, 1, 0, 0xf0f);
        WORLDTRADE_SetNextState((u8 *)p, 23, 1);
        ((struct Obj14176 *)p)->fE1A = 1;
    }
    return 2;
}
