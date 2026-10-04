/*
 * function: func_022067FC
 * address:  0x022067FC
 * packet:   pkt_022067FC
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_022083CC 0x022083CC thumb ov195
 */
#include "../include/Obj00300.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern int func_022083CC(char *, u16);

int func_022067FC(char *a)
{
    u16 id = ((struct Obj00300 *)a)->f0;
    char *t = *(char * *)&((struct Obj00300 *)a)->f58;
    int r = 1;
    u8 i;

    for (i = 0; i < 2; i++) {
        if (*(char **)(t + i * 4 + 8) != 0 && func_022083CC(*(char **)(t + i * 4 + 8), id) == 0)
            r = 0;
    }
    return r;
}
