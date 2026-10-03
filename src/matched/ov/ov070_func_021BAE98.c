/*
 * function: func_021BAE98
 * address:  0x021BAE98
 * packet:   pkt_ov070_021BAE98
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_020450F0  0x020450F0  arm
 *   func_021BAF38  0x021BAF38  thumb  ov070
 *   func_021BA96C  0x021BA96C  thumb  ov070
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_021BAF38(int, int);
extern void func_021BA96C(int, unsigned);

void func_021BAE98(int p)
{
    *(int *)(p + 0x504) = func_020450F0(2, 3, 0x15, 0xC, 3, 0xC, 1);
    *(int *)(p + 0x75C) = func_020450F0(2, 1, 0x15, 8, 3, 0xC, 1);
    *(int *)(p + 0x764) = func_020450F0(2, 9, 0x15, 9, 3, 0xC, 1);
    func_021BAF38(p, *(int *)(p + 0x80C));
    func_021BA96C(p, *(int *)(p + 0x80C));
}
