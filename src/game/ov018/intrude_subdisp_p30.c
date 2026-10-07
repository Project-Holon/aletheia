/*
 * file:     intrude_subdisp_p30.c
 * unit:     yes
 * function: func_02181B44, func_02181B68
 * address:  0x02181B44
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201232C  0x0201232C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0217F3C4  0x0217F3C4  thumb
 *   func_0217F40C  0x0217F40C  thumb
 *   func_0217F420  0x0217F420  thumb
 *   func_0217FE38  0x0217FE38  thumb
 *   d_02183946     0x02183946  data  a2
 */
struct Obj;
struct Ctx;
struct WordSet;
typedef unsigned int u32;

typedef struct {
    void *unk_00;
    u32 unk_04;
    u32 unk_08;
    void *unk_0c;
    void *unk_10;
} Obj;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj;

typedef struct {
    unsigned char pad00[0x10];
    Ov018Obj obj;
    unsigned char pad40[2];
    unsigned char f42;
    unsigned char pad43[0x35];
    int f78;
} Ov018Outer;

extern void func_0201232C(char *p, int a1, int a2);
extern void *func_020124E8(struct Obj *p);
extern void func_02082D44(const void *, void *, u32);
void *func_020124E4(struct Obj *p);
u32 func_02012138(const struct Ctx *p);
int func_02158344(int a0);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_0217F3C4(Ov018Obj *p, int a);
int func_0217F40C(Ov018Obj *p);
int func_0217F420(void);
void func_0217FE38(int v, Ov018Outer *c);
void func_02181B44(Obj *task, const void *src);
int func_02181B68(void *a, int *state, Ov018Outer *c);
extern unsigned short d_02183946[];


/*
 * Callback pointer is copied unchanged by func_0201232C into task +4;
 * its legacy int parameter represents the same full-word payload.
 */
void func_02181B44(Obj *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02181B68, 0xA4);
    dst = func_020124E8((struct Obj *)task);
    func_02082D44(src, dst, 0x98);
}


int func_02181B68(void *a, int *state, Ov018Outer *c)
{
    int v;

    v = func_02158344(func_02012138(func_020124E4(a)));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, &c->f78);
        func_0217F3C4(&c->obj, d_02183946[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C(&c->obj) == 1) {
            *state = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *state = 3;
        }
        break;
    case 3:
        func_0217FE38(v, c);
        return 1;
    }
    return 0;
}
