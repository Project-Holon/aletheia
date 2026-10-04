/*
 * function: func_021C0D2C
 * address:  0x021C0D2C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 44)) to func_021C2A08.
 *
 * symbols:
 *   func_021C2A08  0x021C2A08  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int func_021C2A08(char *p);

void func_021C0D2C(u8 *a0)
{
    func_021C2A08((char *)((u32)(*(u32*)(a0 + 44))));
}

