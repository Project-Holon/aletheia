/*
 * function: func_0217B5E0
 * address:  0x0217B5E0
 * packet:   pkt_ov019_0217B5E0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0217AFB0  0x0217AFB0  thumb  ov019
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D828  0x0216D828  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 */

typedef short s16;

extern int func_0217AFB0(char *, int, int *);
extern int func_0216D3CC(int);
extern void func_0216D828(int, s16 *);
extern void func_0216D410(int, int);
extern void func_0216DAC8(int, int);
extern int func_0216D454(int);
extern int func_0216D480(int);
extern void *func_02188CB4(unsigned char *p);
extern void *func_021A3074(unsigned char *p);

int func_0217B5E0(char *base, int *p, int r2, unsigned char *state)
{
    s16 a[8];
    int h = func_0217AFB0(base, *p, p);
    switch (*state) {
    case 0:
        if (func_0216D3CC(h) == 1) {
            func_0216D828(func_021A3074(func_02188CB4((void *)r2)), a);
            func_0216D828(h, a + 4);
            if (a[4] != a[0] || a[6] != a[2]) {
                func_0216D410(h, 0x44);
                func_0216DAC8(h, 0);
                *state = *state + 1;
            }
        }
        break;
    case 1:
        if (func_0216D454(h) == 1) { func_0216D480(h); return 1; }
        break;
    }
    return 0;
}
