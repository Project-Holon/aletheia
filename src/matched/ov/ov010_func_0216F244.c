/*
 * function: func_0216F244
 * address:  0x0216F244
 * packet:   pkt_ov010_0216F244
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj01640.h"
#include "../include/Obj12408.h"
#include "../include/Obj19152.h"

typedef unsigned char u8;

int func_0216F244(char *a, char *b)
{
    char *q;

    switch (((struct Obj19152 *)b)->f14) {
    case 1:
        return 1;
    case 2:
        return 1;
    case 3:
        return 5;
    case 0:
    default:
        q = **(char ** *)&((struct Obj01640 *)a)->f18;
        if (((struct Obj12408 *)q)->f33 == 0 && ((struct Obj12408 *)q)->f1C != 0)
            return 5;
        return 1;
    }
}
