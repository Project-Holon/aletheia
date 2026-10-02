/*
 * function: func_021F398C
 * address:  0x021F398C
 * packet:   pkt_ov043_021F398C
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F398C  0x021F398C  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_021F3AC0  0x021F3AC0  thumb
 *   d_021F4490    0x021F4490  data  a4
 */

typedef unsigned int u32;

typedef struct {
    int a;
    int b;
    int pad[4];
} E;

extern E d_021F4490[];

extern void *func_0201210C(void *a);
extern u32 func_02188C80(void *a);
extern int *func_021897BC(void *a, int b);
extern u32 func_020120F4(u32 a);
extern u32 func_02012EC4(u32 a);
extern int *func_0200B3A4(u32 a, u32 b);
extern int func_020122C0(void *a, int b, void *cb, int c);
extern void func_021F3AC0(void);

int func_021F398C(void *a, int b)
{
    void *s;
    int *q;
    int *p;
    int step;

    s = func_0201210C((void *)a);
    q = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(s))), 7);
    p = func_021897BC(s, 1);
    if (b >= 6) {
        return 0;
    }
    p[0] = b;
    if (q[b] != 0) {
        p[1] = d_021F4490[b].b;
        p[2] = d_021F4490[b].a;
    } else {
        p[1] = d_021F4490[b].a;
        p[2] = d_021F4490[b].b;
    }
    if (b == 5) {
        step = 0x8000;
        p[15] = 1;
    } else {
        step = 0x4000;
        p[15] = 0;
    }
    if (p[2] - p[1] < 0) {
        p[3] = -step;
    } else {
        p[3] = step;
    }
    p[16] = 0;
    return func_020122C0(a, 0, func_021F3AC0, 0);
}
