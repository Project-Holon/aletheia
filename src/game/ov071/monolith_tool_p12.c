/*
 * file:     monolith_tool_p12.c
 * unit:     yes
 * function: func_021B83C0, func_021B83CC, func_021B8434, func_021B8440, func_021B8494, func_021B855C, func_021B8618, func_021B8650, func_021B869C
 * address:  0x021B83C0
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
 *   func_020452E8  0x020452E8  arm
 *   func_02034714  0x02034714  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02040588  0x02040588  arm
 *   d_021BABF8     0x021BABF8  data  a1
 *   func_02028484  0x02028484  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02045808  0x02045808  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B86BC  0x021B86BC  thumb  ov071
 *   func_021B86E8  0x021B86E8  thumb  ov071
 *   func_021B8764  0x021B8764  thumb  ov071
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_020434DC  0x020434DC  arm
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_021B6F04  0x021B6F04  thumb  ov071
 *   func_021B8798  0x021B8798  thumb  ov071
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02043534 0x02043534 arm
 *   func_020315D4 0x020315D4 arm
 *   func_021B8750 0x021B8750 thumb ov071
 *   func_021B878C 0x021B878C thumb ov071
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02041300  0x02041300  arm
 *   d_021BAA64     0x021BAA64  data  a4
 *   d_021BAA84     0x021BAA84  data  a4
 *   func_020403F4 0x020403F4 arm
 */
#include "../../matched/include/Obj20724.h"
#include "../../matched/include/Obj20725.h"
#include "../../matched/include/Obj06186.h"
#include "../../matched/include/Obj06187.h"
#include "../../matched/include/Obj20733.h"
#include "../../matched/include/Obj20734.h"

struct Descriptor;
struct MsgBank;
struct Blk;
struct Rec3;
struct U16Vec;
struct CharBuf;
struct PrintSys;
struct Obj0203159C;
struct Ctx;
struct S020315D4;
struct BgTemplate;
typedef unsigned int   u32;

typedef struct {
    char pad[0x3c];
    void *f3c;
    void *f40;
    void *f44;
} W;

typedef struct {
    char pad0[0xc];
    unsigned fc;
    char pad10[8];
    unsigned f18;
    char pad1c[0xc];
    void *f28;
} X;

typedef unsigned char u8;

typedef signed int     s32;

typedef struct {
    char pad0[8];
    void *f8;
} Q;

typedef struct {
    void **f0;
    Q *f4;
} C_021B8494;

typedef struct {
    void **f0;
    Q *f4;
    unsigned char *f8;
    char pad[0x21];
    unsigned char f2d;
} C_021B855C;

extern s32 func_02028484(struct Blk *blk, void *h);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_02043534(unsigned int);
extern void func_020315D4(struct S020315D4 *p);
extern void func_021B8750(void **);
extern void func_021B878C(void *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(unsigned int);
void func_021B83C0(void *p);
void func_021B83CC(W *w, X *x, unsigned y);
int func_021B8434(u8 *p, u8 *q);
void func_021B8440(W *w);
int func_021B8494(struct Obj0203159C *a, int *b, C_021B8494 *c, u8 *d);
int func_021B855C(int a, int *p, C_021B855C *c, unsigned char *d);
int func_021B8618(void *a, void *b, char *c, void **d);
void func_021B8650(void);
void func_021B869C(void);
extern char d_021BABF8[];
extern char d_021BAA64[];
extern char d_021BAA84[];

/*
 * Tail call to func_020452E8 on the pointer loaded from offset 0x3c.
 */
void func_021B83C0(void *p)
{
    u32 func_020452E8(struct Descriptor *d);
    func_020452E8(((struct Obj20724 *)p)->f3C);
}

void func_021B83CC(W *w, X *x, unsigned y)
{
    extern void func_02034714(const char *expr, u32 line, const char *file);
    extern void func_0201DD78(u32 r, u32 g, u32 b);
    extern void *func_02045EC0(struct MsgBank *bank, u32 index);
    extern signed char func_02012FFC(void);
    extern void *func_0201CCE4(void *, unsigned, unsigned, void *, unsigned,
                               unsigned, unsigned, unsigned, unsigned, unsigned);
    extern void func_02040588(unsigned char which, unsigned char enable);

    if (w->f40 != 0) {
        func_02034714(d_021BABF8, 0, d_021BABF8);
    }
    func_0201DD78(1, 2, 0xf);
    w->f44 = func_02045EC0(x->f28, y);
    w->f40 = func_0201CCE4(w->f3c, 0, 0, w->f44, x->fc, func_02012FFC(),
                           x->f18, 10, 0x61, 0xf);
    func_02040588(5, 1);
}


int func_021B8434(u8 *p, u8 *q)
{
    return func_02028484((struct Blk *)(p + 0x38), (void *)(((struct Obj20725 *)q)->f40));
}

void func_021B8440(W *w)
{
    extern void *func_02045770(struct Descriptor *p);
    extern void func_02034714(const char *expr, u32 line, const char *file);
    extern void func_0201CE48(struct Rec3 *p);
    extern void func_02045808(struct U16Vec *vec);
    extern void func_02040588(unsigned char which, unsigned char enable);
    extern void func_02043B5C(struct CharBuf *buf, u8 value);
    extern void func_02045334(struct Descriptor *d);
    extern void func_0201DD78(u32 r, u32 g, u32 b);
    unsigned r = (unsigned)func_02045770(w->f3c);

    if (w->f40 == 0) {
        func_02034714(d_021BABF8, 0, d_021BABF8);
    }
    func_0201CE48(w->f40);
    w->f40 = 0;
    func_02045808(w->f44);
    w->f44 = 0;
    func_02040588(5, 0);
    func_02043B5C((struct CharBuf *)r, 0xff);
    func_02045334(w->f3c);
    func_0201DD78(0xf, 2, 0);
}

int func_021B8494(struct Obj0203159C *a, int *b, C_021B8494 *c, u8 *d)
{
    extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
    extern void func_02082BCC(void *, int, int);
    extern void func_021B8650(void);
    extern void func_021B86BC(char *p);
    extern void func_021B86E8(Q *, u8 *);
    extern void func_021B8764(void *p, char *q);
    extern void *func_02045770(struct Descriptor *p);
    extern u32 func_0201C6C4(struct PrintSys *p, void *v);
    extern void func_02045334(struct Descriptor *d);
    extern void func_02040588(unsigned char which, unsigned char enable);
    extern void func_020434DC(u32 mask, u32 enable);
    u8 *m;
    int busy;
    int i;

    switch (*b) {
    case 0:
        m = func_0203159C(a, 0x28, 0x61);
        func_02082BCC(m, 0, 0x28);
        func_021B8650();
        func_021B86BC((char *)c->f4);
        func_021B86E8(c->f4, m);
        func_021B8764(c->f4, (char *)m);
        m[0x24] = 0xff;
        *b = *b + 1;
        break;
    case 1:
        busy = 0;
        for (i = 0; i < 2; i++) {
            void *q = c->f4->f8;
            u8 *s = d + i * 8;
            if (s[0xc] != 0) {
                if (func_0201C6C4(q, (void *)((unsigned)func_02045770(((struct Obj06186 *)s)->f8))) == 0) {
                    func_02045334(((struct Obj06186 *)s)->f8);
                    s[0xc] = 0;
                }
            }
            if ((!s[0xc]) == 0) {
                busy = 1;
            }
        }
        if (busy == 0) {
            func_02040588(0, 1);
            func_02040588(2, 1);
            func_020434DC(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * Both tail returns are 0; the load of *p survives only through a
 * `switch` with a `default`, and `(!s[0xc]) == 1` keeps the boolean.
 */
int func_021B855C(int a, int *p, C_021B855C *c, unsigned char *d)
{
    extern u32 func_02012138(const struct Ctx *p);
    extern int func_02158344(int a0);
    extern int func_021B6F04(void **p, u8 *q);
    extern void *func_02045770(struct Descriptor *p);
    extern u32 func_0201C6C4(struct PrintSys *p, void *v);
    extern void func_02045334(struct Descriptor *d);
    extern void func_021B8798(C_021B855C *, Q *, unsigned char *, int, unsigned);
    int r;
    int n;
    int i;

    r = func_02158344(func_02012138(*c->f0));
    n = 0;
    if (c->f2d == 1) {
        return 1;
    }
    func_021B6F04((void **)c->f4, d + 0x18);
    for (i = 0; i < 2; i++) {
        void *q = c->f4->f8;
        unsigned char *s = d + i * 8;
        if (s[0xc] != 0) {
            if (func_0201C6C4(q, (void *)((unsigned)func_02045770(((struct Obj06187 *)s)->f8))) == 0) {
                func_02045334(((struct Obj06187 *)s)->f8);
                s[0xc] = 0;
            }
        }
        if ((!s[0xc]) == 1) {
            n++;
        }
    }
    if (n == 2) {
        unsigned v = *c->f8;
        if (d[0x24] != v) {
            func_021B8798(c, c->f4, d, r, v);
            d[0x24] = *c->f8;
        }
    }
    switch (*p) {
    case 0:
        return 0;
    default:
        return 0;
    }
}

int func_021B8618(void *a, void *b, char *c, void **d)
{
    if (func_0201C6B4(((struct Obj20734 *)(*(char * *)&((struct Obj20733 *)c)->f4))->f8) == 0) return 0;
    func_02043534(8);
    func_021B8750(d);
    func_021B869C();
    func_021B878C(d);
    func_020315D4(a);
    return 1;
}

void func_021B8650(void)
{
    extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
    extern void func_02041300(int, int, int, int, int, int, int);

    func_0203FCA0(0, (const struct BgTemplate *)d_021BAA64, 0);
    func_0203FCA0(2, (const struct BgTemplate *)d_021BAA84, 0);
    func_02041300(0, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(2, 0, 0, 0, 0x20, 0x20, 0x11);
}

void func_021B869C(void) { func_02040588(0,0); func_02040588(2,0); func_020403F4(0); func_020403F4(2); }
