/*
 * function: func_021DD1B8
 * address: 0x021DD1B8
 * packet: pkt_ov119_021DD1B8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020173EC 0x020173EC thumb
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj08061.h"
typedef unsigned int   u32;
extern u32 func_020173EC(void);
extern void func_02082BCC(void *, int, int);
void func_021DD1B8(char *p)
{
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            char *q = p + i * 12 + j * 4;
            ((struct Obj08061 *)q)->fFA4 = -1;
            ((struct Obj08061 *)q)->fFBC = -1;
            if (((struct Obj08061 *)q)->fFD8) func_02082BCC(((struct Obj08061 *)q)->fFD8, 0, func_020173EC());
        }
    }
}
