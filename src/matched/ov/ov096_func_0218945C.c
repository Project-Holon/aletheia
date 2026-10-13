/*
 * function: func_0218945C
 * address:  0x0218945C
 * packet:   pkt_ov096_0218945C
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   VM_GetU32  0x0201134C  thumb
 */
#include "../include/Obj13661.h"

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
struct UtilWork;
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);

int func_0218945C(struct Cursor *a, int b) {
    int t;
    u8 s;
    int r;
    t = VM_GetU32(a);
    s = func_0218A160((u8 *)b, t);
    t = (int)func_0218A2FC((u8 *)b, s);
    r = 0;
    if (BTL_POKEPARAM_TestContFlag((struct UtilWork *)t, 0) == 0) {
        r = 1;
    }
    ((struct Obj13661 *)b)->f38 = r;
    return ((struct Obj13661 *)b)->fC4;
}
