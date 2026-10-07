/*
 * file:     btlv_effvm_p43.c
 * unit:     yes
 * function: func_021FBE28, func_021FBE60, func_021FBE74, func_021FBE90
 * address:  0x021FBE28
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
 *   func_021F7F1C 0x021F7F1C thumb ov094
 *   func_020113B0 0x020113B0 thumb
 *   func_021FDBB0 0x021FDBB0 thumb ov094
 */
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj21679.h"
#include "../../matched/include/Obj13594.h"
#include "../../matched/include/Obj13595.h"
#include "../../matched/include/Obj21680.h"

struct Cursor;
struct Cur;
typedef unsigned int   u32;

typedef struct {
    unsigned f0_lo : 13;
    unsigned f0_b13 : 1;
    unsigned f0_b14 : 1;
    unsigned f0_b15 : 1;
    unsigned f0_hi : 16;
    char pad[0x244];
    char f248;
    char f249;
    char f24a;
    char f24b;
    int f24c;
    int f250;
    short f254;
    char pad2[0x284 - 0x256];
    int f284;
    char pad3[0x2a0 - 0x288];
    int f2a0;
} State;

extern unsigned int func_0201134C(struct Cursor *p);
extern int func_021F7F1C(int);
extern void func_020113B0(struct Cur *c, u32 v);
extern int func_021FDBB0(char *, int);
int func_021FBE28(struct Cursor *a, char *s);
int func_021FBE60(void *a, char *s);
int func_021FBE74(void *a, char *s);
int func_021FBE90(struct Cursor *a, State *s);


/*
 * Script command: relative jump when func_021F7F1C(x) equals y.
 */
int func_021FBE28(struct Cursor *a, char *s)
{
    int x = func_0201134C(a);
    int y = func_0201134C(a);
    int off = func_0201134C(a);

    if (y == func_021F7F1C(x))
        func_020113B0((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + off);
    return ((struct Obj21679 *)s)->f23C;
}


/*
 * Script command: stores one argument at 4 of the state.
 */
int func_021FBE60(void *a, char *s)
{
    ((struct Obj13594 *)s)->f4 = func_0201134C(a);
    return ((struct Obj13594 *)s)->f23C;
}


/*
 * Script command: stores func_021FDBB0(s, arg) at 4 of the state.
 */
int func_021FBE74(void *a, char *s)
{
    ((struct Obj13595 *)s)->f4 = func_021FDBB0(s, func_0201134C(a));
    return ((struct Obj13595 *)s)->f23C;
}


int func_021FBE90(struct Cursor *a, State *s)
{
    int sel = func_0201134C(a);
    int v = func_0201134C(a);

    switch (sel) {
    case 9:
        s->f248 = v;
        break;
    case 10:
        s->f249 = v;
        break;
    case 11:
        s->f24a = v;
        break;
    case 12:
        s->f24b = v;
        break;
    case 13:
        s->f24c = v;
        break;
    case 14:
        s->f250 = v;
        break;
    case 15:
        s->f254 = v;
        break;
    case 0x35:
        s->f0_b13 = v;
        break;
    case 0x36:
        s->f284 = v;
        break;
    case 0x37:
        s->f2a0 = v;
        break;
    case 0x38:
        s->f0_b15 = v;
        break;
    }
    return ((struct Obj21680 *)s)->f23C;
}
