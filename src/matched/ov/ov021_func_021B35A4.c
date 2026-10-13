/*
 * function: SCRCMD_PROC_FLD_StepShop
 * address:  0x021B35A4
 * packet:   pkt_ov021_021B35A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_PROC_FLD_InitShop  0x021B3258  thumb  ov021
 *   SCRCMD_PROC_FLD_PollItemList  0x021B3470  thumb  ov021
 *   SCRCMD_PROC_FLD_PrintOwnedWindow  0x021B41AC  thumb  ov021
 *   SCRCMD_PROC_FLD_PrintQuantityWindow  0x021B42D0  thumb  ov021
 *   func_0204B3DC  0x0204B3DC  arm
 *   SCRCMD_PROC_FLD_StepQuantitySelect  0x021B4AA4  thumb  ov021
 *   SCRCMD_PROC_FLD_SetQuantityMask  0x021B4BA4  thumb  ov021
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 *   BMP_MENULIST_Redraw  0x02020234  thumb
 *   BMP_MENU_CreateYesNo  0x0201FDA0  thumb
 *   BMP_MENU_ProcessYesNo  0x0201FEBC  thumb
 *   func_020061E4  0x020061E4  thumb
 *   SCRCMD_PROC_FLD_ShowItemMessage  0x021B4714  thumb  ov021
 *   SCRCMD_PROC_FLD_PayPrice  0x021B3568  thumb  ov021
 *   SCRCMD_PROC_FLD_PrintMoneyWindow  0x021B40D4  thumb  ov021
 *   func_02007E50  0x02007E50  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   SCRCMD_PROC_FLD_PollMessageEnd  0x021B34F4  thumb  ov021
 *   SCRCMD_PROC_FLD_FreeItemListMenu  0x021B46FC  thumb  ov021
 *   SCRCMD_PROC_FLD_FreeShopCells  0x021B3F3C  thumb  ov021
 *   SCRCMD_PROC_FLD_FreeShopWindows  0x021B40A8  thumb  ov021
 *   SCRCMD_PROC_FLD_ExitShopGraphics  0x021B3C58  thumb  ov021
 *   SCRCMD_PROC_FLD_FreeItemSlots  0x021B3B04  thumb  ov021
 *   SCRCMD_PROC_FLD_FreeShopResources  0x021B3B84  thumb  ov021
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   TCBL_Main  0x020310C4  arm
 *   d_021D9440     0x021D9440  data   ov021  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00030.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void SCRCMD_PROC_FLD_InitShop(int ctx, u8 *a, int b, int c);
extern void SCRCMD_PROC_FLD_PollItemList(char *p);
extern void SCRCMD_PROC_FLD_PrintOwnedWindow(char *w, u16 b);
extern void SCRCMD_PROC_FLD_PrintQuantityWindow(char *w, u32 a, u32 b);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern int SCRCMD_PROC_FLD_StepQuantitySelect(char *w);
extern void SCRCMD_PROC_FLD_SetQuantityMask(int i);
struct Cfg;
struct PrintSys;
struct Sub02008C20Obj;
struct Tcbl;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32 a);
extern void BMP_MENULIST_Redraw(u8 *p);
extern u32 BMP_MENU_CreateYesNo(const void *a, u32 b, u32 c, u32 d, u32 e);
extern u32 BMP_MENU_ProcessYesNo(u8 *p);
extern void func_020061E4(u32 se);
extern void SCRCMD_PROC_FLD_ShowItemMessage(u8 *p, u32 sel, u32 c, u32 d);
extern void SCRCMD_PROC_FLD_PayPrice(u8 *w, u32 b);
extern void SCRCMD_PROC_FLD_PrintMoneyWindow(char *w);
extern u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern u8 SCRCMD_PROC_FLD_PollMessageEnd(u8 *p);
extern void SCRCMD_PROC_FLD_FreeItemListMenu(u8 *w);
extern void SCRCMD_PROC_FLD_FreeShopCells(char *w);
extern void SCRCMD_PROC_FLD_FreeShopWindows(u8 *w);
extern void SCRCMD_PROC_FLD_ExitShopGraphics(u8 *w);
extern void SCRCMD_PROC_FLD_FreeItemSlots(char *w);
extern void SCRCMD_PROC_FLD_FreeShopResources(char *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *a);
extern void TCBL_Main(struct Tcbl *p);
extern const u8 d_021D9440[];

int SCRCMD_PROC_FLD_StepShop(u32 a, char *p, u32 c, u8 d)
{
    int r;
    u32 q;

    switch (((struct Obj00030 *)p)->f0) {
    case 0:
        SCRCMD_PROC_FLD_InitShop(a, (u8 *)p, c, d);
        (((struct Obj00030 *)p)->f0)++;
        break;
    case 1:
        SCRCMD_PROC_FLD_PollItemList(p);
        break;
    case 2:
        SCRCMD_PROC_FLD_PrintOwnedWindow(p, ((struct Obj00030 *)p)->f1FC);
        SCRCMD_PROC_FLD_PrintQuantityWindow(p, ((struct Obj00030 *)p)->f208, ((struct Obj00030 *)p)->f200);
        func_0204B3DC((struct Obj *)((struct Obj00030 *)p)->f1CC, 1);
        ((struct Obj00030 *)p)->f0 = 3;
        break;
    case 3:
        ((struct Obj00030 *)p)->f0 = SCRCMD_PROC_FLD_StepQuantitySelect(p);
        break;
    case 4:
        SCRCMD_PROC_FLD_SetQuantityMask(0);
        BMP_WIN_MakeScreen((struct Cfg *)(*(u32 *)&((struct Obj00030 *)p)->f16C));
        BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj00030 *)p)->f178));
        func_02041B6C(1);
        func_0204B3DC((struct Obj *)((struct Obj00030 *)p)->f1CC, 0);
        BMP_MENULIST_Redraw((u8 *)(*(u32 *)&((struct Obj00030 *)p)->f1A4));
        ((struct Obj00030 *)p)->f0 = 1;
        break;
    case 5:
        SCRCMD_PROC_FLD_SetQuantityMask(1);
        BMP_WIN_MakeScreen((struct Cfg *)(*(u32 *)&((struct Obj00030 *)p)->f16C));
        func_0204B3DC((struct Obj *)((struct Obj00030 *)p)->f1CC, 0);
        ((struct Obj00030 *)p)->f184 = BMP_MENU_CreateYesNo(d_021D9440, 1, 9, 0, ((struct Obj00030 *)p)->f4);
        if (((struct Obj00030 *)p)->f162 != 1) {
            SCRCMD_PROC_FLD_PrintOwnedWindow(p, ((struct Obj00030 *)p)->f1FC);
        }
        ((struct Obj00030 *)p)->f0 = 7;
        break;
    case 6:
        SCRCMD_PROC_FLD_SetQuantityMask(1);
        BMP_WIN_MakeScreen((struct Cfg *)(*(u32 *)&((struct Obj00030 *)p)->f16C));
        func_0204B3DC((struct Obj *)((struct Obj00030 *)p)->f1CC, 0);
        ((struct Obj00030 *)p)->f184 = BMP_MENU_CreateYesNo(d_021D9440, 1, 9, 0, ((struct Obj00030 *)p)->f4);
        ((struct Obj00030 *)p)->f0 = 7;
        break;
    case 7:
        r = BMP_MENU_ProcessYesNo((u8 *)(((struct Obj00030 *)p)->f184));
        if (r == -1) {
        } else if (r == 0) {
            ((struct Obj00030 *)p)->f0 = 8;
            SCRCMD_PROC_FLD_SetQuantityMask(1);
            BMP_MENULIST_Redraw((u8 *)(*(u32 *)&((struct Obj00030 *)p)->f1A4));
            BMP_WIN_MakeScreen((struct Cfg *)(*(u32 *)&((struct Obj00030 *)p)->f16C));
            func_02041B6C(1);
        } else if (r == -2) {
            ((struct Obj00030 *)p)->f0 = 4;
        }
        break;
    case 8:
        func_020061E4(0x655);
        SCRCMD_PROC_FLD_ShowItemMessage((u8 *)p, 9, ((struct Obj00030 *)p)->f1FC, *(s16 *)&((struct Obj00030 *)p)->f208 > 1);
        SCRCMD_PROC_FLD_PayPrice((u8 *)p, ((struct Obj00030 *)p)->f200 * *(s16 *)&((struct Obj00030 *)p)->f208);
        SCRCMD_PROC_FLD_PrintMoneyWindow(p);
        func_02007E50((u8 *)(((struct Obj00030 *)p)->f10), ((struct Obj00030 *)p)->f1FC, ((struct Obj00030 *)p)->f208, ((struct Obj00030 *)p)->f4);
        ((struct Obj00030 *)p)->f0 = 10;
        *(u8 *)&((struct Obj00030 *)p)->f1 = 9;
        break;
    case 9:
        if (((struct Obj00030 *)p)->f1FC == 4 && *(s16 *)&((struct Obj00030 *)p)->f208 >= 10) {
            SCRCMD_PROC_FLD_ShowItemMessage((u8 *)p, 15, ((struct Obj00030 *)p)->f1FC, *(s16 *)&((struct Obj00030 *)p)->f208 > 1);
            func_02007E50((u8 *)(((struct Obj00030 *)p)->f10), 12, 1, ((struct Obj00030 *)p)->f4);
            func_02008DF0((struct Sub02008C20Obj *)(((struct Obj00030 *)p)->f14), 0x1F);
            ((struct Obj00030 *)p)->f0 = 10;
            *(u8 *)&((struct Obj00030 *)p)->f1 = 4;
        } else {
            ((struct Obj00030 *)p)->f0 = 4;
        }
        break;
    case 10:
        ((struct Obj00030 *)p)->f0 = SCRCMD_PROC_FLD_PollMessageEnd((u8 *)p);
        break;
    case 11:
        SCRCMD_PROC_FLD_FreeItemListMenu((u8 *)p);
        SCRCMD_PROC_FLD_FreeShopCells(p);
        SCRCMD_PROC_FLD_FreeShopWindows((u8 *)p);
        SCRCMD_PROC_FLD_ExitShopGraphics((u8 *)p);
        SCRCMD_PROC_FLD_FreeItemSlots(p);
        SCRCMD_PROC_FLD_FreeShopResources(p);
        return 1;
    }
    PRINTSYS_QUE_Main((struct PrintSys *)(*(u32 *)&((struct Obj00030 *)p)->f1B0));
    q = *(u32 *)&((struct Obj00030 *)p)->f1B0;
    if (((struct Obj00030 *)p)->f1AC != 0 && func_0201C6C4((struct PrintSys *)q, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj00030 *)p)->f1A8))) == 0) {
        BMP_WIN_TransferChars((struct Descriptor *)((struct Obj00030 *)p)->f1A8);
        ((struct Obj00030 *)p)->f1AC = 0;
    }
    TCBL_Main((struct Tcbl *)(((struct Obj00030 *)p)->f1B4));
    TCBL_Main((struct Tcbl *)(((struct Obj00030 *)p)->f1B4));
    return 0;
}
