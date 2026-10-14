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
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
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
extern void func_0203F8F4(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32);
typedef unsigned char  u8;
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void BG_SYS_SetMainPlaneVisible(u32, u32);
extern void BG_SYS_SetSubPlaneVisible(u32, u32);

void MB_SEQ_InitBgs(u8 *a0)
{
    func_0203F8F4(0x66);
    {
        struct DispConfig d = g_7910;
        func_0203FC28(&d);
    }
    {
        struct BgTemplate t = g_79E0;
        func_0203FCA0(4, &t, 0);
        func_020414EC(4);
        func_02040B94(4, 0x20, 0, 0x66);
    }
    {
        struct BgTemplate t = g_79A0;
        func_0203FCA0(5, &t, 0);
        func_020414EC(5);
        func_02040B94(5, 0x20, 0, 0x66);
    }
    {
        struct BgTemplate t = g_79C0;
        func_0203FCA0(6, &t, 0);
        func_020414EC(6);
        func_02040B94(6, 0x20, 0, 0x66);
    }
    {
        struct BgTemplate t = g_7980;
        func_0203FCA0(7, &t, 0);
    }
    {
        struct BgTemplate t = g_7960;
        func_0203FCA0(0, &t, 0);
        func_020414EC(0);
        func_02040B94(0, 0x20, 0, 0x66);
    }
    {
        struct BgTemplate t = g_7940;
        func_0203FCA0(1, &t, 0);
        func_020414EC(1);
        func_02040B94(1, 0x20, 0, 0x66);
    }
    {
        struct BgTemplate t = g_7A00;
        func_0203FCA0(2, &t, 0);
        func_020414EC(2);
    }
    {
        struct BgTemplate t = g_7920;
        func_0203FCA0(3, &t, 0);
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
