/*
 * function: func_021BC318
 * address: 0x021BC318
 * packet: pkt_ov211_021BC318
 * region: ov211
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   func_02041570 0x02041570 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
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
extern void func_0203F8F4(u16);
struct BgTemplate;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32);
extern void func_02040B94(u32, u32, u32, u32);
extern void func_02041570(int, u16);
extern void func_020434DC(u32, u32);
extern void func_02043598(u32, u32);
void func_021BC318(void)
{
    Config16 a;
    Config32 b, c, d, e, f;
    func_0203F8F4(0x7e);
    a = d_021BC8C8;
    func_0203FC28((struct DispConfig *)(&a));
    b = d_021BC910;
    func_0203FCA0(3, (const struct BgTemplate *)(&b), 2);
    func_020414EC(3);
    c = d_021BC930;
    func_0203FCA0(1, (const struct BgTemplate *)(&c), 0);
    func_02040B94(1, 0x20, 0x7fe0, 0x807e);
    func_02041570(1, 0x3ff);
    d = d_021BC950;
    func_0203FCA0(2, (const struct BgTemplate *)(&d), 0);
    func_020414EC(2);
    e = d_021BC970;
    func_0203FCA0(7, (const struct BgTemplate *)(&e), 2);
    func_020414EC(7);
    f = d_021BC8F0;
    func_0203FCA0(5, (const struct BgTemplate *)(&f), 0);
    func_020414EC(5);
    func_020434DC(14, 1);
    func_02043598(10, 1);
}
