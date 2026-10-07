/*
 * file:     tr_ai_p12.c
 * unit:     yes
 * function: func_0218945C, func_0218948C
 * address:  0x0218945C
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
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_0201134C  0x0201134C  thumb
 *   func_021D69AC  0x021D69AC  thumb  ov093
 */
#include "../../matched/include/Obj13661.h"

struct Cursor;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32;

typedef struct {
    u8 pad00[0x38];
    int f38;
    u8 pad3C[0x98 - 0x3c];
    int f98;
    int f9c;
    u8 padA0[0xc4 - 0xa0];
    int fc4;
} Conn;

extern u32 func_0201134C(struct Cursor *p);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern unsigned char func_021D69AC(unsigned char *base, int idx);
int func_0218945C(struct Cursor *a, int b);
int func_0218948C(struct Cursor *a, Conn *b);
int func_021894B4(int a, Conn *b);
int func_021894C4(int a, Conn *b);


int func_0218945C(struct Cursor *a, int b) {
    int t;
    u8 s;
    int r;
    t = func_0201134C(a);
    s = func_0218A160((u8 *)b, t);
    t = (int)func_0218A2FC((u8 *)b, s);
    r = 0;
    if (func_021D5BDC((struct UtilWork *)t, 0) == 0) {
        r = 1;
    }
    ((struct Obj13661 *)b)->f38 = r;
    return ((struct Obj13661 *)b)->fC4;
}


/*
 * func_021894B4 and func_021894C4 are the unlabelled store-and-return stubs
 * after the lead function (function_starts seeds).
 */
int func_0218948C(struct Cursor *a, Conn *b)
{
    b->f38 = func_021D69AC(func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, func_0201134C(a))), 0);
    return b->fc4;
}


int func_021894B4(int a, Conn *b)
{
    b->f38 = b->f98;
    return b->fc4;
}


int func_021894C4(int a, Conn *b)
{
    b->f38 = b->f9c;
    return b->fc4;
}
