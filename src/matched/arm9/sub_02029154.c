/*
 * function: func_02029154
 * address:  0x02029154
 * packet:   pkt_02028FD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   sub_02029344  0x02029344  thumb
 */
#include "../include/Obj16756.h"

typedef unsigned int u32;

extern void sub_02029344(void *obj, u32 value);

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
