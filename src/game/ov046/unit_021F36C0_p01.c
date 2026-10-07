/*
 * file:     unit_021F36C0_p01.c
 * unit:     yes
 * function: func_021F38D4, func_021F3A04, func_021F3A28
 * address:  0x021F38D4
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
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021BE748  0x021BE748  thumb  ov021
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021BE418 0x021BE418 thumb ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021F40D8  0x021F40D8  thumb  ov046
 *   func_021F3FA8  0x021F3FA8  thumb  ov046
 */
struct Big;
struct Ctx;
struct Rec94;
struct Obj00020;
struct VecFx32;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed int     s32;

extern void func_021BE700(void *p, int i, int j, int k, int flag);
extern u8 *func_021BE674(u32 a, int b, u16 c, u16 d);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE6CC(u32 a, int b, u16 c, u16 d, int e);
extern int func_021BE748(u32 a);
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *,int);
extern void func_021897A0(u8 *,int);
extern void func_021BE418(u8 *,u16);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern void func_021BE580(u32);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern int func_021F40D8(int *);
extern void func_021F3FA8(char *a, u32 b, u32 c);
void func_021F38D4(u8 *base, u32 t, int idx);
void func_021F3A04(u32 a);
void func_021F3A28(void *a);


void func_021F38D4(u8 *base, u32 t, int idx)
{
    int *e;
    int n;
    int k;
    u8 *p;
    int m;
    int n1;
    u8 *q;
    int k3;
    int n2;
    u8 *r;

    e = (int *)(base + idx * 12);
    switch (e[0]) {
    case 0:
        k = 1;
        break;
    case 1:
        k = 5;
        break;
    case 3:
        k = 0;
        break;
    case 2:
        k = 2;
        break;
    default:
        k = 1;
        break;
    }
    n = idx * 5;
    p = func_021BE674(t, 0, n, k);
    func_021BE6B0(p, 0);
    func_021BE700((void *)t, 0, (u16)n, (u16)k, 1);
    func_021BE6CC(t, 0, n, k, func_021BE748((u32)p));
    m = 1;
    n1 = n + 1;
    if (e[1] == 0)
        m = 0;
    q = func_021BE674(t, 0, n1, m);
    func_021BE6B0(q, 0);
    func_021BE700((void *)t, 0, (u16)n1, (u16)m, 1);
    func_021BE6CC(t, 0, n1, m, func_021BE748((u32)q));
    k3 = 1;
    n2 = n + 2;
    if (e[2] == 0)
        k3 = 0;
    r = func_021BE674(t, 0, n2, k3);
    func_021BE6B0(r, 0);
    func_021BE700((void *)t, 0, (u16)n2, (u16)k3, 1);
    func_021BE6CC(t, 0, n2, k3, func_021BE748((u32)r));
}

void func_021F3A04(u32 a) { u32 p; p=func_02188D2C((int *)a); func_021897BC((char *)a,1); func_021897A0((u8 *)a,1); func_021BE418((u8 *)p,0); }


void func_021F3A28(void *a)
{
    int v[3];
    u32 r7 = func_02188D2C(a);
    int *r6 = func_021897BC(a, 1);
    int r4 = 1;

    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(a))), 10);
    func_021BE580(r7);
    func_021A3038(func_02188CB4((void *)a), (struct VecFx32 *)v);
    if (func_021F40D8(v) == 0)
        r4 = 0;
    if (r6[9] != r4) {
        func_021F3FA8((char *)r7, (u32)a, r4);
        r6[9] = r4;
    }
}
