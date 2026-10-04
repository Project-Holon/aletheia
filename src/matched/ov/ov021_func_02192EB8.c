/*
 * function: func_02192EB8
 * address:  0x02192EB8
 * packet:   pkt_ov021_02192EB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02005C8C  0x02005C8C  thumb  arm9
 *   func_02030EAC  0x02030EAC  arm  arm9
 *   func_02194704  0x02194704  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12614.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern int func_02005C8C(void);
extern void func_02194704(u32 a);
struct Node;
extern void func_02030EAC(struct Node *n);

void func_02192EB8(u32 a, u8 *b)
{
    if (func_02005C8C() == 0) {
        func_02194704(((struct Obj12614 *)b)->f15C);
        ((struct Obj12614 *)b)->f16C = 0;
        func_02030EAC((struct Node *)a);
    }
}
