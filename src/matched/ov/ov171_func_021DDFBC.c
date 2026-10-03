/*
 * function: func_021DDFBC
 * address: 0x021DDFBC
 * packet: pkt_ov171_021DDFBC
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Descriptor;
struct CharBuf;
extern void func_020456F8(struct Descriptor *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(u32);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,u8);
extern void func_02045334(struct Descriptor *);
void func_021DDFBC(u8 *p)
{
    func_020456F8(*(struct Descriptor **)(p+0xb50));
    func_02041B6C(func_02045730(*(struct Descriptor **)(p+0xb50)));
    func_02043B5C(func_02045770(*(struct Descriptor **)(p+0xb50)),0);
    func_02045334(*(struct Descriptor **)(p+0xb50));
}
