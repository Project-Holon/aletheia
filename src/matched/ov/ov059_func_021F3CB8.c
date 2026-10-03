/*
 * function: func_021F3CB8
 * address:  0x021F3CB8
 * packet:   pkt_ov059_021F3CB8
 * region:   ov059
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
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 */

typedef unsigned short u16;

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188D2C(void *p);
extern int *func_021897BC(char *p, int idx);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern int func_021BE6BC(int *p);

int func_021F3CB8(void *a)
{
    void *t;
    void *s;
    int flag;
    int *p;

    t = func_0201210C(func_020124E4(a));
    s = func_02188D2C(t);
    p = func_021897BC(t, 1);
    flag = 1;
    if (*p == 0) {
        flag = 0;
    }
    if (func_021BE6BC(func_021BE674(s, 0, (u16)flag, 0))) {
        return 1;
    }
    return 0;
}
