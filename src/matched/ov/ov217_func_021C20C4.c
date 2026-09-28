/*
 * function: func_021C20C4
 * address:  0x021C20C4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: branch to func_021C20EC.
 *
 * symbols:
 *   func_021C20EC  0x021C20EC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021C20EC(void);

void func_021C20C4(void)
{
    func_021C20EC();
}
