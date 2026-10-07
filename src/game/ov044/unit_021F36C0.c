/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F3740, func_021F3764, func_021F3770, func_021F37F0, func_021F390C, func_021F392C
 * address:  0x021F36C0
 * region:   ov044
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F39E8     0x021F39E8  data  ov044
 *   d_021F3A1C     0x021F3A1C  data  a4
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_021BE418 0x021BE418 thumb ov021
 *   func_021BE580 0x021BE580 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC5C  0x0218EC5C  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218EC30  0x0218EC30  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 */
struct Big;
struct Ctx;
struct Rec94;
struct Desc;
struct Obj;
struct Obj00020;
struct VecFx32;
typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V;

typedef unsigned char  u8;

typedef unsigned int u32;

typedef signed int     s32;

extern int func_02188D2C(int *p);
extern u16 func_02188C84(u8 *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void  func_021BE760(void *p, void *a, int b);
extern int func_021BE480(char *p, unsigned i, int j);
extern void func_021BE4A4(char *p, int i, int j, int v);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B8(unsigned char *p, int v);
extern void func_021BE6B0(unsigned char *p, int v);
extern int *func_021897BC(char *, int);
extern void func_021897A0(u8 *, int);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern void func_021BE418(u8 *, u16);
extern void func_021BE580(void *);
extern void *func_0201210C(const struct Ctx *p);
extern void  func_021BE700(void *p, int i, int j, int k, int flag);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E4(struct Obj *p);
extern void *func_02188C58(void *p);
extern u32 func_0218EC5C(u8 *p);
extern void func_0218EC54(u8 *p);
extern void func_0218EC30(u32 a, int v);
extern void func_020061E4(u32 a);
extern int func_021BE6BC(int *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_021A3044(u8 *p, void *v);
extern void func_021BE6CC(int a, int b, int c, int d, int e);
void func_021F36C0(void *a0);
void func_021F3740(u8 *p);
void func_021F3764(void *p);
void func_021F3770(void *a0, int a1);
int func_021F37F0(void *a, int *b);
int func_021F390C(int *p);
void func_021F392C(void *p);
extern int d_021F39E8;
extern V d_021F3A1C;


void func_021F36C0(void *a0)
{
    void *r6;
    V *e;
    void *b;
    int i;

    r6 = (void *)func_02188D2C(a0);
    func_02189764(a0, 1, func_02188C84(a0), 0x14);
    func_021BE760(r6, &d_021F39E8, 0);
    e = (V *)func_021BE480(r6, 0, 0);
    *e = d_021F3A1C;
    func_021BE4A4(r6, 0, 0, 1);
    for (i = 0; i < 2; i++) {
        b = func_021BE674(r6, 0, (int)0, (u16)i);
        func_021BE6B8(b, 0);
        func_021BE6B0(b, 1);
    }
    func_021F392C(r6);
}

void func_021F3740(u8 *p)
{
    int x = func_02188D2C((int *)p);
    func_021897BC((char *)p, 1);
    func_021897A0(p, 1);
    func_021BE418((u8 *)x, 0);
}


void func_021F3764(void *p)
{
    func_021BE580((void *)func_02188D2C(p));
}


void func_021F3770(void *a0, int a1)
{
    void *r6;
    int *r4;
    void *x;
    int d;

    r6 = func_0201210C(a0);
    r4 = func_021897BC(r6, 1);
    r4[4] = a1;
    if (a1) {
        r4[0] = 0;
        r4[1] = -0x50000;
    } else {
        r4[0] = -0x50000;
        r4[1] = 0;
        x = (void *)func_02188D2C(r6);
        func_021BE700(x, 0, 0, 0, 1);
        func_021BE700(x, 0, 0, 1, 0);
    }
    d = r4[1] - r4[0];
    if (d < 0) {
        d = -0x2000;
    } else {
        d = 0x2000;
    }
    r4[2] = d;
    func_020122C0(a0, 0, func_021F37F0, 0);
}


/*
 * Once filed EXACT* because the extent ran into the unlabelled leaf func_021F390C
 * (filed as ov044_func_021F390C.c).
 */
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

/*
 * Unlabelled leaf called only from func_021F37F0.
 */
int func_021F390C(int *p)
{
    if (p[2] < 0) {
        if (p[1] >= p[0]) {
            return 1;
        }
    } else {
        if (p[1] <= p[0]) {
            return 1;
        }
    }
    return 0;
}


void func_021F392C(void *p)
{
    func_021BE700(p, 0, 0, 1, 1);
    func_021BE700(p, 0, 0, 0, 0);
    func_021BE6CC((int)p, 0, 0, 1, 0);
    p = func_021BE674(p, 0, 0, 1);
    func_021BE6B0(p, 1);
}
