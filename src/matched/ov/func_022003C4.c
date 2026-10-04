/*
 * function: func_022003C4
 * address:  0x022003C4
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_022003C4   0x022003C4  thumb
 *   func_022019F4 0x022019F4 thumb ov094

 *
 * lane O10 candidate
 */
#include "../include/Obj12226.h"

extern int func_022019F4(char *p, int key);

int func_022003C4(char *p, int key)
{
    int i = func_022019F4(p, key);
    char *e;

    if (i == -1)
        return 0;
    e = p + i * 0x5c;
    if (((struct Obj12226 *)e)->f8 == 0)
        return 0;
    return ((struct Obj12226 *)e)->f44;
}

