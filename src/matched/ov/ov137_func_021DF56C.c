/*
 * unit: yes
 * function: func_021DF56C, func_021DF598
 * address: 0x021DF56C
 * packet: pkt_ov137_021DF56C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E19A4 0x021E19A4 thumb ov137
 *   func_021E0130 0x021E0130 thumb ov137
 */
#include "../include/Obj08219.h"
#include "../include/Obj08220.h"
typedef unsigned char u8;
extern int func_021E19A4(void);
extern void func_021E0130(u8 *p, int message);
int func_021DF56C(u8 *p)
{
    if (((struct Obj08219 *)p)->fC < 180) {
        ((struct Obj08219 *)p)->fC += 1;
    } else if (func_021E19A4() == 0) {
        ((struct Obj08219 *)p)->fC = 0;
        ((struct Obj08219 *)p)->f0 = 41;
        func_021E0130(p, 4);
    }
    return 0;
}
int func_021DF598(u8 *p)
{
    if (((struct Obj08220 *)p)->fC < 180) {
        ((struct Obj08220 *)p)->fC += 1;
    } else {
        ((struct Obj08220 *)p)->fC = 0;
        ((struct Obj08220 *)p)->f0 = 42;
    }
    return 0;
}
