/*
 * function: func_02189640
 * address:  0x02189640
 * packet:   pkt_ov096_02189640
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_0201134C  0x0201134C  thumb
 */
#include "../include/Obj21968.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct Cursor;
extern u32 func_0201134C(struct Cursor *p);
struct Unk021D62A8;
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);

int func_02189640(struct Cursor *a, int b, int c) {
    int r;
    int t;
    r = func_0201134C(a);
    t = func_021D62C4((struct Unk021D62A8 *)(*(u8 * *)&((struct Obj21968 *)b)->fC0), 0xb);
    return func_0218A0F4((u8 *)a, c, t, 1, r);
}
