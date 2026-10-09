/*
 * file:     unit_021E072C_p02.c
 * unit:     yes
 * function: func_021E0900, func_021E0914, func_021E0920, func_021E0944, func_021E098C, func_021E0998
 * address:  0x021E0900
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F2504     0x021F2504  data    a4
 *   func_021D6D54 0x021D6D54 thumb ov093
 *   func_021D67A8 0x021D67A8 thumb ov093
 *   func_021D67B8 0x021D67B8 thumb ov093
 *   func_021E0A64 0x021E0A64 thumb ov093
 *   func_021D5778 0x021D5778 thumb ov093
 *   func_021D70A8 0x021D70A8 thumb ov093
 *   d_021F280C     0x021F280C  data   ov093  a4
 */
#include "../../matched/include/Obj13505.h"
#include "../../matched/include/Obj06267.h"

struct S;
struct QL;
struct QQ;
struct R5;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D7B74(u8 *p, u32 k);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern int func_021D6D54(struct R5 *p);
extern u16 func_021D67A8(struct QL *p);
extern u16 func_021D67B8(u8 *p);
extern int func_021E0A64(int);
extern u8 func_021D5778(void *, int);
extern u16 func_021D70A8(struct QQ *p);
int func_021E0900(int a, int b, int c, int d, unsigned short e);
int *func_021E0914(int *p);
void func_021E0920(int a, void *b, int c, int d);
void func_021E0944(int unused, void *q, int id, int unused2);
int *func_021E098C(int *p);
void func_021E0998(void *a, void *q, int id);
extern int d_021F2504[];
extern int d_021F280C[];


/*
 * Callback passed to func_021D7320 by func_021E0818 (pool word 0x021E0901).
 * Not a worklist entry; filed as the witness for that relocation.
 */
int func_021E0900(int a, int b, int c, int d, unsigned short e)
{
    if (c == 2 && e <= 1)
        return 1;
    return 0;
}



int *func_021E0914(int *p)
{
    *p = 1;
    return d_021F2504;
}



/*
 * The call passes r3 (d) through to func_021E0944, whose own C takes three
 * parameters; the prototype here carries the fourth.
 */
void func_021E0920(int a, void *b, int c, int d)
{
    if (c == func_021D775C(2))
        func_021E0944(a, b, c, d);
}




void func_021E0944(int unused, void *q, int id, int unused2)
{
    u8 *r;
    int n;

    n = func_021D7B74(func_021C7CF4(q, id), 2);
    r = (u8 *)func_021C88A4(q, 7, id);
    r[6] = id;
    ((struct Obj13505 *)r)->f4 = n;
    func_021C8838(r + 0xc, 2, 0x386);
    func_021C8860((struct S *)(r + 0xc), id);
    func_021C88C8(q, r);
}


int *func_021E098C(int *p)
{
    *p = 1;
    return d_021F280C;
}


/*
 * lever: move stays int; the caller passes the full value to func_021D5778 without narrowing.
 */
void func_021E0998(void *a, void *q, int id)
{
    void *m;
    void *t;
    int move;
    int other;
    int slot;
    u8 *r;
    if (id == func_021D775C(3)) {
        m = func_021C7CF4(q, id);
        if (func_021D6D54(m) != 0) return;
        t = func_021C7CF4(q, (u8)func_021D775C(6));
        move = func_021D67A8(t);
        other = func_021D67B8(t);
        if (other != move) move = other;
        if (move == 0 || func_021E0A64(move) != 0 || func_021D5778(m, move) != 4) return;
        slot = func_021D5778(m, func_021D70A8(a));
        if (slot == 4) return;
        r = func_021C88A4(q, 37, id);
        r[4] = id;
        r[5] = slot;
        ((struct Obj06267 *)r)->f8 = move;
        r[6] = 0;
        r[7] = 0;
        func_021C88C8(q, r);
        r = func_021C88A4(q, 4, id);
        func_021C8838(r + 4, 2, 0x2b0);
        func_021C8860((struct S *)(r + 4), id);
        func_021C8860((struct S *)(r + 4), move);
        func_021C88C8(q, r);
    }
}
