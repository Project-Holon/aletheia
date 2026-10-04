/*
 * function: func_021F3844
 * address:  0x021F3844
 * packet:   pkt_ov052_021F3844
 * region:   ov052
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_021ABE30  0x021ABE30  thumb  ov021
 *   d_021F3AC0     0x021F3AC0  data  ov052  a4
 */
#include "../include/Obj13111.h"

extern int func_02188CD0(int);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021ABE30(int, int *, int);
extern char d_021F3AC0[];

void func_021F3844(char *a, int b)
{
    int n;
    int r4 = func_02188CD0(b);

    ((struct Obj13111 *)a)->f24 = func_02030734(((struct Obj13111 *)a)->fC, 4, 1, d_021F3AC0, 0x112);
    n = 0xe;
    func_021ABE30(r4, &n, 1);
}
