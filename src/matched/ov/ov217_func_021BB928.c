/*
 * function: func_021BB928
 * address:  0x021BB928
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to func_021C09CC.
 *
 * symbols:
 *   func_021C09CC  0x021C09CC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 func_021C09CC(void *p);

void func_021BB928(u8 *a0)
{
    func_021C09CC((void *)((u32)(*(u32*)(a0))));
}

