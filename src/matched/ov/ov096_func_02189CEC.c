/*
 * unit:     yes
 * function: func_02189CEC, func_02189D30, func_02189D38, func_02189D40
 * address:  0x02189CEC
 * packet:   pkt_ov096_02189CEC
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_02189D30, func_02189D38 and func_02189D40 are the unlabelled
 * return-field stubs after the lead function (function_starts seeds).
 * The unit ends at 0x02189D48, where the next function starts.
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_021D59B4  0x021D59B4  thumb  ov093
 */
#include "../include/Obj10192.h"
#include "../include/Obj21973.h"
#include "../include/Obj21974.h"
#include "../include/Obj21975.h"

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
extern int func_021D59B4(u8 *p, int k);

int func_02189CEC(struct Cursor *a, int b) {
    int r6;
    int r4;
    u8 s;
    u8 *t;
    int x;
    r6 = VM_GetU32(a);
    r4 = VM_GetU32(a);
    s = func_0218A160((u8 *)b, r6);
    t = func_0218A2FC((u8 *)b, s);
    x = func_021D59B4(t, r4);
    ((struct Obj10192 *)b)->f38 = x - func_021D59B4(*(u8 * *)&((struct Obj10192 *)b)->fBC, r4);
    return ((struct Obj10192 *)b)->fC4;
}

int func_02189D30(int a, int b) {
    return ((struct Obj21973 *)b)->fC4;
}

int func_02189D38(int a, int b) {
    return ((struct Obj21974 *)b)->fC4;
}

int func_02189D40(int a, int b) {
    return ((struct Obj21975 *)b)->fC4;
}
