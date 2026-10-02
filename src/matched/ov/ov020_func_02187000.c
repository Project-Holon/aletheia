/*
 * function: func_02187000
 * address:  0x02187000
 * packet:   pkt_ov020_02187000
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
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021A3460  0x021A3460  thumb  ov021
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_02186090  0x02186090  thumb
 *   func_0219391C  0x0219391C  thumb  ov021
 */

typedef short s16;
typedef unsigned short u16;

extern void *func_0215A5F4(void *p);
extern int *func_02158F58(int a0);
extern int func_02188C98(int);
extern int func_0218DC70(int);
extern void *func_02188CB4(unsigned char *p);
extern void *func_02188C7C(unsigned char *p);
extern int func_02158F74(int);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_02159B10(int, int);
extern void func_021A3460(int, s16 *, s16 *, s16 *);
extern void *func_0216DDC0(int, int, int, int);
extern int func_02186090(void *p);
extern int func_0219391C(int);

int func_02187000(int a0, int a1)
{
    void *r6;
    int *s;
    int a;
    void *b;
    void *c;
    u16 *r4;
    int r5;
    s16 v[3];

    r6 = func_0215A5F4((void *)a1);
    s = func_02158F58(r6);
    a = func_0218DC70(func_02188C98(s[1]));
    b = func_02188CB4(s[1]);
    c = func_02188C7C(s[1]);
    func_02158F74(r6);
    r4 = func_02159AE8((void *)a0, (void *)a1);
    r5 = func_02159B10(a0, a1);
    func_021A3460(b, &v[2], &v[1], &v[0]);
    r6 = func_02186090(func_0216DDC0(c, v[2], v[0], 0));
    r5 = (u16)(r5 - 1);
    if (func_0219391C(a) == 0)
        *r4 = r5 + (r6 * 4 + 1);
    else
        *r4 = r5 + (r6 * 4 + 9);
    return 0;
}
