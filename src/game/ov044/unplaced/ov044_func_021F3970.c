/*
 * function: func_021F3970
 * address:  0x021F3970
 * packet:   pkt_ov044_021F3970
 * region:   ov044
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC5C  0x0218EC5C  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 */

typedef unsigned int u32;

struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
typedef unsigned char  u8;
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *p, int idx);
extern void *func_02188C58(void *p);
extern u32 func_0218EC5C(u8 *p);
extern void func_0218EC54(u8 *p);
extern int func_021BE480(char *p, unsigned i, int j);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
struct VecFx32;
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_021A3044(u8 *p, void *v);

void func_021F3970(void *a)
{
    void *s;
    void *r;
    int *p;
    u32 h;
    void *c;
    int v[3];

    s = func_0201210C((void *)a);
    r = (void *)func_02188D2C(s);
    p = func_021897BC(s, 1);
    h = (u32)func_02188C58(s);
    p[3] = func_0218EC5C((u8 *)h);
    func_0218EC54((u8 *)h);
    ((int *)func_021BE480(r, 0, 0))[1] = -0x50000;
    c = func_02188CB4((void *)s);
    func_021A3038(c, (struct VecFx32 *)v);
    v[1] = -0x50000;
    func_021A3044(c, v);
}
