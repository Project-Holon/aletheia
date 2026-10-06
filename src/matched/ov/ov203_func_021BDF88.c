/*
 * function: func_021BDF88
 * address:  0x021BDF88
 * packet:   pkt_021BDF88
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207CDB8 0x0207CDB8 arm
 *   func_02048CA4 0x02048CA4 arm
 */
#include "../include/Obj25310.h"

extern void func_0207CDB8(int, void *);
typedef unsigned int   u32;
struct LightSlot;
struct Rgb555;
extern void func_02048CA4(struct LightSlot *slots, u32 i, struct Rgb555 *in);

void func_021BDF88(char *p, int a, int b)
{
    int buf[2];
    func_0207CDB8(b, buf);
    func_02048CA4(((struct Obj25310 *)p)->fC, a, (struct Rgb555 *)buf);
}
