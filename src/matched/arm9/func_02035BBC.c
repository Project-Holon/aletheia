/*
 * function: func_02035BBC
 * address:  0x02035BBC
 * packet:   pkt_02035BBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02035750  0x02035750  arm
 *   func_020357C0  0x020357C0  arm
 *   func_02035760  0x02035760  arm
 *   func_02035780  0x02035780  arm
 *   func_02035ADC  0x02035ADC  arm
 */

typedef unsigned int u32;

extern void func_02035750(void *ctx);
typedef unsigned short u16;
struct Kind;
extern u16 func_020357C0(struct Kind *p);
extern void *func_02035760(void *ctx);
extern void *func_02035780(void *ctx);
extern int  func_02035ADC(void *param, void *a, void *b);

int func_02035BBC(void *ctx, void *param)
{
    void *a;
    void *b;

    func_02035750(ctx);
    if (func_020357C0(ctx) == 0) {
        return -1;
    }

    a = func_02035760(ctx);
    b = func_02035780(ctx);

    return func_02035ADC(param, a, b);
}
