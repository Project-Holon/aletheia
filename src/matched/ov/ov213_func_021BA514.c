/*
 * function: func_021BA514
 * address: 0x021BA514
 * packet: pkt_ov213_021BA514
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203D5D4 0x0203D5D4 arm
 *   func_021BA4BC 0x021BA4BC thumb ov213
 * prototype: caller loads r0 net object before D5D4; retained visible input despite callee's void parameter list.
 */
#include "../include/Obj03939.h"
#include "../include/Obj25704.h"
#include "../include/Obj25705.h"
#include "../include/Obj25706.h"
#include "../include/Obj25707.h"
#include "../include/Obj25708.h"
extern int func_0203D5D4(void *);
extern void func_021BA4BC(void *,int,int);
void func_021BA514(char *p)
{
    if(((struct Obj25704 *)(*(char * *)&((struct Obj03939 *)p)->f4))->f54) {
        switch(func_0203D5D4(((struct Obj25705 *)(*(char * *)&((struct Obj03939 *)p)->f4))->f54)) {
        case 37:case 12:case 31:func_021BA4BC(((struct Obj25706 *)(*(char * *)&((struct Obj03939 *)p)->f4))->f54,37,((struct Obj03939 *)p)->f49CC);break;
        case 10:func_021BA4BC(((struct Obj25707 *)(*(char * *)&((struct Obj03939 *)p)->f4))->f54,17,((struct Obj03939 *)p)->f49CC);break;
        case 20:case 21:case 23:case 24:case 25:case 26:
            func_021BA4BC(((struct Obj25708 *)(*(char * *)&((struct Obj03939 *)p)->f4))->f54,13,((struct Obj03939 *)p)->f49CC);break;
        }
    }
}
