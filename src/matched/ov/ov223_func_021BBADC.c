/*
 * function: func_021BBADC
 * address: 0x021BBADC
 * packet: pkt_ov223_021BBADC
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Trailing BB26 halfword is zero alignment padding.
 * symbols:
 *   func_021B9914 0x021B9914 thumb ov223
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 * The original visibly supplies the frame in r1 to 9914 even though its
 * full body reads only its entry r0; preserve that caller input.
 */
#include "../include/Obj01594.h"
extern void func_021B9914(void *, unsigned);
extern void func_0204E720(unsigned, int, int, int);
extern int func_0204E804(void);
int func_021BBADC(char *p, int *state)
{
    if (*(unsigned *)&((struct Obj01594 *)p)->f10 >= 1)
        func_021B9914(p, *(unsigned *)&((struct Obj01594 *)p)->f10);
    switch (*state) {
    case 0:
        func_0204E720(3, 16, 0, 0);
        (*state)++;
        break;
    case 1:
        if (func_0204E804() == 0) {
            ((struct Obj01594 *)p)->f10 = 0;
            return 4;
        }
        break;
    }
    (((struct Obj01594 *)p)->f10)++;
    return 3;
}
