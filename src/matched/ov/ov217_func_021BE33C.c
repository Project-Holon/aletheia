/*
 * function: func_021BE33C
 * address:  0x021BE33C
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
 *   func_021BE90C  0x021BE90C  thumb  ov217
 *
 * Same two-case entry with func_021BE90C() and the ARM9 query func_0204E804().
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
extern u32 func_0204E804();
extern void func_021BE90C(void);
void func_021BE33C(u32 a0)
{
    switch (func_021BE4DC(a0)) {
    case 0:
    func_021BE90C();
    func_021BE4E0(a0);
    break;
    case 1:
    if (func_0204E804() == 0) {
    func_021BE448(a0);
    }
    break;
    }
}
