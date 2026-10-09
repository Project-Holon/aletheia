/*
 * file:     fldeff_namipoke_p03.c
 * unit:     yes
 * function: func_021AD6B8, func_021AD738
 * address:  0x021AD6B8
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
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6694  0x021C6694  thumb  ov021
 *   func_021C66EC  0x021C66EC  thumb  ov021
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021C6658  0x021C6658  thumb  ov021
 */
typedef unsigned short u16;

typedef struct Vec {
    int x, y, z;
} Vec;

typedef struct S16 {
    int a;
    int *b;
    int c, d;
} S16;

typedef struct Obj {
    Vec v;
    int padc;
    u16 h10;
    u16 pad12;
    S16 s14;
} Obj;

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef struct S {
    int pad0[4];
    u16 h10;
    u16 pad12;
    int pad14;
    int *p18;
} S;

extern void func_021AC154(int a);
extern unsigned int func_021ABE18(u8 *p);
extern int func_021C6694(u32 *a, int idx, int v);
extern int func_021C66EC(u32 *a, int idx, int v);
extern void func_021AC1B8(int a, Vec *v);
extern void func_021AC1CC(int a, Vec *v);
extern int func_021C6658(u32 a, u32 b);
void func_021AD6B8(int a, Obj *b);
void func_021AD738(int a, S *s);


void func_021AD6B8(int a, Obj *b)
{
    Vec v;
    int r;

    if (b->padc == 1 && b->s14.a == 1) {
        func_021AC154(a);
        return;
    }
    r = func_021ABE18((u8 *)(*b->s14.b));
    if (b->s14.c == 0) {
        if (b->padc == 0) {
            if (func_021C6694((u32 *)r, b->h10, 0x1000) == 0) {
                b->padc = 1;
            }
        }
    } else {
        func_021C66EC((u32 *)r, b->h10, 0x1000);
    }
    if (b->s14.d != 0) {
        func_021AC1B8(b->s14.d, &v);
        v.x += b->v.x;
        v.y += b->v.y;
        v.z += b->v.z;
        func_021AC1CC(a, &v);
    }
}


void func_021AD738(int a, S *s)
{
    func_021AC1B8(a, (Vec *)(func_021C6658(func_021ABE18((u8 *)(*s->p18)), s->h10)));
}
