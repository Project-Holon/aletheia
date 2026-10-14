/*
 * function: WORLDTRADE_BOX_StateCreateOfferMenu
 * address:  0x021F5FC0
 * packet:   pkt_021F5FC0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_OpenTaskMenuList  0x021F4D50  thumb  ov135
 *   BMP_MENUWORK_Create  0x0201F81C  thumb  arm9
 *   BMP_MENUWORK_AddMsgItem  0x0201F878  thumb  arm9

 * Create the resource, register the three 68/69/6a entries and latch state 0x8.
 */
#include "../include/Obj00448.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern u32 BMP_MENUWORK_Create(u32 a, u32 b);
struct Slot;
extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern void WORLDTRADE_OpenTaskMenuList(u8 *p, u16 a, int count, int b);

int WORLDTRADE_BOX_StateCreateOfferMenu(u8 *p)
{
    *(u32 *)&((struct Obj00448 *)p)->fDE8 = BMP_MENUWORK_Create(3, 0x48);
    BMP_MENUWORK_AddMsgItem((struct Slot *)(*(u32 *)&((struct Obj00448 *)p)->fDE8), *(u32 *)&((struct Obj00448 *)p)->fB6C, 0x68, 1, 0x48);
    BMP_MENUWORK_AddMsgItem((struct Slot *)(*(u32 *)&((struct Obj00448 *)p)->fDE8), *(u32 *)&((struct Obj00448 *)p)->fB6C, 0x69, 2, 0x48);
    BMP_MENUWORK_AddMsgItem((struct Slot *)(*(u32 *)&((struct Obj00448 *)p)->fDE8), *(u32 *)&((struct Obj00448 *)p)->fB6C, 0x6a, 3, 0x48);
    WORLDTRADE_OpenTaskMenuList(p, 0, 3, 0x14);
    ((struct Obj00448 *)p)->f28 = 0x8;
    return 2;
}
