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

typedef unsigned short u16;
typedef unsigned char  u8;
extern void *func_0217AFB0(void **a, u8 *b, u8 *c);
extern int func_0216D3CC(int);
extern void func_0216D828(int, s16 *);
extern void func_0216D410(void *a0, u16 a1);
extern void func_0216DAC8(unsigned int *p, unsigned int v);
extern int func_0216D454(int);
extern int func_0216D480(char *p);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);

int func_0217B5E0(char *base, int *p, int r2, unsigned char *state)
{
    s16 a[8];
    int h = (int)func_0217AFB0((void **)base, (u8 *)(*p), (u8 *)p);
    switch (*state) {
    case 0:
        if (func_0216D3CC(h) == 1) {
            func_0216D828((int)func_021A3074(func_02188CB4((void *)r2)), a);
            func_0216D828(h, a + 4);
            if (a[4] != a[0] || a[6] != a[2]) {
                func_0216D410((void *)h, 0x44);
                func_0216DAC8((unsigned int *)h, 0);
                *state = *state + 1;
            }
        }
        break;
    case 1:
        if (func_0216D454(h) == 1) { func_0216D480((char *)h); return 1; }
        break;
    }
    return 0;
}
