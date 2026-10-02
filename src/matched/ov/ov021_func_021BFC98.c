/*
 * function: func_021BFC98
 * address:  0x021BFC98
 * packet:   pkt_ov021_021BFC98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C58 0x02188C58 thumb ov021
 *   func_02188CB4 0x02188CB4 thumb ov021
 *   func_021A3074 0x021A3074 thumb ov021
 *   func_0218E138 0x0218E138 thumb ov021
 *   func_0218E13C 0x0218E13C thumb ov021
 *   func_0216D410 0x0216D410 thumb ov010
 *   func_0216D454 0x0216D454 thumb ov010
 *   func_0216D480 0x0216D480 thumb ov010
 *   func_021BE92C 0x021BE92C thumb ov021
 *   func_02012374 0x02012374 thumb
 */

extern int func_02188C58(int);
extern void *func_02188CB4(unsigned char *p);
extern void *func_021A3074(unsigned char *p);
extern int func_0218E138(int);
extern void func_0218E13C(int, int);
extern void func_0216D410(int, int);
extern int func_0216D454(int);
extern void func_0216D480(int);
extern int func_021BE92C(int, int, int, int, int, int, int);
extern void func_02012374(int, int);

int func_021BFC98(int a, int *s, int *q)
{
    int h = func_02188C58(q[1]);
    void *t;

    t = func_021A3074(func_02188CB4(q[1]));
    switch (s[0]) {
    case 0:
        q[2] = func_0218E138(h);
        func_0218E13C(h, 0);
        func_0216D410(t, 0x44);
        func_02012374(a, func_021BE92C(q[0], q[1], 0, 1, 1, 0, 0));
        s[0] = s[0] + 1;
        break;
    case 1:
        if (func_0216D454(t) == 1) {
            func_0216D480(t);
            s[0] = s[0] + 1;
        }
        break;
    case 2:
        func_0218E13C(h, q[2]);
        s[0] = s[0] + 1;
        break;
    case 3:
        return 1;
    }
    return 0;
}
