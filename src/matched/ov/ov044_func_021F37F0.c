/*
 * function: func_021F37F0
 * address:  0x021F37F0
 * packet:   pkt_ov044_021F37F0
 * region:   ov044
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Once filed EXACT* because the extent ran into the unlabelled leaf func_021F390C
 * (filed as ov044_func_021F390C.c).
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC5C  0x0218EC5C  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218EC30  0x0218EC30  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_021F390C  0x021F390C  thumb  ov044
 *   func_021F392C  0x021F392C  thumb  ov044
 */

typedef unsigned int u32;

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
typedef unsigned char  u8;
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *p, int idx);
extern void *func_02188C58(void *p);
extern u32 func_0218EC5C(u8 *p);
extern void func_0218EC54(u8 *p);
extern void func_0218EC30(u32 a, int v);
extern void func_020061E4(u32 a);
extern int func_021BE480(char *p, unsigned i, int j);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B0(unsigned char *p, int v);
extern int func_021BE6BC(int *p);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
struct VecFx32;
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_021A3044(u8 *p, void *v);
extern int func_021F390C(int *p);
extern void func_021F392C(void *p);

int func_021F37F0(void *a, int *b)
{
    void *s;
    void *r;
    int *w;
    u32 h;
    void *c;
    int v[3];

    s = func_0201210C(func_020124E4(a));
    r = (void *)func_02188D2C(s);
    w = func_021897BC(s, 1);
    h = (u32)func_02188C58(s);
    switch (*b) {
    case 0:
        if (w[4] != 0) {
            w[3] = func_0218EC5C((u8 *)h);
            func_0218EC54((u8 *)h);
        }
        func_020061E4(w[4] == 0 ? 0x6da : 0x6ca);
        (*b)++;
        break;
    case 1:
        w[0] += w[2];
        if (func_021F390C(w)) {
            w[0] = w[1];
            if (w[4] == 0) {
                func_020061E4(0x6cb);
            }
            (*b)++;
        }
        ((int *)func_021BE480(r, 0, 0))[1] = w[0];
        c = func_02188CB4((void *)s);
        func_021A3038(c, (struct VecFx32 *)v);
        v[1] = w[0];
        func_021A3044(c, v);
        break;
    case 2:
        if (w[4] != 0) {
            return 1;
        }
        if (w[3] != 0) {
            func_0218EC30(h, w[3]);
        }
        func_021BE6B0(func_021BE674(r, 0, 0, 0), 0);
        (*b)++;
        break;
    case 3:
        if (func_021BE6BC(func_021BE674(r, 0, 0, 0))) {
            func_021F392C(r);
            return 1;
        }
        break;
    }
    return 0;
}
