/*
 * function: B_PLIST_MAIN_Init
 * address: 0x0220F4E0
 * packet: pkt_ov198_0220F4E0
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: hardware halfword store at 0220F4EC writes display register 04001050.
 * symbols:
 *   d_04001050 0x04001050 data a2
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   TCBL_Create 0x0203101C arm
 *   B_APP_TOOL_Create 0x0220AF40 thumb ov196
 *   B_APP_TOOL_SetActorsVisible 0x0220AFDC thumb ov196
 *   B_PLIST_MAIN_InitOrder 0x02211034 thumb ov198
 *   B_PLIST_MAIN_ReadParty 0x0221099C thumb ov198
 *   B_PLIST_MAIN_InitBg 0x022104EC thumb ov198
 *   B_PLIST_MAIN_LoadGraphics 0x02210608 thumb ov198
 *   B_PLIST_MAIN_CreateTextResources 0x02210710 thumb ov198
 *   B_PLIST_MAIN_LoadModePalette 0x02210D4C thumb ov198
 *   B_PLIST_ANM_UpdateByMode 0x0220B848 thumb ov198
 *   B_PLIST_ANM_CopyPaletteSlot 0x0220BB94 thumb ov198
 *   B_PLIST_DRAW_Init 0x0220E2B4 thumb ov198
 *   B_PLIST_MAIN_SyncMoveActors 0x0220F060 thumb ov198
 *   B_PLIST_DRAW_LayoutActors 0x0220EA68 thumb ov198
 *   B_PLIST_ANM_CreateTileWindows 0x0220BC24 thumb ov198
 *   B_PLIST_DRAW_DrawModePage 0x0220BE2C thumb ov198
 *   B_PLIST_DRAW_ShowToolWindows 0x0220E25C thumb ov198
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_MAIN_IsBattleSlot 0x02210F04 thumb ov198
 *   B_PLIST_MAIN_CreateCursor 0x02211998 thumb ov198
 *   B_PLIST_MAIN_DrawExpBar 0x02210BFC thumb ov198
 *   PALANM_RequestFade 0x0202173C thumb
 */
#include "../include/Obj00633.h"
#include "../include/Obj25226.h"
#include "../include/Obj25227.h"
#include "../include/Obj25228.h"
#include "../include/Obj25229.h"
#include "../include/Obj25231.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern volatile u16 d_04001050[];
struct Tcbl;
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u8 *B_APP_TOOL_Create(u16 v);
extern void B_APP_TOOL_SetActorsVisible(char *p, void *v);
extern void B_PLIST_MAIN_InitOrder(u8 *);
extern void B_PLIST_MAIN_ReadParty(u8 *);
extern void B_PLIST_MAIN_InitBg(u8 *);
extern void B_PLIST_MAIN_LoadGraphics(char *p);
extern void B_PLIST_MAIN_CreateTextResources(char *p);
extern void B_PLIST_MAIN_LoadModePalette(u8 *,u32),B_PLIST_ANM_UpdateByMode(u8 *,u32),B_PLIST_ANM_CopyPaletteSlot(u8 *,u32);
extern void B_PLIST_DRAW_Init(char *),B_PLIST_MAIN_SyncMoveActors(u8 *),B_PLIST_DRAW_LayoutActors(char *,u32),B_PLIST_ANM_CreateTileWindows(u8 *);
extern int B_PLIST_DRAW_DrawModePage(char *,int);
extern void B_PLIST_DRAW_ShowToolWindows(u8 *);
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
extern u32 B_PLIST_MAIN_IsBattleSlot(u32,u32);
extern void B_PLIST_MAIN_CreateCursor(u8 *,u32,u32),B_PLIST_MAIN_DrawExpBar(u8 *,int);
extern int PALANM_RequestFade(void *,u16,u16,short,u8,u8,u16,void *);
int B_PLIST_MAIN_Init(u8 *p)
{
    d_04001050[0]=0;
    GXx_SetMasterBrightness_((u16 *)((u32)d_04001050+28),-16);
    ((struct Obj00633 *)p)->f1D4=TCBL_Create(((struct Obj25226 *)(*(u8 * *)&((struct Obj00633 *)p)->f0))->f10,((struct Obj25227 *)(*(u8 * *)&((struct Obj00633 *)p)->f0))->f10,1,4);
    if((*(u8 **)p)[31]==4) p[0x2180]=6;
    else if((*(u8 **)p)[31]==5) p[0x2180]=4;
    else p[0x2180]=0;
    ((struct Obj00633 *)p)->f2188=B_APP_TOOL_Create(((struct Obj25228 *)(*(u8 * *)&((struct Obj00633 *)p)->f0))->f10);
    B_PLIST_MAIN_InitOrder(p);B_PLIST_MAIN_ReadParty(p);B_PLIST_MAIN_InitBg(p);B_PLIST_MAIN_LoadGraphics((char *)p);B_PLIST_MAIN_CreateTextResources((char *)p);
    B_PLIST_MAIN_LoadModePalette(p,p[0x2180]);B_PLIST_ANM_UpdateByMode(p,p[0x2180]);B_PLIST_ANM_CopyPaletteSlot(p,p[0x2180]);
    B_PLIST_DRAW_Init((char *)p);
    if((*(u8 **)p)[31]==5) B_PLIST_MAIN_SyncMoveActors(p);
    B_PLIST_DRAW_LayoutActors((char *)p,p[0x2180]);B_PLIST_ANM_CreateTileWindows(p);B_PLIST_DRAW_DrawModePage((char *)p,p[0x2180]);B_PLIST_DRAW_ShowToolWindows(p);
    if(**(u8 * *)&((struct Obj25229 *)(*(u8 * *)&((struct Obj00633 *)p)->f0))->f44==1) *(u32 *)&((struct Obj00633 *)p)->f218C=1;
    else *(u32 *)&((struct Obj00633 *)p)->f218C=0;
    B_APP_TOOL_SetActorsVisible((char *)(*(u8 * *)&((struct Obj00633 *)p)->f2188),((struct Obj00633 *)p)->f218C);
    if(p[0x2180]==0) {
        if(B_PLIST_MAIN_IsBattleSlot((u32)p,B_PLIST_MAIN_GetOrderIndex(p,0))==1) (*(u8 **)p)[32]=1;
        B_PLIST_MAIN_CreateCursor(p,p[0x2180],(*(u8 **)p)[32]);
    } else if((*(u8 **)p)[31]==5) B_PLIST_MAIN_CreateCursor(p,p[0x2180],(*(u8 **)p)[75]);
    else B_PLIST_MAIN_CreateCursor(p,p[0x2180],0);
    B_PLIST_MAIN_DrawExpBar(p,p[0x2180]);
    PALANM_RequestFade(((struct Obj00633 *)p)->f1D8,10,65535,0,16,0,0,((struct Obj25231 *)(*(u8 * *)&((struct Obj00633 *)p)->f0))->f28);
    ((struct Obj00633 *)p)->f2540=1;
    return 1;
}
