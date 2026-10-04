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

typedef unsigned short u16;
typedef unsigned char  u8;
extern void *func_0217AFB0(void **a, u8 *b, u8 *c);
extern int func_0216D3CC(int);
extern void func_0216D410(void *a0, u16 a1);
extern int func_0216D454(int);
extern int func_0216D480(char *p);

int func_0217B66C(char *base, int *p, int r2, unsigned char *state)
{
    int h = (int)func_0217AFB0((void **)base, (u8 *)(*p), (u8 *)p);
    switch (*state) {
    case 0:
        if (func_0216D3CC(h) == 1) { func_0216D410((void *)h, 0x43); *state = *state + 1; }
        break;
    case 1:
        if (func_0216D454(h) == 1) { func_0216D480((char *)h); return 1; }
        break;
    }
    return 0;
}
