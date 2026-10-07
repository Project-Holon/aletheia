/*
 * file:     intrude_field_p07.c
 * unit:     yes
 * function: func_0217BF2C, func_0217BF84, func_0217BFD8, func_0217C070, func_0217C094, func_0217C0A8
 * address:  0x0217BF2C
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
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   d_02182B6C     0x02182B6C  data   a4
 *   d_02182B54 0x02182B54 data a4
 *   func_020120F4  0x020120F4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02012B70  0x02012B70  thumb
 *   func_02012204  0x02012204  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02013D9C  0x02013D9C  thumb
 *   func_0202648C  0x0202648C  thumb
 *   func_02026454  0x02026454  thumb
 *   func_0202647C  0x0202647C  thumb
 *   func_02176258 0x02176258 thumb ov011
 *   func_02026478  0x02026478  thumb
 *   func_02012B80  0x02012B80  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02026474  0x02026474  thumb
 *   func_02012950  0x02012950  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 */
#include "../../matched/include/Obj19353.h"

struct BigObj;
struct Ctx;
struct Rec44;
struct Sub24;
struct Sub0200852CObj;
typedef unsigned short u16;

typedef struct { u16 a, b; int c; } Sub;

typedef struct {
    u16 f00, f02;
    u16 pad04[3];
    u16 f0a;
    u16 pad0c[8];
    Sub s;
} Buf;

typedef unsigned char  u8;

typedef enum { INDEX_ZERO, INDEX_ONE } Index;

typedef struct { u16 f0, f2, f4, f6, f8; } Ent;

typedef unsigned int   u32;

typedef struct { u8 bit:1; u8 rest:7; } Bits;

extern void *func_02188C7C(unsigned char *p);
extern u16 func_02188C9C(u8 *p);
extern void func_0216CE60(int a, int b, int c);
extern void *func_020120F4(const struct Ctx *p);
extern unsigned int func_02012138(const struct Ctx *p);
extern int func_02158344(int);
extern int func_02012B70(const struct BigObj *p);
extern unsigned int func_02012204(const struct Ctx *p);
extern u32 func_02013D5C(u32 id);
extern u32 func_02013D9C(u32 id);
extern u32 func_0202648C(void *obj);
extern u32 func_02026454(void *obj);
extern u32 func_0202647C(void *obj);
extern int func_02176258(u8 *);
extern unsigned int func_02026478(void *obj);
extern u8 func_02012B80(const struct BigObj *p);
extern u8 func_02012B58(const struct BigObj *p);
extern unsigned int func_02026474(void *obj);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
void func_0217BF2C(int a, u16 b, u16 c, int d, u16 e, u16 f, u16 g);
void func_0217BF84(int a);
int func_0217BFD8(const struct Ctx *a, int b);
int func_0217C070(u8 *p);
void func_0217C094(unsigned char *p);
u8 func_0217C0A8(void *a0);
extern const Buf d_02182B6C;
extern const Ent d_02182B54[];


void func_0217BF2C(int a, u16 b, u16 c, int d, u16 e, u16 f, u16 g)
{
    Buf buf;
    void *h;
    int k;
    Sub *q;

    h = func_02188C7C((void *)a);
    k = func_02188C9C((u8 *)a);
    buf = d_02182B6C;
    buf.f00 = g;
    buf.f02 = e;
    buf.f0a = f;
    q = &buf.s;
    q->a = b;
    q->b = c;
    q->c = d;
    func_0216CE60((int)h, (int)(&buf), k);
}

/*
 * lever: enum inner counter preserves the one-iteration loop; unsigned comparison;
 *   named column load fixes the Thumb add operands.
 */
void func_0217BF84(int a)
{
    Index i;
    int j;
    unsigned int column;
    j = 1;
    do {
        i = INDEX_ZERO;
        do {
            column = d_02182B54[i].f2;
            func_0217BF2C(a, column + (j << 6), d_02182B54[i].f4, 0x2001F, d_02182B54[i].f0, d_02182B54[i].f6, j + d_02182B54[i].f8 - 1);
            i++;
        } while ((unsigned int)i < 1);
        j++;
    } while (j < 3);
}


int func_0217BFD8(const struct Ctx *a, int b)
{
    int h;
    int t;
    int w;

    h = (int)func_020120F4((const struct Ctx *)a);
    t = func_02012138((const struct Ctx *)a);
    w = func_02158344(t);
    if (func_02012B70((const struct BigObj *)h) == 0)
        return 0;
    if (w != 0)
        return 0;
    if (func_02012204(a) == 1)
        return 1;
    if (func_02013D5C(b) == 1) {
        if (func_0202648C((void *)t) != 0)
            return 1;
        return 0;
    }
    if (func_02013D9C(b) == 1) {
        if (func_02026454((void *)t) == 2 || (func_02026454((void *)t) == 0 && func_0202647C((void *)t) == 2 && func_0202648C((void *)t) != 0))
            return 1;
        return 0;
    }
    return 1;
}

int func_0217C070(u8 *p)
{
    if (((Bits *)(p + 0x93f))->bit == 1 || func_02176258(p) == 1)
        return 1;
    return 0;
}

void func_0217C094(unsigned char *p)
{
    if (p != 0) {
        p[0x8F8] |= 0x20;
    }
}


u8 func_0217C0A8(void *a0)
{
    int h;
    u8 *q;
    u8 *obj;

    h = func_02026478(a0);
    if (func_02012B70((const struct BigObj *)h) == 0) {
        obj = func_02012944((void *)h);
    } else if (func_02012B80((const struct BigObj *)h) == func_02012B58((const struct BigObj *)h)) {
        obj = func_02012944((void *)h);
    } else {
        q = 0;
        if (func_02026454(a0) == 2 && func_02026474(a0) != 0)
            q = (u8 *)func_02026474(a0);
        if (q == 0) {
            obj = func_02012944((void *)h);
        } else if (func_02013D5C(((struct Obj19353 *)q)->f84) == 1) {
            obj = func_02012944((void *)h);
        } else {
            obj = (u8 *)func_02012950((struct Sub24 *)h, func_02012B80((const struct BigObj *)h));
        }
    }
    return func_02008550((const struct Sub0200852CObj *)obj);
}
