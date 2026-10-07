/*
 * file:     pokemontrade_proc_p07.c
 * unit:     yes
 * function: func_021D9124, func_021D913C
 * address:  0x021D9124
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D90E8  0x021D90E8  thumb  ov119
 */
#include "../../matched/include/Obj22708.h"
#include "../../matched/include/Obj22709.h"

extern int func_021D90E8(int a, int b, int c, int d, int e);
int func_021D9124(int a, int b, int c, int d, int e);
int func_021D913C(int a, int b, int c, int d, int e);


/*
 * Encoder session getter on the byte pointed at by the third argument.
 */
int func_021D9124(int a, int b, int c, int d, int e)
{
    return func_021D90E8(((struct Obj22708 *)c)->f0, 0, a, d, e);
}


int func_021D913C(int a, int b, int c, int d, int e)
{
    return func_021D90E8(((struct Obj22709 *)c)->f0, 1, a, d, e);
}
