/*
 * function: func_021B95E8
 * address: 0x021B95E8
 * packet: pkt_ov092_021B95E8
 * region: ov092
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203133C 0x0203133C arm
 *   func_02045808 0x02045808 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
typedef unsigned int u32;
struct S020314B8;
struct S020315D4;
struct U16Vec;
extern void func_0203133C(struct S020314B8 *);
extern void func_02045808(struct U16Vec *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int heap);
int func_021B95E8(struct S020315D4 *p, u32 b, u32 c, u32 d)
{
    func_0203133C(*(struct S020314B8 **)(d + 0x40));
    if (*(struct U16Vec **)(d + 0x2c)) func_02045808(*(struct U16Vec **)(d + 0x2c));
    func_02045808(*(struct U16Vec **)(d + 4));
    func_020315D4(p);
    func_020306F0(0x52);
    return 1;
}
