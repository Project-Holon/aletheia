/*
 * file:     field_place_name_p18.c
 * unit:     yes
 * function: func_021BD554, func_021BD57C, func_021BD588, func_021BD5D4
 * address:  0x021BD554
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BD484  0x021BD484  thumb  ov021
 *   func_02043B5C  0x02043B5C  arm
 *   func_021BD2C8  0x021BD2C8  thumb  ov021
 *   func_02045A98  0x02045A98  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_020257D0  0x020257D0  thumb
 *   func_02045808  0x02045808  arm
 *   _ffix          0x0209C494  arm
 *   func_021BD304  0x021BD304  thumb  ov021
 */
#include "../../matched/include/Obj18234.h"
#include "../../matched/include/Obj02719.h"

struct CharBuf;
struct Obj;
struct U16Vec;
struct Strbuf;
typedef struct {
    int x, y;
} V2;

typedef struct {
    int a, b, c, d, e, f;
    V2 g;
} Src;

typedef struct {
    char pad[0x10];
    int a, b, c, d;
    char pad2[8];
    int e, f;
    V2 g;
} Obj_021BD554;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short s16;

typedef struct {
    float f0;
    float f4;
} Q;

typedef struct {
    char pad[0xC];
    void *fC;
} Obj_021BD5D4;

extern void func_021BD484(Obj_021BD554 *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u16 func_021BD2C8(u8 *p);
extern u16 func_02045A98(void);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045994(struct Strbuf *a, const u16 *b, u32 c);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_020257D0(struct Obj *o);
extern void func_02045808(struct U16Vec *vec);
extern u8 *func_021BD304(u8 *p);
extern void func_0202590C(void *a, int b, int c);
void func_021BD554(Obj_021BD554 *p, Src *s);
void func_021BD57C(u8 *p);
void func_021BD588(u32 *p);
void func_021BD5D4(Obj_021BD5D4 *p);


void func_021BD554(Obj_021BD554 *p, Src *s)
{
    p->a = s->a;
    p->b = s->b;
    p->c = s->c;
    p->d = s->d;
    p->e = s->e;
    p->f = s->f;
    p->g = s->g;
    func_021BD484(p);
}


/*
 * Tail call on the word at +8 with a zero second argument.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD57C(u8 *p)
{
    func_02043B5C((struct CharBuf *)(((struct Obj18234 *)p)->f8), 0);
}


void func_021BD588(u32 *p)
{
    u16 buf[2];
    u32 h;

    buf[0] = func_021BD2C8((u8 *)p);
    buf[1] = func_02045A98();
    h = (u32)func_020457B0(2, ((struct Obj02719 *)p)->f0);
    func_02045994((struct Strbuf *)h, buf, 2);
    func_0201C7D0((void *)p[2], 0, 0, (void *)h, (void *)p[1], 0x440);
    func_020257D0((struct Obj *)p[3]);
    func_02045808((struct U16Vec *)h);
}


void func_021BD5D4(Obj_021BD5D4 *p)
{
    Q *q = (Q *)func_021BD304((u8 *)p);
    int x = (int)q->f0;
    int y = (int)q->f4;

    func_0202590C(p->fC, x, y);
}
