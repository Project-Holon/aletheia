/*
 * function: func_021C8738
 * address:  0x021C8738
 * packet:   pkt_ov021_021C8738
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 */
#include "../include/Obj06090.h"

int func_021C8738(char *p, int k)
{
    int r;
    int i;

    switch (k) {
    case 0:
        r = ((struct Obj06090 *)p)->f1B0;
        break;
    case 1:
        r = ((struct Obj06090 *)p)->f1B1;
        break;
    case 2:
        r = ((struct Obj06090 *)p)->f1B2;
        break;
    case 3:
        r = ((struct Obj06090 *)p)->f1B3;
        break;
    case 4:
        r = ((struct Obj06090 *)p)->f6;
        break;
    case 5:
        r = 0;
        for (i = 0; i < 15; i++) {
            if (*(int *)(p + i * 0x1c + 0x24) != 0) {
                r++;
            }
        }
        break;
    default:
        r = 0;
        break;
    }
    return r;
}
