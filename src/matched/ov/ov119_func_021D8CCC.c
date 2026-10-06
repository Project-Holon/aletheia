/*
 * function: func_021D8CCC
 * address:  0x021D8CCC
 * packet:   pkt_021D8B54
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B454  0x0204B454  arm
 *   func_02035CB8  0x02035CB8  arm
 *   func_021E4AB8  0x021E4AB8  thumb  ov119
 *   func_021E64DC  0x021E64DC  thumb  ov119
 */
#include "../include/Obj00001.h"

typedef signed short s16;

struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *, struct PtS *, unsigned int);
typedef unsigned int   u32;
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern void func_021E4AB8(int a0, int a1, int a2);
extern void func_021E64DC(int p, int i, int j, int x, int y, void *q);

void func_021D8CCC(void *p, int x, int y, int z, int a4)
{
    int o1, o2;

    ((struct Obj00001 *)p)->fF60 = x;
    func_0204B454((struct Actor *)x, (struct PtS *)((char *)p + 0xf64), 1);
    func_021E4AB8((int)p, ((struct Obj00001 *)p)->fF60, 1);
    if (func_02035CB8((u32 *)(&o1), (u32 *)(&o2)) == 0)
        return;
    ((struct Obj00001 *)p)->fF68 = (s16)((struct Obj00001 *)p)->fF64 - o1;
    ((struct Obj00001 *)p)->fF6A = (s16)((struct Obj00001 *)p)->fF66 - o2;
    func_021E64DC((int)p, y, z,
                  o1 + (s16)((struct Obj00001 *)p)->fF68,
                  o2 + (s16)((struct Obj00001 *)p)->fF6A,
                  (void *)a4);
    ((struct Obj00001 *)p)->fF60 = ((struct Obj00001 *)p)->fF20;
}
