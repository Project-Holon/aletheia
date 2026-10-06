/*
 * function: func_021D5BEC
 * address: 0x021D5BEC
 * packet: pkt_ov120_021D5BEC
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_021D846C 0x021D846C thumb ov120
 *   func_021D63F4 0x021D63F4 thumb ov120
 *   func_02040588 0x02040588 arm
 *   func_021D761C 0x021D761C thumb ov120
 *   func_021D7B38 0x021D7B38 thumb ov120
 *   func_021D883C 0x021D883C thumb ov120
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D588C 0x021D588C thumb ov120
 */
#include "../include/Obj01056.h"
#include "../include/Obj22834.h"
#include "../include/Obj22835.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0203D7B0(u8 a0);
extern void func_0203D7BC(u8 a0);
extern void func_021D846C(u8 *);
extern void func_021D63F4(u8 *p, int flag, int mode);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_021D761C(u8 *p);
extern void func_021D7B38(char *p);
extern void func_021D883C(char *);
extern void func_021D69F4(u8 *p, void *q, u32 n);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D588C(u8 *p);
void func_021D5BEC(u8 *p)
{
    if (((struct Obj22834 *)(*(u8 * *)&((struct Obj01056 *)p)->f48))->f1B0 != 1) {
        int zero = 0;
        func_0203D7B0(0);
        func_0203D7BC(0);
        func_021D846C(*(u8 * *)&((struct Obj01056 *)p)->f40);
        func_021D63F4(((struct Obj01056 *)p)->f3C, 0, 0);
        func_02040588(4, 0);
        func_021D761C(((struct Obj01056 *)p)->f3C);
        func_021D7B38((char *)(*(int *)&((struct Obj01056 *)p)->f40));
        func_021D883C(*(char * *)&((struct Obj01056 *)p)->f40);
        func_021D69F4(((struct Obj01056 *)p)->f3C, 0, 9);
        ((struct Obj01056 *)p)->f1B0 = 1;
        ((struct Obj01056 *)p)->f1B4 = zero;
        ((struct Obj22835 *)(*(u8 * *)&((struct Obj01056 *)p)->f48))->f1B0 = 1;
        func_021D4244((int *)p, (int)func_021D588C, 0x937);
    }
}
