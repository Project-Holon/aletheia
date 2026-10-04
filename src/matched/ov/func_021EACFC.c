/*
 * function: func_021EACFC
 * address:  0x021EACFC
 * packet:   pkt_021EACFC
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021EABD0  0x021EABD0  thumb  ov170
 */
typedef unsigned char u8;
typedef unsigned int u32;

struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(u32 a, int b);
extern void func_021EABD0(u8 *q, int a, u32 b, int c, int d, int e, u32 f, int g);

void func_021EACFC(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x2c);

    func_02043B5C((u32)func_02045770((struct Descriptor *)*(u32 *)(q + 0xe4)), 0);
    func_02043B5C((u32)func_02045770((struct Descriptor *)*(u32 *)(q + 0xec)), 0);
    func_02043B5C((u32)func_02045770((struct Descriptor *)*(u32 *)(q + 0xf4)), 0);
    func_02043B5C((u32)func_02045770((struct Descriptor *)*(u32 *)(q + 0xfc)), 0);
    func_021EABD0(q, 0xa, *(u32 *)(q + 0x80), 0x6d, 0, 0, *(u32 *)(q + 0x78), 0x440);
    func_021EABD0(q, 0xb, *(u32 *)(q + 0x80), 0x64, 0, 0, *(u32 *)(q + 0x78), 0x440);
    func_021EABD0(q, 0xc, *(u32 *)(q + 0x80), 0x65, 0, 0, *(u32 *)(q + 0x78), 0x440);
    func_021EABD0(q, 0xd, *(u32 *)(q + 0x80), 0x66, 0, 0, *(u32 *)(q + 0x78), 0x440);
}
