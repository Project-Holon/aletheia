/*
 * file:     tr_ai_p09.c
 * unit:     yes
 * function: func_021891D4, func_021891E4
 * address:  0x021891D4
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021891F4 0x021891F4 thumb ov096
 */
#include "../../matched/include/Obj21957.h"
#include "../../matched/include/Obj21958.h"

typedef struct Obj Obj;

extern int func_021891F4(int, Obj *, int);
int func_021891D4(int a, Obj * b);
int func_021891E4(int a, Obj * b);

int func_021891D4(int a, Obj * b)
{
    func_021891F4(a, b, 2);
    return ((struct Obj21957 *)((unsigned int)b))->fC4;
}

int func_021891E4(int a, Obj * b)
{
    func_021891F4(a, b, 3);
    return ((struct Obj21958 *)((unsigned int)b))->fC4;
}
