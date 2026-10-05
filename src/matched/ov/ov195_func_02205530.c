/*
 * function: func_02205530
 * address:  0x02205530
 * packet:   pkt_02205530
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_02205A28 0x02205A28 thumb ov195
 *   func_021B6DC0 0x021B6DC0 thumb ov067
 */
#include "../include/Obj03344.h"

typedef unsigned short u16;
typedef unsigned int u32;

struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern int func_02205A28(char *a);
extern u32 func_021B6DC0(u16, int, int, int, int, u32, u32, u32, int);

void func_02205530(int a, char *b)
{
    ((struct Obj03344 *)b)->f90 = (u32)func_02045B38(0, 2, 0xe9, ((struct Obj03344 *)b)->f2);
    ((struct Obj03344 *)b)->f9C = func_021B6DC0(((struct Obj03344 *)b)->f2, 5, 0, 1, 0, func_02205A28((char *)(((struct Obj03344 *)b)->f4)),
                                       ((struct Obj03344 *)b)->f8, ((struct Obj03344 *)b)->fC, 0);
    ((struct Obj03344 *)b)->f94 = 0;
    ((struct Obj03344 *)b)->f98 = 0;
}
