/*
 * function: func_021B0A88
 * address:  0x021B0A88
 * packet:   pkt_ov021_021B0A88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021912D8  0x021912D8  thumb  ov021
 *   func_021B0A60  0x021B0A60  thumb  ov021
 *   func_02159190  0x02159190  thumb  ov010
 *   func_0215A61C  0x0215A61C  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern int func_02159190(u32 a);
extern u32 func_0215A61C(u32 a);
extern void func_021912D8(u32 a);
extern void func_020113D0(u32 a, void (*cb)(void));
extern void func_021B0A60(void);

void func_021B0A88(u32 a, u32 b)
{
    if (func_02159190(2) != 0) {
        func_021912D8(func_0215A61C(b));
        func_020113D0(a, func_021B0A60);
    }
}
