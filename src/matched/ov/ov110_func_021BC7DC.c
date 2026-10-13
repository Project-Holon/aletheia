/*
 * function: PMSIV_BGSCROLL_Step
 * address: 0x021BC7DC
 * packet: pkt_ov110_021BC7DC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMSIV_BGSCROLL_Task 0x021BC828 thumb ov110
 *   PMS_INPUT_VIEW_AddVBlankTask 0x021B9BA4 thumb ov110
 *   func_02030EAC 0x02030EAC arm
 */
#include "../include/Obj05293.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void PMSIV_BGSCROLL_Task(void *, u8 *);
struct Node;
extern void *PMS_INPUT_VIEW_AddVBlankTask(void (*fn)(void *, u8 *), u8 *p, int n);
extern void func_02030EAC(struct Node *n);
int PMSIV_BGSCROLL_Step(u8 *p)
{
    switch (((struct Obj05293 *)p)->f16) {
    case 0:
        ((struct Obj05293 *)p)->f18=PMS_INPUT_VIEW_AddVBlankTask(PMSIV_BGSCROLL_Task,p,0);
        ++((struct Obj05293 *)p)->f16;
        break;
    case 1:
        if (((struct Obj05293 *)p)->f14==0) {
            func_02030EAC(((struct Obj05293 *)p)->f18);
            ++((struct Obj05293 *)p)->f16;
            return 1;
        }
        break;
    case 2: return 1;
    }
    return 0;
}
