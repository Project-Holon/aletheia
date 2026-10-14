/*
 * function: WORLDTRADE_DEPOSIT_StateCreateSpeciesMenu
 * address: 0x021F7B50
 * packet: pkt_ov135_021F7B50
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_DEPOSIT_CreateSpeciesMenuList 0x021F875C thumb ov135
 */
#include "../include/Obj02855.h"
#include "../include/Obj23386.h"
typedef unsigned char u8;
extern void *WORLDTRADE_DEPOSIT_CreateSpeciesMenuList(void *p, void *dst, void *win, void *bank, void *names, void *obj, void *ctx);
int WORLDTRADE_DEPOSIT_StateCreateSpeciesMenu(u8 *p)
{
    ((struct Obj02855 *)p)->fDF4 = WORLDTRADE_DEPOSIT_CreateSpeciesMenuList(p, p + 0xDE8, ((struct Obj02855 *)p)->fD54, ((struct Obj02855 *)p)->fB6C, ((struct Obj02855 *)p)->fB70, ((struct Obj02855 *)p)->fE00, ((struct Obj23386 *)(*(u8 * *)&((struct Obj02855 *)p)->f0))->f10);
    ((struct Obj02855 *)p)->fBC = 0xFFFF;
    ((struct Obj02855 *)p)->f28 = 6;
    return 2;
}
