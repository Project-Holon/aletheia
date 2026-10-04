/*
 * function: func_02186170
 * address:  0x02186170
 * packet:   pkt_ov023_02186170
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02184180  0x02184180  thumb  ov022
 */
#include "../include/Obj20363.h"


extern char *func_02184180(unsigned char *p, int i);

int func_02186170(char *p)
{
    int i;
    int r;

    r = 0;
    for (i = 0; i < 5; i++) {
        *(int *)(p + i * 8 + 0x1cc) = *(int *)(p + i * 8 + 0x1c8);
        *(int *)(p + i * 8 + 0x1c8) = (int)func_02184180((unsigned char *)(**(int * *)&((struct Obj20363 *)p)->f4), (unsigned char)i);
    }
    for (i = 0; i < 5; i++) {
        if (*(int *)(p + i * 8 + 0x1cc) != *(int *)(p + i * 8 + 0x1c8))
            r = 1;
    }
    return r;
}
