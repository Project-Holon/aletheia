/*
 * function: func_0218A034
 * address:  0x0218A034
 * packet:   pkt_ov096_0218A034
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   VM_Jump  0x020113B0  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_021C82F4  0x021C82F4  thumb  ov093
 */
#include "../include/Obj00005.h"
#include "../include/Obj13671.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct Cursor;
extern u32 func_0201134C(struct Cursor *p);
struct Cur;
extern void VM_Jump(struct Cur *c, u32 v);
extern u8 func_0218A160(u8 *, int);
extern int func_021C82F4(int, int, int);

int func_0218A034(struct Cursor *a, u8 *b)
{
    int t;
    int n;
    t = func_0201134C(a);
    n = func_0201134C(a);
    if (func_021C82F4(((struct Obj13671 *)b)->fB4, func_0218A160(b, t), 3) != 0)
        VM_Jump((struct Cur *)a, (u32)(*(u8 * *)&((struct Obj00005 *)a)->f14 + n));
    return ((struct Obj13671 *)b)->fC4;
}
