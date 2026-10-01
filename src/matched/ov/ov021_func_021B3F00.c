/*
 * function: func_021B3F00
 * address:  0x021B3F00
 * packet:   pkt_ov021_021B3F00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B22C  0x0204B22C  arm
 *   func_021B3C78  0x021B3C78  thumb  ov021
 *   func_021B3CFC  0x021B3CFC  thumb  ov021
 *   func_021B3DEC  0x021B3DEC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0204B100(u32, u32, u16);
extern void func_0204B22C(u32, u32);
extern void func_021B3C78(u8 *);
extern u32 func_020490F4(u32, u16);
extern void func_021B3CFC(u8 *);
extern void func_021B3DEC(u8 *);

void func_021B3F00(u8 *w)
{
    *(u32 *)(w + 0x1BC) = func_0204B100(5, 1, *(u16 *)(w + 4));
    func_0204B22C(*(u32 *)(w + 0x1BC), 1);
    func_021B3C78(w);
    *(u32 *)(w + 0x1F8) = func_020490F4(0x19, *(u16 *)(w + 4));
    func_021B3CFC(w);
    func_021B3DEC(w);
}
