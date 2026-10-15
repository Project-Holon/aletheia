/*
 * function: GTSNEGO_DISP_InitBgLayers
 * address:  0x021D6100
 * packet:   pkt_ov120_021D6100
 * region:   ov120
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * BG-layer init: eight copies of the const template table at 0x021D89B0
 * (index order 0,5,1,2,3,4,6,7) passed to BG_SYS_InitBgLayer, each followed by
 * its layer enable / fill sequence.  The local array is written high-to-low
 * (b[7] first) because the original places the first-used slot at the top of
 * the frame.
 * symbols:
 *   d_021D89B0      0x021D89B0  data
 *   BG_SYS_InitBgLayer   0x0203FCA0  arm
 *   BG_SYS_FreeSlot   0x020414AC  arm
 *   BG_SYS_PushTile   0x020409B4  arm
 *   func_02040588   0x02040588  arm
 *   BG_SYS_Init   0x02040C14  arm
 *   BG_SYS_SetTileEntry   0x02041300  arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

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

extern const struct BgTemplate d_021D89B0[8];
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u32);
extern void BG_SYS_PushTile(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_Init(u32, u32, u32, u32);
extern void BG_SYS_SetTileEntry(u32, u32, u32, u32, u8, u8, u8);

void GTSNEGO_DISP_InitBgLayers(u8 *a0)
{
    struct BgTemplate b[8];

    b[7] = d_021D89B0[0];
    BG_SYS_InitBgLayer(0, &b[7], 0);
    BG_SYS_FreeSlot(0);
    BG_SYS_PushTile(0);
    func_02040588(0, 1);

    b[6] = d_021D89B0[5];
    BG_SYS_InitBgLayer(1, &b[6], 0);
    func_02040588(1, 1);
    BG_SYS_Init(1, 0, 1, 0);
    BG_SYS_SetTileEntry(1, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(1);

    b[5] = d_021D89B0[1];
    BG_SYS_InitBgLayer(2, &b[5], 0);
    func_02040588(2, 1);
    BG_SYS_SetTileEntry(2, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(2);

    b[4] = d_021D89B0[2];
    BG_SYS_InitBgLayer(3, &b[4], 0);
    func_02040588(3, 1);
    BG_SYS_SetTileEntry(3, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(3);

    b[3] = d_021D89B0[3];
    BG_SYS_InitBgLayer(4, &b[3], 0);
    func_02040588(4, 1);
    BG_SYS_PushTile(4);

    b[2] = d_021D89B0[4];
    BG_SYS_InitBgLayer(5, &b[2], 0);
    func_02040588(5, 1);
    BG_SYS_Init(5, 0, 1, 0);
    BG_SYS_SetTileEntry(5, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(5);

    b[1] = d_021D89B0[6];
    BG_SYS_InitBgLayer(6, &b[1], 0);
    func_02040588(6, 1);
    BG_SYS_Init(6, 0, 1, 0);
    BG_SYS_SetTileEntry(6, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(6);

    b[0] = d_021D89B0[7];
    BG_SYS_InitBgLayer(7, &b[0], 0);
    func_02040588(7, 1);
    BG_SYS_PushTile(7);
}
