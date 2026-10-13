/*
 * function: REPORT_InitBgs
 * address:  0x021F0114
 * packet:   pkt_ov034_021F0114
 * region:   ov034
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021F0AA0 0x021F0AA0 data ov034 a4
 *   sReportBgTemplate5 0x021F0AC0 data ov034 a4
 *   sReportBgTemplate4 0x021F0AE0 data a4
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
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_020409B4(u32 layer);

extern struct BgTemplate d_021F0AA0;
extern struct BgTemplate sReportBgTemplate5;
extern struct BgTemplate sReportBgTemplate4;

void REPORT_InitBgs(u32 heapId)
{
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 0);
    func_02040588(7, 0);
    {
        struct BgTemplate t = sReportBgTemplate4;

        func_0203FCA0(4, &t, 0);
    }
    func_020414EC(4);
    func_02040B94(4, 0x20, 0, heapId);
    func_020409B4(4);
    {
        struct BgTemplate t = sReportBgTemplate5;

        func_0203FCA0(5, &t, 0);
    }
    func_020414EC(5);
    func_02040B94(5, 0x20, 0, heapId);
    func_020409B4(5);
    {
        struct BgTemplate t = d_021F0AA0;

        func_0203FCA0(6, &t, 0);
    }
    func_020414EC(6);
    func_02040B94(6, 0x20, 0, heapId);
    func_020409B4(6);
}
