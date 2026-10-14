/*
 * function: WORLDTRADE_DEPOSIT_StateCategoryMenuInput
 * address: 0x021F7A8C
 * packet: pkt_ov135_021F7A8C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_ENTER_UpdateListMenu 0x021F8950 thumb ov135
 *   WORLDTRADE_ADAPTER_ClearWindowScreen 0x02202644 thumb ov135
 *   WORLDTRADE_SetStateAndReturn 0x021F4EC0 thumb ov135
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_MENUWORK_Delete  0x0201F868  thumb  arm9
 *   BMP_MENULIST_Delete  0x0202020C  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj01552.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int WORLDTRADE_ENTER_UpdateListMenu(void *p, u16 *old);
typedef unsigned int   u32;
struct Descriptor;
struct Obj;
extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);
extern u32 BMP_MENUWORK_Delete(void *p);
extern void WORLDTRADE_ADAPTER_ClearWindowScreen(u32 a, int kind);
extern void func_0201F7A8(void *p, unsigned kind);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
int WORLDTRADE_DEPOSIT_StateCategoryMenuInput(u8 *p)
{
    switch ((unsigned)WORLDTRADE_ENTER_UpdateListMenu(((struct Obj01552 *)p)->fDF4, (u16 *)(p + 0xBC))) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
        BMP_MENULIST_Delete(((struct Obj01552 *)p)->fDF4, (u16 *)(*(u8 * *)&((struct Obj01552 *)p)->fE00 + 6), (u16 *)(*(u8 * *)&((struct Obj01552 *)p)->fE00 + 4));
        BMP_MENUWORK_Delete(((struct Obj01552 *)p)->fDE8);
        ((struct Obj01552 *)p)->f28 = 5;
        GFL_USE_PlaySeDefaultVolume(0x54C);
        break;
    case (unsigned)-2:
        BMP_MENULIST_Delete(((struct Obj01552 *)p)->fDF4, (u16 *)(*(u8 * *)&((struct Obj01552 *)p)->fE00 + 6), (u16 *)(*(u8 * *)&((struct Obj01552 *)p)->fE00 + 4));
        BMP_MENUWORK_Delete(((struct Obj01552 *)p)->fDE8);
        WORLDTRADE_ADAPTER_ClearWindowScreen((u32)(((struct Obj01552 *)p)->fD50), 0);
        func_0201F7A8(((struct Obj01552 *)p)->fD40, 0);
        BMP_WIN_Delete(((struct Obj01552 *)p)->fD50);
        BMP_WIN_Delete(((struct Obj01552 *)p)->fD54);
        WORLDTRADE_SetStateAndReturn(p, 5, 5);
        ((struct Obj01552 *)p)->f28 = 2;
        GFL_USE_PlaySeDefaultVolume(0x54C);
        break;
    case 0:
        break;
    }
    return 2;
}
