/*
 * function: func_021BBC6C
 * address: 0x021BBC6C
 * packet: pkt_ov223_021BBC6C
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9914 0x021B9914 thumb ov223
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 * Preserve the original 9914 call's visible r1=258 and r2=frame inputs;
 * the full callee body reads only entry r0.
 */
#include "../include/Obj01594.h"
extern void func_021B9914(void *, int, int);
extern void func_0204E720(unsigned, int, int, int);
extern int func_0204E804(void);
int func_021BBC6C(char *p, int *state)
{
    if (((struct Obj01594 *)p)->f50 != 258)
        func_021B9914(p, 258, ((struct Obj01594 *)p)->f50);
    switch (*state) {
    case 0:
        func_0204E720(12, 0, 16, 3);
        (*state)++;
        break;
    case 1:
        if (func_0204E804() == 0) {
            ((struct Obj01594 *)p)->f10 = 0;
            return 6;
        }
        break;
    }
    (((struct Obj01594 *)p)->f10)++;
    return 5;
}
