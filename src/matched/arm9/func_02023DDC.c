/*
 * function: func_02023DDC
 * address:  0x02023DDC
 * packet:   pkt_02023DDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 */
#include "../include/Obj04734.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


struct Node;
extern void func_02023C3C(u32 x2, u32 y2, u32 x1, u32 y1, int win, int sub);
extern void func_02030EAC(struct Node *n);

void func_02023DDC(void *a0, short *a1)
{
    func_02023C3C(a1[0], a1[1], a1[2], a1[3],
                  ((struct Obj04734 *)a1)->f8, ((struct Obj04734 *)a1)->fC);
    func_02030EAC(a0);
}
