/*
 * function: func_021F3D78
 * address:  0x021F3D78
 * packet:   pkt_ov043_021F3D78
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Once filed EXACT* because the extent ran into the unlabelled leaf func_021F3ECC
 * (filed as ov043_func_021F3ECC.c) and the unlabelled follower
 * 0x021F3EEC. Twin of ov044_func_021F37F0.c.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
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
 *   func_021F3ECC  0x021F3ECC  thumb  ov043
 *   func_021F41B8  0x021F41B8  thumb  ov043
 *   func_021F4210  0x021F4210  thumb  ov043
 *   func_021F4174  0x021F4174  thumb  ov043
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188D2C(void *a);
extern int *func_021897BC(char *p, int idx);
extern u32 func_02188C58(void *a);
extern u32 func_02188C80(void *a);
extern u32 func_020120F4(u32 a);
extern u32 func_02012EC4(u32 a);
extern int *func_0200B3A4(u32 a, u32 b);
extern int func_0218EC5C(u32 a);
extern void func_0218EC54(u32 a);
extern void func_0218EC30(u32 a, int v);
extern void func_020061E4(u32 a);
extern int *func_021BE480(void *p, int i, int j);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B0(unsigned char *p, int v);
extern int func_021BE6BC(int *p);
extern void *func_02188CB4(unsigned char *p);
struct VecFx32;
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_021A3044(void *a, int *v);
extern int func_021F3ECC(int *p);
extern void func_021F41B8(u8 a0, int a1, int a2, u32 a3, void *s);
extern int func_021F4210(void *s);
extern void func_021F4174(void *p);

int func_021F3D78(void *a, int *b)
{
    void *s;
    void *r;
    int *w;
    u32 h;
    void *c;
    int v[3];

    s = func_0201210C(func_020124E4(a));
    r = func_02188D2C(s);
    w = func_021897BC(s, 1);
    h = func_02188C58(s);
    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(s))), 7);
    switch (*b) {
    case 0:
        if (w[5] != 0) {
            w[4] = func_0218EC5C(h);
            func_0218EC54(h);
        }
        func_020061E4(w[5] == 0 ? 0x6da : 0x6ca);
        (*b)++;
        break;
    case 1:
        w[1] += w[3];
        if (func_021F3ECC(w)) {
            w[1] = w[2];
            if (w[5] == 0) {
                func_021F41B8(0xff, w[3], 0, h, w + 8);
                func_020061E4(0x6cb);
            }
            (*b)++;
        }
        func_021BE480(r, 0, 7)[1] = w[1];
        c = func_02188CB4((void *)s);
        func_021A3038(c, (struct VecFx32 *)v);
        v[1] = w[1];
        func_021A3044(c, v);
        break;
    case 2:
        if (w[5] != 0) {
            return 1;
        }
        if (func_021F4210(w + 8)) {
            if (w[4] != 0) {
                func_0218EC30(h, w[4]);
            }
            func_021BE6B0(func_021BE674(r, 0, 7, 1), 0);
            (*b)++;
        }
        break;
    case 3:
        if (func_021BE6BC(func_021BE674(r, 0, 7, 1))) {
            func_021F4174(r);
            return 1;
        }
        break;
    }
    return 0;
}
