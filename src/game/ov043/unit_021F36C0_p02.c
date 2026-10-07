/*
 * file:     unit_021F36C0_p02.c
 * unit:     yes
 * function: func_021F398C, func_021F3A28
 * address:  0x021F398C
 * region:   ov043
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
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_021F3AC0  0x021F3AC0  thumb
 *   d_021F4490    0x021F4490  data  a4
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021F3D78  0x021F3D78  thumb
 */
struct Ctx;
struct Big;
struct Desc;
struct Rec94;
typedef unsigned int u32;

typedef struct {
    int a;
    int b;
    int pad[4];
} E;

typedef unsigned char  u8;

typedef signed int     s32;

extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C80(void *p);
extern int *func_021897BC(char *p, int idx);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F3AC0(void *a, int *b);
extern int func_02188D2C(int *p);
extern void  func_021BE700(void *p, int i, int j, int k, int flag);
extern int func_021F3D78(void *a, int *b);
int func_021F398C(void *a, int b);
void func_021F3A28(void *a0, int a1);
extern E d_021F4490[];


int func_021F398C(void *a, int b)
{
    void *s;
    int *q;
    int *p;
    int step;

    s = func_0201210C((void *)a);
    q = func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(s))), 7);
    p = func_021897BC(s, 1);
    if (b >= 6) {
        return 0;
    }
    p[0] = b;
    if (q[b] != 0) {
        p[1] = d_021F4490[b].b;
        p[2] = d_021F4490[b].a;
    } else {
        p[1] = d_021F4490[b].a;
        p[2] = d_021F4490[b].b;
    }
    if (b == 5) {
        step = 0x8000;
        p[15] = 1;
    } else {
        step = 0x4000;
        p[15] = 0;
    }
    if (p[2] - p[1] < 0) {
        p[3] = -step;
    } else {
        p[3] = step;
    }
    p[16] = 0;
    return (int)func_020122C0(a, 0, func_021F3AC0, 0);
}


void func_021F3A28(void *a0, int a1)
{
    void *r6;
    int *r4;
    void *x;
    int d;

    r6 = func_0201210C(a0);
    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(r6))), 7);
    r4 = func_021897BC(r6, 1);
    r4[5] = a1;
    if (a1) {
        r4[1] = 0x320000;
        r4[2] = 0x370000;
    } else {
        r4[1] = 0x370000;
        r4[2] = 0x320000;
        x = (void *)func_02188D2C(r6);
        func_021BE700(x, 0, 7, 1, 1);
        func_021BE700(x, 0, 7, 0, 0);
    }
    d = r4[2] - r4[1];
    if (d < 0) {
        d = -0x2000;
    } else {
        d = 0x2000;
    }
    r4[3] = d;
    func_020122C0(a0, 0, func_021F3D78, 0);
}
