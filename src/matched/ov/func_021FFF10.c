/*
 * function: WORLDTRADE_TITLE_SetupBgPlanes
 * address:  0x021FFF10
 * packet:   pkt_021FFF10
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_GetSubVisiblePlanes  0x02043668  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   func_02040588  0x02040588  arm
 *   BG_SYS_InitRun  0x02040B94  arm
 *   g_02203914  0x02203914  data  ov135
 *   g_022039A4  0x022039A4  data  ov135
 *   g_02203984  0x02203984  data  ov135
 *   g_022039C4  0x022039C4  data  ov135
 *   BG_SYS_SetTileEntry  0x02041300  arm  arm9
 *   BG_SYS_ClearLayerEx  0x02041570  arm  arm9
 *
 * Three-layer bring-up with layer 0's tilemap cleared and plane 0x10 turned
 * on through both 020434DC and 02043598.
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
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_SetSubVisiblePlanes(u32 a);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_ClearSlot(u32 i);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);
extern void BG_SYS_SetTileEntry(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_020409B4(u32 layer);
extern void BG_SYS_ClearLayerEx(int channel, u16 val);

extern struct DispConfig g_02203914;
extern struct BgTemplate g_022039A4;
extern struct BgTemplate g_02203984;
extern struct BgTemplate g_022039C4;

void WORLDTRADE_TITLE_SetupBgPlanes(void)
{
    struct DispConfig c = g_02203914;
    u32 v = BG_SYS_GetSubVisiblePlanes();

    BG_SYS_SetGraphicsMode(&c);
    BG_SYS_SetSubVisiblePlanes(v);
    {
        struct BgTemplate t = g_022039A4;
        BG_SYS_InitBgLayer(0, &t, 0);
    }
    BG_SYS_ClearSlot(0);
    func_02040588(0, 1);
    {
        struct BgTemplate t = g_02203984;
        BG_SYS_InitBgLayer(1, &t, 0);
    }
    func_02040588(1, 1);
    {
        struct BgTemplate t = g_022039C4;
        BG_SYS_InitBgLayer(2, &t, 0);
    }
    func_02040588(2, 1);
    BG_SYS_InitRun(0, 0x20, 0, 0x48);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}
