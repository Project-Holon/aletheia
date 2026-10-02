/*
 * function: func_0217B6B4
 * address:  0x0217B6B4
 * packet:   pkt_ov019_0217B6B4
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0217AFB0 0x0217AFB0  thumb  ov019
 *   func_0217AED4 0x0217AED4  thumb  ov019
 *   func_0216D3CC 0x0216D3CC  thumb  ov010
 *   func_02188CB4 0x02188CB4  thumb  ov021
 *   func_021A3074 0x021A3074  thumb  ov021
 *   func_0216D5F8 0x0216D5F8  thumb  ov010
 *   func_0216D410 0x0216D410  thumb  ov010
 *   func_0216D480 0x0216D480  thumb  ov010
 *   func_0216D548 0x0216D548  thumb  ov010
 *   func_0216D550 0x0216D550  thumb  ov010
 */

typedef unsigned short u16;

struct S {
    char pad[0x58];
    u16 f58;
};

extern int func_0217AFB0(char *, int, int *);
extern int func_0217AED4(int, int *);
extern int func_0216D3CC(int);
extern void *func_02188CB4(unsigned char *p);
extern void *func_021A3074(unsigned char *p);
extern int func_0216D5F8(void *);
extern void func_0216D410(int, int);
extern int func_0216D480(int);
extern void func_0216D548(int, int);
extern void func_0216D550(int, int);

int func_0217B6B4(char *base, int *p, int r2, unsigned char *state)
{
    struct S *q = (struct S *)(base + 0x2830);
    int h;
    int k;

    h = func_0217AFB0(base, *p, p);
    switch (*state) {
    case 0:
        if (func_0216D3CC(h) == 1) {
            switch (func_0216D5F8(func_021A3074(func_02188CB4((void *)r2)))) {
            case 0:
                k = 1;
                break;
            case 1:
                k = 0;
                break;
            case 2:
                k = 3;
                break;
            case 3:
            default:
                k = 2;
                break;
            }
            func_0216D410(h, k);
            *state = *state + 1;
        }
        break;
    case 1:
        if (func_0216D480(h) == 1) {
            func_0216D548(h, 8);
            *state = *state + 1;
        }
        break;
    case 2:
        if (q->f58 != func_0217AED4(*p, p)) {
            func_0216D550(h, 8);
            return 1;
        }
        break;
    }
    return 0;
}
