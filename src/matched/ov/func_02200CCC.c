/*
 * function: WORLDTRADE_SERVER_SetupBgPlanes
 * address:  0x02200CCC
 * packet:   pkt_02200CCC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_GetSubVisiblePlanes  0x02043668  arm
 *   func_0203FC28  0x0203FC28  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040588  0x02040588  arm
 *   func_02040B94  0x02040B94  arm
 *   g_02203A04  0x02203A04  data  ov135
 *   g_02203A14  0x02203A14  data  ov135
 *   g_02203A54  0x02203A54  data  ov135
 *   g_02203A34  0x02203A34  data  ov135
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm  arm9
 *
 * Three-layer bring-up with all three layers 020414EC'd, tilemap clears for
 * layers 0 and 1 and plane 0x10 toggled.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct DispConfig {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

extern u32 BG_SYS_GetSubVisiblePlanes(void);
extern void func_0203FC28(struct DispConfig *cfg);
extern void BG_SYS_SetSubVisiblePlanes(u32 a);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_020409B4(u32 layer);
extern void func_02041570(int channel, u16 val);

extern struct DispConfig g_02203A04;
extern struct BgTemplate g_02203A14;
extern struct BgTemplate g_02203A54;
extern struct BgTemplate g_02203A34;

void WORLDTRADE_SERVER_SetupBgPlanes(void)
{
    struct DispConfig c = g_02203A04;
    u32 v = BG_SYS_GetSubVisiblePlanes();

    func_0203FC28(&c);
    BG_SYS_SetSubVisiblePlanes(v);
    {
        struct BgTemplate t = g_02203A14;
        func_0203FCA0(0, &t, 0);
    }
    func_020414EC(0);
    func_02040588(0, 1);
    {
        struct BgTemplate t = g_02203A54;
        func_0203FCA0(1, &t, 0);
    }
    func_020414EC(1);
    func_02040588(1, 1);
    {
        struct BgTemplate t = g_02203A34;
        func_0203FCA0(2, &t, 0);
    }
    func_020414EC(2);
    func_02040588(2, 1);
    func_02040B94(0, 0x20, 0, 0x48);
    func_02040B94(1, 0x20, 0, 0x48);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
}
