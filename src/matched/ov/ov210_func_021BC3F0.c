/*
 * function: ZKNSEARCH_MAIN_InitBackgrounds
 * address: 0x021BC3F0
 * packet: pkt_ov210_021BC3F0
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   func_02041B6C 0x02041B6C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   g_0784 0x021C0784 data
 *   g_0814 0x021C0814 data
 *   g_07F4 0x021C07F4 data
 *   g_0854 0x021C0854 data
 *   g_0874 0x021C0874 data
 *   g_0834 0x021C0834 data
 *   g_07D4 0x021C07D4 data
 *   g_07B4 0x021C07B4 data
 *   g_0794 0x021C0794 data
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct DispConfig { u32 w[4]; };
struct BgTemplate { u32 w[8]; };
extern const struct DispConfig g_0784;
extern const struct BgTemplate g_0814;
extern const struct BgTemplate g_07F4;
extern const struct BgTemplate g_0854;
extern const struct BgTemplate g_0874;
extern const struct BgTemplate g_0834;
extern const struct BgTemplate g_07D4;
extern const struct BgTemplate g_07B4;
extern const struct BgTemplate g_0794;
extern void BG_SYS_Create(u16);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_ClearSlot(u32);
extern void func_02041B6C(u32);
extern void BG_SYS_SetMainPlaneVisible(u32, u32);
extern void BG_SYS_SetSubPlaneVisible(u32, u32);

void ZKNSEARCH_MAIN_InitBackgrounds(void)
{
    BG_SYS_Create(0x7B);
    {
        struct DispConfig d = g_0784;
        BG_SYS_SetGraphicsMode(&d);
    }
    {
        struct BgTemplate t = g_0814;
        BG_SYS_InitBgLayer(0, &t, 0);
    }
    {
        struct BgTemplate t = g_07F4;
        BG_SYS_InitBgLayer(1, &t, 0);
        BG_SYS_ClearSlot(1);
        func_02041B6C(1);
    }
    {
        struct BgTemplate t = g_0854;
        BG_SYS_InitBgLayer(2, &t, 0);
    }
    {
        struct BgTemplate t = g_0874;
        BG_SYS_InitBgLayer(3, &t, 0);
        BG_SYS_ClearSlot(3);
        func_02041B6C(3);
    }
    {
        struct BgTemplate t = g_0834;
        BG_SYS_InitBgLayer(4, &t, 0);
    }
    {
        struct BgTemplate t = g_07D4;
        BG_SYS_InitBgLayer(5, &t, 0);
        BG_SYS_ClearSlot(5);
        func_02041B6C(5);
    }
    {
        struct BgTemplate t = g_07B4;
        BG_SYS_InitBgLayer(6, &t, 0);
    }
    {
        struct BgTemplate t = g_0794;
        BG_SYS_InitBgLayer(7, &t, 0);
        BG_SYS_ClearSlot(7);
        func_02041B6C(7);
    }
    BG_SYS_SetMainPlaneVisible(0xF, 1);
    BG_SYS_SetSubPlaneVisible(0xF, 1);
}
