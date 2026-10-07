/*
 * file:     tr_ai_p13.c
 * unit:     yes
 * function: func_02189524, func_02189548, func_02189590, func_021895AC, func_021895C4
 * address:  0x02189524
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
 *   func_0218A378  0x0218A378  thumb  ov096
 *   func_0201134C 0x0201134C thumb
 *   func_0218A160 0x0218A160 thumb ov096
 *   func_0218A2FC 0x0218A2FC thumb ov096
 *   func_021D67A8 0x021D67A8 thumb ov093
 *   func_021D679C 0x021D679C thumb ov093
 *   func_020113B0 0x020113B0 thumb
 *   func_02011290 0x02011290 thumb
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   d_0218A580     0x0218A580  data   ov096  a4
 */
#include "../../matched/include/Obj07924.h"
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj21964.h"
#include "../../matched/include/Obj10184.h"

struct Cursor;
struct QL;
struct Cur;
struct ScriptVm;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32;

typedef struct { int a, b, c; } Tri;

extern int func_0218A378(int, u16, int);
extern u32 func_0201134C(struct Cursor *p);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern u16 func_021D67A8(struct QL *p);
extern u16 func_021D679C(u8 *p);
extern void func_020113B0(struct Cur *c, u32 v);
extern struct ScriptVm *func_02011290(struct ScriptVm *vm);
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);
extern int func_021D59B4(u8 *p, int k);
int func_02189524(int a, int b);
u32 func_02189548(struct Cursor *x, u8 *p);
int func_02189590(struct Cursor *a, u8 *b);
int func_021895AC(u8 *a, u8 *b);
int func_021895C4(struct Cursor *a, int b);
extern const Tri d_0218A580;


int func_02189524(int a, int b) {
    int t;
    if (((struct Obj07924 *)b)->f38 != 0) {
        t = func_0218A378(b, (u16)((struct Obj07924 *)b)->f38, 0x1c);
    } else {
        t = -1;
    }
    ((struct Obj07924 *)b)->f38 = t;
    return ((struct Obj07924 *)b)->fC4;
}

/*
 * 2026-10-05 (wD5 lane01): EXACT. The store is written in each arm (`p[0x38] = 0;` / `p[0x38] = f(q);`);
 *   a value local v merged at the join swapped p and q. Older notes below.
 * 2026-10-04 (wave D2 lane 08): re-tested, still DIFF (10 bytes). Whole-body swap: image p=r4 q=r5, ours p=r5 q=r4. Allocation looks priority-ordered by reference count (q has four references, p four); no source tie-break found without changing the bytes.
 * note: 2026-10-04 Residue: whole-body register swap (original p in r4, q in r5; ours p in r5, q in r4); branch layout and instructions match otherwise. First param is unused (original uses r1 as p). Tried: ternary, early store, v-first, int v, copy of p, hoisted field pointer, struct p, split index locals, || vs && with Y-first.
 * note: 2026-10-05 (wD4 lane20): tried swapped declaration order of q and v, and the nested call chain split into three statements (a = f(x); a = g(p,a); q = h(p,a)); p stays r5, q r4. Residue unchanged: whole-body p/q colour swap (10 bytes).
 */
u32 func_02189548(struct Cursor *x, u8 *p)
{
    u8 *q;
    q = func_0218A2FC(p, func_0218A160(p, func_0201134C(x)));
    if (func_021D67A8((struct QL *)q) != 0xB6 && func_021D67A8((struct QL *)q) != 0xC5 && func_021D67A8((struct QL *)q) != 0xCB)
        *(u32 *)(p + 0x38) = 0;
    else
        *(u32 *)(p + 0x38) = func_021D679C(q);
    return *(u32 *)(p + 0xC4);
}

int func_02189590(struct Cursor *a, u8 *b)
{
    u32 t; t = func_0201134C(a); func_020113B0((struct Cur *)a, *(u32 *)&((struct Obj00005 *)a)->f14 + t); return ((struct Obj21964 *)b)->fC4;
}

int func_021895AC(u8 *a, u8 *b)
{
    b[0x44] |= 1; func_02011290((struct ScriptVm *)a); return 1;
}


int func_021895C4(struct Cursor *a, int b) {
    int r6;
    int r7;
    int x;
    int y;
    Tri t;
    r6 = func_0201134C(a);
    r7 = func_0201134C(a);
    t = d_0218A580;
    x = func_021D59B4(*(u8 * *)&((struct Obj10184 *)b)->fBC, 15);
    y = func_021D59B4(*(u8 * *)&((struct Obj10184 *)b)->fC0, 15);
    func_0218A0F4((u8 *)a, ((int *)&t)[r6], x, y, r7);
    return ((struct Obj10184 *)b)->fC4;
}
