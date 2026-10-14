/*
 * function: WORLDTRADE_BOX_StateCancelConfirmInput
 * address: 0x021F63A8
 * packet: pkt_ov135_021F63A8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_UpdateTaskMenuYesNo 0x021F4D14 thumb ov135
 *   WORLDTRADE_CloseTaskMenu 0x021F4CE4 thumb ov135
 *   WORLDTRADE_SetStateAndReturn 0x021F4EC0 thumb ov135
 *   func_02034714 0x02034714 arm
 *   d_02203B68 0x02203B68 data a4
 */
#include "../include/Obj00045.h"
typedef unsigned char u8;
extern int WORLDTRADE_UpdateTaskMenuYesNo(char *p);
extern void WORLDTRADE_CloseTaskMenu(char *p);
typedef unsigned int   u32;
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_02203B68[];
int WORLDTRADE_BOX_StateCancelConfirmInput(u8 *p)
{
    unsigned result = WORLDTRADE_UpdateTaskMenuYesNo((char *)p);
    func_02034714(d_02203B68, 0, d_02203B68);
    if (result == 1) {
        WORLDTRADE_CloseTaskMenu((char *)p);
        ((struct Obj00045 *)p)->f28 = 2;
        WORLDTRADE_SetStateAndReturn(p, 0, 0);
    } else if (result == 2) {
        WORLDTRADE_CloseTaskMenu((char *)p);
        ((struct Obj00045 *)p)->f28 = 0;
    }
    return 2;
}
