/*
 * function: BOX2_MAIN_InitBgSys
 * address:  0x021DC9E0
 * packet:   pkt_ov170_021DC9E0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_Create 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021EF7FC 0x021EF7FC data
 *   d_021EF82C 0x021EF82C data
 *   d_021EF8CC 0x021EF8CC data
 *   d_021EF86C 0x021EF86C data
 *   d_021EF88C 0x021EF88C data
 *   d_021EF80C 0x021EF80C data
 *   d_021EF8AC 0x021EF8AC data
 *   d_021EF84C 0x021EF84C data
 *
 * Background setup of the box screen: display banks, seven layers from
 * the rodata templates (clearing 1, 4 and 6), then the plane masks.
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

extern void BG_SYS_Create(u16 heap);
extern void func_0203FC28(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_ClearSlot(u32 i);
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

extern const struct DispConfig d_021EF7FC;
extern const struct BgTemplate d_021EF82C;
extern const struct BgTemplate d_021EF8CC;
extern const struct BgTemplate d_021EF86C;
extern const struct BgTemplate d_021EF88C;
extern const struct BgTemplate d_021EF80C;
extern const struct BgTemplate d_021EF8AC;
extern const struct BgTemplate d_021EF84C;

void BOX2_MAIN_InitBgSys(u8 *a0)
{
    struct DispConfig c;
    struct BgTemplate t0;
    struct BgTemplate t1;
    struct BgTemplate t2;
    struct BgTemplate t3;
    struct BgTemplate t4;
    struct BgTemplate t5;
    struct BgTemplate t6;

    BG_SYS_Create(0x4C);
    c = d_021EF7FC;
    func_0203FC28(&c);
    t0 = d_021EF82C;
    BG_SYS_InitBgLayer(0, &t0, 0);
    t1 = d_021EF8CC;
    BG_SYS_InitBgLayer(1, &t1, 0);
    BG_SYS_ClearSlot(1);
    BG_SYS_InitRun(1, 0x20, 0, 0x4C);
    t2 = d_021EF86C;
    BG_SYS_InitBgLayer(2, &t2, 0);
    t3 = d_021EF88C;
    BG_SYS_InitBgLayer(3, &t3, 0);
    t4 = d_021EF80C;
    BG_SYS_InitBgLayer(4, &t4, 0);
    BG_SYS_ClearSlot(4);
    BG_SYS_InitRun(4, 0x20, 0, 0x4C);
    t5 = d_021EF8AC;
    BG_SYS_InitBgLayer(5, &t5, 0);
    t6 = d_021EF84C;
    BG_SYS_InitBgLayer(6, &t6, 0);
    BG_SYS_ClearSlot(6);
    BG_SYS_InitRun(6, 0x20, 0, 0x4C);
    BG_SYS_SetMainPlaneVisible(0xF, 1);
    BG_SYS_SetSubPlaneVisible(7, 1);
}
