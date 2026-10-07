/*
 * function: func_021C2CF4
 * address:  0x021C2CF4
 * packet:   pkt_ov021_021C2CF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020124E8  0x020124E8  thumb
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *
 * func_020124E8 takes the task (the first parameter, still in r0 on the
 * path to the call): that is what keeps r0 live and puts the switch value
 * in r1.
 */
#include "../../../matched/include/Obj04276.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 *func_020124E8(void *task);
typedef signed int     s32;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);

int func_021C2CF4(void *a, u8 *p)
{
    switch (((struct Obj04276 *)p)->f130) {
    case 0:
        if (((struct Obj04276 *)p)->f11C != 0 && ((struct Obj04276 *)p)->f120 != 0 && ((struct Obj04276 *)p)->f124 != 0)
            ((struct Obj04276 *)p)->f130 = ((struct Obj04276 *)p)->f130 + 1;
        break;
    case 1:
        func_0204E720(func_020124E8(a)[0xF] != 0 ? 0xC : 3, 0, 0x10, -1);
        ((struct Obj04276 *)p)->f130 += 1;
    case 2:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}
