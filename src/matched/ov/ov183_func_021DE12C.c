/*
 * function: func_021DE12C
 * address: 0x021DE12C
 * packet: pkt_ov183_021DE12C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj10737.h"
#include "../include/Obj24580.h"
typedef unsigned short u16;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void MI_CpuFill8(void *, int, unsigned);
void func_021DE12C(char *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        char *slot = p + i * 4;
        if (((struct Obj10737 *)slot)->f4) {
            CLACT_DeleteActor(((struct Obj10737 *)slot)->f4);
            ((struct Obj10737 *)slot)->f4 = 0;
        }
    }
    CLACT_DeleteActor(((struct Obj24580 *)p)->f0);
    MI_CpuFill8(p, 0, 20);
}
