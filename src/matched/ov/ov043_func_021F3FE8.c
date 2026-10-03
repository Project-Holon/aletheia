/*
 * function: func_021F3FE8
 * address:  0x021F3FE8
 * packet:   pkt_ov043_021F3FE8
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_02188C64's result is bound to t before the A01FC call: passed inline,
 * the ternary fourth argument is evaluated before the call.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_02006148  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_021F41B8  0x021F41B8  thumb  ov043
 *   func_021F4210  0x021F4210  thumb  ov043
 *   func_02188C68  0x02188C68  thumb  ov021
 *   func_021A03A4  0x021A03A4  thumb  ov021
 *   func_021A03B8  0x021A03B8  thumb  ov021
 *   func_02188C64  0x02188C64  thumb  ov021
 *   func_021A01FC  0x021A01FC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188D2C(void *a);
extern int *func_021897BC(char *p, int idx);
extern u32 func_02188C58(void *a);
extern u32 func_02188C80(void *a);
extern u32 func_020120F4(u32 a);
extern u32 func_02012EC4(u32 a);
extern int *func_0200B3A4(u32 a, u32 b);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B0(unsigned char *p, int v);
extern int func_021BE6BC(int *p);
extern void func_020061E4(u32 a);
extern int func_02006148(u32 a0);
extern void func_020061F8(int i);
extern void func_021F41B8(u8 a0, int a1, int a2, u32 a3, void *s);
extern int func_021F4210(void *s);
extern u32 func_02188C68(u8 *p);
extern int func_021A03A4(u32 a);
extern int func_021A03B8(u32 a);
extern u32 func_02188C64(u8 *p);
extern void func_021A01FC(u32 a, int b, int c, int d);

void func_021F3FE8(void *a)
{
    void *s;
    void *r;
    int *w;
    u32 h;
    int *q;
    int flag;
    u32 t;
    int x;
    int y;

    s = func_0201210C((void *)a);
    r = func_02188D2C(s);
    w = func_021897BC(s, 1);
    h = func_02188C58(s);
    q = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(s))), 7);
    if (w[0] != 5) {
        return;
    }
    if (q[6] == 0 && w[1] <= -0x230000) {
        q[6] = 1;
        func_021BE6B0(func_021BE674(r, 0, 6, 0), 0);
        func_020061E4(0x6cd);
        w[1] = -0x230000;
        w[6] = 1;
        ((u16 *)w)[14] = 0;
        ((u16 *)w)[15] = 0;
        w[16] = 1;
    }
    if (w[6] != 0) {
        switch (((u16 *)w)[15]) {
        case 0:
            func_021F41B8(w[0], w[3], 0, h, w + 8);
            func_020061E4(0x6cb);
            ((u16 *)w)[15]++;
            break;
        case 1:
            if (func_021F4210(w + 8)) {
                ((u16 *)w)[14]++;
                if (((u16 *)w)[14] >= 100) {
                    w[3] = -0x2000;
                    w[6] = 0;
                    func_020061E4(0x6ca);
                }
            }
            break;
        }
    }
    if (w[15] != 0) {
        flag = 0;
        if (w[3] >= 0) {
            if (w[1] >= -0x2a0000) {
                t = func_02188C68(s);
                flag = 1;
                x = func_021A03A4(t);
                y = func_021A03B8(t);
            }
        } else {
            if (w[1] <= -0x310000) {
                flag = 1;
                x = 0x7fdf;
                y = 9;
            }
        }
        if (flag) {
            t = func_02188C64(s);
            func_021A01FC(t, x, y, w[3] == -0x2000 ? 0x20 : 0x10);
            w[15] = 0;
        }
    }
    if (w[16] != 0) {
        if (w[16] == 1) {
            w[16] = 2;
            return;
        }
        if (func_021BE6BC(func_021BE674(r, 0, 6, 0))) {
            func_020061F8(func_02006148(0x6cd));
            w[16] = 0;
        }
    }
}
