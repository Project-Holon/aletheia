/*
 * function: func_021BF55C
 * address:  0x021BF55C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) a0, 1, 1 to func_021BF580.
 *
 * symbols:
 *   func_021BF580  0x021BF580  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021BF580(u8 *p, u32 i, u32 j);

void func_021BF55C(void *a0)
{
    func_021BF580((u8 *)a0, 1, 1);
}

