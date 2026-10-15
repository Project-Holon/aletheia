/*
 * function: STA_ACT_SCRIPT_RunScript
 * address: 0x021FAD2C
 * packet: pkt_ov132_021FAD2C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: follower 021FAD7C is separately filed under pkt_ov132_021FAD7C.
 * symbols:
 *   VM_Control 0x02011298 thumb
 *   func_02011290 0x02011290 thumb
 *   VM_Delete 0x02011264 thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj02485.h"
typedef unsigned short u16;
struct ScriptVm;
extern int VM_Control(struct ScriptVm *vm);
extern struct ScriptVm *func_02011290(struct ScriptVm *vm);
extern void VM_Delete(void *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
int STA_ACT_SCRIPT_RunScript(void *unused, char *p)
{
    if (((struct Obj02485 *)p)->f14 != 0) (((struct Obj02485 *)p)->f14)--;
    if (((struct Obj02485 *)p)->f14 == 0 && !(((struct Obj02485 *)p)->f16 & 4)) {
        VM_Control(((struct Obj02485 *)p)->f4);
        if (((struct Obj02485 *)p)->f16 & 1) {
            func_02011290(((struct Obj02485 *)p)->f4);
            VM_Delete(((struct Obj02485 *)p)->f4);
            if (((struct Obj02485 *)p)->f16 & 8) func_020307B0(((struct Obj02485 *)p)->fC);
            return 1;
        }
    }
    (((struct Obj02485 *)p)->f10)++;
    return 0;
}
