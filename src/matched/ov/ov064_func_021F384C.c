/*
 * function: func_021F384C
 * address:  0x021F384C
 * packet:   pkt_ov064_021F384C
 * region:   ov064
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021BE6E8  0x021BE6E8  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE748  0x021BE748  thumb  ov021
 *   func_02006210  0x02006210  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern void *func_020124E4(void *task);
extern void *func_0201210C(void *p);
extern int func_02188D2C(int a);
extern int *func_021897BC(char *p, int idx);
extern int func_021BE6E8(int a, int b, int c, int d);
extern u8 *func_021BE674(int a, int b, int c, u16 d);
extern int func_021BE748(u8 *e);
extern void func_02006210(void);
extern void func_020061E4(int a);
extern void func_0204E720(int a, int b, int c, int d);
extern int func_0204E804(void);

int func_021F384C(void *task, int *st)
{
    void *sys;
    int s;
    int *w;
    int v;
    int lim;

    sys = func_0201210C(func_020124E4(task));
    s = func_02188D2C(sys);
    w = func_021897BC((char *)sys, 1);
    v = func_021BE6E8(s, 0, 0, 0);
    lim = func_021BE748(func_021BE674(s, 0, 0, 0));
    if (v >= 0 && w[2] == 0) {
        func_02006210();
        func_020061E4(0x7D0);
        w[2] = 1;
    } else if (v >= 0x83000 && w[3] == 0) {
        func_02006210();
        func_020061E4(0x7CB);
        w[3] = 1;
    } else if (v >= 0x6C000 && w[4] == 0) {
        func_02006210();
        func_020061E4(0x7CC);
        w[4] = 1;
    } else if (v >= 0xFA000 && w[5] == 0) {
        func_02006210();
        func_020061E4(0x7F2);
        w[5] = 1;
    }
    switch (*st) {
    case 0:
        if (v == 0x65000) {
            func_0204E720(w[0], 0, 0x10, 0);
            w[1] = 15;
            (*st)++;
        }
        break;
    case 1:
        if (func_0204E804() == 0) {
            if (w[1] <= 0) {
                func_0204E720(w[0], 0x10, 0, 0);
                (*st)++;
            } else {
                w[1]--;
            }
        }
        break;
    case 2:
        if (func_0204E804() == 0) {
            (*st)++;
        }
        break;
    }
    return v >= lim;
}
