/*
 * file:     unit_0202913C.c
 * unit:     yes
 * function: func_0202913C, func_02029154
 * address:  0x0202913C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_02029344  0x02029344  thumb
 */
#include "../../matched/include/Obj16755.h"
#include "../../matched/include/Obj16756.h"

typedef unsigned int u32;

extern void sub_02029344(void *obj, u32 value);
void func_0202913C(void *obj);
void func_02029154(void *obj);


void func_0202913C(void *obj)
{
    switch (((struct Obj16755 *)obj)->f1C) {
    case 0:
    case 5:
        break;
    case 3:
        sub_02029344(obj, 11);
        break;
    }
}


void func_02029154(void *obj)
{
    switch (((struct Obj16756 *)obj)->f1C) {
    case 0:
    case 5:
        break;
    case 3:
        sub_02029344(obj, 12);
        break;
    }
}
