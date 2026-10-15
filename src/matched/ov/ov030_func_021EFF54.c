/*
 * function: NO_GEAR_SetupBackgrounds
 * address:  0x021EFF54
 * packet:   pkt_ov030_021EFF54
 * region:   ov030
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02040588  0x02040588  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_SetVisibleLayer  0x0204047C  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   gNoGearBgTemplateMain     0x021F014C  data  ov030  a4
 *   gNoGearBgTemplateMid     0x021F016C  data  ov030  a4
 *   gNoGearBgTemplateBack     0x021F018C  data  ov030  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

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

extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_SetVisibleLayer(int idx, unsigned short val);
extern void BG_SYS_SetTileEntry(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void BG_SYS_PushTile(u32 layer);

extern struct BgTemplate gNoGearBgTemplateMain;
extern struct BgTemplate gNoGearBgTemplateMid;
extern struct BgTemplate gNoGearBgTemplateBack;

void NO_GEAR_SetupBackgrounds(void)
{
    int i;

    for (i = 4; i <= 7; i++) {
        func_02040588((u8)i, 0);
    }
    {
        struct BgTemplate t = gNoGearBgTemplateMain;
        BG_SYS_InitBgLayer(6, &t, 0);
        func_02040588((u8)6, 1);
        BG_SYS_SetVisibleLayer(6, 3);
        BG_SYS_SetTileEntry(6, 0, 0, 0, 0x20, 0x20, 0x11);
        BG_SYS_PushTile(6);
    }
    {
        struct BgTemplate t = gNoGearBgTemplateMid;
        BG_SYS_InitBgLayer(5, &t, 0);
        func_02040588((u8)5, 1);
        BG_SYS_SetVisibleLayer(5, 1);
        BG_SYS_SetTileEntry(5, 0, 0, 0, 0x20, 0x20, 0x11);
        BG_SYS_PushTile(5);
    }
    {
        struct BgTemplate t = gNoGearBgTemplateBack;
        BG_SYS_InitBgLayer(4, &t, 0);
        func_02040588((u8)4, 1);
        BG_SYS_SetVisibleLayer(4, 2);
        BG_SYS_SetTileEntry(4, 0, 0, 0, 0x20, 0x20, 0x11);
        BG_SYS_PushTile(4);
    }
}
