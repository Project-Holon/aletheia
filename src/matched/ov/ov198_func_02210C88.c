/*
 * function: B_PLIST_MAIN_ApplyMode
 * address: 0x02210C88
 * packet: pkt_ov198_02210C88
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   B_PLIST_DRAW_DeleteStateWindows 0x0220BDD4 thumb ov198
 *   B_PLIST_DRAW_CreateStateWindows 0x0220BC70 thumb ov198
 *   B_PLIST_DRAW_DrawModePage 0x0220BE2C thumb ov198
 *   B_PLIST_MAIN_LoadModePalette 0x02210D4C thumb ov198
 *   BG_SYS_ClearLayerEx 0x02041570 arm
 *   B_PLIST_DRAW_ShowToolWindows 0x0220E25C thumb ov198
 *   B_PLIST_MAIN_DrawExpBar 0x02210BFC thumb ov198
 *   B_PLIST_DRAW_LayoutActors 0x0220EA68 thumb ov198
 *   B_PLIST_MAIN_InitSelectionForMode 0x02210FCC thumb ov198
 *   B_PLIST_ANM_UpdateByMode 0x0220B848 thumb ov198
 *   B_PLIST_ANM_CopyPaletteSlot 0x0220BB94 thumb ov198
 * FCC receives only two loaded arguments here; mode is in 0..8, so its
 * out-of-domain incoming-r2 fallback is unused. BB94 receives live mode.
 */
#include "../include/Obj03351.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct State { u8 pad[0x2177]; u8 step:4; u8 flags:4; } State;
typedef unsigned short u16;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern void B_PLIST_DRAW_DeleteStateWindows(char *);
extern void B_PLIST_DRAW_CreateStateWindows(u8 *,u32);
extern int B_PLIST_DRAW_DrawModePage(char *,int);
extern void B_PLIST_MAIN_LoadModePalette(u8 *,u32);
extern void BG_SYS_ClearLayerEx(int channel, u16 val);
extern void B_PLIST_DRAW_ShowToolWindows(u8 *);
extern void B_PLIST_MAIN_DrawExpBar(u8 *,int);
extern void B_PLIST_DRAW_LayoutActors(char *,unsigned);
extern void B_PLIST_MAIN_InitSelectionForMode(u8 *,u32);
extern void B_PLIST_ANM_UpdateByMode(u8 *,unsigned);
extern void B_PLIST_ANM_CopyPaletteSlot(u8 *,unsigned);
int B_PLIST_MAIN_ApplyMode(u8 *p,unsigned mode)
{
    switch(((State *)p)->step) {
    case 0:
        if(PRINTSYS_QUE_IsFinished(((struct Obj03351 *)p)->f1EAC)==1) {
            B_PLIST_DRAW_DeleteStateWindows((char *)p);
            B_PLIST_DRAW_CreateStateWindows(p,mode);
            B_PLIST_DRAW_DrawModePage((char *)p,mode);
            ((State *)p)->step=(u8)(((State *)p)->step+1);
        }
        break;
    case 1:
        if(PRINTSYS_QUE_IsFinished(((struct Obj03351 *)p)->f1EAC)==1) {
            B_PLIST_MAIN_LoadModePalette(p,mode);
            BG_SYS_ClearLayerEx(4,0);
            BG_SYS_ClearLayerEx(5,0);
            B_PLIST_DRAW_ShowToolWindows(p);
            B_PLIST_MAIN_DrawExpBar(p,mode);
            B_PLIST_DRAW_LayoutActors((char *)p,mode);
            B_PLIST_MAIN_InitSelectionForMode(p,mode);
            B_PLIST_ANM_UpdateByMode(p,mode);
            B_PLIST_ANM_CopyPaletteSlot(p,mode);
            p[0x2180]=mode;
            ((State *)p)->step=0;
            return 1;
        }
        break;
    }
    return 0;
}
