/*
 * function: func_021DD8BC
 * address: 0x021DD8BC
 * packet: pkt_ov171_021DD8BC
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Descriptor;
extern void func_020452E8(struct Descriptor *);
extern void func_020450C8(void);
void func_021DD8BC(u8 *p)
{
    func_020452E8(*(struct Descriptor **)(p+0xb48));
    func_020452E8(*(struct Descriptor **)(p+0xb50));
    func_020450C8();
}
