/*
 * function: func_02201CD0
 * address:  0x02201CD0
 * packet:   pkt_ov094_02201CD0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B454  0x0204B454  arm
 *   func_02201E04  0x02201E04  thumb  ov094
 *   func_02201F98  0x02201F98  thumb  ov094
 *   func_02201FD8  0x02201FD8  thumb  ov094
 */
#include "../include/Obj07895.h"
typedef short s16;

typedef struct {
    int x, y, z;
} Vec;

struct Actor;
struct PtS;
typedef unsigned short u16;
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_02201F98(void *a, void *b);
extern void func_02201FD8(void *a);
extern void func_02201E04(void *o, int idx, int c, Vec *v, Vec *w, int s1, int s2, int s3,
                          void (*f1)(void *, void *), void (*f2)(void *));

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
