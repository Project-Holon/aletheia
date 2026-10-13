/*
 * function: PMSIV_MENU_Update
 * address: 0x021BCA84
 * packet: pkt_ov110_021BCA84
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding after return.
 * symbols:
 *   PMSIV_MENU_UpdateBlend 0x021BD348 thumb ov110
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb  arm9
 */
#include "../include/Obj06388.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Actor;
extern void APP_TASKMENU_WIN_Update(u8 *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void PMSIV_MENU_UpdateBlend(char *p);
void PMSIV_MENU_Update(u8 *p)
{
    int i;
    for (i=0;i<3;i++) if (*(void **)(p+0x64+i*4)) APP_TASKMENU_WIN_Update(*(void **)(p+0x64+i*4));
    switch (((struct Obj06388 *)p)->f2C) {
    case 0: break;
    case 1: ((struct Obj06388 *)p)->f2C=2;
    case 2: if (!CLACT_IsActorAnimActive(((struct Obj06388 *)p)->f28)) ((struct Obj06388 *)p)->f2C=3; break;
    case 3: ((struct Obj06388 *)p)->f2C=0; break;
    }
    PMSIV_MENU_UpdateBlend((char *)p);
}
