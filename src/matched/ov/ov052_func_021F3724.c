/*
 * function: func_021F3724
 * address:  0x021F3724
 * packet:   pkt_ov052_021F3724
 * region:   ov052
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_021F3998  0x021F3998  thumb  ov052
 *   func_0200B3A4  0x0200B3A4  thumb
 *   d_021F3A2C     0x021F3A2C  data  a4
 */

typedef struct { void (*f0)(void *, void *); void (*f1)(void *, void *); void (*f2)(void *, void *); } Ent;

extern int func_02188C84(void *);
extern int func_02188C80(void *);
extern unsigned func_020120F4(unsigned);
extern unsigned func_02012EC4(unsigned);
extern int func_02188C9C(void *);
extern void func_021F3998(int, int *, int *);
extern unsigned short *func_0200B3A4(unsigned, int);
extern Ent d_021F3A2C[];

void func_021F3724(void *a)
{
    int s1;
    int s0;
    unsigned h;
    unsigned short *p;
    void (*f)(void *, void *);

    func_02188C84(a);
    h = func_02012EC4(func_020120F4(func_02188C80(a)));
    func_021F3998(func_02188C9C(a), &s0, &s1);
    p = func_0200B3A4(h, s0);
    f = d_021F3A2C[p[1]].f1;
    if (f)
        f(p, a);
}
