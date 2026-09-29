/*
 * function: func_0219B520
 * address:  0x0219B520
 * packet:   pkt_ov021_0219B520
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D6B8  0x0216D6B8  thumb  ov010
 *   func_0219B494  0x0219B494  thumb  ov021
 *   func_0219B4C8  0x0219B4C8  thumb  ov021
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 */

typedef unsigned char u8;
typedef signed char   s8;

typedef struct St {
    u8 state;
    s8 f1;
    s8 cur;
    s8 max;
} St;

extern St *func_0216D6B8(int a);
extern int func_0219B494(int a);
extern int func_0219B4C8(int a);
extern int func_0216DA5C(int a);

int func_0219B520(int a)
{
    St *p;

    p = func_0216D6B8(a);
    switch (p->state) {
    case 0:
        if (func_0219B494(a) == 1) {
            p->state++;
        }
        break;
    case 1:
        if (func_0219B4C8(a) == 0) {
            break;
        }
        p->cur++;
        if (p->cur < p->max) {
            p->state = 0;
            break;
        }
        p->state++;
    case 2:
        if (func_0216DA5C(a) == 1) {
            break;
        }
        p->state++;
        p->cur = 0;
        p->f1 = 0;
    case 3:
        return 1;
    }
    return 0;
}
