/*
 * function: func_021BC4A4
 * address:  0x021BC4A4
 * packet:   pkt_ov088_021BC4A4
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020084E4  0x020084E4  thumb
 *   func_0200854C  0x0200854C  thumb
 *   func_02005728  0x02005728  thumb
 *   func_0200852C  0x0200852C  thumb
 *   func_0203F0A8  0x0203F0A8  arm
 *   func_02008550  0x02008550  thumb
 *   func_02008558  0x02008558  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

extern u32 func_020084E4(u32 value, void *dst);
extern void func_0200854C(int, int);
extern u32 func_02005728(int);
extern void func_0200852C(int, u32);
extern u32 func_0203F0A8(void);
extern u32 func_02008550(int);
extern void func_02008558(int, u32);

void func_021BC4A4(int a, int b, int c)
{
    u64 x;
    u32 y;
    func_020084E4(a, (void *)b);
    func_0200854C(a, c);
    func_0200852C(a, func_02005728(-1));
    x = func_0203F0A8();
    y = func_02008550(a);
    func_02008558(a, (u8)((u32)((x * 8) >> 32) + y * 8));
}
