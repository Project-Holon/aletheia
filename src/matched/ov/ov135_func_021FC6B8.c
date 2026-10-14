/*
 * function: WORLDTRADE_DETAIL_StateCreateMenu
 * address: 0x021FC6B8
 * packet: pkt_ov135_021FC6B8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   WORLDTRADE_OpenTaskMenuList 0x021F4D50 thumb ov135
 *   WORLDTRADE_SetBrightnessOut 0x021F5034 thumb ov135
 */
#include "../include/Obj00448.h"
typedef unsigned int u32;
extern void *BMP_MENUWORK_Create(u32 n, u32 heap);
typedef unsigned short u16;
typedef unsigned char  u8;
struct Slot;
extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern void WORLDTRADE_OpenTaskMenuList(u8 *p, u16 a, int count, int b);
extern void WORLDTRADE_SetBrightnessOut(u32 x);
int WORLDTRADE_DETAIL_StateCreateMenu(char *p)
{
    ((struct Obj00448 *)p)->fDE8 = BMP_MENUWORK_Create(2, 0x48);
    BMP_MENUWORK_AddMsgItem(((struct Obj00448 *)p)->fDE8, (u32)(((struct Obj00448 *)p)->fB6C), 0x3d, 1, 0x48);
    BMP_MENUWORK_AddMsgItem(((struct Obj00448 *)p)->fDE8, (u32)(((struct Obj00448 *)p)->fB6C), 0x3e, 2, 0x48);
    WORLDTRADE_OpenTaskMenuList((u8 *)p, 2, 2, 0x14);
    WORLDTRADE_SetBrightnessOut(1);
    *(int *)&((struct Obj00448 *)p)->f28 = 8;
    return 2;
}
