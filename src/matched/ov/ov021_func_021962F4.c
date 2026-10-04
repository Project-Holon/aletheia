/*
 * function: func_021962F4
 * address:  0x021962F4
 * packet:   pkt_ov021_021962F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021962C4  0x021962C4  thumb  ov021
 *   func_020452E8  0x020452E8  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

struct Descriptor;
extern int func_021962C4(u32 a);
extern void func_020452E8(struct Descriptor *d);

void func_021962F4(u8 *a)
{
    func_021962C4((u32)a);
    func_020452E8((struct Descriptor *)(*(u32 *)(a + 0x2B0)));
    *(u32 *)(a + 0x2B0) = 0;
}
