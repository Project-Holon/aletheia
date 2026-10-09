/*
 * file:     intrude_subdisp_p11.c
 * unit:     yes
 * function: func_0218191C, func_02181940, func_021819D0, func_021819F4, func_02181A74, func_02181A98, func_02181B44, func_02181B68, func_02181BE8, func_02181C0C, func_02181D8C, func_02181DD4, func_02181E6C, func_02181E90, func_02181F10, func_02181F34, func_02181FB4, func_02181FD8, func_02182080
 * address:  0x0218191C
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
 *   d_02183928     0x02183928  data  a2
 *   d_0218393C     0x0218393C  data  a2
 *   func_020061E4  0x020061E4  thumb
 *   func_0217CA1C  0x0217CA1C  thumb
 *   func_0201235C  0x0201235C  thumb
 *   d_02183932     0x02183932  data  a2
 *   d_02183946     0x02183946  data  a2
 *   func_0217405C  0x0217405C  thumb  ov011
 *   func_02175CF4  0x02175CF4  thumb  ov011
 *   func_0217456C  0x0217456C  thumb  ov011
 *   func_021762D8  0x021762D8  thumb  ov011
 *   func_021804F8  0x021804F8  thumb
 *   d_02183950     0x02183950  data  a2
 *   d_0218395A     0x0218395A  data  a2
 *   d_02183964     0x02183964  data  a2
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F20  0x02012F20  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_0200846C  0x0200846C  thumb
 *   func_0202E82C  0x0202E82C  thumb
 *   func_02008494  0x02008494  thumb
 *   func_0217F2B4  0x0217F2B4  thumb
 *   func_0217F318  0x0217F318  thumb
 *   func_02158768  0x02158768  thumb  ov010
 *   func_021589D0  0x021589D0  thumb  ov010
 *   func_02159058  0x02159058  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_02183970     0x02183970  data  a2
 *   d_02183984     0x02183984  data  a2
 *   d_0218397A     0x0218397A  data   a2
 *   func_021820A4 0x021820A4 thumb ov018
 */
struct Obj;
struct Ctx;
struct WordSet;
struct S0201235C;
struct Desc;
struct S;
struct Evt;
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
} Ov018Obj_0218191C;

typedef struct {
    unsigned char pad00[0x10];
    Ov018Obj_0218191C obj;
    unsigned char pad40[2];
    unsigned char f42;
    unsigned char pad43[0x35];
    int f78;
} Ov018Outer_0218191C;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    u16 f00;            /* 0x00 */
    u8 pad02[0x10 - 0x02];
    Ov018Obj_0218191C obj;       /* 0x10 */
    u8 f40;             /* 0x40 */
    u8 pad41;
    u8 f42;             /* 0x42 */
    u8 pad43;
    u8 f44[0x5C - 0x44]; /* 0x44 */
    u8 f5C[0x98 - 0x5C]; /* 0x5C */
    int f98;            /* 0x98 */
    int f9C;            /* 0x9C */
    int fA0;            /* 0xA0 */
} Ov018Outer_02181BE8;

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
    void *f30;
} Ov018Obj_02181DD4;

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

typedef struct {
    u8 pad00[0x10];
    Ov018Obj obj;       /* 0x10 */
    u8 pad40[2];
    u8 f42;             /* 0x42 */
    u8 pad43[0x78 - 0x43];
    u8 f78[0x98 - 0x78]; /* 0x78 */
} Outer;

extern void func_0201232C(char *p, int a1, int a2);
extern void *func_020124E8(struct Obj *p);
extern void func_02082D44(const void *, void *, u32);
void *func_020124E4(struct Obj *p);
u32 func_02012138(const struct Ctx *p);
int func_02158344(int a0);
void func_0201F02C(struct WordSet *p, u32 i, void *a);
void func_0217F3C4(Ov018Obj_0218191C *p, int a);
int func_0217F40C(Ov018Obj_0218191C *p);
int func_0217F420(void);
void func_0217FE38(int v, Ov018Outer_0218191C *c);
void func_020061E4(u32 a);
void *func_0217CA1C(void *p);
void func_0201235C(struct S0201235C *o, u32 *out);
int func_0217405C(char *a, char *b);
int func_02175CF4(char *p, u8 *q);
int func_0217456C(int a, int b, int c, ...);
void func_021762D8(void *, void *, void *, u32);
void *func_021804F8(void *, int);
void *func_020120F4(const struct Ctx *p);
int func_02012F20(int p0);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_0200846C(int a0);
void *func_0202E82C(struct S *p);
void func_02008494(void *, void *);
void func_0217F2B4(void *, void *);
void func_0217F318(Ov018Obj_02181DD4 *p);
struct Desc *func_02158768(int a0, int a1, int a2, int a3);
int func_021589D0(int a0);
int func_02159058(int a, int b, int c, int d, u16 e);
void func_02012374(struct Evt *evt, struct Evt **out);
u32 func_020307B0(void *p);
extern int func_021820A4(void);
void func_0218191C(Obj *task, const void *src);
int func_02181940(void *a, int *state, Ov018Outer_0218191C *c);
void func_021819D0(Obj *task, const void *src);
int func_021819F4(void *a, int *state, Ov018Outer_0218191C *c);
void func_02181A74(Obj *task, const void *src);
int func_02181A98(void *a, int *state, Ov018Outer_0218191C *c);
void func_02181B44(Obj *task, const void *src);
int func_02181B68(void *a, int *state, Ov018Outer_0218191C *c);
void func_02181BE8(Obj *task, const void *src);
int func_02181C0C(void *a, int *state, Ov018Outer_02181BE8 *c);
void *func_02181D8C(void *a, void *b);
int func_02181DD4(void *a, int *state, Ov018Obj_02181DD4 *c);
void func_02181E6C(Obj *task, const void *src);
int func_02181E90(void *a, int *state, Ov018Outer *c);
void func_02181F10(Obj *task, const void *src);
int func_02181F34(void *a, int *state, Ov018Outer *c);
void func_02181FB4(Obj *task, const void *src);
int func_02181FD8(void *a, int *state, Outer *c);
void func_02182080(void *a, void *b);
extern unsigned short d_02183928[];
extern unsigned short d_0218393C[];
extern unsigned short d_02183932[];
extern unsigned short d_02183946[];
extern const u16 d_02183950[];
extern const u16 d_0218395A[];
extern const u16 d_02183964[];
extern unsigned short d_02183970[];
extern unsigned short d_02183984[];
extern u16 d_0218397A[];







/*
 * Callback pointer is copied unchanged by func_0201232C into task +4;
 * its legacy int parameter represents the same full-word payload.
 */
void func_0218191C(Obj *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02181940, 0xA4);
    dst = func_020124E8((struct Obj *)task);
    func_02082D44(src, dst, 0x98);
}







int func_02181940(void *a, int *state, Ov018Outer_0218191C *c)
{
    int v;

    v = func_02158344(func_02012138(func_020124E4(a)));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, &c->f78);
        func_0217F3C4((Ov018Obj_0218191C *)(&c->obj), d_02183928[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj_0218191C *)(&c->obj)) == 1) {
            (*state)++;
        }
        break;
    case 2:
        if (func_0217F40C((Ov018Obj_0218191C *)(&c->obj)) == 1) {
            *state = 3;
        }
        break;
    case 3:
        if (func_0217F420() == 1) {
            *state = 4;
        }
        break;
    case 4:
        func_0217FE38(v, (Ov018Outer_0218191C *)c);
        return 1;
    }
    return 0;
}







void func_021819D0(Obj *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_021819F4, 0xA4);
    dst = func_020124E8((struct Obj *)task);
    func_02082D44(src, dst, 0x98);
}







int func_021819F4(void *a, int *state, Ov018Outer_0218191C *c)
{
    int v;

    v = func_02158344(func_02012138(func_020124E4(a)));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, &c->f78);
        func_0217F3C4((Ov018Obj_0218191C *)(&c->obj), d_0218393C[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj_0218191C *)(&c->obj)) == 1) {
            *state = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *state = 3;
        }
        break;
    case 3:
        func_0217FE38(v, (Ov018Outer_0218191C *)c);
        return 1;
    }
    return 0;
}







void func_02181A74(Obj *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02181A98, 0xA4);
    dst = func_020124E8((struct Obj *)task);
    func_02082D44(src, dst, 0x98);
}







int func_02181A98(void *a, int *state, Ov018Outer_0218191C *c)
{
    void *sub;
    void *sys;
    int v;

    sub = func_020124E4(a);
    sys = (void *)func_02012138(sub);
    v = func_02158344((int)sys);
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, &c->f78);
        func_0217F3C4((Ov018Obj_0218191C *)(&c->obj), d_02183932[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj_0218191C *)(&c->obj)) == 1) {
            *state = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *state = 3;
        }
        break;
    case 3:
        func_0217FE38(v, (Ov018Outer_0218191C *)c);
        if (func_02158344((int)sys) != 0) {
            func_020061E4(0x737);
            func_0201235C(a, func_0217CA1C(sub));
            return 0;
        }
        return 1;
    }
    return 0;
}







void func_02181B44(Obj *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02181B68, 0xA4);
    dst = func_020124E8((struct Obj *)task);
    func_02082D44(src, dst, 0x98);
}







int func_02181B68(void *a, int *state, Ov018Outer_0218191C *c)
{
    int v;

    v = func_02158344(func_02012138(func_020124E4(a)));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, &c->f78);
        func_0217F3C4((Ov018Obj_0218191C *)(&c->obj), d_02183946[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj_0218191C *)(&c->obj)) == 1) {
            *state = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *state = 3;
        }
        break;
    case 3:
        func_0217FE38(v, (Ov018Outer_0218191C *)c);
        return 1;
    }
    return 0;
}






void func_02181BE8(Obj *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02181C0C, 0xA4);
    dst = func_020124E8((struct Obj *)task);
    func_02082D44(src, dst, 0x98);
}






int func_02181C0C(void *a, int *state, Ov018Outer_02181BE8 *c)
{
    void *sub;
    u8 *v;
    int r;

    sub = func_020124E4(a);
    v = (u8 *)func_02158344((int)((void *)func_02012138(sub)));
    if (v == 0 && *state <= 2 && *state < 6) {
        func_0217F3C4((Ov018Obj_0218191C *)(&c->obj), 4);
        *state = 6;
        c->f98 = 1;
        return 0;
    }
    switch (*state) {
    case 0:
        if (func_0217405C((char *)v, (char *)(v + 0x1AC)) == 1) {
            (*state)++;
        }
        break;
    case 1:
        r = c->fA0 = func_02175CF4((char *)v, v + 0x1AC);
        switch (r) {
        case 1:
            *state = 2;
            break;
        case 2:
            *state = 5;
            break;
        }
        break;
    case 2:
        if (func_0217456C((int)v, c->f40, 2) == 1) {
            (*state)++;
        }
        break;
    case 3:
        c->f9C = 1;
        func_021762D8(c->f44, c->f5C, c->obj.f00, c->f00);
        func_0217F3C4((Ov018Obj_0218191C *)(&c->obj), d_02183950[c->f42]);
        (*state)++;
        break;
    case 4:
        if (func_0217F40C((Ov018Obj_0218191C *)(&c->obj)) == 1) {
            func_0217F3C4((Ov018Obj_0218191C *)(&c->obj), d_0218395A[c->f42]);
            func_020061E4(0x5E0);
            *state = 6;
        }
        break;
    case 5:
        c->f9C = 1;
        func_021762D8(c->f44, c->f5C, c->obj.f00, c->f00);
        func_0217F3C4((Ov018Obj_0218191C *)(&c->obj), d_02183964[c->f42]);
        *state = 6;
        break;
    case 6:
        if (func_0217F40C((Ov018Obj_0218191C *)(&c->obj)) == 1) {
            *state = 7;
        }
        break;
    case 7:
        if (func_0217F420() == 1) {
            *state = 8;
        }
        break;
    case 8:
        func_0217FE38((int)v, (Ov018Outer_0218191C *)c);
        if (c->fA0 == 1) {
            func_0201235C(a, func_021804F8(sub, c->f9C));
            return 0;
        }
        return 1;
    }
    return 0;
}






/*
 *   0x02008494 (unresolved site +0034), 0x0202E82C (site +002E). Verified EXACT in scratch:
 *     void func_02008494(void *a, void *b) { func_02082D44(a, b, 0x20); }   (func_02082D44 arm)
 *     typedef struct { int f00; int f04; } S;
 *     void *func_0202E82C(S *p) { if (p->f04 != 0) return (char *)p + 0x2C; return (char *)p + 0xC; }
 */
void *func_02181D8C(void *a, void *b)
{
    void *w;
    void *r;
    u8 *t;

    w = (void *)func_02012F20((int)func_020120F4(a));
    r = func_020122C0(a, 0, func_02181DD4, 0x34);
    t = func_020124E8(r);
    *(void **)(t + 0x30) = func_0200846C((int)b);
    func_02008494(func_0202E82C(w), *(void **)(t + 0x30));
    func_0217F2B4(t, a);
    return r;
}




int func_02181DD4(void *a, int *state, Ov018Obj_02181DD4 *c)
{
    void *sub;
    void *w;

    sub = func_020124E4(a);
    switch (*state) {
    case 0:
        func_0201F02C(c->f00, 0, c->f30);
        func_0217F3C4((Ov018Obj_0218191C *)c, 0x1C);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj_0218191C *)c) == 1) {
            (*state)++;
        }
        break;
    case 2:
        func_0217F318((Ov018Obj_02181DD4 *)c);
        w = func_02158768((int)sub, 0xAFD, 0, 4);
        func_02159058(func_021589D0((int)w), 0x1C, 1, 0, 0);
        func_02012374(a, w);
        (*state)++;
        break;
    case 3:
        *state = 4;
        break;
    case 4:
        func_020307B0(c->f30);
        return 1;
    }
    return 0;
}





void func_02181E6C(Obj *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02181E90, 0x9C);
    dst = func_020124E8((struct Obj *)task);
    func_02082D44(src, dst, 0x98);
}





int func_02181E90(void *a, int *state, Ov018Outer *c)
{
    int v;

    v = func_02158344(func_02012138(func_020124E4(a)));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, &c->f78);
        func_0217F3C4((Ov018Obj_0218191C *)(&c->obj), d_02183970[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj_0218191C *)(&c->obj)) == 1) {
            *state = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *state = 3;
        }
        break;
    case 3:
        func_0217FE38(v, (Ov018Outer_0218191C *)c);
        return 1;
    }
    return 0;
}





void func_02181F10(Obj *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02181F34, 0x9C);
    dst = func_020124E8((struct Obj *)task);
    func_02082D44(src, dst, 0x98);
}





int func_02181F34(void *a, int *state, Ov018Outer *c)
{
    int v;

    v = func_02158344(func_02012138(func_020124E4(a)));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, &c->f78);
        func_0217F3C4((Ov018Obj_0218191C *)(&c->obj), d_02183984[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj_0218191C *)(&c->obj)) == 1) {
            *state = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *state = 3;
        }
        break;
    case 3:
        func_0217FE38(v, (Ov018Outer_0218191C *)c);
        return 1;
    }
    return 0;
}





void func_02181FB4(Obj *task, const void *src)
{
    void *dst;

    func_0201232C((char *)task, (int)func_02181FD8, 0x9C);
    dst = func_020124E8((struct Obj *)task);
    func_02082D44(src, dst, 0x98);
}



/*
 * Task callback in the shape of func_021809A4: a 4-state sequence with an exit that retasks the callback driving
 * the Ov018Obj at +0x10.
 */
int func_02181FD8(void *a, int *state, Outer *c)
{
    void *h;
    u8 *v;

    h = func_020124E4(a);
    v = (u8 *)func_02158344((int)((void *)func_02012138(h)));
    switch (*state) {
    case 0:
        func_0201F02C(c->obj.f00, 0, c->f78);
        func_0217F3C4((Ov018Obj_0218191C *)(&c->obj), d_0218397A[c->f42]);
        (*state)++;
        break;
    case 1:
        if (func_0217F40C((Ov018Obj_0218191C *)(&c->obj)) == 1) {
            *state = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *state = 3;
        }
        break;
    case 3:
        func_0217FE38((int)v, (Ov018Outer_0218191C *)c);
        if (v != 0) {
            func_020061E4(0x737);
            func_0201235C(a, func_0217CA1C(h));
            return 0;
        }
        return 1;
    }
    return 0;
}


/*
 * Interface: callback payload passed as pointer; owner body stores unchanged word at +4.
 */
void func_02182080(void *a, void *b) { func_0201232C(a,(int)((void *)func_021820A4),0x9c); func_02082D44(b,func_020124E8(a),0x98); }
