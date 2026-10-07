/*
 * file:     unit_021B95A0_p03.c
 * unit:     yes
 * function: func_021B984C, func_021B989C, func_021B98E4, func_021B98F0, func_021B98F8, func_021B98FC, func_021B9900, func_021B9968, func_021B99F4
 * address:  0x021B984C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C4AC4  0x021C4AC4  thumb  ov127
 *   func_021C4864  0x021C4864  thumb  ov127
 *   func_021C5858  0x021C5858  thumb  ov127
 *   func_021C584C  0x021C584C  thumb  ov127
 *   func_021B9F90  0x021B9F90  thumb
 *   func_021B9FD0  0x021B9FD0  thumb  ov099
 *   func_021BA168  0x021BA168  thumb
 *   func_021BA0F8  0x021BA0F8  thumb  ov099
 *   func_021BA1C4  0x021BA1C4  thumb
 *   func_021BA228  0x021BA228  thumb  ov099
 *   func_021BA190  0x021BA190  thumb
 *   func_021C5994  0x021C5994  thumb  ov127
 *   func_021C5A60  0x021C5A60  thumb  ov127
 *   func_021BA04C  0x021BA04C  thumb
 *   func_021BA248  0x021BA248  thumb
 *   func_021C49A4  0x021C49A4  thumb  ov127
 *   func_021C57D8  0x021C57D8  thumb  ov127
 *   func_021C57DC  0x021C57DC  thumb  ov127
 *   func_021BA5B4  0x021BA5B4  thumb
 */
#include "../../matched/include/Obj22009.h"

typedef unsigned short u16;

typedef unsigned int u32_021B984C;

typedef struct {
    short x, y;
} Pos;

typedef struct {
    char pad[0x570];
    void **f570;
    char pad574[0x14];
    void *f588;
} Work_021B984C;

typedef unsigned char  u8;

typedef struct {
    void *f0;
    void *f4;
} Rec;

typedef short s16_021B98E4;

typedef signed char s8;

typedef unsigned int u32_021B98E4;

typedef int s32_021B98E4;

typedef short s16_021B98F0;

typedef unsigned int u32_021B98F0;

typedef int s32_021B98F0;

typedef unsigned long  u32_021B98F8;

typedef signed short   s16_021B98F8;

typedef signed long    s32_021B98F8;

typedef int BOOL;

typedef struct {
    u32_021B98F8 f00, f04, f08, f0C;
} S;

typedef unsigned long  u32_021B98FC;

typedef signed short   s16_021B98FC;

typedef signed long    s32_021B98FC;

typedef unsigned int u32_021B9900;

typedef struct {
    char pad[0x570];
    void **f570;
} Work_021B9968;

typedef unsigned int   u32_021B9968;

typedef struct {
    void *f0;
    void *f4;
    short f8;
    short pad;
    short fc;
    short pad2;
    int f10;
    int f14;
    int f18;
} Ent;

extern Pos func_021C4AC4(void *v);
extern u32_021B984C func_021C4864(u8 *p, u16 x, u16 y);
extern int func_021C5858(u8 *p);
extern void func_021C584C(u8 *p, int a);
extern void func_021B9F90(void *o, Pos pos, int c);
extern void func_021B9FD0(void *p);
extern u8 *func_021BA168(u8 *p);
extern void func_021BA0F8(void *p, u16 *xy);
extern void func_021BA1C4(u8 *p, void **out, short *xy, int a, u16 d, u8 c, int b);
extern void func_021BA228(void *w, u8 *s);
extern void func_021BA190(u8 *p, u8 *s, int n);
extern void func_021C5994(void *p, void *q);
extern void func_021C5A60(char *p, void *q);
extern void func_021BA04C(char *p, u16 *out, u32_021B9968 c);
extern void func_021BA248(void *o, void *e);
extern int func_021C49A4(u8 *p, unsigned int i);
extern void func_021C57D8(u8 *p, int v);
extern void func_021C57DC(u8 *p);
extern void func_021BA5B4(void *a, int b, u8 **p);
void func_021B984C(Work_021B984C *w);
void func_021B989C(void *o, Rec *r);
void func_021B98E4(int a, u8 *b);
void func_021B98F0(void *p);
void func_021B98F8(S *s, u32_021B98F8 v);
u32_021B98FC func_021B98FC(S *s);
u8 *func_021B9900(u8 *p, int v);
void *func_021B9968(Work_021B9968 *o, int a, int b);
void func_021B99F4(void *o, Ent *e);


void func_021B984C(Work_021B984C *w)
{
    Pos b = func_021C4AC4(*w->f570);

    func_021C4864(w->f588, b.x / 16, b.y / 16 + 1);
}


void func_021B989C(void *o, Rec *r)
{
    Pos p = func_021C4AC4(r->f0);

    func_021B9F90(o, p, func_021C5858(r->f4) - 2);
    func_021C584C(r->f4, 0);
}

void func_021B98E4(int a, u8 *b) { func_021C584C((u8 *)(((struct Obj22009 *)b)->f4), 1); }

void func_021B98F0(void *p) { func_021B9FD0(p); }


void func_021B98F8(S *s, u32_021B98F8 v)
{
    s->f0C = v;
}


u32_021B98FC func_021B98FC(S *s)
{
    return s->f0C;
}


u8 *func_021B9900(u8 *p, int v)
{
    u8 *s;
    u16 xy[2];

    s = func_021BA168(p);
    *(u8 **)(p + 0x570) = s;
    func_021BA0F8(p, xy);
    func_021BA1C4(p, (void **)s, (short int *)xy, 0, v, 0, 0);
    func_021BA228(p, s);
    func_021BA190(p, s, 1);
    func_021C5994(p + 0x594, **(void ***)(p + 0x570));
    func_021C5A60(*(char **)(p + 0x598), p + 0x594);
    return s;
}


void *func_021B9968(Work_021B9968 *o, int a, int b)
{
    void *e;
    Pos t;
    Pos d;

    e = func_021BA168((u8 *)o);
    func_021BA04C((char *)o, (u16 *)(&t), b - 1);
    if (o->f570 != 0) {
        d = func_021C4AC4(*o->f570);
        if (d.x == t.x && d.y == t.y)
            return 0;
    }
    func_021BA1C4((u8 *)o, e, (short int *)(&t), b, a, 1, 4);
    func_021BA248(o, e);
    func_021BA190((u8 *)o, e, 0);
    return e;
}


void func_021B99F4(void *o, Ent *e)
{
    func_021C49A4(e->f0, 6);
    e->f10 = 0x021BA521;
    e->f8 = 0;
    e->f18 = 0x021BA2D5;
    e->fc = 2;
    func_021C57D8(e->f4, 0);
    func_021C57DC(e->f4);
    func_021BA5B4(o, 4, (u8 **)e);
}
