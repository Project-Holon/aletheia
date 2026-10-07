/*
 * file:     fldmmdl_p02.c
 * unit:     yes
 * function: func_0216C0E4, func_0216C0E8, func_0216C204, func_0216C270
 * address:  0x0216C0E4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0218FEA4  0x0218FEA4  thumb  ov021
 *   func_0218FE78  0x0218FE78  thumb  ov021
 *   func_0218FF00  0x0218FF00  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb
 *   func_0218FE98  0x0218FE98  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_020114D0  0x020114D0  thumb
 *   func_02006148  0x02006148  thumb
 *   func_0200616C  0x0200616C  thumb
 *   func_02011610  0x02011610  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE480  0x021BE480  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_02011590  0x02011590  thumb
 *   func_02011558  0x02011558  thumb
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_021854B0  0x021854B0  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0216C44C  0x0216C44C  thumb  ov010
 *   func_0201235C  0x0201235C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_0218FE80  0x0218FE80  thumb  ov021
 *   func_0218FEA0  0x0218FEA0  thumb  ov021
 *   d_02172528     0x02172528  data  ov010  a4
 */
struct Evt;
struct IcaAnime;
struct S0201235C;
struct Rec12;
struct Obj00020;
struct Desc;
struct Obj;
struct Work;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef int s32_0216C0E8;

typedef s32_0216C0E8 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Pos {
    u32 f00;
    u32 f04;
    u32 f08;
} Pos;

typedef struct Work_0216C0E8 {
    void *sys;          /* 0x00 */
    void *field;        /* 0x04 */
    void *f08;          /* 0x08 */
    void *f0c;          /* 0x0C */
    void *anim;         /* 0x10 */
    u8 pad14[4];
    u8 f18[0x60 - 0x18];/* 0x18 */
    void *f60;          /* 0x60 */
} Work_0216C0E8;

typedef struct B32 { int w[8]; } B32;

typedef struct Work_0216C270 {
    u8 pad00[0x10];
    void *anim;         /* 0x10 */
} Work_0216C270;

typedef signed int     s32_0216C270;

extern void func_0218FEA4(void *p);
extern void func_0218FE78(void *p, void *q);
extern int func_0218FF00(u32 a);
extern int func_021C6E48(void *p);
extern void func_0218FE98(void *p);
extern u16 func_02188C84(u8 *p);
extern void *func_020114D0(u32 heap, u32 a1, u32 a2);
extern int func_02006148(u32 a0);
extern void func_0200616C(void *arg, int i);
extern u32 func_02011610(struct IcaAnime *anim, struct Rec12 *out);
extern int func_02188D2C(int *p);
extern VecFx32 *func_021BE480(void *p, int a, int b);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_021A3044(u8 *p, void *v);
extern u32 func_02011590(struct IcaAnime *p, s32_0216C0E8 v);
extern void func_02011558(struct IcaAnime *p);
extern void *func_021BE8D4(void *sys, void *proc, u32 a, u32 b);
extern void *func_021854B0(void *p, void *q, u32 id, Pos *pos, u32 flag);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_0216C44C(void *sys, void *field);
extern void func_0201235C(struct S0201235C *o, u32 *out);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, unsigned int size);
extern void *func_020124E8(struct Obj *p);
extern void *func_02188C58(void *p);
extern unsigned int func_02188D38(u8 *p);
extern void *func_0218FE80(void *a);
extern void func_0218FEA0(u8 *p, unsigned int v);
int func_0216C0E4(int *p);
int func_0216C0E8(void *evt, u32 *state, Work_0216C0E8 *w);
int func_0216C204(void *a, u8 *b);
int func_0216C270(Work_0216C270 *w);
extern B32 d_02172528;

int func_0216C0E4(int *p)
{
    return p[7];
}


/*
 * Eight-state proc of the field event beside func_0216C2FC: run the
 * ov021 camera move, animate the actor to the ground, then push the next
 * screens. First draft.
 */
int func_0216C0E8(void *evt, u32 *state, Work_0216C0E8 *w)
{
    VecFx32 cur;
    VecFx32 v;
    Pos pos;
    void *sys = w->sys;
    void *field = w->field;
    void *f0c = w->f0c;
    void *q;

    switch (*state) {
    case 0:
        func_0218FEA4(w->f60);
        func_0218FE78(w->f08, w->f18);
        func_0218FF00((u32)w->f60);
        (*state)++;
        break;
    case 1:
        if (func_021C6E48(f0c) != 0) {
            func_0218FE98(w->f60);
            (*state)++;
        }
        break;
    case 2:
        w->anim = func_020114D0(func_02188C84(field), 0x9D, 0x18);
        func_0200616C((void *)1953, func_02006148(1953));
        (*state)++;
        break;
    case 3:
        func_02011610(w->anim, (struct Rec12 *)&cur);
        func_021BE480((void *)func_02188D2C(field), 0, 0)->y = cur.y;
        q = func_02188CB4(field);
        func_021A3038(q, &v);
        v.y = cur.y;
        func_021A3044(q, &v);
        if (func_02011590(w->anim, 0x1000) != 0) {
            func_02011558(w->anim);
            (*state)++;
        }
        break;
    case 4:
        func_02012374(evt, func_021BE8D4(sys, field, 0, 0));
        (*state)++;
        break;
    case 5:
        pos.f00 = 0;
        pos.f04 = 0;
        pos.f08 = 0;
        func_02012374(evt, func_021854B0(sys, field, 0x8A, &pos, 1));
        (*state)++;
        break;
    case 6:
        func_0201235C(evt, func_0216C44C(sys, field));
        (*state)++;
        break;
    case 7:
        return 1;
    }
    return 0;
}


int func_0216C204(void *a, u8 *b)
{
    int r = (int)func_020122C0(a, 0, (void *)func_0216C0E8, 0x64);
    int *p = func_020124E8((struct Obj *)r);
    p[0] = (int)a;
    p[1] = (int)b;
    p[4] = 0;
    p[2] = (int)func_02188C58((void *)b);
    p[3] = func_02188D38(b);
    p[5] = 0x14;
    *(B32 *)(p + 14) = d_02172528;
    p[22] = 1;
    p[23] = 1;
    p[24] = (int)func_0218FE80((void *)b);
    func_0218FEA0((u8 *)p[24], (unsigned int)(p + 5));
    return r;
}


int func_0216C270(Work_0216C270 *w)
{
    return func_02011590(w->anim, 0x1000);
}
