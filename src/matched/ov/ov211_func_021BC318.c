/*
 * function: ZUKAN_SEARCH_SCREEN_InitBg
 * address: 0x021BC318
 * packet: pkt_ov211_021BC318
 * region: ov211
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_Create 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   func_02041570 0x02041570 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021BC8C8 0x021BC8C8 data a4
 *   d_021BC910 0x021BC910 data a4
 *   d_021BC930 0x021BC930 data a4
 *   d_021BC950 0x021BC950 data a4
 *   d_021BC970 0x021BC970 data a4
 *   d_021BC8F0 0x021BC8F0 data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Config16 { u32 words[4]; } Config16;
typedef struct Config32 { u32 words[8]; } Config32;
extern const Config16 d_021BC8C8;
extern const Config32 d_021BC910, d_021BC930, d_021BC950, d_021BC970, d_021BC8F0;
extern void BG_SYS_Create(u16);
struct BgTemplate;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_ClearSlot(u32);
typedef unsigned char  u8;
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02041570(int, u16);
extern void BG_SYS_SetMainPlaneVisible(u32, u32);
extern void BG_SYS_SetSubPlaneVisible(u32, u32);
void ZUKAN_SEARCH_SCREEN_InitBg(void)
{
    Config16 a;
    Config32 b, c, d, e, f;
    BG_SYS_Create(0x7e);
    a = d_021BC8C8;
    func_0203FC28((struct DispConfig *)(&a));
    b = d_021BC910;
    BG_SYS_InitBgLayer(3, (const struct BgTemplate *)(&b), 2);
    BG_SYS_ClearSlot(3);
    c = d_021BC930;
    BG_SYS_InitBgLayer(1, (const struct BgTemplate *)(&c), 0);
    BG_SYS_InitRun(1, 0x20, 0x7fe0, 0x807e);
    func_02041570(1, 0x3ff);
    d = d_021BC950;
    BG_SYS_InitBgLayer(2, (const struct BgTemplate *)(&d), 0);
    BG_SYS_ClearSlot(2);
    e = d_021BC970;
    BG_SYS_InitBgLayer(7, (const struct BgTemplate *)(&e), 2);
    BG_SYS_ClearSlot(7);
    f = d_021BC8F0;
    BG_SYS_InitBgLayer(5, (const struct BgTemplate *)(&f), 0);
    BG_SYS_ClearSlot(5);
    BG_SYS_SetMainPlaneVisible(14, 1);
    BG_SYS_SetSubPlaneVisible(10, 1);
}
