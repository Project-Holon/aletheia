/*
 * file:     ui_scene_p04.c
 * unit:     yes
 * function: func_021B91D0, func_021B9228, func_021B9280, func_021B92F0, func_021B9344
 * address:  0x021B91D0
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B8FE4  0x021B8FE4  thumb
 *   func_021B90B8  0x021B90B8  thumb
 *   func_021B9138  0x021B9138  thumb
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020355C4  0x020355C4  arm
 *   func_0202EB04  0x0202EB04  thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045770  0x02045770  arm
 *   func_02045334  0x02045334  arm
 */
struct CodeIn;
struct PrintSys;
struct Descriptor;
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

struct Ops {
    void (*fn)(void *a, int b, u8 *c, s16 d, int e);
};

struct S_021B91D0 {
    u8 f0;
    u8 _1[0x20 - 1];
    struct Ops *f20;
    void *f24;
    u8 _28[0x38 - 0x28];
    u8 *f38;
    u8 _3c[0x46 - 0x3c];
    s8 f46;
    u8 _47[0x4c - 0x47];
    u16 f4c;
    u8 _4e[0x66 - 0x4e];
    s8 f66;
};

struct S_021B9228 {
    u8 f0;
    u8 f1;
    u8 _2[0x20 - 2];
    struct Ops *f20;
    void *f24;
    u8 _28[0x38 - 0x28];
    u8 *f38;
    u8 _3c[0x45 - 0x3c];
    u8 f45;
    s8 f46;
    s8 f47;
    u8 _48[0x66 - 0x48];
    s8 f66;
};

struct H {
    u16 v;
};

struct Pair {
    u32 a;
    u32 b;
};

struct S_021B92F0 {
    u8 _0[0x11];
    u8 f11;
    u8 _12[0x28 - 0x12];
    struct Pair *f28;
    u8 _2c[0x30 - 0x2c];
    void *f30;
    u8 _34[0x40 - 0x34];
    struct H **f40;
    u8 _44[0x5e - 0x44];
    u16 f5e;
    u8 _60[0x62 - 0x60];
    s16 f62;
};

struct Elem {
    void *p;
    u8 flag;
    u8 pad[3];
};

struct S_021B9344 {
    u8 _0[0x34];
    int f34;
    struct Elem *arr;
    u8 _3c[0x44 - 0x3c];
    u8 count;
};

extern void func_021B8FE4(struct S_021B91D0 *s, u32 a1, u32 a2);
extern void func_021B90B8(struct S_021B91D0 *p, int a1, int a2);
extern void func_021B9138(struct S_021B91D0 *p, int a1, int a2);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32);
extern u8 func_020355C4(void);
extern void func_0202EB04(struct CodeIn *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void *func_02045770(struct Descriptor *p);
extern void func_02045334(struct Descriptor *d);
void func_021B91D0(struct S_021B91D0 *p, int i, int a2);
void func_021B9228(struct S_021B9228 *p, int i, int a2);
void func_021B9280(u8 *p, int a, u32 b);
void func_021B92F0(struct S_021B92F0 *p, u32 a1, u32 a2);
void func_021B9344(struct S_021B9344 *s);



void func_021B91D0(struct S_021B91D0 *p, int i, int a2)
{
    if (i >= 0 && i < p->f4c) {
        func_021B8FE4((struct S_021B91D0 *)p, i, p->f46);
        func_021B90B8((struct S_021B91D0 *)p, p->f46, a2);
        p->f20->fn(p->f24, i, p->f38 + p->f46 * 8, a2 * 8 - p->f66, 1);
    } else {
        func_021B9138((struct S_021B91D0 *)p, p->f0, a2);
    }
}



void func_021B9228(struct S_021B9228 *p, int i, int a2)
{
    int k;

    if (p->f1 != 0xff) {
        if (i >= 0) {
            k = p->f47 + p->f45;
            func_021B8FE4((struct S_021B91D0 *)p, i, k);
            func_021B90B8((struct S_021B91D0 *)p, k, (int)a2);
            p->f20->fn(p->f24, i, p->f38 + k * 8, a2 * 8 - p->f66, 0);
        } else {
            func_021B9138((struct S_021B91D0 *)p, p->f1, a2);
        }
    }
}


void func_021B9280(u8 *p, int a, u32 b) {
    s16 pos = (s8)p[102]/8 + ((s8)p[3] + a*p[5]);
    u16 i = 0;
    for (; i < p[5]; i++) {
        if (pos < 0) pos += 32;
        else if (pos >= 32) pos -= 32;
        func_020413B0(p[0],p[2],(u8)pos,p[4],1,(u8)b);
        pos++;
    }
    func_02041B6C(p[0]);
}



void func_021B92F0(struct S_021B92F0 *p, u32 a1, u32 a2)
{
    if (a2 < p->f5e)
        func_021B9280((u8 *)p, a2, (u16)(p->f40[p->f28[p->f62 + a2].a]->v >> 12));
    if (a1 < p->f5e && func_020355C4() == 0) {
        func_0202EB04(p->f30);
        func_021B9280((u8 *)p, a1, p->f11);
    }
}



void func_021B9344(struct S_021B9344 *s)
{
    u32 i;

    func_0201C4E4((struct PrintSys *)s->f34);
    for (i = 0; i < s->count; i++) {
        struct Elem *e = &s->arr[i];
        int a = s->f34;

        if (e->flag != 0) {
            if (func_0201C6C4((struct PrintSys *)a, (void *)((int)func_02045770((struct Descriptor *)e->p))) == 0) {
                func_02045334((struct Descriptor *)e->p);
                e->flag = 0;
            }
        }
    }
}
