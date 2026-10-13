/*
 * function: func_021BC3F0
 * address: 0x021BC3F0
 * packet: pkt_ov210_021BC3F0
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020434DC 0x020434DC arm
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
extern void func_0203F8F4(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32);
extern void func_02041B6C(u32);
extern void func_020434DC(u32, u32);
extern void BG_SYS_SetSubPlaneVisible(u32, u32);

void func_021BC3F0(void)
{
    func_0203F8F4(0x7B);
    {
        struct DispConfig d = g_0784;
        func_0203FC28(&d);
    }
    {
        struct BgTemplate t = g_0814;
        func_0203FCA0(0, &t, 0);
    }
    {
        struct BgTemplate t = g_07F4;
        func_0203FCA0(1, &t, 0);
        func_020414EC(1);
        func_02041B6C(1);
    }
    {
        struct BgTemplate t = g_0854;
        func_0203FCA0(2, &t, 0);
    }
    {
        struct BgTemplate t = g_0874;
        func_0203FCA0(3, &t, 0);
        func_020414EC(3);
        func_02041B6C(3);
    }
    {
        struct BgTemplate t = g_0834;
        func_0203FCA0(4, &t, 0);
    }
    {
        struct BgTemplate t = g_07D4;
        func_0203FCA0(5, &t, 0);
        func_020414EC(5);
        func_02041B6C(5);
    }
    {
        struct BgTemplate t = g_07B4;
        func_0203FCA0(6, &t, 0);
    }
    {
        struct BgTemplate t = g_0794;
        func_0203FCA0(7, &t, 0);
        func_020414EC(7);
        func_02041B6C(7);
    }
    func_020434DC(0xF, 1);
    BG_SYS_SetSubPlaneVisible(0xF, 1);
}
