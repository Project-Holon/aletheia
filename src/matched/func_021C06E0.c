/*
 * function: func_021C06E0
 * address:  0x021C06E0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 932)), 932 to func_02025588.
 *
 * symbols:
 *   func_02025588  0x02025588  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_02025588(u32, u32);

void func_021C06E0(u8 *a0, u32 a1)
{
    func_02025588((u32)(*(u32*)(a0 + 932)), 932);
}

