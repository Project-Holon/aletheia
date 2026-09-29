/*
 * function: func_021BAD60
 * address:  0x021BAD60
 * packet:   pkt_ov068_021BAD60
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_021BA1C4  0x021BA1C4  thumb  ov068
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void  func_02082BCC(void *p, u32 v, u32 n);
extern void *func_02045EC0(void *h, u32 idx);
extern void  func_021BA1C4(u8 *p, u32 a, u32 b, void *c, u32 d, u32 e, u16 f);

void func_021BAD60(u8 *p, u32 a, u32 b, void *c, u32 s0, u32 s1, u32 s2, u16 s3)
{
    int i;

    func_02082BCC(p, 0, 0x70);
    *(u16 *)(p + 0x54) = 0;
    *(u32 *)(p + 0x6c) = s1;
    func_021BA1C4(p, a, b, c, s0, s2, s3);
    for (i = 0; i < 2; i++) {
        u8 *e = p + i * 12;

        *(void **)(e + 0x3c) = func_02045EC0(c, i + 0x22);
        *(u16 *)(e + 0x40) = 0x39E3;
        *(u32 *)(e + 0x44) = 0;
    }
    *(u32 *)(p + 0x58) = s3;
    *(u8 *)(p + 0x5c) = 2;
    *(u8 **)(p + 0x60) = p + 0x3c;
    *(u32 *)(p + 0x64) = 1;
    *(u8 *)(p + 0x68) = 0x20;
    *(u8 *)(p + 0x69) = 0xc;
    *(u8 *)(p + 0x6a) = 0xd;
    *(u8 *)(p + 0x6b) = 3;
}
