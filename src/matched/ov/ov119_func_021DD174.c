/*
 * function: func_021DD174
 * address: 0x021DD174
 * packet: pkt_ov119_021DD174
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj10358.h"
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021DD174(char *p)
{
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            char *q = p + i * 12 + j * 4;
            if (((struct Obj10358 *)q)->fFD8) {
                func_020307B0(((struct Obj10358 *)q)->fFD8);
                ((struct Obj10358 *)q)->fFD8 = 0;
            }
        }
    }
}
