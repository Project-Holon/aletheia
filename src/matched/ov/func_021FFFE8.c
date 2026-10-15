/*
 * function: WORLDTRADE_TITLE_ScrollBg
 * address:  0x021FFFE8
 * packet:   pkt_021FFFE8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_ClearLayerEx  0x02041570  arm
 *   func_02040588  0x02040588  arm
 *   BG_SYS_InitRun  0x02040B94  arm
 *   g_02203944  0x02203944  data  ov135
 *   g_02203924  0x02203924  data  ov135
 *   g_02203964  0x02203964  data  ov135
 *   g_022039E4  0x022039E4  data  ov135
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm  arm9
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm  arm9
 *   BG_SYS_GetSubVisiblePlanes  0x02043668  arm  arm9
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm  arm9
 *   BG_SYS_ClearSlot  0x020414EC  arm  arm9
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm  arm9
 *   BG_SYS_SetTileEntry  0x02041300  arm  arm9
 *   BG_SYS_PushTile  0x020409B4  arm  arm9
 *
 * One-shot bring-up of layers 4..7 gated on the field at p+0x12e0: the
 * layer-4 clear, the layer-6 clear only when the second argument is zero,
 * layer 5 with its second word taken from the first argument, layer 7, then
 * the four enables.  The four templates are declared together in use order,
 * which is what fixes the stack slots to 0x60/0x40/0x20/0x00.
 */
#include "../include/Obj12225.h"

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
extern void BG_SYS_PushTile(u32 layer);
extern void BG_SYS_ClearLayerEx(int channel, u16 val);

extern struct BgTemplate g_02203944;
extern struct BgTemplate g_02203924;
extern struct BgTemplate g_02203964;
extern struct BgTemplate g_022039E4;

void WORLDTRADE_TITLE_ScrollBg(u8 *p, u32 a, u32 b)
{
    if (((struct Obj12225 *)p)->f12E0 == 0) {
        struct BgTemplate t4;
        struct BgTemplate t6;
        struct BgTemplate t5;
        struct BgTemplate t7;

        ((struct Obj12225 *)p)->f12E0 = 1;
        t4 = g_02203944;
        BG_SYS_InitBgLayer(4, &t4, 0);
        BG_SYS_ClearLayerEx(4, 0);
        t6 = g_02203924;
        BG_SYS_InitBgLayer(6, &t6, 0);
        if (b == 0) {
            BG_SYS_ClearLayerEx(6, 0);
        }
        t5 = g_02203964;
        t5.unk_04 = a;
        BG_SYS_InitBgLayer(5, &t5, 0);
        BG_SYS_InitRun(4, 0x20, 0, 0x48);
        t7 = g_022039E4;
        BG_SYS_InitBgLayer(7, &t7, 0);
        BG_SYS_ClearLayerEx(7, 0);
    }
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_02040588(6, 1);
    func_02040588(7, 1);
}
