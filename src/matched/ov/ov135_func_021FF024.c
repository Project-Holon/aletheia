/*
 * unit: yes
 * function: WORLDTRADE_SEARCH_StateClearConfirmInput, WORLDTRADE_SEARCH_StateReturnToMain
 * address: 0x021FF024
 * packet: pkt_ov135_021FF024
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_UpdateTaskMenuYesNo 0x021F4D14 thumb ov135
 *   WORLDTRADE_CloseTaskMenu 0x021F4CE4 thumb ov135
 *   WORLDTRADE_SetStateAndReturn 0x021F4EC0 thumb ov135
 *   WORLDTRADE_SUBLCD_UpdateSlotAnims 0x021FFBC8 thumb ov135
 */
#include "../include/Obj00045.h"
#include "../include/Obj23427.h"
extern int WORLDTRADE_UpdateTaskMenuYesNo(char *p);
extern void WORLDTRADE_CloseTaskMenu(char *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);
extern void WORLDTRADE_SUBLCD_UpdateSlotAnims(u8 *p);
int WORLDTRADE_SEARCH_StateClearConfirmInput(char *p)
{
    unsigned r = WORLDTRADE_UpdateTaskMenuYesNo(p);
    if (r == 1) {
        WORLDTRADE_CloseTaskMenu(p);
        *(int *)&((struct Obj00045 *)p)->f28 = 2;
        WORLDTRADE_SetStateAndReturn((u8 *)p, 1, 0);
        if (((struct Obj00045 *)p)->fD0 > 0) WORLDTRADE_SUBLCD_UpdateSlotAnims((u8 *)p);
        ((struct Obj00045 *)p)->fD0 = 0;
    } else if (r == 2) {
        WORLDTRADE_CloseTaskMenu(p);
        *(int *)&((struct Obj00045 *)p)->f28 = 0;
    }
    return 2;
}
int WORLDTRADE_SEARCH_StateReturnToMain(char *p)
{
    ((struct Obj23427 *)p)->f28 = 1;
    return 2;
}
