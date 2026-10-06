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

extern int func_02035750(void);
typedef unsigned short u16;
struct Kind;
extern int func_020357A0(struct Kind *p);
extern u16 func_02035760(struct Kind *p);
extern u16 func_02035780(struct Kind *p);
struct R;
extern int func_02035ADC(struct R *p, u32 x, u32 y);

int func_02035B58(u32 a, u32 b)
{
    u32 x;
    u32 y;

    func_02035750();
    if (func_020357A0((struct Kind *)a) == 0) {
        return -1;
    }
    x = func_02035760((struct Kind *)a);
    y = func_02035780((struct Kind *)a);
    return func_02035ADC((struct R *)b, x, y);
}
