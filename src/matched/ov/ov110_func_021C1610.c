/*
 * function: PMS_SELECT_GRAPHIC_CreateScene
 * address: 0x021C1610
 * packet: pkt_ov110_021C1610
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Heap argument is u16: widening it adds a truncation before PMS_SELECT_GRAPHIC_InitSceneBgs.
 * volatile: hardware display registers re-read at 021C163C and 021C1646.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   PMS_SELECT_GRAPHIC_InitSceneBgs 0x021C1738 thumb ov110
 *   PMS_SELECT_GRAPHIC_InitSceneActors 0x021C17DC thumb ov110
 *   PMS_SELECT_GRAPHIC_SceneTask 0x021C1724 thumb ov110
 *   func_020056A0 0x020056A0 thumb
 *   gPmsSelectGraphicSceneFileName 0x021C3C98 data a1
 *   gPmsSelectGraphicVramBanks 0x021C3A44 data a4
 */
#include "../include/Obj22414.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern const char gPmsSelectGraphicSceneFileName[];
extern const unsigned gPmsSelectGraphicVramBanks[];
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void MI_CpuFill8(void *,int,unsigned);
extern void BG_SYS_ClearGraphicsMemory(unsigned);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetLcdSwap(unsigned);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern void PMS_SELECT_GRAPHIC_InitSceneBgs(void *,u16);
extern void PMS_SELECT_GRAPHIC_InitSceneActors(void **p, unsigned arg, unsigned heap);
extern void PMS_SELECT_GRAPHIC_SceneTask(int a, u8 *p);
extern void *func_020056A0(void *,void *,unsigned);
void *PMS_SELECT_GRAPHIC_CreateScene(unsigned arg, u16 heap) {
    u8 *p;
    p=func_02030734(heap,16,0,gPmsSelectGraphicSceneFileName,0x151);
    MI_CpuFill8(p,0,16);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)gPmsSelectGraphicVramBanks);
    BG_SYS_SetLcdSwap(arg);
    BG_SYS_ResetSubDisplay(); BG_SYS_ClearMainPlanes(); BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    PMS_SELECT_GRAPHIC_InitSceneBgs(p,heap);
    PMS_SELECT_GRAPHIC_InitSceneActors((void **)(p+4),(unsigned)gPmsSelectGraphicVramBanks,heap);
    ((struct Obj22414 *)p)->fC=func_020056A0(PMS_SELECT_GRAPHIC_SceneTask,p,0);
    return p;
}
