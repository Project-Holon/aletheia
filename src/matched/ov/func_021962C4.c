/*
 * function: func_021962C4
 * address:  0x021962C4
 * packet:   pkt_021962C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0202F038  0x0202F038  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_02041B6C  0x02041B6C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0201F7A8(u32, u32);
extern u32 func_0202F038(u32);
extern u32 func_02041B6C(u32);
extern u32 func_020456F8(u32);

int func_021962C4(u32 a)
{
if (*(u32 *)((u8 *)(a) + ((186 << 2))) != 0) {
    func_0202F038(*(u32 *)((u8 *)(a) + ((186 << 2))));
    *(u32 *)((u8 *)(a) + ((186 << 2))) = 0;
}
func_0201F7A8(*(u32 *)((u8 *)(a) + ((43 << 4))), 2);
func_020456F8(*(u32 *)((u8 *)(a) + ((43 << 4))));
return func_02041B6C(5);
}

