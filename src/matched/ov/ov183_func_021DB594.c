/*
 * function: func_021DB594
 * address: 0x021DB594
 * packet: pkt_ov183_021DB594
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: enum mask local materializes one before the call; int mask left nine bytes different
 * symbols:
 *   func_021FEE74 0x021FEE74 thumb ov186
 *   func_021FE794 0x021FE794 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DB690 0x021DB690 thumb ov183
 */
#include "../include/Obj05470.h"
#include "../include/Obj24531.h"
#include "../include/Obj24532.h"
#include "../include/Obj24533.h"
#include "../include/Obj24534.h"
typedef unsigned int   u32;
extern void func_021FEE74(char *p);
extern void func_021FE794(char *p, u32 index, u32 a, u32 b, u32 c);
extern int func_021FE7B0(int *);
extern void func_021F9BA0(void *);
extern void func_021FD73C(int *p, int v);
extern void func_021DB690(int *);
void func_021DB594(int *task, int *state, char *p)
{
    switch(*state) {
    case 0: *state=1; break;
    case 1:
        func_021FEE74((char *)(((struct Obj24531 *)(*(char * *)&((struct Obj05470 *)p)->f1C))->f14));
        *state=2;
        break;
    case 2:
        if((((struct Obj05470 *)p)->f10)++ !=0) {
            ((struct Obj05470 *)p)->f10=0;
            func_021FE794((char *)(((struct Obj24532 *)(*(char * *)&((struct Obj05470 *)p)->f1C))->f8),3,3,1,26);
            *state=3;
        }
        break;
    case 3:
    {
        enum { MASK=1 } mask=MASK;
        if(func_021FE7B0(*(int * *)&((struct Obj24533 *)(*(char * *)&((struct Obj05470 *)p)->f1C))->f8)&mask) *state=4;
        break;
    }
    case 4:
        func_021F9BA0(((struct Obj24534 *)(*(char * *)&((struct Obj05470 *)p)->f1C))->f10);
        func_021FD73C(task,(int)func_021DB690);
        break;
    }
}
