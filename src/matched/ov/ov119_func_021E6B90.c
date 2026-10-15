/*
 * function: POKETRADE_2D_SetupCursorBg
 * address: 0x021E6B90
 * packet: pkt_ov119_021E6B90
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02049740 0x02049740 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   func_020403F4 0x020403F4 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_02040618 0x02040618 arm
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   POKETRADE_2D_SetCursorSlidePositions 0x021E6AB0 thumb ov119
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   gCursorBgTemplate 0x021E7E44 data a4
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef unsigned int u32;
struct BgTemplate {
    u32 w[8];
};
extern const struct BgTemplate gCursorBgTemplate;
extern void *BMP_MENUWORK_LoadFrameGfx(void *a0, u32 a1, u32 a2, u32 a3);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void ARC_UTIL_UploadBgPaletteAddFromHandle(void *, u32, u32, u32, u16, u32, u32, u16);
extern void func_020403F4(u32 i);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void BG_SYS_SetVisibleLayer(int idx, unsigned short val);
extern void ARC_TOOL_DeleteHandle(void *);
extern void POKETRADE_2D_SetCursorSlidePositions(const char *p);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
void POKETRADE_2D_SetupCursorBg(char *p)
{
    void *h;
    struct BgTemplate t;
    ((struct Obj00001 *)p)->f644 = BMP_MENUWORK_LoadFrameGfx((void *)6, 15, 0, ((struct Obj00001 *)p)->f5F4);
    h = func_020490F4(0x66, ((struct Obj00001 *)p)->f5F4);
    ((struct Obj00001 *)p)->f870 = func_02049740(h, 13, 5, 0, 0, ((struct Obj00001 *)p)->f5F4);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 7, 4, 0, (u16)((struct Obj00001 *)p)->f870, 0, 0, ((struct Obj00001 *)p)->f5F4);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 7, 5, 0, (u16)((struct Obj00001 *)p)->f870, 0, 0, ((struct Obj00001 *)p)->f5F4);
    t = gCursorBgTemplate;
    func_020403F4(7);
    BG_SYS_InitBgLayer(7, &t, 0);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 8, 7, 0, (u16)((struct Obj00001 *)p)->f870, 0, 0, ((struct Obj00001 *)p)->f5F4);
    func_02040618(4, 0, -0x80);
    func_02040618(7, 0, 0);
    BG_SYS_SetVisibleLayer(4, 3);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 11, 2, 0, (u16)((struct Obj00001 *)p)->f86C, 0, 0, ((struct Obj00001 *)p)->f5F4);
    ARC_TOOL_DeleteHandle(h);
    ((struct Obj00001 *)p)->f11DE = 0;
    POKETRADE_2D_SetCursorSlidePositions(p);
    BG_SYS_SetSubVisiblePlanes(0x1f);
}
