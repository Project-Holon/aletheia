/*
 * function: func_021BC8D8
 * address:  0x021BC8D8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 12)) to func_0201D83C.
 *
 * symbols:
 *   func_0201D83C  0x0201D83C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_0201D83C(void *ptr);

void func_021BC8D8(u8 *a0)
{
    func_0201D83C((void *)((u32)(*(u32*)(a0 + 12))));
}

