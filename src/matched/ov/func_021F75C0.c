/*
 * function: func_021F75C0
 * address:  0x021F75C0
 * packet:   pkt_021F75C0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040588  0x02040588  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040B94  0x02040B94  arm
 *   g_02202F64  0x02202F64  data  ov135
 *   g_02202F84  0x02202F84  data  ov135
 *   g_02202F44  0x02202F44  data  ov135
 *   g_02202FA4  0x02202FA4  data  ov135
 *
 * Four-layer bring-up with no display restore: layer 2 is seeded by the
 * 02041300 tile dump and its 020409B4 redraw before the enable.
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
extern void func_02043598(u32 mask, u32 enable);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_020409B4(u32 layer);
extern void func_02041570(int channel, u16 val);

extern struct BgTemplate g_02202F64;
extern struct BgTemplate g_02202F84;
extern struct BgTemplate g_02202F44;
extern struct BgTemplate g_02202FA4;

void func_021F75C0(void)
{
    {
        struct BgTemplate t = g_02202F64;
        func_0203FCA0(0, &t, 0);
    }
    func_020414EC(0);
    func_02040588(0, 1);
    {
        struct BgTemplate t = g_02202F84;
        func_0203FCA0(1, &t, 0);
    }
    func_02040588(1, 1);
    {
        struct BgTemplate t = g_02202F44;
        func_0203FCA0(2, &t, 0);
    }
    func_02041300(2, 0, 0, 0, 0x20, 0x18, 0);
    func_020409B4(2);
    func_02040588(2, 1);
    {
        struct BgTemplate t = g_02202FA4;
        func_0203FCA0(3, &t, 0);
    }
    func_020414EC(3);
    func_02040588(3, 1);
    func_02040B94(0, 0x20, 0, 0x48);
    func_02040B94(3, 0x20, 0, 0x48);
}
