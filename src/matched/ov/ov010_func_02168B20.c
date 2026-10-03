/*
 * function: func_02168B20
 * address:  0x02168B20
 * packet:   pkt_ov010_02168B20
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * lever: 02026454 reads the live 02012138 result in r0 in cases 0 and 1.
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CCC  0x02188CCC  thumb ov021
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02012158  0x02012158  thumb
 *   func_020121CC  0x020121CC  thumb
 *   func_021A0F7C  0x021A0F7C  thumb ov021
 *   func_02168B18  0x02168B18  thumb ov010
 */

extern int func_0201210C(int);
extern int func_02188CCC(int);
extern int func_02012138(int);
extern int func_02026454(int);
extern void func_02026400(int);
extern void func_02012158(int, int);
extern void func_020121CC(int);
extern void func_021A0F7C(int, int, void *, int *);
extern void func_02168B18(int *);

typedef enum { ST_0, ST_1, ST_2, ST_3, ST_4, ST_5 } State;

int func_02168B20(int a, int *b, int *c)
{
    int s = c[2];
    int x = func_02188CCC(func_0201210C(s));
    int y = func_02012138(s);
    State t = (State)*b;
    switch (t) {
    case 0:
        if (func_02026454(y) != 0)
            func_02026400(y);
        (*b)++;
        break;
    case 1:
        if (func_02026454(y) != 0)
            break;
        func_02012158(s, 0);
        (*b)++;
        break;
    case 2:
        if (c[1] != 0) {
            func_02012158(s, 1);
            func_020121CC(s);
        }
        (*b)++;
        break;
    case 3:
        func_021A0F7C(x, 8, func_02168B18, c);
        (*b)++;
        break;
    case 4:
        if (c[0] != 0)
            *b = t + 1;
        break;
    case 5:
        return 1;
    }
    return 0;
}
