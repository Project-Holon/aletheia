/*
 * function: MAILVIEW_InitBgs
 * address: 0x021C4DE4
 * packet: pkt_ov136_021C4DE4
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MAILVIEW_InitBgs 0x021C4DE4 thumb
 *   MAILVIEW_SetVramBanks 0x021C4DD4 thumb
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
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
extern void MAILVIEW_SetVramBanks(void);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *);
extern void BG_SYS_SetLcdSwap(u32);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_ClearSlot(u32);
typedef unsigned char  u8;
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);

void MAILVIEW_InitBgs(u32 *p)
{
    MAILVIEW_SetVramBanks();
    {
        struct DispConfig d = g_77F4;
        BG_SYS_SetGraphicsMode(&d);
    }
    BG_SYS_SetLcdSwap(0);
    {
        struct BgSet s = g_7804;
        BG_SYS_InitBgLayer(0, &s.t[0], 0);
        BG_SYS_InitBgLayer(1, &s.t[1], 0);
        BG_SYS_InitBgLayer(2, &s.t[2], 0);
        BG_SYS_InitBgLayer(3, &s.t[3], 0);
        BG_SYS_InitBgLayer(4, &s.t[4], 0);
    }
    BG_SYS_ClearSlot(0);
    BG_SYS_ClearSlot(1);
    BG_SYS_ClearSlot(2);
    BG_SYS_ClearSlot(3);
    BG_SYS_ClearSlot(4);
    BG_SYS_InitRun(0, 0x20, 0, (u16)(*p));
    BG_SYS_InitRun(1, 0x20, 0, (u16)(*p));
    BG_SYS_InitRun(2, 0x20, 0, (u16)(*p));
    BG_SYS_InitRun(3, 0x20, 0, (u16)(*p));
    BG_SYS_InitRun(4, 0x20, 0, (u16)(*p));
}
