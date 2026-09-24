/*
 * function: func_021BD868
 * address:  0x021BD868
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BE448  0x021BE448  thumb  ov217
 *   func_021BE4DC  0x021BE4DC  thumb  ov217
 *   func_021BE4E0  0x021BE4E0  thumb  ov217
 *   func_021C0918  0x021C0918  thumb  ov217
 *   func_021C093C  0x021C093C  thumb  ov217
 *
 * Same two-case entry with the func_021C0918()/func_021C093C() pair.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021BE448();
extern u32 func_021BE4DC();
extern u32 func_021BE4E0();
extern u32 func_021C0918();
extern u32 func_021C093C();
void func_021BD868(u32 a0)
{
    switch (func_021BE4DC(a0)) {
    case 0:
    func_021C0918(a0);
    func_021BE4E0(a0);
    break;
    case 1:
    if (func_021C093C(a0) != 0) {
    func_021BE448(a0);
    }
    break;
    }
}
