/*
 * function: func_021F3E70
 * address:  0x021F3E70
 * packet:   pkt_ov039_021F3E70
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     case 1 reads s->idx once into a local (int or s8; u8 differs);
 *           re-reading the field per call reloads it and shifts sys to r6.
 *
 * symbols:
 *   func_020124E4 0x020124E4 thumb
 *   func_0201210C 0x0201210C thumb
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021897BC 0x021897BC thumb
 *   func_02188C80 0x02188C80 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_021BE700 0x021BE700 thumb ov021
 *   func_021BE674 0x021BE674 thumb ov021
 *   func_021BE6B0 0x021BE6B0 thumb ov021
 *   func_021BE6CC 0x021BE6CC thumb ov021
 *   func_021BE6BC 0x021BE6BC thumb ov021
 *   func_020061E4 0x020061E4 thumb
 *   func_021F4740 0x021F4740 thumb ov039
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[5];
    s8 idx;
    u8 mode;
} Work;

typedef struct {
    u8 pad0[0x10];
    u8 flag[8];
} Save;

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern Work *func_021897BC(void *p, int idx);
extern u32 func_02188C80(void *p);
struct Big;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern void func_021BE700(void *p, int i, int j, int k, int flag);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B0(unsigned char *p, int v);
extern void func_021BE6CC(int a, int b, int c, int d, int e);
extern int func_021BE6BC(int *p);
extern void func_020061E4(u32 a);
extern void func_021F4740(u32 a, void *b);

int func_021F3E70(int a0, int *a1)
{
    void *sys;
    int h;
    Work *s;
    Save *q;
    u8 a;
    u8 b;
    void *o;
    void *o2;
    int i;

    sys = func_0201210C(func_020124E4((void *)a0));
    h = func_02188D2C(sys);
    s = func_021897BC(sys, 1);
    q = (Save *)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((const struct Ctx *)func_02188C80(sys))), 2);
    switch (*a1) {
    case 0:
        s->mode = q->flag[s->idx];
        a = s->idx + 4;
        b = s->idx + 8;
        if (s->mode == 0) {
            func_021BE700((void *)h, 0, a, 0, 0);
            func_021BE700((void *)h, 0, b, 0, 0);
            func_021BE700((void *)h, 0, a, 1, 1);
            func_021BE700((void *)h, 0, b, 1, 1);
            func_021BE6B0(func_021BE674((char *)h, 0, (u8)a, (u16)1), 0);
            func_021BE6B0(func_021BE674((char *)h, 0, (u8)b, (u16)1), 0);
            func_021BE6CC((int)((void *)h), 0, a, 1, 0);
            func_021BE6CC((int)((void *)h), 0, b, 1, 0);
            s->mode = 1;
        } else {
            func_021BE700((void *)h, 0, a, 1, 0);
            func_021BE700((void *)h, 0, b, 1, 0);
            func_021BE700((void *)h, 0, a, 0, 1);
            func_021BE700((void *)h, 0, b, 0, 1);
            func_021BE6B0(func_021BE674((char *)h, 0, (u8)a, (u16)0), 0);
            func_021BE6B0(func_021BE674((char *)h, 0, (u8)b, (u16)0), 0);
            func_021BE6CC((int)((void *)h), 0, a, 0, 0);
            func_021BE6CC((int)((void *)h), 0, b, 0, 0);
            s->mode = 0;
        }
        func_020061E4(0x689);
        *a1 = *a1 + 1;
        break;
    case 1:
        i = s->idx;
        o = func_021BE674((char *)h, 0, (u8)(i + 4), (u16)s->mode);
        o2 = func_021BE674((char *)h, 0, (u8)(i + 8), (u16)s->mode);
        if (func_021BE6BC(o) && func_021BE6BC(o2)) {
            func_021F4740((u32)sys, (void *)h);
            s->idx = -1;
            return 1;
        }
        break;
    }
    return 0;
}
