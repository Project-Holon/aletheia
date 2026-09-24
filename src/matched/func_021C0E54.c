/*
 * function: func_021C0E54
 * address:  0x021C0E54
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: branch to func_021C0EC0.
 *
 * symbols:
 *   func_021C0EC0  0x021C0EC0  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021C0EC0(void);

void func_021C0E54(void)
{
    func_021C0EC0();
}
