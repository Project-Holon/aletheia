/*
 * function: func_02200E48
 * address: 0x02200E48
 * packet: pkt_ov135_02200E48
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 02200E92..02200E94 two zero alignment bytes.
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(u32, u32);
extern void func_02045334(u32);
extern void func_02045374(u32);
extern u32 func_02045730(u32);
extern void func_020409B4(u32);
void func_02200E48(u8 *p)
{
    u32 w;
    *(u32 *)(p + 0xd40) = func_020450F0(0, 2, 0x13, 0x1b, 4, 0xd, 1);
    func_02043B5C((u32)func_02045770((struct Descriptor *)*(u32 *)(p + 0xd40)), 0);
    w = *(u32 *)(p + 0xd40);
    func_02045334(w);
    func_02045374(w);
    func_020409B4(func_02045730(w));
}
