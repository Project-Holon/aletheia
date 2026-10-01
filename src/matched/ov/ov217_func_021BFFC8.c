/*
 * function: func_021BFFC8
 * address: 0x021BFFC8
 * packet: pkt_ov217_021BFFC8
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * data: pool 021C0068 contains 6c 36 1c 02; contested ov217 hint removed per canonical rule, data a4 resolves sole-ref.
 * symbols:
 *   func_0203FC28 0x0203FC28 arm
 *   func_0204044C 0x0204044C arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   sub_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   sub_02045088 0x02045088 arm
 *   d_021C366C 0x021C366C data a4
 *   d_021C36D8 0x021C36D8 data ov217
 *   d_021C36F8 0x021C36F8 data ov217
 *   d_021C3718 0x021C3718 data ov217
 *   d_021C3738 0x021C3738 data ov217
 */
typedef unsigned int u32;
typedef unsigned short u16;
struct DispConfig { u32 a,b,c,d; };
struct BgTemplate { u32 a,b,c,d; unsigned char e,f,g,h; u32 i; unsigned char j,k,l,m; u32 n; };
extern struct DispConfig d_021C366C;
extern const struct BgTemplate d_021C36D8,d_021C36F8,d_021C3718,d_021C3738;
extern void func_0203FC28(struct DispConfig *);
extern void func_0204044C(u32);
extern void func_0203FCA0(u32, const struct BgTemplate *, u32);
extern void sub_02040588(u32, u32);
extern void func_0207D63C(u32 *, u32, u32, int, int);
extern void sub_02045088(u16);
void func_021BFFC8(char *p)
{
    func_0203FC28(&d_021C366C);
    func_0204044C(2);
    func_0203FCA0(6, &d_021C36D8, 0);
    func_0203FCA0(7, &d_021C3738, 0);
    func_0203FCA0(2, &d_021C36F8, 0);
    func_0203FCA0(3, &d_021C3718, 0);
    sub_02040588(4, 1);
    sub_02040588(5, 1);
    sub_02040588(6, 1);
    sub_02040588(7, 1);
    sub_02040588(0, 1);
    sub_02040588(1, 1);
    sub_02040588(2, 1);
    sub_02040588(3, 1);
    func_0207D63C((u32 *)0x04001050, 2, 1, 7, 15);
    func_0207D63C((u32 *)0x04000050, 4, 2, 16, 5);
    sub_02045088(*(u16 *)(p + 4));
}
