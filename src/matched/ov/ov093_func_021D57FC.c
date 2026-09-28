/*
 * function: func_021D57FC
 * address:  0x021D57FC
 * packet:   pkt_ov093_021D57FC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D57A8  0x021D57A8  thumb  ov093
 *   func_021E8CE0  0x021E8CE0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021D57A8(void *p, u8 *a, u8 *b);
extern u16 func_021E8CE0(u32 a, u32 b);

u16 func_021D57FC(void *p)
{
    u8 a;
    u8 b;
    func_021D57A8(p, &a, &b);
    return func_021E8CE0(a, b);
}
