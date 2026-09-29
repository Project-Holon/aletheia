/*
 * function: func_021B0084
 * address:  0x021B0084
 * packet:   pkt_ov021_021B0084
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A684  0x0215A684  thumb  ov010
 *   func_0215A690  0x0215A690  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02190BE4  0x02190BE4  thumb  ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 * State 2 is a nested switch on func_02190C78's result (case 0, case 2
 * empty, default) with the flag store and the state increment written out
 * in each arm: the compiler cross-jumps the default arm into case 0's
 * tail, which is why `movs r1,#1; b` sits after the shared increment.
 * An if/else chain puts that arm inline. The listing extent includes two
 * bytes of padding.
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 a0;
    u16 *flag;
    u32 h;
} Ctx;

extern u32 func_0215A5F4(u32 a);
extern void func_0215A684(u32 a, u32 b);
extern u32 func_0215A690(u32 a);
extern u32 func_0215A5DC(u32 a);
extern u32 func_0201210C(u32 a);
extern u32 func_02188C54(u32 a);
extern u32 func_02190BE4(u32 a, u32 b);
extern u32 func_02190C78(u32 a);
extern void func_021909BC(u32 a);

int func_021B0084(u32 a0, int *st, Ctx *c)
{
    func_0215A5F4(c->a0);
    switch (*st) {
    case 0:
        func_0215A684(c->a0, 8);
        (*st)++;
    case 1:
        if (func_0215A690(c->a0) == 1) {
            c->h = func_02190BE4(func_02188C54(func_0201210C(func_0215A5DC(c->a0))), 0);
            (*st)++;
        }
        break;
    case 2:
        switch (func_02190C78(c->h)) {
        case 0:
            *c->flag = 0;
            (*st)++;
            break;
        case 2:
            break;
        default:
            *c->flag = 1;
            (*st)++;
            break;
        }
        break;
    case 3:
        func_021909BC(c->h);
        return 1;
    }
    return 0;
}
