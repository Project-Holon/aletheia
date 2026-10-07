/*
 * file:     shinka_demo_p06.c
 * unit:     yes
 * function: func_02205384, func_022053E8, func_0220546C
 * address:  0x02205384
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0220549C 0x0220549C thumb ov195
 *   func_02205620 0x02205620 thumb ov195
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CD10 0x0201CD10 thumb
 *   func_0203630C  0x0203630C  arm
 *   func_02035C38  0x02035C38  arm
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_020355D8  0x020355D8  arm
 */
#include "../../matched/include/Obj01429.h"
#include "../../matched/include/Obj10819.h"

struct Rec;
typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short   s16;

typedef signed int     s32;

typedef unsigned char  u8;

extern void func_0220549C(char *, int);
extern u32 func_02205620(u32, u32, u32, u32, u32, u32, u32);
extern signed char func_02012FFC(void);
extern struct Rec *func_0201CD10(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern u32 func_0201CE30(void *p);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201CE38(void *p);
extern void func_020061E4(u32 a);
extern unsigned int func_0203630C(void);
extern int func_02035C38(void);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_020355D8(u8 v);
void func_02205384(char *a, u32 b, u32 c, u32 d, u32 k0, u32 v0, u32 k1, u32 v1);
int func_022053E8(char *a);
int func_0220546C(void);


void func_02205384(char *a, u32 b, u32 c, u32 d, u32 k0, u32 v0, u32 k1, u32 v1)
{
    func_0220549C(a, 0xf);
    *(u32 *)&((struct Obj01429 *)a)->f80 = func_02205620(((struct Obj01429 *)a)->f2, b, c, k0, v0, k1, v1);
    *(u32 *)&((struct Obj01429 *)a)->f64 = (u32)func_0201CD10(*(u32 *)&((struct Obj01429 *)a)->f6C, 0, 0, *(u32 *)&((struct Obj01429 *)a)->f80, ((struct Obj01429 *)a)->f8,
                                       func_02012FFC(), ((struct Obj01429 *)a)->f68, 2, ((struct Obj01429 *)a)->f2, 0xf, d);
}


/*
 * The `(x & 3) != 0 ? 0 : 1` call arguments must be written as an explicit
 * if/else. The ternary makes mwccarm pick the opposite branch polarity and
 * then colour the pointer r5/result r4 the other way; the if/else gives the
 * original pointer r4 / result r5 split and the shared return. See
 * docs/idioms/a-ternary-constant-call-argument-takes-the-opposite-branch-polarity.md.
 */
int func_022053E8(char *a)
{
    int r = 0;

    switch (func_0201CE30((void *)(((struct Obj10819 *)a)->f64))) {
    case 0:
        if ((func_0203630C() & 3) != 0 || func_02035C38() != 0) {
            func_0201CE5C((struct Rec *)(((struct Obj10819 *)a)->f64), 0);
            if ((func_0203630C() & 3) != 0)
                func_020355D8(0);
            else
                func_020355D8(1);
        }
        break;
    case 1:
        if ((func_020362DC() & 3) != 0 || func_02035C60() != 0) {
            func_020061E4(0x547);
            func_0201CE38((void *)(((struct Obj10819 *)a)->f64));
            if ((func_020362DC() & 3) != 0)
                func_020355D8(0);
            else
                func_020355D8(1);
        }
        break;
    case 2:
        r = 1;
        break;
    }
    return r;
}


/*
 * Leaf of the func_022040E0 dependency tree: a confirm gate.  True once the
 * action key is held (func_020362DC & 3) or the touch probe fires; it hands
 * the pressed/released flag to func_020355D8.  The two arms must be separate
 * call statements, not a selected value: only then does mwccarm tail-merge
 * them with the original's `beq`-to-true orientation.
 */
int func_0220546C(void)
{
    if ((func_020362DC() & 3) != 0 || func_02035C60() != 0) {
        if ((func_020362DC() & 3) != 0)
            func_020355D8(0);
        else
            func_020355D8(1);
        return 1;
    }
    return 0;
}
