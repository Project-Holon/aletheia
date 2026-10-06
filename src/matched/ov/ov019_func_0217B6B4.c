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

typedef unsigned int   u32;
typedef unsigned char  u8;
extern void *func_0217AFB0(void **a, u8 *b, u8 *c);
extern u16 func_0217AED4(u8 *a, u8 *b);
extern int func_0216D3CC(int);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern u16 func_0216D5F8(void *p);
extern void func_0216D410(int, int);
extern int func_0216D480(char *p);
extern void func_0216D548(u32 *p, u32 v);
extern void func_0216D550(u32 *p, u32 v);

int func_0217B6B4(char *base, int *p, int r2, unsigned char *state)
{
    struct S *q = (struct S *)(base + 0x2830);
    int h;
    int k;

    h = (int)func_0217AFB0((void **)base, (u8 *)(*p), (u8 *)p);
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
        if (func_0216D480((char *)h) == 1) {
            func_0216D548((u32 *)h, 8);
            *state = *state + 1;
        }
        break;
    case 2:
        if (q->f58 != func_0217AED4((u8 *)(*p), (u8 *)p)) {
            func_0216D550((u32 *)h, 8);
            return 1;
        }
        break;
    }
    return 0;
}
