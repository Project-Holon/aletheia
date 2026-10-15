/*
 * function: EGG_DEMO_MAIN_LoadBgm2, EGG_DEMO_MAIN_IsBgm2Loading
 * address: 0x021F6000
 * packet: pkt_ov215_021F6000
 * region: ov215
 * unit: yes
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_StepBgmLoad 0x020063B4 thumb
 */
#include "../include/Obj14708.h"
#include "../include/Obj25744.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 GFL_USE_StepBgmLoad(u8 *a0, u32 *a1, u32 a2);
void EGG_DEMO_MAIN_LoadBgm2(void *unused, char *p)
{
    ((struct Obj14708 *)p)->f24 = 0;
    GFL_USE_StepBgmLoad((u8 *)0x519, (u32 *)(p + 0x24), 1);
    ((struct Obj14708 *)p)->f18 = 5;
}

int EGG_DEMO_MAIN_IsBgm2Loading(void *unused, char *p)
{
    int state = ((struct Obj25744 *)p)->f18;
    int result = 1;
    if (state != 5 && state != 6) result = 0;
    return result;
}
