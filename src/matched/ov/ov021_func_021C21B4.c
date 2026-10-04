/*
 * function: func_021C21B4
 * address:  0x021C21B4
 * packet:   pkt_ov021_021C21B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021C24A8  0x021C24A8  thumb  ov021
 *   func_021C1AB4  0x021C1AB4  thumb  ov021
 */
#include "../include/Obj01864.h"

typedef unsigned short u16;

void func_021C24A8(char *p, int k);
typedef unsigned int   u32;
int func_021C1AB4(u32 *p);

int func_021C21B4(char *p)
{
    if (((struct Obj01864 *)p)->f64 == 0) {
        if (((struct Obj01864 *)p)->f78 == 0) {
            if (((struct Obj01864 *)p)->f5C != 0) {
                (((struct Obj01864 *)p)->f5C)--;
            } else {
                func_021C24A8(p, 0);
                ((struct Obj01864 *)p)->f78 = 1;
            }
        }
        if (((struct Obj01864 *)p)->f7C == 0) {
            if (((struct Obj01864 *)p)->f5E != 0) {
                (((struct Obj01864 *)p)->f5E)--;
            } else {
                func_021C24A8(p, 1);
                ((struct Obj01864 *)p)->f7C = 1;
            }
        }
        if (((struct Obj01864 *)p)->f78 != 0 && ((struct Obj01864 *)p)->f7C != 0)
            ((struct Obj01864 *)p)->f64 = 1;
    } else if (func_021C1AB4((u32 *)(((struct Obj01864 *)p)->f0)) != 0) {
        return 1;
    }
    return 0;
}
