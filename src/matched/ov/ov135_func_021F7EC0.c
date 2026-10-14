/*
 * function: WORLDTRADE_DEPOSIT_StateConfirmYesNoInput
 * address: 0x021F7EC0
 * packet: pkt_ov135_021F7EC0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_UpdateTaskMenuYesNo 0x021F4D14 thumb ov135
 *   WORLDTRADE_CloseTaskMenu 0x021F4CE4 thumb ov135
 *   WORLDTRADE_SetStateAndReturn 0x021F4EC0 thumb ov135
 *   WORLDTRADE_DEPOSIT_StoreOfferInWork 0x021F8668 thumb ov135
 */
#include "../include/Obj10576.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int WORLDTRADE_UpdateTaskMenuYesNo(char *p);
extern void WORLDTRADE_CloseTaskMenu(char *p);
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);
extern void WORLDTRADE_DEPOSIT_StoreOfferInWork(u8 *dst, u8 *p);
int WORLDTRADE_DEPOSIT_StateConfirmYesNoInput(u8 *p)
{
    int result;
    result = WORLDTRADE_UpdateTaskMenuYesNo((char *)p);
    if (result == 1) {
        WORLDTRADE_CloseTaskMenu((char *)p);
        WORLDTRADE_SetStateAndReturn(p, 7, 7);
        ((struct Obj10576 *)p)->f28 = 2;
        ((struct Obj10576 *)p)->fEB4 = 1;
        WORLDTRADE_DEPOSIT_StoreOfferInWork(p + 0xE4, p);
    } else if (result == 2) {
        WORLDTRADE_CloseTaskMenu((char *)p);
        WORLDTRADE_SetStateAndReturn(p, 5, 5);
        ((struct Obj10576 *)p)->f28 = 2;
    }
    return 2;
}
