/*
 * function: func_021EC94C
 * address: 0x021EC94C
 * packet: pkt_ov170_021EC94C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _ffix 0x0209C494 arm
 *   func_0204B570 0x0204B570 arm
 *   func_0204B5AC 0x0204B5AC arm
 *   func_0204B588 0x0204B588 arm
 */
#include "../include/Obj04546.h"
typedef unsigned int   u32;
struct Actor;
extern void func_0204B570(struct Actor *actor, u32 value);
extern void func_0204B5AC(void *, int *);
struct Pt;
extern void func_0204B588(struct Actor *actor, const struct Pt *src);
void func_021EC94C(char *p)
{
    int pair[2];
    unsigned short shape[2];
    *(float *)(p + 8) = 4096.0f;
    p[7] = 0;
    func_0204B570(((struct Obj04546 *)p)->f0, 1);
    pair[0] = (int)*(float *)(p + 8);
    pair[1] = (int)*(float *)(p + 8);
    func_0204B5AC(((struct Obj04546 *)p)->f0, pair);
    shape[0] = 0;
    shape[1] = 8;
    func_0204B588(((struct Obj04546 *)p)->f0, (const struct Pt *)shape);
}
