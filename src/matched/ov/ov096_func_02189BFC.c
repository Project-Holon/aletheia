/*
 * function: func_02189BFC
 * address:  0x02189BFC
 * packet:   pkt_ov096_02189BFC
 * region:   ov096
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   VM_Jump  0x020113B0  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_0218A390  0x0218A390  thumb  ov096
 *   BTL_POKEPARAM_GetLastUsedMoveId  0x021D67A8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021C7E14  0x021C7E14  thumb  ov093
 */
#include "../include/Obj00005.h"
#include "../include/Obj06344.h"

typedef unsigned char u8;
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *p);
typedef unsigned short u16;
typedef unsigned int   u32;
struct Cur;
struct QL;
extern void VM_Jump(struct Cur *c, u32 v);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern u32 func_0218A390(u8 *a, u8 *b, u8 *c, int d);
extern u16 BTL_POKEPARAM_GetLastUsedMoveId(struct QL *p);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u16 func_021C7E14(u8 *p, int a, int b, u32 c, int e0, int e1);

int func_02189BFC(struct Cursor *a, int b)
{
    int t0;
    int t1;
    int t2;
    u8 *v;
    unsigned int w;
    int x;
    int y;
    int z;
    unsigned int r;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    t2 = VM_GetU32(a);
    v = func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, t0));
    w = func_0218A390((u8 *)b, *(u8 * *)&((struct Obj06344 *)b)->fBC, *(u8 * *)&((struct Obj06344 *)b)->fC0, t1);
    x = BTL_POKEPARAM_GetLastUsedMoveId((struct QL *)v);
    y = BTL_POKEPARAM_GetPokeId(v);
    z = BTL_POKEPARAM_GetPokeId(*(u8 * *)&((struct Obj06344 *)b)->fC0);
    r = func_021C7E14((u8 *)(((struct Obj06344 *)b)->fB4), y, z, x, 1, t1);
    if (w < r)
        VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + t2);
    return ((struct Obj06344 *)b)->fC4;
}
