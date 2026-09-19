/*
 * function: func_02035B58
 * address:  0x02035B58
 * packet:   pkt_02035ADC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_02035750 0x02035750  arm
 *   func_020357A0 0x020357A0  arm
 *   func_02035760 0x02035760  arm
 *   func_02035780 0x02035780  arm
 *   func_02035ADC 0x02035ADC  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02035750(u32 a);
extern u32  func_020357A0(u32 a);
extern u32  func_02035760(u32 a);
extern u32  func_02035780(u32 a);
extern int  func_02035ADC(u8 *p, u32 b, u32 c);

int func_02035B58(u32 a, u32 b)
{
    u32 x;
    u32 y;

    func_02035750(a);
    if (func_020357A0(a) == 0) {
        return -1;
    }
    x = func_02035760(a);
    y = func_02035780(a);
    return func_02035ADC((u8 *)b, x, y);
}
