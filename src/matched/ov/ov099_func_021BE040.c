/*
 * function: WIFICLUB_InitBackgrounds
 * address: 0x021BE040
 * packet: pkt_ov099_021BE040
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Separate 16/32-byte struct assignments retain every aggregate stack copy; initialize the loop counter before the first layer call.
 * volatile: Hardware halfword writes at 021BE1E4 and 021BE1E8 to 04000050 and 04001050.
 * prototypes: SDK asm 414AC reads r0 and forwards the index despite void(void); 414C4 argument narrowed at 021BE1B2/B4.
 * symbols:
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   BG_SYS_InitSlot 0x020414C4 arm
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   d_021C37F4 0x021C37F4 data a4
 *   d_021C396C 0x021C396C data a4
 *   d_021C382C 0x021C382C data a4
 *   d_021C384C 0x021C384C data a4
 *   d_021C386C 0x021C386C data a4
 *   d_021C38AC 0x021C38AC data a4
 *   d_021C38CC 0x021C38CC data a4
 *   d_021C392C 0x021C392C data a4
 *   d_021C394C 0x021C394C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 a, b, c, d; } Disp;
typedef struct { u32 a, b, c, d; u8 e, f, g, h; u32 i; u8 j, k, l, m; u32 n; } Bg;
extern const Disp d_021C37F4;
extern const Bg d_021C396C, d_021C382C, d_021C384C, d_021C386C;
extern const Bg d_021C38AC, d_021C38CC, d_021C392C, d_021C394C;
extern void BG_SYS_Create(u16);
struct BgTemplate;
struct DispConfig;
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u32);
extern void func_020409B4(u32);
extern void BG_SYS_Init(u32, u32, u32, u32);
extern void BG_SYS_InitSlot(u32 idx);
extern void BG_SYS_SetVisibleLayer(int, u16);
void WIFICLUB_InitBackgrounds(u16 heap)
{
    Disp d;
    Bg b0, b1, b2, b3, b4, b5, b6, b7;
    int i;
    BG_SYS_Create(heap);
    d = d_021C37F4;
    BG_SYS_SetGraphicsMode((struct DispConfig *)(&d));
    b0 = d_021C396C;
    i = 0;
    BG_SYS_InitBgLayer(0, (const struct BgTemplate *)(&b0), 0);
    BG_SYS_FreeSlot(0);
    func_020409B4(0);
    b1 = d_021C382C;
    BG_SYS_InitBgLayer(1, (const struct BgTemplate *)(&b1), 0);
    BG_SYS_FreeSlot(1);
    func_020409B4(1);
    b2 = d_021C384C;
    BG_SYS_InitBgLayer(2, (const struct BgTemplate *)(&b2), 0);
    BG_SYS_Init(2, 0, 1, 0);
    BG_SYS_FreeSlot(2);
    func_020409B4(2);
    b3 = d_021C386C;
    BG_SYS_InitBgLayer(3, (const struct BgTemplate *)(&b3), 0);
    BG_SYS_FreeSlot(3);
    func_020409B4(3);
    b4 = d_021C38AC;
    BG_SYS_InitBgLayer(4, (const struct BgTemplate *)(&b4), 0);
    BG_SYS_FreeSlot(4);
    b5 = d_021C38CC;
    BG_SYS_InitBgLayer(5, (const struct BgTemplate *)(&b5), 0);
    BG_SYS_FreeSlot(5);
    b6 = d_021C392C;
    BG_SYS_InitBgLayer(6, (const struct BgTemplate *)(&b6), 0);
    BG_SYS_FreeSlot(6);
    b7 = d_021C394C;
    BG_SYS_InitBgLayer(7, (const struct BgTemplate *)(&b7), 0);
    BG_SYS_FreeSlot(7);
    for (; i < 7; i++) BG_SYS_InitSlot((u8)i);
    BG_SYS_SetVisibleLayer(0, 3);
    BG_SYS_SetVisibleLayer(1, 1);
    BG_SYS_SetVisibleLayer(3, 1);
    BG_SYS_SetVisibleLayer(2, 0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
}
