/*
 * file:     unit_021F36C0_p02.c
 * unit:     yes
 * function: func_021F3A88, func_021F3AD0, func_021F3B18, func_021F3B5C, func_021F3BC8
 * address:  0x021F3A88
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_021F3BFC  0x021F3BFC  thumb  ov046
 *   func_021F3C8C  0x021F3C8C  thumb  ov046
 *   func_021F3D40  0x021F3D40  thumb  ov046
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021F3EFC  0x021F3EFC  thumb  ov046
 */
struct Big;
struct Ctx;
struct Desc;
struct Rec94;
struct Obj00020;
struct VecFx32;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef signed int     s32;

extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern int *func_021897BC(char *, int);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F3BFC(u32 a, int *b);
extern int func_021F3C8C(u32 a, int *b);
extern int func_021F3D40(u32 a, int *b);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern int func_021F3EFC(u32 a, int *b);
void func_021F3A88(void *a, int b, int c);
void func_021F3AD0(void *a, int b, int c);
void func_021F3B18(void *a, int b);
void *func_021F3B5C(void *a, int b);
int func_021F3BC8(int *p);


void func_021F3A88(void *a, int b, int c)
{
    void *x = func_0201210C(a);
    int p;
    int *q;

    p = (int)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((void *)func_02188C80(x))), 10);
    q = func_021897BC(x, 1);
    q[0] = b;
    q[1] = c;
    q[2] = p + b * 12;
    func_020122C0(a, 0, func_021F3BFC, 0);
}


void func_021F3AD0(void *a, int b, int c)
{
    void *x = func_0201210C(a);
    int p;
    int *q;

    p = (int)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((void *)func_02188C80(x))), 10);
    q = func_021897BC(x, 1);
    q[0] = b;
    q[1] = c;
    q[2] = p + b * 12;
    func_020122C0(a, 0, func_021F3C8C, 0);
}


void func_021F3B18(void *a, int b)
{
    void *x = func_0201210C(a);
    int p;
    int *q;

    p = (int)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((void *)func_02188C80(x))), 10);
    q = func_021897BC(x, 1);
    q[0] = b;
    q[2] = p + b * 12;
    func_020122C0(a, 0, func_021F3D40, 0);
}


/*
 * The negation is a multiply by 0xffffffff (see the idiom on
 * multiplying by minus one), and the +12 base is a separate local that
 * is formed after the func_020122C0 call.
 */
void *func_021F3B5C(void *a, int b)
{
    void *x = func_0201210C(a);
    char *q;
    int *w;
    void *r;
    int v[3];

    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((void *)func_02188C80(x))), 10);
    q = (char *)func_021897BC(x, 1);
    r = func_020122C0(a, 0, func_021F3EFC, 0);
    w = (int *)(q + 12);
    ((unsigned char *)w)[3] = 0;
    w[1] = 0x2000;
    func_021A3038(func_02188CB4((void *)x), (struct VecFx32 *)v);
    w[2] = v[1];
    if (b == 2)
        w[1] = w[1] * 0xffffffff;
    return r;
}

int func_021F3BC8(int *p)
{
    if (p[1] == 0) {
        if (p[2] == 0)
            return 0;
        return 3;
    }
    if (p[2] == 0)
        return 2;
    return 1;
}
