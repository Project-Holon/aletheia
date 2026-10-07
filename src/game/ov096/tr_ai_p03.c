/*
 * file:     tr_ai_p03.c
 * unit:     yes
 * function: func_0218871C, func_0218872C, func_0218873C, func_0218874C, func_0218875C, func_0218878C, func_021887B4, func_021887C4, func_021887D4
 * address:  0x0218871C
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
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_0201134C  0x0201134C  thumb
 *   func_021887F4 0x021887F4 thumb ov096
 */
#include "../../matched/include/Obj21916.h"
#include "../../matched/include/Obj21917.h"
#include "../../matched/include/Obj21918.h"
#include "../../matched/include/Obj21919.h"
#include "../../matched/include/Obj07919.h"
#include "../../matched/include/Obj21920.h"
#include "../../matched/include/Obj21921.h"
#include "../../matched/include/Obj21922.h"

struct Cursor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32;

typedef enum { Z0 } E;

extern u32 func_0201134C(struct Cursor *p);
extern u32 func_0203F0A8(void);
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);
extern int func_021887F4(struct Cursor *a, int b, int c);
int func_0218871C(struct Cursor *p, int q);
int func_0218872C(struct Cursor *a, u8 *b);
int func_0218873C(struct Cursor *a, u8 *b);
int func_0218874C(struct Cursor *a, u8 *b);
int func_0218875C(struct Cursor *a, int unused, int c);
int func_0218878C(struct Cursor *a, u8 *b);
int func_021887B4(struct Cursor *a, int b);
int func_021887C4(struct Cursor *a, int b);
int func_021887D4(struct Cursor *a, int b);

int func_0218871C(struct Cursor *p, int q)
{
    func_0218875C(p, q, 0);
    return ((struct Obj21916 *)q)->fC4;
}

int func_0218872C(struct Cursor *a, u8 *b)
{
    func_0218875C(a, (int)b, 1);
    return ((struct Obj21917 *)b)->fC4;
}

int func_0218873C(struct Cursor *a, u8 *b)
{
    func_0218875C(a, (int)b, 2);
    return ((struct Obj21918 *)b)->fC4;
}

int func_0218874C(struct Cursor *a, u8 *b)
{
    func_0218875C(a, (int)b, 3);
    return ((struct Obj21919 *)b)->fC4;
}


/*
 * Two levers closed this: (1) the third argument's zero is an enum-typed
 *   value (`typedef enum { Z0 } E; z = Z0;`) so mwcc does not fold
 *   `(v >> 24) | (z << 8)`; the operand order must put the shift second so
 *   its register is the accumulator (`lsls r2` + `orrs r2,r4`).  (2) the
 *   twice-called helper is 0x0201134C, not the 0x02011324 the old name
 *   implied.
 */
int func_0218875C(struct Cursor *a, int unused, int c) {
    u8 *p;
    u32 v;
    int r;
    E z;
    p = (u8 *)func_0201134C(a);
    r = (int)func_0201134C(a);
    v = func_0203F0A8();
    z = Z0;
    return func_0218A0F4((u8 *)a, c, ((v >> 24) | (z << 8)), (int)p, r);
}

int func_0218878C(struct Cursor *a, u8 *b)
{
    u32 value;
    value = func_0201134C(a);
    *(u32 *)((u32)b + 4 + b[1] * 4) += value;
    if (*(int *)((u32)b + 4 + b[1] * 4) < 0)
        *(int *)((u32)b + 4 + b[1] * 4) = 0;
    return ((struct Obj07919 *)b)->fC4;
}

int func_021887B4(struct Cursor *a, int b)
{
    func_021887F4(a, b, 0);
    return ((struct Obj21920 *)((unsigned int)b))->fC4;
}

int func_021887C4(struct Cursor *a, int b)
{
    func_021887F4(a, b, 1);
    return ((struct Obj21921 *)((unsigned int)b))->fC4;
}

int func_021887D4(struct Cursor *a, int b)
{
    func_021887F4(a, b, 2);
    return ((struct Obj21922 *)((unsigned int)b))->fC4;
}
