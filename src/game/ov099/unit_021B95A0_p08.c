/*
 * file:     unit_021B95A0_p08.c
 * unit:     yes
 * function: func_021B9EB8, func_021B9F34
 * address:  0x021B9EB8
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
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   sub_0204B3B4  0x0204B3B4  arm
 */
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32_021B9EB8;

typedef struct {
    u32_021B9EB8 f0;
    u32_021B9EB8 f4;
    u32_021B9EB8 f8;
    u32_021B9EB8 fc;
    u32_021B9EB8 f10;
    u32_021B9EB8 f14;
    u32_021B9EB8 f18;
} Obj;

typedef struct {
    u16 a, b, c;
    u8 d, e;
} Rec;

typedef unsigned long  u32_021B9F34;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef struct {
    char pad[0x14];
    void *f14;
    void *f18;
} S;

extern struct Obj *func_0204B294(void *a, unsigned int b, unsigned int c, unsigned int d, const void *e, u16 f, u16 g);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B92C(struct Obj *a, u32_021B9EB8 b);
extern void sub_0204B3B4(struct Obj *p);
void func_021B9EB8(Obj *o, int a);
void func_021B9F34(S *s);


void func_021B9EB8(Obj *o, int a)
{
    Rec r;

    r.a = 1;
    r.b = 1;
    r.c = 0;
    r.d = 0;
    r.e = 0;
    o->f14 = (u32_021B9EB8)func_0204B294((void *)o->f0, o->f8, o->fc, o->f10, &r, 0, a);
    r.c = 2;
    r.d = 0xfe;
    r.e = 3;
    o->f18 = (u32_021B9EB8)func_0204B294((void *)o->f0, o->f8, o->fc, o->f10, &r, 0, a);
    func_0204B3DC((struct Obj *)o->f14, 0);
    func_0204B3DC((struct Obj *)o->f18, 0);
    func_0204B92C((struct Obj *)o->f14, 1);
    func_0204B92C((struct Obj *)o->f18, 1);
}


void func_021B9F34(S *s)
{
    sub_0204B3B4(s->f14);
    sub_0204B3B4(s->f18);
}
