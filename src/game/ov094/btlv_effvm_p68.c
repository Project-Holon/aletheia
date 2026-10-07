/*
 * file:     btlv_effvm_p68.c
 * unit:     yes
 * function: func_021FFF0C, func_021FFF38
 * address:  0x021FFF0C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_022019F4 0x022019F4 thumb ov094
 */
#include "../../matched/include/Obj12223.h"
#include "../../matched/include/Obj12224.h"

extern int func_022019F4(char *p, int key);
int func_021FFF0C(char *p, int key);
int func_021FFF38(char *p, int key);


/*
 * lane O10 candidate
 */
int func_021FFF0C(char *p, int key)
{
    int i = func_022019F4(p, key);
    char *e;

    if (i == -1)
        return 0;
    e = p + i * 0x5c;
    if (((struct Obj12223 *)e)->f8 == 0)
        return 0;
    return ((struct Obj12223 *)e)->f40;
}


int func_021FFF38(char *p, int key)
{
    int i;
    char *e;

    if (key == 0xff)
        return 0;
    i = func_022019F4(p, key);
    if (i == -1)
        return 0;
    e = p + i * 0x5c;
    if (((struct Obj12224 *)e)->f8 == 0)
        return 0;
    return ((struct Obj12224 *)e)->f48;
}
