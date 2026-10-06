/*
 * function: func_021BE040
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
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040C14 0x02040C14 arm
 *   func_020414C4 0x020414C4 arm
 *   func_0204047C 0x0204047C arm
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
extern void func_0203F8F4(u16);
struct BgTemplate;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u32);
extern void func_020409B4(u32);
extern void func_02040C14(u32, u32, u32, u32);
extern void func_020414C4(u32 idx);
extern void func_0204047C(int, u16);
void func_021BE040(u16 heap)
{
    Disp d;
    Bg b0, b1, b2, b3, b4, b5, b6, b7;
    int i;
    func_0203F8F4(heap);
    d = d_021C37F4;
    func_0203FC28((struct DispConfig *)(&d));
    b0 = d_021C396C;
    i = 0;
    func_0203FCA0(0, (const struct BgTemplate *)(&b0), 0);
    func_020414AC(0);
    func_020409B4(0);
    b1 = d_021C382C;
    func_0203FCA0(1, (const struct BgTemplate *)(&b1), 0);
    func_020414AC(1);
    func_020409B4(1);
    b2 = d_021C384C;
    func_0203FCA0(2, (const struct BgTemplate *)(&b2), 0);
    func_02040C14(2, 0, 1, 0);
    func_020414AC(2);
    func_020409B4(2);
    b3 = d_021C386C;
    func_0203FCA0(3, (const struct BgTemplate *)(&b3), 0);
    func_020414AC(3);
    func_020409B4(3);
    b4 = d_021C38AC;
    func_0203FCA0(4, (const struct BgTemplate *)(&b4), 0);
    func_020414AC(4);
    b5 = d_021C38CC;
    func_0203FCA0(5, (const struct BgTemplate *)(&b5), 0);
    func_020414AC(5);
    b6 = d_021C392C;
    func_0203FCA0(6, (const struct BgTemplate *)(&b6), 0);
    func_020414AC(6);
    b7 = d_021C394C;
    func_0203FCA0(7, (const struct BgTemplate *)(&b7), 0);
    func_020414AC(7);
    for (; i < 7; i++) func_020414C4((u8)i);
    func_0204047C(0, 3);
    func_0204047C(1, 1);
    func_0204047C(3, 1);
    func_0204047C(2, 0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
}
