/*
 * function: func_021C63AC
 * address: 0x021C63AC
 * packet: pkt_ov128_021C63AC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_021CA458 0x021CA458 thumb ov128
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(u32);
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(u32);
extern void func_021CA458(char *p, void *q);
void func_021C63AC(void *p,u32 *out,u32 a,u32 b,u8 c,u8 d,u8 e,u8 f,u32 unused,u8 g)
{
    *out=func_020450F0(a,b,c,d,e,f,1);
    func_02043B5C(func_02045770(*out),g);
    func_02045334(*out);
    func_021CA458(p,out);
}
