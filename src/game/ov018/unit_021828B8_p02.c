/*
 * file:     unit_021828B8_p02.c
 * unit:     yes
 * function: func_021829A8, func_021829C8, func_021829F8, func_02182A08
 * address:  0x021829A8
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
 *   d_02183A80 0x02183A80 data a2
 *   func_021828B8 0x021828B8 thumb ov018
 *   d_02183A44 0x02183A44 data a2
 *   d_02183A2C 0x02183A2C data a2
 *   d_02183A14 0x02183A14 data a2
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0201232C  0x0201232C  thumb
 *   func_02182AA4  0x02182AA4  thumb  ov018
 *   func_020124E8  0x020124E8  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02034714  0x02034714  arm
 *   d_02183B50     0x02183B50  data   a1
 *   d_02183ABC     0x02183ABC  data   a2
 */
struct Obj;
struct WordSet;
struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { u8 pad[0x48]; unsigned int n : 4; unsigned int other : 28; } Src_021829A8;

typedef struct { u8 pad[0x48]; unsigned int n : 4; unsigned int other : 28; } Src_021829C8;

typedef struct {
    u8 pad00[0x10];
    void *f10;
    u8 pad14[0x42 - 0x14];
    u8 f42;
    u8 pad43[0x78 - 0x43];
    u8 f78[0x20];
} Src_02182A08;

typedef struct {
    u8 pad00[0x40];
    u8 f40;
    u8 pad41[0x9C - 0x41];
    u16 f9C;
} Dst;

typedef struct {
    u8 pad00[0x80];
    u16 f80;
    u8 pad82[0x9C - 0x82];
    u16 tab[1];
} Ctx;

typedef unsigned int   u32;

extern void func_021828B8(void *, void *, u16 *);
extern void *func_020124E4(struct Obj *p);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158344(int a0);
extern void func_0201232C(char *p, int a1, int a2);
extern void func_02182AA4();
extern void *func_020124E8(struct Obj *p);
extern void func_02082D44(void *, void *, int);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_02034714(const char *expr, u32 line, const char *file);
void func_021829A8(void *a, Src_021829A8 *b);
void func_021829C8(void *a, Src_021829C8 *b);
void func_021829E8(void *a, void *b);
void func_021829F8(void *a, void *b);
void func_02182A08(void *a, Src_02182A08 *b);
extern u16 d_02183A80[][5];
extern u16 d_02183A44[][5];
extern u16 d_02183A2C[];
extern unsigned short d_02183A14[];
extern const char d_02183B50[];
extern u16 d_02183ABC[];

void func_021829A8(void *a, Src_021829A8 *b) { int n; n = b->n; if (n >= 6) n = 0; func_021828B8(a,b,d_02183A80[n]); }

void func_021829C8(void *a, Src_021829C8 *b) { int n; n = b->n; if (n >= 6) n = 0; func_021828B8(a,b,d_02183A44[n]); }

void func_021829E8(void *a, void *b) { func_021828B8(a,b,d_02183A2C); }

void func_021829F8(void *a, void *b) { func_021828B8(a,b,d_02183A14); }


void func_02182A08(void *a, Src_02182A08 *b)
{
    Ctx *v;
    Dst *p;
    int m;

    v = (Ctx *)func_02158344((int)((void *)func_02012138(func_020124E4(a))));
    func_0201232C(a, (int)func_02182AA4, 0xA0);
    p = func_020124E8(a);
    func_02082D44(b, p, 0x98);
    if (v != 0) {
        m = 0;
        p->f9C = d_02183ABC[b->f42];
        func_0201F02C(b->f10, 0, b->f78);
    } else {
        func_02034714(d_02183B50, 0, d_02183B50);
        return;
    }
    if (v->f80 == 2)
        m = 3;
    else if (v->f80 == 3)
        m = 2;
    else if (v->f80 != 1)
        m = 1;
    *(u16 *)((u8 *)v + 0x1C * p->f40 + 0x9C) = m;
}
