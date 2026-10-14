/*
 * function: GSYNC_MENU_InitBgLayers
 * address: 0x021D424C
 * packet: pkt_ov123_021D424C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021DA690 0x021DA690 data a4
 *   d_021DA6B0 0x021DA6B0 data a4
 *   d_021DA6D0 0x021DA6D0 data a4
 *   d_021DA6F0 0x021DA6F0 data a4
 *   d_021DA710 0x021DA710 data a4
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204047C 0x0204047C arm
 *   func_02040588 0x02040588 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct BgTemplate {
    u32 unk_00, unk_04, bufSize, unk_0c;
    u8 unk_10, unk_11, unk_12, unk_13;
    u32 unk_14;
    u8 unk_18, unk_19, unk_1a, unk_1b;
    u32 unk_1c;
};
extern const struct BgTemplate d_021DA690, d_021DA6B0, d_021DA6D0, d_021DA6F0, d_021DA710;
extern void func_0203FCA0(u32, const struct BgTemplate *, u32);
extern void func_020414AC(u32);
extern void func_020409B4(u32);
extern void func_0204047C(int, u16);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040C14(u32, u32, u32, u32);
extern void func_02041300(u32, u32, u32, u32, u8, u8, u8);
void GSYNC_MENU_InitBgLayers(char *a0)
{
    struct BgTemplate b[5];
    b[4] = d_021DA690;
    func_0203FCA0(0, &b[4], 0);
    func_020414AC(0);
    func_020409B4(0);
    func_0204047C(0, 0);
    func_02040588(0, 1);
    b[3] = d_021DA6B0;
    func_0203FCA0(4, &b[3], 0);
    func_02040588(4, 1);
    func_020409B4(4);
    b[2] = d_021DA6D0;
    func_0203FCA0(5, &b[2], 0);
    func_02040C14(5, 0, 1, 0);
    func_02041300(5, 0, 0, 0, 32, 32, 17);
    func_020409B4(5);
    func_02040588(5, 1);
    b[1] = d_021DA6F0;
    func_0203FCA0(6, &b[1], 0);
    func_02040588(6, 1);
    func_020409B4(6);
    b[0] = d_021DA710;
    func_0203FCA0(7, &b[0], 0);
    func_02040588(7, 1);
    func_020409B4(7);
}
