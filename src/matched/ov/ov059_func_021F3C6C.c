/*
 * function: func_021F3C6C
 * address:  0x021F3C6C
 * packet:   pkt_ov059_021F3C6C
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021BE6E8  0x021BE6E8  thumb  ov021
 */

typedef unsigned short u16;

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *p, int idx);
extern int func_021BE6E8(int a, int b, int c, int d);

int func_021F3C6C(void *a)
{
    void *t;
    void *s;
    int lim;
    int flag;
    int *p;

    t = func_0201210C(func_020124E4(a));
    s = (void *)func_02188D2C(t);
    p = func_021897BC(t, 1);
    flag = 1;
    if (*p == 0) {
        lim = 0x5000;
        flag = 0;
    } else {
        lim = 0x22000;
    }
    if (func_021BE6E8((int)s, 0, (u16)flag, 0) >= lim) {
        return 1;
    }
    return 0;
}
