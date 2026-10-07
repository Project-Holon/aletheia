/*
 * file:     tr_ai_p11.c
 * unit:     yes
 * function: func_021893DC, func_02189400, func_02189434
 * address:  0x021893DC
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A3F4  0x0218A3F4  thumb  ov096
 *   func_021D59B4  0x021D59B4  thumb  ov093
 */
#include "../../matched/include/Obj13658.h"
#include "../../matched/include/Obj13659.h"
#include "../../matched/include/Obj13660.h"

struct Cursor;
struct QI;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32;

extern u32 func_0201134C(struct Cursor *p);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern u16 func_021D5B40(struct QI *p);
extern int func_0218A3F4(int a, int b, int c);
extern int func_021D59B4(u8 *p, int k);
int func_021893DC(struct Cursor *a, int b);
int func_02189400(struct Cursor *a, int b);
int func_02189434(struct Cursor *a, int b);


int func_021893DC(struct Cursor *a, int b) {
    int t;
    u8 s;
    t = func_0201134C(a);
    s = func_0218A160((u8 *)b, t);
    t = func_021D5B40((struct QI *)func_0218A2FC((u8 *)b, s));
    ((struct Obj13658 *)b)->f38 = t;
    return ((struct Obj13658 *)b)->fC4;
}


int func_02189400(struct Cursor *a, int b) {
    int t;
    u8 s;
    t = func_0201134C(a);
    s = func_0218A160((u8 *)b, t);
    t = func_021D5B40((struct QI *)func_0218A2FC((u8 *)b, s));
    t = func_0218A3F4(b, (u16)t, 1);
    ((struct Obj13659 *)b)->f38 = t;
    return ((struct Obj13659 *)b)->fC4;
}


int func_02189434(struct Cursor *a, int b) {
    int t;
    u8 s;
    t = func_0201134C(a);
    s = func_0218A160((u8 *)b, t);
    t = func_021D59B4(func_0218A2FC((u8 *)b, s), 0x12);
    ((struct Obj13660 *)b)->f38 = t;
    return ((struct Obj13660 *)b)->fC4;
}
