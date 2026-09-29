/*
 * function: func_021C622C
 * address:  0x021C622C
 * packet:   pkt_ov021_021C622C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C62F0  0x021C62F0  thumb  ov021
 *   func_021C6368  0x021C6368  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021D3288  0x021D3288  thumb  ov021
 *   func_021D325C  0x021D325C  thumb  ov021
 *   func_021D3244  0x021D3244  thumb  ov021
 */

typedef unsigned char u8;

typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    void *f4;
} Ctx;

extern void func_021C62F0(Ctx *c);
extern void func_021C6368(Ctx *c);
extern void func_020061E4(int n);
extern void func_021D3288(void *a, int b, int c);
extern void func_021D325C(void *a, int b, int c, int d, int e);
extern void func_021D3244(void *a, int b, int c);

int func_021C622C(void *unused, int *st, Ctx *c)
{
    switch (*st) {
    case 0:
        func_021C62F0(c);
        func_020061E4(0x683);
        *st = *st + 1;
        break;
    case 1:
        if (c->f3++ >= c->f2) {
            c->f1++;
            func_021D3288(c->f4, c->f1, 0x10 - c->f1);
            c->f3 = 0;
        }
        if (c->f1 >= 8) {
            *st = *st + 1;
        }
        break;
    case 2:
        if (c->f3++ < 0x1e) {
            *st = *st + 1;
        }
        break;
    case 3:
        if (c->f3++ >= c->f2) {
            c->f1--;
            func_021D3288(c->f4, c->f1, 0x10 - c->f1);
            c->f3 = 0;
        }
        if (c->f1 == 0) {
            *st = *st + 1;
        }
        break;
    case 4:
        func_021D325C(c->f4, 0, 0, 0, 0x1f);
        func_021D3244(c->f4, c->f0, 0);
        *st = *st + 1;
        break;
    default:
        func_021C6368(c);
        return 1;
    }
    return 0;
}
