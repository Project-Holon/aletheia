/*
 * function: func_021BF8F4
 * address: 0x021BF8F4
 * packet: pkt_ov110_021BF8F4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040B94 0x02040B94 arm
 *   func_02041300 0x02041300 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021BF94C 0x021BF94C thumb ov110
 *   func_02040588 0x02040588 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02040B94(u32,u32,u32,u32);
extern void func_02041300(unsigned,int,int,int,u8,u8,u8);
extern void *func_02045770(u32);
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(u32);
extern void func_02045334(u32);
extern void func_020409B4(u32);
extern void func_021BF94C(u8 *);
extern void func_02040588(u32,u32);
void func_021BF8F4(u8 *p) {
    func_02040B94(2,32,0,42);
    func_02041300(2,0,0,0,32,32,13);
    func_02043B5C(func_02045770(*(u32 *)(p+12)),0);
    func_02045374(*(u32 *)(p+12));
    func_02045334(*(u32 *)(p+12));
    func_020409B4(2); func_021BF94C(p); func_02040588(2,0);
}
