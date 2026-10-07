/*
 * file:     btlv_effvm_p42.c
 * unit:     yes
 * function: func_021FBD34, func_021FBD44, func_021FBD88, func_021FBDD4
 * address:  0x021FBD34
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021FDBB0  0x021FDBB0  thumb  ov094
 *   func_020113B0  0x020113B0  thumb
 */
#include "../../matched/include/Obj21675.h"
#include "../../matched/include/Obj21678.h"

struct Cursor;
struct Cur;
typedef unsigned int   u32;

typedef struct {
    char pad[0x23c];
    int f23c;
} State;

extern u32 func_0201134C(struct Cursor *p);
extern int func_021FDBB0(State *s, int i);
extern void func_020113B0(struct Cur *c, u32 v);
void func_021FBD34(void *a, char *s);
int func_021FBD44(struct Cursor *a, State *s);
int func_021FBD88(struct Cursor *a, State *s);
void func_021FBDD4(int a, int b, int c, int op, int e);


/*
 * Script command: stores one argument at 0x23c of the state.
 */
void func_021FBD34(void *a, char *s)
{
    ((struct Obj21675 *)s)->f23C = func_0201134C(a);
}


int func_021FBD44(struct Cursor *a, State *s)
{
    int x = func_021FDBB0(s, func_0201134C(a));
    int op = func_0201134C(a);
    int y = func_0201134C(a);
    int z = func_0201134C(a);

    func_021FBDD4((int)a, x, y, op, z);
    return s->f23c;
}


int func_021FBD88(struct Cursor *a, State *s)
{
    int x = func_021FDBB0(s, func_0201134C(a));
    int op = func_0201134C(a);
    int y = func_021FDBB0(s, func_0201134C(a));
    int z = func_0201134C(a);

    func_021FBDD4((int)a, x, y, op, z);
    return s->f23c;
}


void func_021FBDD4(int a, int b, int c, int op, int e)
{
    int t = 0;

    switch (op) {
    case 0:
        if (b == c)
            t = 1;
        break;
    case 1:
        if (b != c)
            t = 1;
        break;
    case 2:
        if (b < c)
            t = 1;
        break;
    case 3:
        if (b > c)
            t = 1;
        break;
    case 4:
        if (b <= c)
            t = 1;
        break;
    case 5:
        if (b >= c)
            t = 1;
        break;
    }
    if (t == 1)
        func_020113B0((struct Cur *)a, ((struct Obj21678 *)a)->f14 + e);
}
