/*
 * function: func_021C6ADC
 * address: 0x021C6ADC
 * packet: pkt_ov128_021C6ADC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   func_021CA4B4 0x021CA4B4 thumb ov128
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021B6AE4(u8 *p, u32 a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern void func_021CA4B4(char *p);
void func_021C6ADC(u8 *p,u8 *q,unsigned v)
{
    func_02043B5C(func_02045770(*(void **)q),0);
    func_02045334(*(void **)q);
    func_02045CAC(*(void **)(p+4),v,*(void **)(p+0x18));
    func_0201F250(*(void **)p,*(void **)(p+0x14),*(void **)(p+0x18));
    func_021B6AE4(q,(u32)(*(void **)(p+0x34)),0,4,(u32)(*(void **)(p+0x14)),(u32)(*(void **)(p+0x17c)),0x3c40,0);
    func_021CA4B4(*(void **)q);
}
