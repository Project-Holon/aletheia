/*
 * function: func_02186CC4
 * address:  0x02186CC4
 * packet:   pkt_ov020_02186CC4
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC70  0x0218DC70  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_021A3460  0x021A3460  thumb  ov021
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_02186090  0x02186090  thumb
 *   func_02193B68  0x02193B68  thumb  ov021
 */

typedef short s16;

extern void *func_0215A5F4(void *p);
extern int *func_02158F58(void *a0);
extern void *func_02188C98(int);
extern void *func_0218DC70(void *);
extern void *func_02188CB4(int p);
extern void *func_02188C7C(int p);
extern void *func_02158F74(void *);
extern int func_02159B10(int, int);
extern int func_0215A5CC(int);
extern void func_021A3460(void *, s16 *, s16 *, s16 *);
extern void *func_0216DDC0(void *, int, int, int);
extern int func_02186090(void *p);
extern void func_02193B68(void *, void *, int, int, int);

int func_02186CC4(int a0, int a1)
{
    void *r6;
    int *s;
    void *a;
    void *b;
    void *c;
    int r5;
    int r4;
    s16 v[3];

    r6 = func_0215A5F4((void *)a1);
    s = func_02158F58(r6);
    a = func_0218DC70(func_02188C98(s[1]));
    b = func_02188CB4(s[1]);
    c = func_02188C7C(s[1]);
    r6 = func_02158F74(r6);
    r5 = func_02159B10(a0, a1);
    r4 = func_0215A5CC(a1);
    func_021A3460(b, &v[2], &v[1], &v[0]);
    func_02193B68(a, r6, func_02186090(func_0216DDC0(c, v[2], v[0], 0)), r5, r4);
    return 0;
}
