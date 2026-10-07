/*
 * file:     unit_06899CDC.c
 * unit:     yes
 * function: func_06899CDC, func_06899D04
 * address:  0x06899CDC
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0220266C 0x0220266C thumb ov094
 *   func_06899D1C 0x06899D1C thumb ov095
 */
#include "../../matched/include/Obj07908.h"
#include "../../matched/include/Obj21884.h"

struct Obj;
typedef signed char s8;

typedef unsigned int u32;

extern void func_0220266C(struct Obj *p);
extern int func_06899D1C(u32);
void func_06899CDC(const s8 *p);
int func_06899D04(u32 p);

/*
 * note: const source parameter allows pointee load before final byte store;
 *       veneer extent follower, function_starts seed 06899CDC.
 */
void func_06899CDC(const s8 *p)
{
    ((struct Obj07908 *)p)->f8C = -16;
    ((struct Obj07908 *)p)->f8D = 0;
    ((struct Obj07908 *)p)->f8E = 1;
    func_0220266C((struct Obj *)(*(const u32 *)&((struct Obj07908 *)p)->fB0));
}

/*
 * note: trailing two-byte alignment padding.
 */
int func_06899D04(u32 p)
{
    if (func_06899D1C(((struct Obj21884 *)p)->fB0) == 0) return 1;
    return 0;
}
