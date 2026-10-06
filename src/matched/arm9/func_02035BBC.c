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

extern int func_02035750(void);
typedef unsigned short u16;
struct Kind;
extern u16 func_020357C0(struct Kind *p);
struct R;
extern u16 func_02035760(struct Kind *p);
extern u16 func_02035780(struct Kind *p);
extern int func_02035ADC(struct R *p, u32 x, u32 y);

int func_02035BBC(void *ctx, void *param)
{
    void *a;
    void *b;

    func_02035750();
    if (func_020357C0(ctx) == 0) {
        return -1;
    }

    a = (void *)func_02035760(ctx);
    b = (void *)func_02035780(ctx);

    return func_02035ADC(param, (u32)a, (u32)b);
}
