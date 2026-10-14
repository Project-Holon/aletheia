/*
 * function: WORLDTRADE_SEARCH_HandleButton
 * address: 0x021FE264
 * packet: pkt_ov135_021FE264
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_Start 0x0202208C thumb
 *   POKE_PERSONAL_Create 0x0201ADE4 thumb
 *   POKE_PERSONAL_GetParam 0x0201AE1C thumb
 *   POKE_PERSONAL_Delete 0x0201AE14 thumb
 *   WORLDTRADE_DEPOSIT_CheckGenderEvent 0x021F7B9C thumb ov135
 *   WORLDTRADE_SEARCH_PrintMessage 0x021FF318 thumb ov135
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 */
#include "../include/Obj00018.h"
#include "../include/Obj23414.h"
#include "../include/Obj23415.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void *POKE_PERSONAL_Create(u32,int,u32);
struct Personal;
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *p);
extern int WORLDTRADE_DEPOSIT_CheckGenderEvent(u8 *p, int event);
extern void WORLDTRADE_SEARCH_PrintMessage(u8 *p, u32 k, int b, int c, int d);
extern void WORLDTRADE_SetNextState(u8 *p, u32 a, u32 b);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
void WORLDTRADE_SEARCH_HandleButton(u8 *p, int mode)
{
    u32 h,v;
    switch(mode) {
    case 0: ((struct Obj00018 *)p)->f28=4; break;
    case 1:
        if(((struct Obj00018 *)p)->fB56!=0) {
            h=(u32)POKE_PERSONAL_Create((u16)((struct Obj00018 *)p)->fB56,0,0x48);
            v=POKE_PERSONAL_GetParam((const struct Personal *)h,0x14);
            POKE_PERSONAL_Delete((void *)h);
            ((struct Obj23414 *)(*(u8 * *)&((struct Obj00018 *)p)->fE00))->f20=v;
            if(WORLDTRADE_DEPOSIT_CheckGenderEvent(p+0xB56,((struct Obj23415 *)(*(u8 * *)&((struct Obj00018 *)p)->fE00))->f20)) break;
        }
        ((struct Obj00018 *)p)->f28=7;
        break;
    case 2: ((struct Obj00018 *)p)->f28=10; break;
    case 3: ((struct Obj00018 *)p)->f28=13; break;
    case 4:
        if(*(u32 *)&((struct Obj00018 *)p)->fD0) {
            ((struct Obj00018 *)p)->f28=32;
            WIPE_SYS_Start(0,0,0,0,16,1,0x48);
        }
        break;
    case 5: ((struct Obj00018 *)p)->f28=16; break;
    case 6:
        WORLDTRADE_SEARCH_PrintMessage(p,15,1,0,0xF0F);
        WORLDTRADE_SetNextState(p,23,26);
        break;
    }
}
