/*
 * function: WORLDTRADE_LIST_StateConfirmYesNoInput
 * address: 0x021FD550
 * packet: pkt_ov135_021FD550
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_UpdateTaskMenuYesNo 0x021F4D14 thumb ov135
 *   WORLDTRADE_CloseTaskMenu 0x021F4CE4 thumb ov135
 *   WORLDTRADE_SetStateAndReturn 0x021F4EC0 thumb ov135
 *   WORLDTRADE_LIST_PrintLabel 0x021FD760 thumb ov135
 *   WORLDTRADE_LIST_PrintHeader 0x021FD790 thumb ov135
 *   WORLDTRADE_LIST_DrawSelectedRecord 0x021FD5F0 thumb ov135
 */
#include "../include/Obj00045.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern int WORLDTRADE_UpdateTaskMenuYesNo(char *p);
extern void WORLDTRADE_CloseTaskMenu(char *p);
typedef unsigned char  u8;
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);
extern void WORLDTRADE_LIST_PrintLabel(void *, void *, u32, void *, u16);
extern void WORLDTRADE_LIST_PrintHeader(void *, void *, u32, void *);
extern void WORLDTRADE_LIST_DrawSelectedRecord(void *);
extern void func_0201F7A8(void *, u32);
int WORLDTRADE_LIST_StateConfirmYesNoInput(unsigned char *p)
{
    unsigned r = WORLDTRADE_UpdateTaskMenuYesNo((char *)p);
    if (r == 1) {
        WORLDTRADE_CloseTaskMenu((char *)p);
        *(int *)&((struct Obj00045 *)p)->f28 = 2;
        WORLDTRADE_SetStateAndReturn(p, 5, 6);
        WORLDTRADE_LIST_PrintLabel(((struct Obj00045 *)p)->fB6C, p + 0xdc8, 0x53, p + 0xfa0, 0x440);
        WORLDTRADE_LIST_PrintLabel(((struct Obj00045 *)p)->fB6C, p + 0xdb4, 0x57, p + 0xfa0, 0x3c40);
        WORLDTRADE_LIST_DrawSelectedRecord(p);
    } else if (r == 2) {
        WORLDTRADE_CloseTaskMenu((char *)p);
        func_0201F7A8(((struct Obj00045 *)p)->fD40, 0);
        *(int *)&((struct Obj00045 *)p)->f28 = 1;
        WORLDTRADE_LIST_PrintHeader(((struct Obj00045 *)p)->fB6C, p + 0xd50, 0x5e, p + 0xfa0);
        WORLDTRADE_LIST_PrintHeader(((struct Obj00045 *)p)->fB6C, p + 0xd54, 0x73, p + 0xfa0);
    }
    return 2;
}
