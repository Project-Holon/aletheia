/*
 * file:     btlv_effvm_p83.c
 * unit:     yes
 * function: func_02201CA4, func_02201CD0, func_02201D5C
 * address:  0x02201CA4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B454  0x0204B454  arm
 *   func_02201E04  0x02201E04  thumb  ov094
 *   func_02201F98  0x02201F98  thumb  ov094
 *   func_02201FD8  0x02201FD8  thumb  ov094
 *   func_02201FF4  0x02201FF4  thumb  ov094
 *   func_0220203C  0x0220203C  thumb  ov094
 */
#include "../../matched/include/Obj07895.h"

struct Obj;
struct Actor;
struct PtS;
typedef struct Ent { void *h8; void *hc; void *h10; void *h14; } Ent;

typedef struct Res { void *owner; void *h; Ent e[7]; } Res;

typedef unsigned int   u32;

typedef short s16;

typedef struct {
    int x, y, z;
} Vec;

typedef unsigned short u16;

extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_02201F98(void *a, void *b);
extern void func_02201FD8(void *a);
extern void func_02201E04(void *o, int idx, int c, Vec *v, Vec *w, int s1, int s2, int s3,
                          void (*f1)(void *, void *), void (*f2)(void *));
extern void func_02201FF4(void *a, void *b);
extern void func_0220203C(void *a);
void func_02201CA4(Res *r, int i);
void func_02201CD0(char *o, int idx, int c, s16 *p, int s1, int s2, int s3);
void func_02201D5C(char *o, int idx, int c, void *d, int s1, int s2, int s3);


void func_02201CA4(Res *r, int i)
{
    func_0204A8D4((u32)r->e[i].hc);
    func_0204ADA4((u32)r->e[i].h10);
    func_0204AFD8((u32)r->e[i].h14);
    func_0204B3B4(r->e[i].h8);
    r->e[i].h8 = 0;
}


void func_02201CD0(char *o, int idx, int c, s16 *p, int s1, int s2, int s3)
{
    Vec b;
    Vec a;
    s16 t[2];

    a.x = p[0] << 12;
    a.y = p[1] << 12;
    a.z = 0;
    func_0204B454(*(void **)(o + idx * 16 + 8), (struct PtS *)t, 0);
    b.x = t[0] << 12;
    b.y = t[1] << 12;
    b.z = 0;
    if (c == 1) {
        a.x += b.x;
        a.y += b.y;
        a.z += b.z;
    }
    func_02201E04(o, idx, c, &b, &a, s1, s2, s3, func_02201F98, func_02201FD8);
    ((struct Obj07895 *)o)->f78 |= 1 << idx;
}


/*
 * lever: a brace-initialised Vec local compiles to an @N rodata template; three field stores do not.
 */
void func_02201D5C(char *o, int idx, int c, void *d, int s1, int s2, int s3)
{
    Vec v;

    v.x = 0x1000;
    v.y = 0x1000;
    v.z = 0x1000;

    func_02201E04(o, idx, c, &v, d, s1, s2, s3, func_02201FF4, func_0220203C);
    ((struct Obj07895 *)o)->f7C |= 1 << idx;
}
