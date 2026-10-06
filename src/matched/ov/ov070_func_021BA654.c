/*
 * function: func_021BA654
 * address:  0x021BA654
 * packet:   pkt_ov070_021BA654
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02035CB8  0x02035CB8  arm
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 */
#include "../include/Obj13158.h"

typedef struct {
    unsigned short a, b;
} Pt;

typedef unsigned int   u32;
extern u32 func_02035CB8(u32 *outA, u32 *outB);
struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *actor, struct PtS *out, unsigned int space);
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);

void func_021BA654(char *p)
{
    unsigned w;
    unsigned v;
    Pt pt;
    if (func_02035CB8(&w, &v) == 1) {
        if (v < 0x1A) {
            v = 0x1A;
        } else if (v > 0x8E) {
            v = 0x8E;
        }
        func_0204B454((struct Actor *)((struct Obj13158 *)p)->f6A8, (struct PtS *)&pt, 0xFFFF);
        pt.b = v;
        func_0204B404((struct Obj *)(((struct Obj13158 *)p)->f6A8), (const struct Vec2 *)(&pt), 0xFFFF);
    }
}
