/*
 * function: func_021BC72C
 * address:  0x021BC72C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 304)), (u32)(a2 + 0), (u32)(a2) to func_02025774.
 *
 * symbols:
 *   func_02025774  0x02025774  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_02025774(u32, u32, u32);

void func_021BC72C(u8 *a0, u32 a1, u8 *a2)
{
    func_02025774((u32)(*(u32*)(a0 + (a1)*4 + 304)), (u32)(a2 + 0), (u32)(a2));
}

