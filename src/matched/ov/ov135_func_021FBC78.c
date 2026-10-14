/*
 * function: WORLDTRADE_INPUT_StateConditionListClose
 * address: 0x021FBC78
 * packet: pkt_ov135_021FBC78
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   WORLDTRADE_INPUT_MenuFinish 0x021F9660 thumb ov135
 *   BMP_MENUWORK_Delete  0x0201F868  thumb  arm9
 */
#include "../include/Obj00098.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int on);
extern void WORLDTRADE_INPUT_MenuFinish(void *p, u32 mode);
extern u32 BMP_MENUWORK_Delete(void *p);
int WORLDTRADE_INPUT_StateConditionListClose(u8 *p)
{
    if (CLACT_IsActorAnimActive(((struct Obj00098 *)p)->f8) != 0) return -1;
    CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)&((struct Obj00098 *)p)->f8, 0);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00098 *)p)->fC, 0);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00098 *)p)->f10, 0);
    WORLDTRADE_INPUT_MenuFinish(p, 3);
    BMP_MENUWORK_Delete(((struct Obj00098 *)p)->f30);
    return ((struct Obj00098 *)p)->f3E;
}
