/*
 * function: func_021FAD2C
 * address: 0x021FAD2C
 * packet: pkt_ov132_021FAD2C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: follower 021FAD7C is separately filed under pkt_ov132_021FAD7C.
 * symbols:
 *   func_02011298 0x02011298 thumb
 *   func_02011290 0x02011290 thumb
 *   func_02011264 0x02011264 thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj02485.h"
typedef unsigned short u16;
struct ScriptVm;
extern int func_02011298(struct ScriptVm *vm);
extern void func_02011290(struct ScriptVm *vm);
extern void func_02011264(void *);
extern void func_020307B0(void *);
int func_021FAD2C(void *unused, char *p)
{
    if (((struct Obj02485 *)p)->f14 != 0) (((struct Obj02485 *)p)->f14)--;
    if (((struct Obj02485 *)p)->f14 == 0 && !(((struct Obj02485 *)p)->f16 & 4)) {
        func_02011298(((struct Obj02485 *)p)->f4);
        if (((struct Obj02485 *)p)->f16 & 1) {
            func_02011290(((struct Obj02485 *)p)->f4);
            func_02011264(((struct Obj02485 *)p)->f4);
            if (((struct Obj02485 *)p)->f16 & 8) func_020307B0(((struct Obj02485 *)p)->fC);
            return 1;
        }
    }
    (((struct Obj02485 *)p)->f10)++;
    return 0;
}
