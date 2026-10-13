/*
 * function: PMSIV_MENU_Create
 * address: 0x021BC990
 * packet: pkt_ov110_021BC990
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gPmsivMenuHeapSite 0x021C3C68 data
 *   func_02030734 0x02030734 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   PMS_INPUT_GetUiInputModePtr 0x021BF6D4 thumb ov110
 *   PMS_INPUT_VIEW_GetFont 0x021BAC44 thumb ov110
 *   PMS_INPUT_VIEW_GetPrintQue 0x021BAC4C thumb ov110
 *   PMSIV_MENU_CreateBackButton 0x021BD194 thumb ov110
 *   PMSIV_MENU_CreateItems 0x021BD044 thumb ov110
 *   PMSIV_MENU_CreateExtraItems 0x021BD114 thumb ov110
 *   PMSIV_MENU_LoadBlendColors 0x021BD2F0 thumb ov110
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 */
#include "../include/Obj01249.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern const char gPmsivMenuHeapSite[];
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern u8 *PMS_INPUT_GetUiInputModePtr(u8 *);
typedef unsigned int   u32;
struct MsgBank;
struct R;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern unsigned PMS_INPUT_VIEW_GetFont(u8 *);
extern unsigned PMS_INPUT_VIEW_GetPrintQue(u8 *);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void PMSIV_MENU_CreateBackButton(u8 *);
extern void PMSIV_MENU_CreateItems(u8 *);
extern void PMSIV_MENU_CreateExtraItems(u8 *);
extern void PMSIV_MENU_LoadBlendColors(u8 *);
u8 *PMSIV_MENU_Create(u8 *a,u8 *b,void *c)
{
    u8 *p;
    int i;
    unsigned x;
    p=func_02030734(42,188,1,gPmsivMenuHeapSite,309);
    *(u8 * *)&((struct Obj01249 *)p)->f0=a; *(u8 * *)&((struct Obj01249 *)p)->f4=b; ((struct Obj01249 *)p)->f8=c;
    *(u8 * *)&((struct Obj01249 *)p)->fC=PMS_INPUT_GetUiInputModePtr(b);
    ((struct Obj01249 *)p)->f30=func_02045B38(0,2,146,42);
    for (i=0;i<3;i++) {
        x=PMS_INPUT_VIEW_GetFont(*(u8 * *)&((struct Obj01249 *)p)->f0);
        *(void **)(p+0x34+i*4)=APP_TASKMENU_RES_Create(0,8,x,PMS_INPUT_VIEW_GetPrintQue(*(u8 * *)&((struct Obj01249 *)p)->f0),42);
    }
    func_02049B40(43,9,0,448,64,42);
    PMSIV_MENU_CreateBackButton(p);PMSIV_MENU_CreateItems(p);PMSIV_MENU_CreateExtraItems(p);PMSIV_MENU_LoadBlendColors(p);
    return p;
}
