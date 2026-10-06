/*
 * function: func_02189FC0
 * address:  0x02189FC0
 * packet:   pkt_ov096_02189FC0
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_020113B0  0x020113B0  thumb
 *   func_021895AC  0x021895AC  thumb  ov096
 *   func_0218A378  0x0218A378  thumb  ov096
 */
#include "../include/Obj00005.h"
#include "../include/Obj13669.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct Cursor;
extern u32 func_0201134C(struct Cursor *p);
struct Cur;
extern void func_020113B0(struct Cur *c, u32 v);
extern int func_021895AC(u8 *, u8 *);
extern int func_0218A378(u8 *, int, int);

int func_02189FC0(struct Cursor *a, u8 *b)
{
    int t;
    int u;
    int w;
    u16 *base;
    int m;
    int flag;
    t = func_0201134C(a);
    u = func_0201134C(a);
    w = func_0201134C(a);
    base = (u16 *)(*(u8 * *)&((struct Obj00005 *)a)->f14 + w);
    flag = 0;
    if (t == 0) {
        m = func_0218A378(b, ((struct Obj13669 *)b)->f2, 0x1c) * 2;
        if (m / 2 > u)
            flag = 1;
    } else {
        flag = 1;
    }
    if (flag == 1)
        return func_021895AC((u8 *)a, b);
    func_020113B0((struct Cur *)a, (u32)((u8 *)base + (base[m] | (base[m + 1] << 16))));
    return ((struct Obj13669 *)b)->fC4;
}
