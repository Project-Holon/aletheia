/*
 * function: func_021BB5A0
 * address: 0x021BB5A0
 * packet: pkt_ov110_021BB5A0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero padding
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(u32);
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(u32);
u8 *func_021BB5A0(u8 *p,u8 *q) {
    u32 a;
    a=func_020450F0(1,10,3,11,2,12,1);
    func_02043B5C(func_02045770(a),1);
    func_02045334(a);
    *(u32 *)(p+0x94)=a;
    return q+0x16;
}
