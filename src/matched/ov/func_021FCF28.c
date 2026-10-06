/*
 * function: func_021FCF28
 * address:  0x021FCF28
 * packet:   pkt_021FCF28
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02043668  0x02043668  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_020435F4  0x020435F4  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040588  0x02040588  arm
 *   func_02040B94  0x02040B94  arm
 *   func_020434DC  0x020434DC  arm
 *   g_02203618  0x02203618  data  ov135
 *   g_02203628  0x02203628  data  ov135
 *   g_02203648  0x02203648  data  ov135
 *
 * Three-layer bring-up: the saved display config, layers 2 and 1 enabled
 * (only 2 020414EC'd) and layer 2's 0x20x0x48 tilemap cleared.
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

extern u32 func_02043668(void);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_020435F4(u32 a);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_020434DC(u32 mask, u32 enable);

extern struct DispConfig g_02203618;
extern struct BgTemplate g_02203628;
extern struct BgTemplate g_02203648;

void func_021FCF28(int y)
{
    struct DispConfig c = g_02203618;
    u32 v = func_02043668();

    func_0203FC28(&c);
    func_020435F4(v);
    {
        struct BgTemplate t = g_02203628;

        func_0203FCA0(2, &t, 0);
    }
    func_020414EC(2);
    func_02040588(2, 1);
    {
        struct BgTemplate t = g_02203648;

        func_0203FCA0(1, &t, 0);
    }
    func_02040588(1, 1);
    func_02040B94(2, 0x20, 0, 0x48);
    func_020434DC(8, 0);
}
