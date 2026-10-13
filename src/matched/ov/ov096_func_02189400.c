/*
 * function: func_02189400
 * address:  0x02189400
 * packet:   pkt_ov096_02189400
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_0218A3F4  0x0218A3F4  thumb  ov096
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   VM_GetU32  0x0201134C  thumb
 */
#include "../include/Obj13659.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern int func_0218A3F4(int a, int b, int c);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);

int func_02189400(struct Cursor *a, int b) {
    int t;
    u8 s;
    t = VM_GetU32(a);
    s = func_0218A160((u8 *)b, t);
    t = BTL_POKEPARAM_GetItem((struct QI *)func_0218A2FC((u8 *)b, s));
    t = func_0218A3F4(b, (u16)t, 1);
    ((struct Obj13659 *)b)->f38 = t;
    return ((struct Obj13659 *)b)->fC4;
}
