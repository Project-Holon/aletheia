/*
 * function: BEACON_DETAIL_InitMainScreen
 * address: 0x021849A4
 * packet: pkt_ov219_021849A4
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: explicit original heap shift pairs require narrow extern parameters for D7EC/40B94 despite their full-width own declarations;84968 returns descriptor pointer.
 * symbols:
 *   GF_FONT_Create 0x0201D7EC thumb
 *   GF_FONT_GetTextColor 0x0201DE00 thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   func_02049658 0x02049658 arm
 *   func_02049B68 0x02049B68 arm
 *   func_020498F4 0x020498F4 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   func_02049B40 0x02049B40 arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   BG_SYS_LoadPlttEntry 0x02040EBC arm
 *   BEACON_DETAIL_CreateBmpWin 0x02184968 thumb ov219
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BG_SYS_SetLowBit 0x0204044C arm
 *   BEACON_DETAIL_CreateTaskMenu 0x02184BAC thumb ov219
 *   d_02185E58 0x02185E58 data a4
 *   d_02185E78 0x02185E78 data a4
 *   d_02185DBD 0x02185DBD data a1
 */
#include "../include/Obj01012.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct BgTemplate;
extern const struct BgTemplate d_02185E58,d_02185E78;
extern const u8 d_02185DBD[];
struct GfFont;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern void GF_FONT_GetTextColor(u8 *,u8 *,u8 *),GF_FONT_SetTextColor(u32,u32,u32);
extern void BG_SYS_InitBgLayer(u32,const struct BgTemplate *,u32),BG_SYS_ClearSlot(u32);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void BMP_MENUWORK_LoadCharAndPltt(u32,u32,u32,u32,u16);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);
extern void BG_SYS_LoadPlttEntry(u32,u32);
extern u32 BEACON_DETAIL_CreateBmpWin(const u8 *p, int flag);
struct Descriptor;
extern void BMP_MENUWORK_DrawWindow(void *,int,int,int),BMP_WIN_TransferChars(struct Descriptor *),BG_SYS_SetLowBit(u32),BEACON_DETAIL_CreateTaskMenu(char *);
void BEACON_DETAIL_InitMainScreen(char *p,void *arc)
{
    ((struct Obj01012 *)p)->fC06C=GF_FONT_Create(0x17,0,0,0,(u16)(((struct Obj01012 *)p)->f0));
    GF_FONT_GetTextColor((u8 *)p+0xc084,(u8 *)p+0xc085,(u8 *)p+0xc086);
    GF_FONT_SetTextColor(1,2,0xf);
    BG_SYS_InitBgLayer(6,&d_02185E58,0);
    BG_SYS_ClearSlot(6);
    BG_SYS_InitBgLayer(7,&d_02185E78,0);
    func_02049658(arc,5,7,0,0,0,((struct Obj01012 *)p)->f0);
    func_02049B68(arc,6,4,0,0x80,((struct Obj01012 *)p)->f0);
    func_020498F4(arc,7,7,0,0,0,((struct Obj01012 *)p)->f0);
    BMP_MENUWORK_LoadCharAndPltt(6,4,6,0,((struct Obj01012 *)p)->f0);
    BMP_MENUWORK_LoadCharAndPltt(6,0x22,7,0,((struct Obj01012 *)p)->f0);
    func_02049B40(0x17,5,4,0x80,0x20,((struct Obj01012 *)p)->f0);
    BG_SYS_InitRun(6,0x20,0,(u16)(((struct Obj01012 *)p)->f0));
    BG_SYS_LoadPlttEntry(6,0x4753);
    ((struct Obj01012 *)p)->fC01C=(void *)BEACON_DETAIL_CreateBmpWin(d_02185DBD,1);
    BMP_MENUWORK_DrawWindow(((struct Obj01012 *)p)->fC01C,0,4,6);
    BMP_WIN_TransferChars(((struct Obj01012 *)p)->fC01C);
    ((struct Obj01012 *)p)->fC0B0=0;
    BG_SYS_InitBgLayer(2,&d_02185E58,0);
    BG_SYS_ClearSlot(2);
    BG_SYS_SetLowBit(1);
    BG_SYS_InitBgLayer(3,&d_02185E78,0);
    func_02049658(arc,5,3,0,0,0,((struct Obj01012 *)p)->f0);
    func_02049B68(arc,6,0,0,0x80,((struct Obj01012 *)p)->f0);
    func_020498F4(arc,7,3,0,0,0,((struct Obj01012 *)p)->f0);
    BMP_MENUWORK_LoadCharAndPltt(2,0x22,7,0,((struct Obj01012 *)p)->f0);
    func_02049B40(0x17,5,0,0x80,0x20,((struct Obj01012 *)p)->f0);
    func_02049B40(0x17,5,0,0x100,0x20,((struct Obj01012 *)p)->f0);
    BG_SYS_InitRun(2,0x20,0,(u16)(((struct Obj01012 *)p)->f0));
    BG_SYS_LoadPlttEntry(2,0);
    BEACON_DETAIL_CreateTaskMenu(p);
}
