/*
 * function: WORLDTRADE_SEARCH_StateUpdateHistorySlots
 * address: 0x021FE7F0
 * packet: pkt_ov135_021FE7F0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_StopAllSe 0x02006210 thumb
 *   WORLDTRADE_SUBLCD_UpdateSlotPalettes 0x021FFB20 thumb ov135
 *   WORLDTRADE_SEARCH_DrawHistoryHeader 0x021FF474 thumb ov135
 */
#include "../include/Obj03832.h"
extern void GFL_USE_StopAllSe(void);
typedef unsigned char  u8;
extern void WORLDTRADE_SUBLCD_UpdateSlotPalettes(u8 *p, int count, int flag);
extern void WORLDTRADE_SEARCH_DrawHistoryHeader(void *, void *, int, void *);
int WORLDTRADE_SEARCH_StateUpdateHistorySlots(char *p)
{
    if (((struct Obj03832 *)p)->f12E8 == 0) {
        GFL_USE_StopAllSe();
        WORLDTRADE_SUBLCD_UpdateSlotPalettes((u8 *)p, ((struct Obj03832 *)p)->fD0, 1);
        if (((struct Obj03832 *)p)->fD0 == 0)
            WORLDTRADE_SEARCH_DrawHistoryHeader(((struct Obj03832 *)p)->fDB0, ((struct Obj03832 *)p)->fB6C, 0, p + 0xfa0);
        else
            WORLDTRADE_SEARCH_DrawHistoryHeader(((struct Obj03832 *)p)->fDB0, ((struct Obj03832 *)p)->fB6C, 1, p + 0xfa0);
        ((struct Obj03832 *)p)->f28 = 20;
    }
    return 2;
}
