/*
 * file:     tr_ai_p06.c
 * unit:     yes
 * function: func_02188B64, func_02188BB0, func_02188C1C, func_02188C88
 * address:  0x02188B64
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
 *   func_0201134C  0x0201134C  thumb
 *   func_020113B0  0x020113B0  thumb
 *   func_0218A378  0x0218A378  thumb  ov096
 *   func_021D5448  0x021D5448  thumb  ov093
 *   func_021D54C0  0x021D54C0  thumb  ov093
 *   func_021C8138 0x021C8138 thumb ov093
 */
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj10175.h"
#include "../../matched/include/Obj10176.h"

struct Cursor;
struct Cur;
struct QG;
struct Q7;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 pad00[0xbc];
    u8 *fbc;
    u8 padC0[4];
    int fc4;
} Conn;

extern u32 func_0201134C(struct Cursor *p);
extern void func_020113B0(struct Cur *c, u32 v);
extern int func_0218A378(Conn *, int, int);
extern u8 func_021D5448(struct QG *p);
extern u16 func_021D54C0(u8 *p, int i);
extern unsigned short func_021C8138(struct Q7 *);
int func_02188B64(struct Cursor *a, int b);
int func_02188BB0(struct Cursor *a, Conn *b);
int func_02188C1C(struct Cursor *a, Conn *b);
int func_02188C88(int a, unsigned char *b);


int func_02188B64(struct Cursor *a, int b)
{
    u16 *p;
    int m;
    int i;
    int v;

    p = (u16 *)(*(int *)&((struct Obj00005 *)a)->f14 + func_0201134C(a));
    m = func_0201134C(a);
    i = 0;
    do {
        v = p[i] | (p[i + 1] << 16);
        if (((struct Obj10175 *)b)->f38 == v)
            return ((struct Obj10175 *)b)->fC4;
        i += 2;
    } while (v != -1);
    func_020113B0((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + m);
    return ((struct Obj10175 *)b)->fC4;
}


/*
 * Lever: b is a pointer to a Conn struct (fields fbc, fc4) so the b+0xbc
 *   address is not CSE'd across the calls (the original re-adds it each time);
 *   func_0218A378's second parameter is int (no truncation before the bl).
 */
int func_02188BB0(struct Cursor *a, Conn *b)
{
    int m;
    int i;

    m = func_0201134C(a);
    for (i = 0; i < func_021D5448((struct QG *)b->fbc); i++) {
        if (func_0218A378(b, func_021D54C0(b->fbc, (u8)i), 3) != 0)
            break;
    }
    if (i < func_021D5448((struct QG *)b->fbc))
        func_020113B0((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + m);
    return b->fc4;
}


/*
 * Lever: as func_02188BB0 (Conn struct pointer, int second parameter).
 */
int func_02188C1C(struct Cursor *a, Conn *b)
{
    int m;
    int i;

    m = func_0201134C(a);
    for (i = 0; i < func_021D5448((struct QG *)b->fbc); i++) {
        if (func_0218A378(b, func_021D54C0(b->fbc, (u8)i), 3) != 0)
            break;
    }
    if (i == func_021D5448((struct QG *)b->fbc))
        func_020113B0((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + m);
    return b->fc4;
}

int func_02188C88(int a, unsigned char *b) { ((struct Obj10176 *)b)->f38=func_021C8138(*(struct Q7 * *)&((struct Obj10176 *)b)->fB4); return ((struct Obj10176 *)b)->fC4; }
