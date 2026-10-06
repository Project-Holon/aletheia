/*
 * function: func_021F97E4
 * address:  0x021F97E4
 * packet:   pkt_ov094_021F97E4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Releases the owner's buffer at 0x1e8 after func_021FC448.
 *
 * symbols:
 *   func_02011324 0x02011324 thumb
 *   func_021FC448 0x021FC448 thumb ov094
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj10136.h"
struct ScriptVm;
extern void *func_02011324(struct ScriptVm *vm);
extern void func_021FC448(void *, char *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_021F97E4(void *a)
{
    char *s = func_02011324(a);

    if (((struct Obj10136 *)s)->f1E8 != 0) {
        func_021FC448(a, func_02011324(a));
        func_020307B0(((struct Obj10136 *)s)->f1E8);
        ((struct Obj10136 *)s)->f1E8 = 0;
    }
}
