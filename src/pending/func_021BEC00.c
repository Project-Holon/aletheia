/*
 * function: func_021BEC00
 * address:  0x021BEC00
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)), 0 to func_021C09D8.
 *
 * MATCH: the pool word has no witness outside the compared range:
 *   021C09D8 (thumb, ov217) - see func_021BA31C.
 *
 * symbols:
 *   func_021C09D8  0x021C09D8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021C09D8(u32, u32);

void func_021BEC00(u8 *a0, u32 a1)
{
    func_021C09D8((u32)(*(u32*)(a0)), 0);
}

