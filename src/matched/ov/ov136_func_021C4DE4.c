/*
 * function: func_021C4DE4
 * address: 0x021C4DE4
 * packet: pkt_ov136_021C4DE4
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C4DE4 0x021C4DE4 thumb
 *   func_021C4DD4 0x021C4DD4 thumb
 *   func_0203FC28 0x0203FC28 arm
 *   func_0204363C 0x0204363C arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   g_77F4 0x021C77F4 data
 *   g_7804 0x021C7804 data
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct DispConfig { u32 w[4]; };
struct BgTemplate { u32 w[8]; };
struct BgSet { struct BgTemplate t[5]; };
extern const struct DispConfig g_77F4;
extern const struct BgSet g_7804;
extern void func_021C4DD4(void);
extern void func_0203FC28(struct DispConfig *);
extern void func_0204363C(u32);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32);
extern void func_02040B94(u32 layer, u32 size, u32 offset, u32 heapId);

void func_021C4DE4(u32 *p)
{
    func_021C4DD4();
    {
        struct DispConfig d = g_77F4;
        func_0203FC28(&d);
    }
    func_0204363C(0);
    {
        struct BgSet s = g_7804;
        func_0203FCA0(0, &s.t[0], 0);
        func_0203FCA0(1, &s.t[1], 0);
        func_0203FCA0(2, &s.t[2], 0);
        func_0203FCA0(3, &s.t[3], 0);
        func_0203FCA0(4, &s.t[4], 0);
    }
    func_020414EC(0);
    func_020414EC(1);
    func_020414EC(2);
    func_020414EC(3);
    func_020414EC(4);
    func_02040B94(0, 0x20, 0, (u16)(*p));
    func_02040B94(1, 0x20, 0, (u16)(*p));
    func_02040B94(2, 0x20, 0, (u16)(*p));
    func_02040B94(3, 0x20, 0, (u16)(*p));
    func_02040B94(4, 0x20, 0, (u16)(*p));
}
