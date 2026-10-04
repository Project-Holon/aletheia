/*
 * function: func_0217E414
 * address: 0x0217E414
 * packet: pkt_ov176_0217E414
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02157E78 0x02157E78 thumb ov010
 *   func_02157E8C 0x02157E8C thumb ov010
 *   func_0203D210 0x0203D210 arm
 */
#include "../include/Obj04563.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_02157E78(u8 *p);
extern int func_02157E8C(int a0);
extern u32 func_0203D210(void);
int func_0217E414(char *p)
{
    if (((struct Obj04563 *)p)->f1018)
        func_02157E78(((struct Obj04563 *)p)->f1018);
    switch (((struct Obj04563 *)p)->f0) {
    case 0:
        if (((struct Obj04563 *)p)->f1018) {
            func_02157E8C((int)(((struct Obj04563 *)p)->f1018));
            ((struct Obj04563 *)p)->f1018 = 0;
        }
        (((struct Obj04563 *)p)->f0)++;
        break;
    case 1:
        if (func_0203D210())
            return 1;
        break;
    }
    return 0;
}
