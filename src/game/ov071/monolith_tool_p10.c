/*
 * file:     monolith_tool_p10.c
 * unit:     yes
 * function: func_021B7D6C, func_021B7D98, func_021B7DAC, func_021B7DE0, func_021B7E24, func_021B7E3C, func_021B7E60, func_021B7EE0, func_021B8150
 * address:  0x021B7D6C
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02041300 0x02041300 arm
 *   d_021BA928 0x021BA928 data a4
 *   func_02040588 0x02040588 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020498F4 0x020498F4 arm
 *   func_021B7234 0x021B7234 thumb ov071
 *   func_020409B4 0x020409B4 arm
 *   func_021B6F40  0x021B6F40  thumb  ov071
 *   func_021B6F54  0x021B6F54  thumb  ov071
 *   d_021BAA4C     0x021BAA4C  data  a4
 *   d_021BA948     0x021BA948  data  a4
 *   func_021B6FD8 0x021B6FD8 thumb ov071
 *   func_021B6FE0 0x021B6FE0 thumb ov071
 *   func_020120F4  0x020120F4  thumb
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_021B8308  0x021B8308  thumb  ov071
 *   func_021B8350  0x021B8350  thumb  ov071
 *   func_021B81A0  0x021B81A0  thumb  ov071
 *   func_021B82E4  0x021B82E4  thumb  ov071
 *   func_02043598  0x02043598  arm
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_021B82A4  0x021B82A4  thumb  ov071
 *   func_021B82FC  0x021B82FC  thumb  ov071
 *   func_02035C08  0x02035C08  arm
 *   func_020355D8  0x020355D8  arm
 *   func_0203633C  0x0203633C  arm
 *   func_020362DC  0x020362DC  arm
 *   func_021B6B98  0x021B6B98  thumb  ov071
 *   func_020061E4  0x020061E4  thumb
 *   func_02175B14  0x02175B14  thumb  ov011
 *   func_021B83CC  0x021B83CC  thumb  ov071
 *   func_021B6BEC  0x021B6BEC  thumb  ov071
 *   func_021B7108  0x021B7108  thumb  ov071
 *   func_021B6C74  0x021B6C74  thumb  ov071
 *   func_021B7114  0x021B7114  thumb  ov071
 *   func_021B8434  0x021B8434  thumb  ov071
 *   func_02035C60  0x02035C60  arm
 *   func_021B8440  0x021B8440  thumb  ov071
 *   d_021BA978     0x021BA978  data  a4
 *   d_021BA9F8     0x021BA9F8  data  a4
 *   d_021BA9C8     0x021BA9C8  data  a4
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_020435F4  0x020435F4  arm
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02045808  0x02045808  arm
 *   func_021B8270  0x021B8270  thumb  ov071
 *   func_021B82F0  0x021B82F0  thumb  ov071
 *   func_021B83C0  0x021B83C0  thumb  ov071
 *   func_021B833C  0x021B833C  thumb  ov071
 *   func_020315D4  0x020315D4  arm
 */
struct BgTemplate;
struct P;
struct Ctx;
struct BigObj;
struct Obj0203159C;
struct PrintSys;
struct Rec3;
struct S020315D4;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct {
    int pad[3];
    int v[6];
} S;

typedef struct {
    char pad[0x32];
    unsigned char f32;
} W_021B7E60;

typedef struct {
    char pad[0x3d];
    unsigned char f3d;
} Q;

typedef struct {
    Q *q;
    int *f4;
} C_021B7E60;

typedef signed int     s32;

typedef signed char s8;

typedef struct {
    void **f0;
    void *f4;
    char pad8[0x24];
    u8 f2c;
    u8 f2d;
    u8 f2e;
} C_021B7EE0;

typedef struct {
    u8 pad0[0x30];
    s8 sel;
    s8 res;
    u8 kind;
    u8 armed;
    u8 f34[8];
} D;

typedef struct {
    u8 b[0x14];
} Menu;

typedef struct {
    char pad[0x40];
    void *f40;
    void *f44;
} W_021B8150;

typedef struct {
    int f0;
    struct {
        char pad[8];
        void *f8;
    } *f4;
} B;

extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02041300(unsigned,int,int,int,u8,u8,u8);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(unsigned);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_021B7234(void *,int,int);
extern void func_020409B4(unsigned);
extern void func_021B6FD8(void *);
extern void *func_021B6F40(u8 **p);
extern void func_021B6FE0(void *,unsigned char *,int);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158344(int a0);
extern void func_021B82A4(int *a, char *p);
extern void func_021B82FC(void *p);
extern int func_02035C08(const void *p);
extern void func_020355D8(u8 v);
extern unsigned int func_0203633C(void);
extern u32 func_020362DC(void);
extern void func_021B6B98(void *p, int *tbl, int n, int sel, int c);
extern void func_020061E4(unsigned int);
extern int func_02175B14(u8 *);
extern void func_021B83CC(void *w, void *x, unsigned y);
extern void func_021B6BEC(void *p, int *tbl, int n, int sel, int c);
extern void func_021B7108(void *);
extern u8 func_021B6C74(void *p, int i);
extern int func_021B7114(void *);
extern int func_021B8434(u8 *p, u8 *q);
extern int func_02035C60(void);
extern void func_021B8440(void *w);
void func_021B7D6C(void);
void func_021B7D98(void);
void func_021B7DAC(void *a,unsigned *b);
void func_021B7DE0(S *a, int *b);
void func_021B7E24(void **p);
void func_021B7E3C(void **a,void *p);
int func_021B7E60(struct Obj0203159C *a, int unused, C_021B7E60 *c);
int func_021B7EE0(int a, int *state, C_021B7EE0 *c, D *d);
int func_021B8150(void *a, int unused, B *b, W_021B8150 *w);
extern const char d_021BA928[];
extern const unsigned d_021BAA4C[];
extern const char d_021BA948[];
extern unsigned d_021BA978[];
extern Menu d_021BA9F8[];
extern int d_021BA9C8[][4];

void func_021B7D6C(void) { func_0203FCA0(2,(const struct BgTemplate *)d_021BA928,0); func_02041300(2,0,0,0,0x20,0x20,0x11); }

void func_021B7D98(void) { func_02040588(2, 0); func_020403F4(2); }

void func_021B7DAC(void *a,unsigned *b) { func_020498F4((void *)b[12],11,2,0,0,1,0x61); func_021B7234(a,0,2); func_020409B4(2); }

void func_021B7DE0(S *a, int *b)
{
    void *func_021B6F40(u8 **p);
    int func_021B6F54(struct P *p, u8 *q, int c, const int *d, int e);
    int i;
    int t = (int)func_021B6F40((u8 **)b);

    for (i = 0; i < 6; i++) {
        int r;
        unsigned u = d_021BAA4C[i];
        r = func_021B6F54((struct P *)b[1], (u8 *)t, i, (const int *)(d_021BA948 + u * 8), 0);
        a->v[i] = r;
    }
}

void func_021B7E24(void **p) { int i; for(i=0;i<6;i++) func_021B6FD8(p[i+3]); }

void func_021B7E3C(void **a,void *p) { int i; unsigned char *t; t=func_021B6F40(p); for(i=0;i<6;i++) func_021B6FE0(a[i+3],t,i); }

int func_021B7E60(struct Obj0203159C *a, int unused, C_021B7E60 *c)
{
    extern void *func_020120F4(const struct Ctx *p);
    extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
    extern void func_02082BCC(void *, int, int);
    extern u32 func_0201296C(const struct BigObj *p);
    extern u32 func_020142E8(void *bitmap, s32 id);
    extern void func_021B8308(void);
    extern void func_021B8350(W_021B7E60 *, int *);
    extern void func_021B81A0(int *a, u8 *p);
    extern void func_021B82E4(void *, int);
    extern void func_02043598(u32 mask, u32 enable);
    void *h = func_020120F4(*(void **)c->q);
    W_021B7E60 *w = func_0203159C(a, 0x48, 0x61);

    func_02082BCC(w, 0, 0x48);
    if (func_020142E8((void *)func_0201296C(h), 0x980) == 0) {
        w->f32 = 2;
    } else if (c->q->f3d == 1) {
        w->f32 = 1;
    } else {
        w->f32 = 0;
    }
    func_021B8308();
    func_021B8350(w, c->f4);
    func_021B81A0((int *)c, (u8 *)w);
    func_021B82E4(c, (int)w);
    func_02043598(0x10, 1);
    return 1;
}


int func_021B7EE0(int a, int *state, C_021B7EE0 *c, D *d)
{
    u8 *r;
    int res;
    u32 keys;
    int t;

    r = (u8 *)func_02158344(func_02012138(*c->f0));
    func_021B82A4((int *)c, (char *)d);
    func_021B82FC(d);
    if (c->f2e == 1) {
        return 1;
    }
    switch (*state) {
    case 0:
        res = func_02035C08(&d_021BA9F8[d->kind]);
        if (res != -1) {
            d->sel = res;
            d->res = d_021BA9C8[d->kind][res];
            func_020355D8(1);
            d->armed = 0;
            (*state)++;
            break;
        }
        keys = func_0203633C();
        t = func_020362DC();
        if (t > 0 && d->armed == 1) {
            func_020355D8(0);
            d->armed = 0;
            func_021B6B98(c, (int *)d, d_021BA978[d->kind], d->sel, 3);
            func_020061E4(0x548);
            break;
        }
        if (t & 1) {
            d->res = d_021BA9C8[d->kind][d->sel];
            (*state)++;
        } else if (t & 2) {
            d->res = 3;
            (*state)++;
        } else if (keys & 0x80) {
            d->sel++;
            if (d->sel >= d_021BA978[d->kind]) {
                d->sel = 0;
            }
            func_021B6B98(c, (int *)d, d_021BA978[d->kind], d->sel, 3);
            func_020061E4(0x548);
        } else if (keys & 0x40) {
            d->sel--;
            if (d->sel < 0) {
                d->sel = d_021BA978[d->kind] - 1;
            }
            func_021B6B98(c, (int *)d, d_021BA978[d->kind], d->sel, 3);
            func_020061E4(0x548);
        }
        break;
    case 1:
        if (d->res == 0) {
            if (((u8 *)c->f0)[0x3d] == 0) {
                (*state)--;
                break;
            }
            if (r != 0 && func_02175B14(r + 0x1ac) == 1) {
                func_020061E4(0x54c);
                func_021B83CC(d, c->f4, 4);
                *state = 3;
                break;
            }
        }
        if (d->res != 3) {
            func_021B6BEC(c, (int *)d, d_021BA978[d->kind], d->sel, 3);
            func_020061E4(0x54c);
        } else {
            func_021B7108(d->f34);
            func_020061E4(0x551);
        }
        (*state)++;
        break;
    case 2:
        if (d->res != 3) {
            if (func_021B6C74(c, 3) != 2) {
                c->f2c = d->res + 1;
                return 1;
            }
        } else {
            if (func_021B7114(d->f34) == 0) {
                c->f2c = d->res + 1;
                return 1;
            }
        }
        break;
    case 3:
        if (func_021B8434(c->f4, (u8 *)d) == 1) {
            if (func_02035C60() != 0 || (func_020362DC() & 3) != 0) {
                func_021B8440(d);
                func_020061E4(0x547);
                *state = 0;
            }
        }
        break;
    }
    return 0;
}

int func_021B8150(void *a, int unused, B *b, W_021B8150 *w)
{
    extern u32 func_0201C6B4(const struct PrintSys *p);
    extern void func_020435F4(u32 planes);
    extern void func_0201CE48(struct Rec3 *p);
    extern void func_02045808(struct U16Vec *vec);
    extern void func_021B8270(unsigned char *p);
    extern void func_021B82F0(void *p);
    extern void func_021B83C0(void *p);
    extern void func_021B833C(void);
    extern void func_020315D4(struct S020315D4 *p);

    if (func_0201C6B4(b->f4->f8) == 0) {
        return 0;
    }
    func_020435F4(8);
    if (w->f40 != 0) {
        func_0201CE48(w->f40);
    }
    if (w->f44 != 0) {
        func_02045808(w->f44);
    }
    func_021B8270((unsigned char *)w);
    func_021B82F0(w);
    func_021B83C0(w);
    func_021B833C();
    func_020315D4(a);
    return 1;
}
