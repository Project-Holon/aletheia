/*
 * file:     unit_020746C4_p04.c
 * function: func_0207482C
 * address:  0x0207482C
 * packet:   pkt_02074770
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../../matched/include/Obj07066.h"

typedef unsigned char u8; typedef unsigned int u32;

struct DList;
extern unsigned int func_02061124(char *p, int n, int v);
extern void *func_0206062C(struct DList *list, void *elem);
extern void func_020604AC(u32, u32);

u32 func_0207482C(u32 *a, u32 b, u32 c, u32 d, u32 e) {
    u32 t;
    u32 r = func_02061124((char *)(*a), ((b + 0x1f) & ~0x1fu) + 0x20, 0x20);
    if (r == 0) return 0;
    t = (u32)func_0206062C((struct DList *)(a + 1), 0);
    ((struct Obj07066 *)r)->f8 = b;
    ((struct Obj07066 *)r)->fC = c;
    ((struct Obj07066 *)r)->f10 = d;
    ((struct Obj07066 *)r)->f14 = e;
    func_020604AC(t, r);
    return r + 0x20;
}
