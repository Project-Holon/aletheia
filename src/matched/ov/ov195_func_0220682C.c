/*
 * function: func_0220682C
 * address:  0x0220682C
 * packet:   pkt_0220682C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02208420 0x02208420 thumb ov195
 */
#include "../include/Obj00300.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern int func_02208420(char *, u16);

int func_0220682C(char *a)
{
    u16 id = ((struct Obj00300 *)a)->f0;
    char *t = *(char * *)&((struct Obj00300 *)a)->f58;
    int r = 1;
    u8 i;

    for (i = 0; i < 2; i++) {
        if (*(char **)(t + i * 4 + 8) != 0 && func_02208420(*(char **)(t + i * 4 + 8), id) == 0)
            r = 0;
    }
    return r;
}
