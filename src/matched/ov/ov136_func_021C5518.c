/*
 * function: MB_SEQ_InitBgs
 * address: 0x021C5518
 * packet: pkt_ov136_021C5518
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   g_7910 0x021C7910 data
 *   g_79E0 0x021C79E0 data
 *   g_79A0 0x021C79A0 data
 *   g_79C0 0x021C79C0 data
 *   g_7980 0x021C7980 data
 *   g_7960 0x021C7960 data
 *   g_7940 0x021C7940 data
 *   g_7A00 0x021C7A00 data
 *   g_7920 0x021C7920 data
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct DispConfig { u32 w[4]; };
struct BgTemplate { u32 w[8]; };
extern const struct DispConfig g_7910;
extern const struct BgTemplate g_79E0;
extern const struct BgTemplate g_79A0;
extern const struct BgTemplate g_79C0;
extern const struct BgTemplate g_7980;
extern const struct BgTemplate g_7960;
extern const struct BgTemplate g_7940;
extern const struct BgTemplate g_7A00;
extern const struct BgTemplate g_7920;
extern void BG_SYS_Create(u16);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_ClearSlot(u32);
typedef unsigned char  u8;
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);
extern void BG_SYS_SetMainPlaneVisible(u32, u32);
extern void BG_SYS_SetSubPlaneVisible(u32, u32);

void MB_SEQ_InitBgs(u8 *a0)
{
    BG_SYS_Create(0x66);
    {
        struct DispConfig d = g_7910;
        BG_SYS_SetGraphicsMode(&d);
    }
    {
        struct BgTemplate t = g_79E0;
        BG_SYS_InitBgLayer(4, &t, 0);
        BG_SYS_ClearSlot(4);
        BG_SYS_InitRun(4, 0x20, 0, 0x66);
    }
    {
        struct BgTemplate t = g_79A0;
        BG_SYS_InitBgLayer(5, &t, 0);
        BG_SYS_ClearSlot(5);
        BG_SYS_InitRun(5, 0x20, 0, 0x66);
    }
    {
        struct BgTemplate t = g_79C0;
        BG_SYS_InitBgLayer(6, &t, 0);
        BG_SYS_ClearSlot(6);
        BG_SYS_InitRun(6, 0x20, 0, 0x66);
    }
    {
        struct BgTemplate t = g_7980;
        BG_SYS_InitBgLayer(7, &t, 0);
    }
    {
        struct BgTemplate t = g_7960;
        BG_SYS_InitBgLayer(0, &t, 0);
        BG_SYS_ClearSlot(0);
        BG_SYS_InitRun(0, 0x20, 0, 0x66);
    }
    {
        struct BgTemplate t = g_7940;
        BG_SYS_InitBgLayer(1, &t, 0);
        BG_SYS_ClearSlot(1);
        BG_SYS_InitRun(1, 0x20, 0, 0x66);
    }
    {
        struct BgTemplate t = g_7A00;
        BG_SYS_InitBgLayer(2, &t, 0);
        BG_SYS_ClearSlot(2);
    }
    {
        struct BgTemplate t = g_7920;
        BG_SYS_InitBgLayer(3, &t, 0);
    }
    BG_SYS_SetMainPlaneVisible(1, 1);
    BG_SYS_SetMainPlaneVisible(2, 1);
    BG_SYS_SetMainPlaneVisible(4, 1);
    BG_SYS_SetMainPlaneVisible(8, 1);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(1, 1);
    BG_SYS_SetSubPlaneVisible(2, 1);
    BG_SYS_SetSubPlaneVisible(4, 1);
    BG_SYS_SetSubPlaneVisible(8, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}
