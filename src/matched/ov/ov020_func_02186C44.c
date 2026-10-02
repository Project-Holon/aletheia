/*
 * function: func_02186C44
 * address:  0x02186C44
 * packet:   pkt_ov020_02186C44
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC70  0x0218DC70  thumb  ov021
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_020127F0  0x020127F0  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_021A3460  0x021A3460  thumb  ov021
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_02186090  0x02186090  thumb
 *   func_02193BE4  0x02193BE4  thumb  ov021
 *   func_02193BC4  0x02193BC4  thumb  ov021
 *   func_021869B0  0x021869B0  thumb
 */

typedef short s16;

extern int func_0215A5F4(int);
extern int *func_02158F58(int a0);
extern int func_02188C98(int);
extern int func_0218DC70(int);
extern int func_0215A5E4(int);
extern int func_020127F0(int);
extern int func_02188CB4(int);
extern int func_02188C7C(int);
extern void func_021A3460(int, s16 *, s16 *, s16 *);
extern void *func_0216DDC0(int, int, int, int);
extern int func_02186090(void *p);
extern int func_02193BE4(int, int);
extern void func_02193BC4(int, int);
extern void func_021869B0(int);

int func_02186C44(int a0, int a1)
{
    int *s;
    int a;
    int b;
    int c;
    int d;
    int e;
    s16 v[3];

    s = func_02158F58(func_0215A5F4(a1));
    a = func_0218DC70(func_02188C98(s[1]));
    b = func_020127F0(func_0215A5E4(a1));
    c = func_02188CB4(s[1]);
    d = func_02188C7C(s[1]);
    func_021A3460(c, &v[2], &v[1], &v[0]);
    e = func_02186090(func_0216DDC0(d, v[2], v[0], 0));
    if (func_02193BE4(a, e) != 0) {
        func_02193BC4(a, e);
        func_021869B0(b);
    }
    return 0;
}
