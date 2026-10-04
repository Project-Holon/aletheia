/*
 * function: func_02193D08
 * address:  0x02193D08
 * packet:   pkt_ov021_02193D08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj19618.h"

int func_02193D08(unsigned char *p)
{
    int count = 0;
    int i;
    unsigned char *q = *(unsigned char * *)&((struct Obj19618 *)p)->f4;

    if (q != 0) {
        for (i = 0; i < 10; i++) {
            if (*(unsigned short *)(q + i * 0x50) != 0)
                count++;
        }
    }
    return count;
}
