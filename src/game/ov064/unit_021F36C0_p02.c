/*
 * file:     unit_021F36C0_p02.c
 * unit:     yes
 * function: func_021F37B8, func_021F384C
 * address:  0x021F37B8
 * region:   ov064
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
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021BE6E8  0x021BE6E8  thumb  ov021
 *   func_021BE748  0x021BE748  thumb  ov021
 *   func_02006210  0x02006210  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 */
struct Ctx;
struct Obj00020;
struct VecFx32;
struct Desc;
struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V3;

typedef unsigned int   u32;

typedef signed int     s32;

extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3038(unsigned char *a, struct VecFx32 *v);
extern int func_021BE480(char *p, unsigned i, int j);
extern void func_021BE4B4(char *p, int i, int j, int v);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE700(int a, int b, int c, u16 d, int e);
extern void func_021BE6CC(int a, int b, int c, u16 d, int e);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E4(struct Obj *p);
extern int *func_021897BC(char *p, int idx);
extern int func_021BE6E8(int a, int b, int c, int d);
extern int func_021BE748(u32 a);
extern void func_02006210(void);
extern void func_020061E4(u32 a);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
void *func_021F37B8(int a);
int func_021F384C(void *task, int *st);


void *func_021F37B8(int a)
{
    int i;
    void *sys;
    int s;
    V3 v;

    sys = func_0201210C((void *)a);
    s = func_02188D2C(sys);
    func_021A3038(func_02188CB4((void *)sys), (struct VecFx32 *)&v);
    *(V3 *)func_021BE480((char *)s, 0, 0) = v;
    func_021BE4B4((char *)s, 0, 0, 0);
    for (i = 0; i < 4; i++) {
        func_021BE6B0(func_021BE674((char *)s, 0, (int)0, (u16)i), 0);
        func_021BE700(s, 0, 0, i, 1);
        func_021BE6CC(s, 0, 0, i, 0);
    }
    return func_020122C0((void *)a, 0, (void *)func_021F384C, 0);
}


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
    lim = func_021BE748((u32)func_021BE674((char *)s, 0, 0, 0));
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
