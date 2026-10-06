/*
 * function: func_02192B20
 * address:  0x02192B20
 * packet:   pkt_ov021_02192B20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045374  0x02045374  arm
 *   func_02045334  0x02045334  arm
 *   func_02192A04  0x02192A04  thumb  ov021
 */

typedef unsigned int u32;

extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, unsigned char c, unsigned char d, unsigned char slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *a);
extern void func_02192A04(u32 a);

u32 func_02192B20(u8 a, u8 b, u8 c, u8 d, u32 e)
{
    u32 w;

    w = func_020450F0(2, a, b, c, d, 0xE, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)w)), 0xFF);
    func_02045374((struct Cfg *)w);
    func_02045334((struct Descriptor *)w);
    func_02192A04(w);
    return w;
}
