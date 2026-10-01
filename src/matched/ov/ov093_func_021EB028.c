/*
 * function: func_021EB028
 * address: 0x021EB028
 * packet: pkt_ov093_021EB028
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_020215EC 0x020215EC thumb
 *   func_020215BC 0x020215BC thumb
 *   func_02041300 0x02041300 arm
 *   func_02040C14 0x02040C14 arm
 *   func_021EB1D8 0x021EB1D8 thumb ov093
 *   func_0204989C 0x0204989C arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02045374 0x02045374 arm
 *   func_020454E0 0x020454E0 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_021ED76C 0x021ED76C thumb ov093
 *   func_021ED930 0x021ED930 thumb ov093
 *   func_021EDB3C 0x021EDB3C thumb ov093
 *   func_020409B4 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   func_020434DC 0x020434DC arm
 *   d_021F3930 0x021F3930 data a4
 *   d_021F3950 0x021F3950 data a4
 *   d_021F3970 0x021F3970 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct BgTemplate;
extern const struct BgTemplate d_021F3930, d_021F3950, d_021F3970;
extern void func_0203FCA0(u32, const struct BgTemplate *, u32);
extern void *func_021F86E0(void);
extern void func_020215EC(void *, u32, u32, u32, u32, u32, u16, u16);
extern void func_020215BC(void *, const void *, u32, u32, u16);
extern void func_02041300(u32, int, int, int, u8, u8, u8);
extern void func_02040C14(u32, u32, u32, u32);
extern u16 func_021EB1D8(u8 *, u32, u32, u32);
extern void func_0204989C(u32, u32, u32, u32, u32, u32, u32);
extern void *func_020450F0(u32, u32, u32, u32, u32, u32, u32);
extern void *func_02045770(void *);
extern void func_02045374(void *);
extern void func_020454E0(void *, u16, u32);
extern void func_02043B5C(void *, int);
extern void func_02045334(void *);
extern void func_021ED76C(void *, void *);
extern void func_021ED930(void *);
extern void func_021EDB3C(void *, void *);
extern void func_020409B4(u8);
extern void func_02040588(u32, u8);
extern void func_020434DC(int, int);

void func_021EB028(u8 *p)
{
    u16 zero;
    u32 tile;
    func_0203FCA0(1, &d_021F3930, 0);
    func_0203FCA0(2, &d_021F3950, 0);
    func_0203FCA0(3, &d_021F3970, 0);
    func_020215EC(func_021F86E0(), 0xb, 0x5a, *(u16 *)(p + 0x13c), 0, 0x20, 0, 0);
    func_020215EC(func_021F86E0(), 0xb, 0xd6, *(u16 *)(p + 0x13c), 0, 0x60, 0x10, 0x10);
    zero = 0;
    func_020215BC(func_021F86E0(), &zero, 0, 0, 2);
    func_02041300(1, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02040C14(1, 0, 1, 0);
    tile = func_021EB1D8(p, 0xb, 0x59, 1);
    *(u32 *)(p + 0x14) = func_021EB1D8(p, 0xb, 0xd5, 3);
    func_0204989C(0xb, 0xd7, 2, 0, 0, 0, *(u16 *)(p + 0x13c));
    func_0204989C(0xb, 0xd8, 3, 0, 0, 0, *(u16 *)(p + 0x13c));
    *(void **)p = func_020450F0(1, 1, 0x13, 0x1e, 4, 0, 0);
    *(void **)(p + 4) = func_02045770(*(void **)p);
    func_02045374(*(void **)p);
    func_020454E0(*(void **)p, tile, 0);
    func_02043B5C(*(void **)(p + 4), 0xc);
    func_02045334(*(void **)p);
    *(u32 *)(p + 0x10) = func_021EB1D8(p, 0xb, 0xdd, 3);
    *(void **)(p + 8) = func_020450F0(3, 0x15, 0x25, 0xa, 0xc, 3, 0);
    *(void **)(p + 0xc) = func_02045770(*(void **)(p + 8));
    func_021ED76C(p + 0x154, *(void **)p);
    func_021ED930(p);
    func_021EDB3C(p, *(void **)(p + 0x14));
    func_020409B4(1);
    func_020409B4(2);
    func_020409B4(3);
    func_02040588(0, 1);
    func_02040588(1, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
    func_020434DC(0x10, 1);
}
