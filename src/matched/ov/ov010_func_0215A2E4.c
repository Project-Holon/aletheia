/*
 * function: func_0215A2E4
 * address:  0x0215A2E4
 * packet:   pkt_ov010_0215A2E4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0215A370  0x0215A370  thumb  ov010
 *   d_021728CC     0x021728CC  data  ov010  a4
 */

extern void *func_02030734(int, int, int, void *, int);
extern int func_020120F4(int);
extern void *func_02012934(void *p);
extern int func_0201AA18(int);
extern int func_020122C0(int, int, void (*)(void), int);
extern int *func_020124E8(int);
extern void func_0215A370(void);
extern int d_021728CC;

int func_0215A2E4(int a, int b, int c, int d, int e, int f, unsigned short g)
{
    int t8 = func_020120F4(a);
    void *t12 = func_02012934((void *)t8);
    char *p = (char *)func_02030734(4, 0x98, 1, &d_021728CC, 0x11d);
    int r;
    int *q;

    *(int *)p = t12;
    p[0xc] = 1;
    p[0xe] = func_0201AA18(t12);
    p[0xf] = c;
    p[0x10] = 1;
    *(unsigned short *)(p + 0x14) = g;
    p[0xd] = (f == 1) ? 3 : 2;
    *(int *)(p + 0x20) = 0;
    *(int *)(p + 8) = t8;
    r = func_020122C0(a, 0, func_0215A370, 0x14);
    q = func_020124E8(r);
    q[0] = a;
    q[1] = b;
    q[2] = (int)p;
    q[3] = d;
    q[4] = e;
    return r;
}
