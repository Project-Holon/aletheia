/*
 * file:     unit_021F5620_p02.c
 * unit:     yes
 * function: func_021F5748, func_021F57D4
 * address:  0x021F5748
 * region:   ov078
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF560  0x021CF560  thumb  ov021
 *   func_021F5950  0x021F5950  thumb  ov078
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_021CF51C 0x021CF51C thumb ov021
 *   func_0207DD24 0x0207DD24 arm
 *   func_021F52D8 0x021F52D8 thumb ov075
 */
#include "../../matched/include/Obj03671.h"

struct Ctx;
struct Obj;
typedef unsigned char u8;

typedef short s16;

typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned short u16;

extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02189A08(unsigned char *p);
extern u32 func_021CF560(u32 *p);
extern int func_021F5950(u8 *p);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern u32 func_021CF51C(u32 *p);
extern void func_0207DD24(u16,int,int,int,int);
extern void func_021F52D8(u32 *);
int func_021F5748(void *task, int *st);
void func_021F57D4(void *p);


int func_021F5748(void *task, int *st)
{
    u8 *w;

    w = (u8 *)func_021CF560((u32 *)func_02189A08((unsigned char *)((int)func_0201210C(func_020124E4(task)))));
    switch (*st) {
    case 0:
        if (((struct Obj03671 *)w)->f19D8 != 0) {
            (((struct Obj03671 *)w)->f19D8)--;
        } else if (((struct Obj03671 *)w)->f19DC == 0) {
            func_0204E720(((struct Obj03671 *)w)->f19D4, 0, 0x10, 0);
            ((struct Obj03671 *)w)->f19DC = 1;
        }
        if (func_021F5950(w) != 0) {
            ((struct Obj03671 *)w)->f19C8 = 6;
            (*st)++;
        }
        break;
    case 1:
        if (((struct Obj03671 *)w)->f19C8 != 0) {
            (((struct Obj03671 *)w)->f19C8)--;
        } else if (func_0204E804() == 0) {
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * note (2026-10-04, wD2 lane07): re-verified MATCH: the only wildcard is the ov021 callee 021CF51C (no label witness). Filed src/matched/ov/ov021_func_021CF51C.c (EXACT, 4-byte accessor); it needs a manifest shard to count as a witness.
 */
void func_021F57D4(void *p) {
    u32 h = func_021CF51C(p);
    func_0207DD24(0x4210,31,0x7FFF,0,0);
    func_021F52D8((u32 *)h);
}
