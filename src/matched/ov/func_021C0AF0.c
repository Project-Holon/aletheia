/*
 * function: func_021C0AF0
 * address:  0x021C0AF0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: branch to func_0204A5AC.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_0204A5AC(void);

void func_021C0AF0(void)
{
    func_0204A5AC();
}
