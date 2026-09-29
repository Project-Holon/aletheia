/*
 * function: func_021AD6B8
 * address:  0x021AD6B8
 * packet:   pkt_ov021_021AD6B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6694  0x021C6694  thumb  ov021
 *   func_021C66EC  0x021C66EC  thumb  ov021
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
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

extern void func_021AC154(int a);
extern int func_021ABE18(int a);
extern int func_021C6694(int a, int b, int c);
extern void func_021C66EC(int a, int b, int c);
extern void func_021AC1B8(int a, Vec *v);
extern void func_021AC1CC(int a, Vec *v);

void func_021AD6B8(int a, Obj *b)
{
    Vec v;
    int r;

    if (b->padc == 1 && b->s14.a == 1) {
        func_021AC154(a);
        return;
    }
    r = func_021ABE18(*b->s14.b);
    if (b->s14.c == 0) {
        if (b->padc == 0) {
            if (func_021C6694(r, b->h10, 0x1000) == 0) {
                b->padc = 1;
            }
        }
    } else {
        func_021C66EC(r, b->h10, 0x1000);
    }
    if (b->s14.d != 0) {
        func_021AC1B8(b->s14.d, &v);
        v.x += b->v.x;
        v.y += b->v.y;
        v.z += b->v.z;
        func_021AC1CC(a, &v);
    }
}
