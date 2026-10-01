/*
 * function: func_021BC9FC
 * address: 0x021BC9FC
 * packet: pkt_ov217_021BC9FC
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_02045088 0x02045088 arm
 *   d_021C30C0 0x021C30C0 data a4 ov217
 *   d_021C3110 0x021C3110 data a4 ov217
 *   d_021C3130 0x021C3130 data a4 ov217
 *   d_021C30F0 0x021C30F0 data a4 ov217
 *   d_021C3150 0x021C3150 data a4
 *   d_021C3170 0x021C3170 data a4 ov217
 * Pool +B4 names 021C3150; no cross-overlay loading proof. Alignment-only
 * hint permits sole-ref/data validation of the original template address.
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct DispConfig;
struct BgTemplate;
extern struct DispConfig d_021C30C0;
extern const struct BgTemplate d_021C3110, d_021C3130, d_021C30F0, d_021C3150, d_021C3170;
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32, const struct BgTemplate *, u32);
extern void func_02040588(u32, u32);
extern void func_0207D63C(u32, u32, u32, u32, u32);
extern void func_02045088(u16);
void func_021BC9FC(char *p)
{
    func_0203FC28(&d_021C30C0);
    func_0203FCA0(6, &d_021C3110, 0);
    func_0203FCA0(7, &d_021C3130, 0);
    func_0203FCA0(0, &d_021C30F0, 0);
    func_0203FCA0(2, &d_021C3150, 0);
    func_0203FCA0(3, &d_021C3170, 0);
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_02040588(6, 1);
    func_02040588(7, 1);
    func_02040588(1, 1);
    func_02040588(0, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
    func_0207D63C(0x04001050, 2, 1, 16, 5);
    func_0207D63C(0x04000050, 4, 2, 16, 5);
    func_02045088(*(u16 *)(p + 8));
}
