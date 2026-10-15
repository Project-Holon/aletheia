/*
 * function: PMS_INPUT_VIEW_InitDisplay
 * address: 0x021BA070
 * packet: pkt_ov110_021BA070
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: GX_SetDispSelect's enum inline keeps the 0xFFFF7FFF pool mask;
 *   a direct halfword &= expression emits 0x00007FFF (two bytes differ).
 * abi: original A0E0..A0EC truncates i separately before both calls;
 *   narrow first extern parameters retain those explicit u8 argument values.
 * volatile: hardware halfword at 04000304 is read/modified at A078..A07E.
 * symbols:
 *   gPmsInputVramBanks 0x021C3714 data a4
 *   gPmsInputDispConfig 0x021C3604 data a4
 *   gPmsInputBgTemplate0 0x021C3694 data a4
 *   gPmsInputBgTemplate1 0x021C36B4 data a4
 *   gPmsInputBgTemplate2 0x021C3674 data a4
 *   gPmsInputBgTemplate3 0x021C3614 data a4
 *   gPmsInputBgTemplate4 0x021C36F4 data a4
 *   gPmsInputBgTemplate5 0x021C36D4 data a4
 *   gPmsInputBgTemplate6 0x021C3654 data a4
 *   gPmsInputBgTemplate7 0x021C3634 data a4
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   func_02040588 0x02040588 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_CreateEx 0x0201C450 thumb
 */
#include "../include/Obj13769.h"
#include "../include/Obj22333.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { GX_DISP_SELECT_SUB_MAIN=0, GX_DISP_SELECT_MAIN_SUB=1 } GXDispSelect;
static inline void GX_SetDispSelect(GXDispSelect sel) {
    *(volatile u16 *)0x04000304=(u16)((*(volatile u16 *)0x04000304 & ~0x8000) | (sel<<15));
}
extern const u8 gPmsInputVramBanks[];
extern u8 gPmsInputDispConfig[];
extern const u8 gPmsInputBgTemplate0[],gPmsInputBgTemplate1[],gPmsInputBgTemplate2[],gPmsInputBgTemplate3[];
extern const u8 gPmsInputBgTemplate4[],gPmsInputBgTemplate5[],gPmsInputBgTemplate6[],gPmsInputBgTemplate7[];
struct BgTemplate;
struct DispConfig;
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
struct GfFont;
extern void BG_SYS_ClearSlot(u32 i);
extern void func_02040588(unsigned char which, unsigned char enable);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern void *PRINTSYS_QUE_CreateEx(u16,u32);
void PMS_INPUT_VIEW_InitDisplay(u8 *p) {
    u8 *q=*(u8 * *)&((struct Obj22333 *)p)->f0;
    int i;
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    BG_SYS_SetVramBanks((const struct DispVram *)gPmsInputVramBanks);
    BG_SYS_SetGraphicsMode((struct DispConfig *)gPmsInputDispConfig);
    BG_SYS_InitBgLayer(0,(const struct BgTemplate *)gPmsInputBgTemplate0,0);
    BG_SYS_InitBgLayer(1,(const struct BgTemplate *)gPmsInputBgTemplate1,0);
    BG_SYS_InitBgLayer(2,(const struct BgTemplate *)gPmsInputBgTemplate2,0);
    BG_SYS_InitBgLayer(3,(const struct BgTemplate *)gPmsInputBgTemplate3,0);
    BG_SYS_InitBgLayer(4,(const struct BgTemplate *)gPmsInputBgTemplate4,0);
    BG_SYS_InitBgLayer(5,(const struct BgTemplate *)gPmsInputBgTemplate5,0);
    BG_SYS_InitBgLayer(6,(const struct BgTemplate *)gPmsInputBgTemplate6,0);
    BG_SYS_InitBgLayer(7,(const struct BgTemplate *)gPmsInputBgTemplate7,0);
    for(i=0;i<=7;++i) {
        BG_SYS_ClearSlot((u8)i);
        func_02040588((u8)i,1);
    }
    ((struct Obj13769 *)q)->f80=GF_FONT_Create(23,0,0,0,42);
    ((struct Obj13769 *)q)->f7C=PRINTSYS_QUE_CreateEx(0x500,42);
}
