/*
 * function: func_021F3730
 * address:  0x021F3730
 * packet:   pkt_ov051_021F3730
 * region:   ov051
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the flag test reads p[0] as unsigned char (ldrb); a plain char
 *           test gives ldrsb with a zero register hoisted above the branch.
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_021F3D94  0x021F3D94  thumb  ov051
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_02030734  0x02030734  arm
 *   func_021ABE30  0x021ABE30  thumb  ov021
 *   func_021F36EC  0x021F36EC  thumb  ov051
 *   func_021F36E0  0x021F36E0  thumb  ov051
 *   func_021F3B44  0x021F3B44  thumb  ov051
 *   func_02188C7C  0x02188C7C  thumb
 *   func_0216DD1C  0x0216DD1C  thumb
 *   func_0216D588  0x0216D588  thumb
 *   func_021F3B88  0x021F3B88  thumb  ov051
 *   func_021F3724  0x021F3724  thumb  ov051
 *   func_021F3718  0x021F3718  thumb  ov051
 *   func_021F3CCC  0x021F3CCC  thumb  ov051
 *   d_021F40A0     0x021F40A0  data  ov051  a4
 */

extern int func_02188C84(int a);
extern int func_02188C80(int a);
extern unsigned func_020120F4(unsigned);
extern unsigned func_02012EC4(unsigned);
extern int func_02188CD0(int a);
extern int func_02188C9C(int a);
extern int func_021F3D94(int a);
extern char *func_0200B3A4(unsigned, int);
extern void *func_02030734(int, int, int, void *, int);
extern void func_021ABE30(int, int *, int);
extern unsigned int func_021F36EC(int a);
extern int *func_021F36E0(int a);
extern void func_021F3B44(int *a, int *out, int x, int y);
extern void *func_02188C7C(unsigned char *p);
extern int func_0216DD1C(int it, int *cur, int *v);
extern int func_0216D588(int a);
extern void func_021F3B88(int *a, int *out, int c);
extern unsigned int func_021F3724(int a);
extern int *func_021F3718(int a);
extern void func_021F3CCC(int *a, int *out, int x, int y, int z);
extern char d_021F40A0[];

void func_021F3730(int a)
{
    int n;
    int v;
    int cur;
    int r4;
    unsigned h;
    int sp8;
    int r5;
    char *p;
    int *q;
    unsigned int i;
    unsigned int cnt;
    int *e;
    void *it;

    r4 = func_02188C84(a);
    h = func_02012EC4(func_020120F4(func_02188C80(a)));
    sp8 = func_02188CD0(a);
    r5 = func_02188C9C(a);
    p = func_0200B3A4(h, func_021F3D94(r5));
    q = func_02030734(r4, 0xa4, 1, d_021F40A0, 0xca);
    *(int **)(p + 4) = q;
    q[1] = (int)p;
    q[2] = a;
    q[0] = r5;
    n = 0xb;
    func_021ABE30(sp8, &n, 1);
    if (*(unsigned char *)p == 0) {
        cnt = func_021F36EC(q[0]);
        e = func_021F36E0(q[0]);
        i = 0;
        if (i < cnt)
            for (; i < cnt; i++) {
                func_021F3B44(q, q + 3 + i * 2, e[0], e[2]);
                e += 3;
            }
    } else {
        i = 0;
        v = 0;
        it = func_02188C7C((void *)a);
        while (func_0216DD1C(it, &cur, &v)) {
            if (func_0216D588(cur) == 0xfd) {
                func_021F3B88(q, q + 3 + i * 2, cur);
                i++;
                if (i >= 12)
                    break;
            }
        }
    }
    cnt = func_021F3724(q[0]);
    e = func_021F3718(q[0]);
    i = 0;
    if (i < cnt)
        for (; i < cnt; i++) {
            func_021F3CCC(q, q + 0x1b + i, e[0], e[1], e[2]);
            e += 3;
        }
    *p = 1;
}
