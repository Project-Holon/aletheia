/*
 * function: func_0217B66C
 * address:  0x0217B66C
 * packet:   pkt_ov019_0217B66C
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0217AFB0  0x0217AFB0  thumb  ov019
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 */

extern int func_0217AFB0(char *, int, int *);
extern int func_0216D3CC(int);
extern void func_0216D410(int, int);
extern int func_0216D454(int);
extern int func_0216D480(int);

int func_0217B66C(char *base, int *p, int r2, unsigned char *state)
{
    int h = func_0217AFB0(base, *p, p);
    switch (*state) {
    case 0:
        if (func_0216D3CC(h) == 1) { func_0216D410(h, 0x43); *state = *state + 1; }
        break;
    case 1:
        if (func_0216D454(h) == 1) { func_0216D480(h); return 1; }
        break;
    }
    return 0;
}
