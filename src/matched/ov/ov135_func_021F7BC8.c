/*
 * function: WORLDTRADE_DEPOSIT_StateSpeciesMenuInput
 * address: 0x021F7BC8
 * packet: pkt_ov135_021F7BC8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: signed halfword selection store keeps the unsigned argument truncation after it.
 * symbols:
 *   WORLDTRADE_INPUT_MenuUpdate 0x021F99F0 thumb ov135
 *   WORLDTRADE_SetStateAndReturn 0x021F4EC0 thumb ov135
 *   WORLDTRADE_DEPOSIT_CheckGenderEvent 0x021F7B9C thumb ov135
 *   WORLDTRADE_DEPOSIT_DrawRequestWindow 0x021F81C8 thumb ov135
 *   WORLDTRADE_ENTER_SetListRangeEntry 0x021F89A8 thumb ov135
 *   POKE_PERSONAL_Create 0x0201ADE4 thumb
 *   POKE_PERSONAL_GetParam 0x0201AE1C thumb
 *   POKE_PERSONAL_Delete 0x0201AE14 thumb
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 */
#include "../include/Obj01553.h"
#include "../include/Obj03830.h"
#include "../include/Obj23387.h"
#include "../include/Obj23388.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int WORLDTRADE_INPUT_MenuUpdate(void *);
extern void BMP_MENUWORK_DrawWindowBorder(void *,u32);
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);
extern void *POKE_PERSONAL_Create(u32,int,u32);
struct Personal;
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *p);
extern int WORLDTRADE_DEPOSIT_CheckGenderEvent(u8 *p, int event);
extern void WORLDTRADE_DEPOSIT_DrawRequestWindow(void *bank, void *names, int unused, u8 *win, u32 index, int mode, int place, void *g);
extern void WORLDTRADE_ENTER_SetListRangeEntry(u8 *p, int i, u16 a, u16 b);
int WORLDTRADE_DEPOSIT_StateSpeciesMenuInput(u8 *p)
{
    int result=WORLDTRADE_INPUT_MenuUpdate(((struct Obj01553 *)p)->fDE4);
    u32 h,v;
    int mode;
    u8 *target;
    switch(result) {
    case (u32)-2:
        BMP_MENUWORK_DrawWindowBorder(((struct Obj01553 *)p)->fD40,0);
        WORLDTRADE_SetStateAndReturn(p,5,5);
        ((struct Obj01553 *)p)->f28=2;
        target=*(u8 * *)&((struct Obj01553 *)p)->fE00;
        WORLDTRADE_ENTER_SetListRangeEntry(p+0xEEC,((struct Obj03830 *)target)->f6+((struct Obj03830 *)target)->f4,((struct Obj03830 *)target)->fA,((struct Obj03830 *)target)->f8);
        break;
    case (u32)-1:
        break;
    default:
        ((struct Obj01553 *)p)->fB50=result;
        h=(u32)POKE_PERSONAL_Create((u16)result,0,0x48);
        v=POKE_PERSONAL_GetParam((const struct Personal *)h,20);
        POKE_PERSONAL_Delete((void *)h);
        ((struct Obj23387 *)(*(u8 * *)&((struct Obj01553 *)p)->fE00))->f20=v;
        if(WORLDTRADE_DEPOSIT_CheckGenderEvent(p+0xB50,((struct Obj23388 *)(*(u8 * *)&((struct Obj01553 *)p)->fE00))->f20)) {
            ((struct Obj01553 *)p)->f28=10;
            mode=((struct Obj01553 *)p)->fB52;
        } else {
            ((struct Obj01553 *)p)->f28=7;
            mode=3;
        }
        WORLDTRADE_DEPOSIT_DrawRequestWindow(((struct Obj01553 *)p)->fB6C,((struct Obj01553 *)p)->fB70,(int)(((struct Obj01553 *)p)->fB68),p+0xD90,((struct Obj01553 *)p)->fB50,mode,-1,p+0xFA0);
        target=*(u8 * *)&((struct Obj01553 *)p)->fE00;
        WORLDTRADE_ENTER_SetListRangeEntry(p+0xEEC,((struct Obj03830 *)target)->f6+((struct Obj03830 *)target)->f4,((struct Obj03830 *)target)->fA,((struct Obj03830 *)target)->f8);
        break;
    }
    return 2;
}
