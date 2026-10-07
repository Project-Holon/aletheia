/*
 * file:     btlv_effvm_p105.c
 * unit:     yes
 * function: func_02206B14, func_02206B30, func_02206B58, func_02206B74
 * address:  0x02206B14
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
 *   func_020061E4  0x020061E4  thumb
 */
#include "../../matched/include/Obj00823.h"

typedef unsigned int   u32;

extern void func_020061E4(u32 a);
void func_02206B14(char *p);
void func_02206B30(char *p);
void func_02206B58(char *p);
void func_02206B74(char *p);


void func_02206B14(char *p)
{
    if (((struct Obj00823 *)p)->f54 != 3 || ((struct Obj00823 *)p)->f58 == 6)
        func_020061E4(0x548);
}


/*
 * lane S13 leaf of func_0220648C
 */
void func_02206B30(char *p)
{
    if (((struct Obj00823 *)p)->f58 != 6) {
        if (((struct Obj00823 *)p)->f54 != 3) {
            func_020061E4(0x54d);
        }
    } else {
        func_020061E4(0x54c);
    }
}


/*
 * lane S13 leaf of func_022064CC-area callers (func_0220648C)
 */
void func_02206B58(char *p)
{
    if (((struct Obj00823 *)p)->f54 != 3 || ((struct Obj00823 *)p)->f58 == 6)
        func_020061E4(0x552);
}


void func_02206B74(char *p)
{
    if (((struct Obj00823 *)p)->f54 != 3 || ((struct Obj00823 *)p)->f58 == 6)
        func_020061E4(0x579);
}
