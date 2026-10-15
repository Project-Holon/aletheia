/*
 * function: WIFIBATTLEMATCH_SYS_HandleRule2Command
 * address: 0x02213278
 * packet: pkt_ov199_02213278
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02034714 0x02034714 arm
 *   WIFIBATTLEMATCH_SYS_SetStep 0x02213808 thumb ov199
 *   WIFIBATTLEMATCH_SYS_SetStepDone 0x0221380C thumb ov199
 *   d_02213D00 0x02213D00 data ov199 a1
 */
#include "../include/Obj14578.h"
extern unsigned int func_020307B0(void *p);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void WIFIBATTLEMATCH_SYS_SetStep(char *, int);
extern void WIFIBATTLEMATCH_SYS_SetStepDone(unsigned char *p);
extern const char d_02213D00[];
int WIFIBATTLEMATCH_SYS_HandleRule2Command(char *a, void *work, char *p)
{
    switch (((struct Obj14578 *)p)->f1C) {
    case 0:
        if (((struct Obj14578 *)p)->f24 != 0)
            WIFIBATTLEMATCH_SYS_SetStepDone((unsigned char *)a);
        else
            WIFIBATTLEMATCH_SYS_SetStep(a, 0);
        break;
    case 1:
        func_02034714(d_02213D00, 0, d_02213D00);
        break;
    case 2:
    case 3:
        WIFIBATTLEMATCH_SYS_SetStepDone((unsigned char *)a);
        break;
    }
    func_020307B0(work);
    return 1;
}
