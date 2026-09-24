/*
 * function: func_021BA094
 * address:  0x021BA094
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BA150  0x021BA150  thumb  ov217
 *   func_021BA190  0x021BA190  thumb  ov217
 *   func_021BA194  0x021BA194  thumb  ov217
 *   func_021BA364  0x021BA364  thumb  ov217
 *
 * Two-case entry picked by func_021BA190(): mode 0 runs the
 * func_021BA364()/func_021BA194() pair, mode 1 runs func_021BA150() when the
 * ARM9 query func_0204E804() is clear.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_0204E804();
extern u32 func_021BA150();
extern u32 func_021BA190();
extern u32 func_021BA194();
extern u32 func_021BA364();
void func_021BA094(u32 a0)
{
    switch (func_021BA190(a0)) {
    case 0:
    func_021BA364();
    func_021BA194(a0);
    break;
    case 1:
    if (func_0204E804() == 0) {
    func_021BA150(a0);
    }
    break;
    }
}
