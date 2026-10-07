/*
 * file:     btlv_effvm_p106.c
 * unit:     yes
 * function: func_02206B90, func_02206BAC
 * address:  0x02206B90
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj00823.h"

typedef unsigned int   u32;

extern void func_020061E4(u32 a);
void func_02206B90(char *p);
void func_02206BAC(char *p);


void func_02206B90(char *p)
{
    if (((struct Obj00823 *)p)->f54 != 3 || ((struct Obj00823 *)p)->f58 == 6)
        func_020061E4(0x54d);
}


void func_02206BAC(char *p)
{
    if (((struct Obj00823 *)p)->f54 != 3 || ((struct Obj00823 *)p)->f58 == 6)
        func_020061E4(0x557);
}
