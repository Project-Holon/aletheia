/*
 * function: func_021F21BC
 * address:  0x021F21BC
 * packet:   pkt_021F21BC
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045A98 0x02045A98 arm
 *   func_021F23FC 0x021F23FC thumb
 */
#include "../include/Obj01574.h"

extern unsigned short func_02045A98(void);
typedef unsigned char  u8;
extern int func_021F23FC(u8 *p, int direction);

int func_021F21BC(unsigned char *p, unsigned short a, unsigned short b)
{
    if (((struct Obj01574 *)p)->f1E < ((struct Obj01574 *)p)->f22 &&
        ((struct Obj01574 *)p)->f20 < 3) {
        *(unsigned short *)(p + 0x16 + ((struct Obj01574 *)p)->f20 * 2) = a;
        ((struct Obj01574 *)p)->f20 += 1;
        *(unsigned short *)(p + 0x16 + ((struct Obj01574 *)p)->f20 * 2) =
            func_02045A98();
        func_021F23FC(p, b);
        ((struct Obj01574 *)p)->f28 = 1;
        return 1;
    }
    return 0;
}
